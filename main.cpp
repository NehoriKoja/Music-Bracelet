#include <Arduino.h>
#include <BleKeyboard.h>
#include <NimBLEDevice.h>

BleKeyboard bleKeyboard("Music Bracelet 1.0", "DIY", 100);

const int BTN_PINS[4] = {2, 3, 4, 6};
const int ENC_A = 5;
const int ENC_B = 7;
const char* BTN_NAMES[4] = {"Next track", "Play/Pause", "Previous track", "Mute"};

bool lastBtn[4] = {true, true, true, true};
unsigned long lastDebounce[4] = {0, 0, 0, 0};
int lastEncA;
bool wasConnected = false;
String cmd;

// ---------- actions (used by both real inputs and serial commands) ----------
const MediaKeyReport* mediaKey(int i) {
  static const MediaKeyReport* keys[4] = {&KEY_MEDIA_NEXT_TRACK, &KEY_MEDIA_PLAY_PAUSE, &KEY_MEDIA_PREVIOUS_TRACK, &KEY_MEDIA_MUTE};
  return keys[i];
}

void buttonDown(int i) {
  Serial.printf("[BTN %d] DOWN -> %s\n", i + 1, BTN_NAMES[i]);
  bleKeyboard.press(*mediaKey(i));
}
void buttonUp(int i) {
  Serial.printf("[BTN %d] UP\n", i + 1);
  bleKeyboard.release(*mediaKey(i));
}
void wheel(bool up) {
  Serial.printf("[WHEEL] %s\n", up ? "UP -> volume up" : "DOWN -> volume down");
  bleKeyboard.write(up ? KEY_MEDIA_VOLUME_UP : KEY_MEDIA_VOLUME_DOWN);
}

void printHelp() {
  Serial.println("\n=== Debug commands (type + Enter) ===");
  Serial.println("1 / 2 / 3 / 4    tap button 1/2/3/4");
  Serial.println("d1 / d2 / d3 / d4  hold button down");
  Serial.println("u1 / u2 / u3 / u4  release button");
  Serial.println("+  or  -      wheel up / down");
  Serial.println("t <text>      type text, e.g.  t hello");
  Serial.println("pins          show raw pin states");
  Serial.println("status        show connection status");
  Serial.println("help          show this list\n");
}

void printStatus() {
  Serial.printf("Connected: %s\n", bleKeyboard.isConnected() ? "YES" : "NO");
}

void printPins() {
  for (int i = 0; i < 3; i++)
    Serial.printf("BTN%d (GPIO%d): %s\n", i + 1, BTN_PINS[i],
                  digitalRead(BTN_PINS[i]) ? "released" : "PRESSED");
  Serial.printf("ENC A (GPIO%d): %d   ENC B (GPIO%d): %d\n",
                ENC_A, digitalRead(ENC_A), ENC_B, digitalRead(ENC_B));
}

void handleCommand(String c) {
  c.trim();
  if (c.length() == 0) return;

  // commands that don't need a connection
  if (c == "help" || c == "?") { printHelp(); return; }
  if (c == "status")           { printStatus(); return; }
  if (c == "pins")             { printPins(); return; }

  if (!bleKeyboard.isConnected()) {
    Serial.println("Not connected to a device. Pair first, then try again.");
    return;
  }

  if (c == "1" || c == "2" || c == "3" || c == "4") {
    int i = c.toInt() - 1;
    buttonDown(i);
    delay(50);
    buttonUp(i);
  } else if (c.length() == 2 && (c[0] == 'd' || c[0] == 'u') && c[1] >= '1' && c[1] <= '3') {
    int i = c[1] - '1';
    if (c[0] == 'd') buttonDown(i); else buttonUp(i);
  } else if (c == "+") {
    wheel(true);
  } else if (c == "-") {
    wheel(false);
  } else if (c.startsWith("t ")) {
    String text = c.substring(2);
    Serial.printf("[TYPE] \"%s\"\n", text.c_str());
    bleKeyboard.print(text);
  } else {
    Serial.printf("Unknown command: %s  (type 'help')\n", c.c_str());
  }
}

void setup() {
  Serial.begin(115200);
  delay(2000);
  for (int i = 0; i < 3; i++) pinMode(BTN_PINS[i], INPUT_PULLUP);
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
  lastEncA = digitalRead(ENC_A);

  bleKeyboard.begin();
  NimBLEDevice::setPower(ESP_PWR_LVL_N0);
  Serial.println("Keyboard advertising...");
  printHelp();
}

void loop() {
  // ---- serial commands ----
  while (Serial.available()) {
    char ch = Serial.read();
    if (ch == '\n' || ch == '\r') { handleCommand(cmd); cmd = ""; }
    else cmd += ch;
  }

  // ---- connection change messages ----
  bool conn = bleKeyboard.isConnected();
  if (conn != wasConnected) {
    wasConnected = conn;
    Serial.println(conn ? "** Connected **" : "** Disconnected **");
  }
  if (!conn) { delay(20); return; }

  // ---- real buttons ----
  for (int i = 0; i < 3; i++) {
    bool state = digitalRead(BTN_PINS[i]);
    if (state != lastBtn[i] && millis() - lastDebounce[i] > 20) {
      lastDebounce[i] = millis();
      lastBtn[i] = state;
      if (!state) buttonDown(i); else buttonUp(i);
    }
  }

  // ---- real wheel ----
  int a = digitalRead(ENC_A);
  if (a != lastEncA && a == LOW) wheel(digitalRead(ENC_B) == HIGH);
  lastEncA = a;
}