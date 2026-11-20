# 🎵 Music Bracelet

<p align="center">
  **A wearable Bluetooth music controller.**
  <br>
  Control your music directly from your wrist without taking your phone out of your pocket.
</p>

---

## 📖 About the Project

The Music Bracelet is a custom-designed wearable Bluetooth media controller built around the ESP32-C3.

The goal is to create a compact bracelet that allows users to control music playback and volume through physical controls, without needing to interact with their phone.

The device combines custom PCB design, embedded electronics, battery management, and Bluetooth communication into a single wearable device.

**Submission Type:** Design Submission  
**Project Status:** In Development 🚧

## 💡 Why I Made This

I wanted to create a small wearable device that makes controlling music more convenient.

Instead of constantly taking my phone out of my pocket to change songs or adjust the volume, I wanted to have these controls directly on my wrist.

I decided to design the entire electronic system myself, including the PCB, power management, and hardware layout, rather than relying on an existing development board or ready-made solution.

## ✨ Features

- **Bluetooth Connectivity:** Connects to Android devices using the ESP32-C3's Bluetooth capabilities.
- **Media Controls:** Dedicated physical buttons for music playback.
- **Volume Control:** A rotary control for adjusting music volume.
- **Rechargeable Battery:** Integrated Li-Po charging circuit.
- **USB-C Charging:** Convenient charging through a USB-C connector.
- **Compact PCB:** Custom-designed electronics intended to fit inside a wearable enclosure.
- **Standalone Operation:** Designed to work without a dedicated mobile application.

## 🖼️ Project Gallery

### 3D Assembly

<img width="447" height="364" alt="image" src="https://github.com/user-attachments/assets/c6181862-1431-4478-9f05-42aba1a644bc" />
#3D model of the bracelet enclosure, including the physical controls and charging port.

### PCB Design

<img width="317" height="200" alt="image" src="https://github.com/user-attachments/assets/52f6af5a-e1ee-4ac8-98a2-8f6e6eb5a6da" />
#Custom PCB layout designed in KiCad.

### Schematic

<img width="566" height="386" alt="image" src="https://github.com/user-attachments/assets/81b885b1-fe65-4256-a202-5254d5a17eef" />
#Electrical schematic showing the ESP32-C3 connections and battery charging circuit.

## 🔌 Electronics

The project uses a custom PCB designed around the following components:

| Component | Purpose |
|---|---|
| ESP32-C3-MINI-1 | Main microcontroller and Bluetooth connectivity |
| MCP73871 | Li-Po battery charging and power management |
| AP2112K | Voltage regulation |
| USB-C Connector | Charging and USB connectivity |
| Rotary Encoder | Volume control |
| Push Buttons | Media controls |
| Li-Po Battery | Portable power source |
| Power Switch | Main power control |

## 📐 PCB Design

The PCB is designed using **KiCad**.

Some of the main design considerations include:

- Keeping the PCB as compact as possible.
- Making the physical controls accessible.
- Integrating the charging and power management circuits.
- Keeping the ESP32-C3 antenna clear of surrounding components.
- Designing the board to fit inside a wearable enclosure.

## 🧾 Bill of Materials (BOM)

The Bill of Materials contains the components required to manufacture and assemble the bracelet.

Each component includes its quantity, manufacturer or supplier, and purchase link.

| Component | Quantity | Supplier |
|---|---:|---|
| ESP32-C3-MINI-1 | 1 | [Link](ADD_LINK) |
| MCP73871 | 1 | [Link](ADD_LINK) |
| AP2112K | 1 | [Link](ADD_LINK) |
| USB-C Connector | 1 | [Link](ADD_LINK) |
| Rotary Encoder | 1 | [Link](ADD_LINK) |
| Push Buttons | 3 | [Link](ADD_LINK) |
| Li-Po Battery | 1 | [Link](ADD_LINK) |

For the complete component list, see [`BOM.csv`](BOM.csv).

## 💻 Firmware

The firmware will run on the ESP32-C3 and handle:

- Bluetooth connection and communication.
- Media playback commands.
- Volume control.
- Reading physical button inputs.
- Battery and power management.

The firmware is currently under development.

## 🛠️ Tools & Technologies

- **KiCad** – PCB design and schematic capture.
- **ESP32-C3** – Microcontroller.
- **Embedded C/C++** – Firmware development.
- **3D CAD Software** – Mechanical design and enclosure development.

## 🚧 Development Roadmap

1. Complete schematic design.
2. Finish PCB routing.
3. Finalize mechanical design and 3D assembly.
4. Generate manufacturing files (Gerbers).
5. Finalize the Bill of Materials.
6. Manufacture and assemble the PCB.
7. Develop the firmware.
8. Implement and test Bluetooth media controls.
9. Complete final assembly and testing.

## 🎯 Future Plans

After completing the digital design, the next step is to manufacture the PCB and assemble the bracelet.

The final goal is to have a fully functional wearable device that can connect to a phone and control music reliably.

---

**Designed and developed by me.**
