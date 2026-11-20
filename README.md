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
**Project Status:** Digital Design Completed – Hardware Development Pending 🚧

## 💡 Why I Made This

I wanted to create a small wearable device that makes controlling music more convenient.

Instead of constantly taking my phone out of my pocket to change songs or adjust the volume, I wanted to have these controls directly on my wrist.

I decided to design the entire electronic system myself, including the PCB, power management, and hardware layout, rather than relying on an existing development board or ready-made solution.

## ✨ Features

- **Bluetooth Connectivity:** Designed to connect to Android devices using the ESP32-C3's Bluetooth capabilities.
- **Media Controls:** Dedicated physical buttons for music playback.
- **Volume Control:** A rotary control for adjusting the volume.
- **Rechargeable Battery:** Integrated Li-Po charging circuit.
- **USB-C Charging:** Charging through a USB-C connector.
- **Compact PCB:** Custom-designed electronics intended to fit inside a wearable enclosure.
- **Standalone Operation:** Designed to work without a dedicated mobile application.

## 🖼️ Project Gallery

### 3D Assembly

<p align="center">
  <img width="447" src="https://github.com/user-attachments/assets/c6181862-1431-4478-9f05-42aba1a644bc" alt="3D model of the Music Bracelet enclosure">
</p>

*3D model of the bracelet enclosure, including the physical controls and charging port.*

**[🔗 View Full 3D Assembly on Onshape](https://cad.onshape.com/documents/3bd6b4cfeb2b41e224dd819f/w/d73a3a9d2469daf80b615cbf/e/bd991009cba7e1cd4ab621f9)**

### PCB Design

<p align="center">
  <img width="317" src="https://github.com/user-attachments/assets/52f6af5a-e1ee-4ac8-98a2-8f6e6eb5a6da" alt="3D render of the custom PCB">
</p>

*3D render of the custom PCB designed in KiCad.*

### Schematic

<p align="center">
  <img width="566" src="https://github.com/user-attachments/assets/81b885b1-fe65-4256-a202-5254d5a17eef" alt="Music Bracelet electrical schematic">
</p>

*Electrical schematic showing the ESP32-C3 connections and battery charging circuit.*

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

### PCB Source Files

The KiCad project files are included in this repository:

- [KiCad Project](./music%20bracelet%20schem.kicad_pro)
- [PCB Layout](./music%20bracelet%20schem.kicad_pcb)
- [Electrical Schematic](./music%20bracelet%20schem.kicad_sch)
- [PCB Project Settings](./music%20bracelet%20schem.kicad_prl)

### Manufacturing Files

The Gerber and drill files are packaged together for PCB manufacturing.

**[📥 Download Gerber Files (ZIP)](./gerbers.zip)**

## 🧾 Bill of Materials (BOM)

The Bill of Materials contains the electronic components used in the Music Bracelet project.

It includes component information, quantities, and manufacturing details.

**[📥 View Bill of Materials (CSV)](./BOM.csv)**

## 💻 Firmware

The firmware will run on the ESP32-C3 and handle:

- Bluetooth connection and communication.
- Media playback commands.
- Volume control.
- Reading physical button inputs.
- Battery and power management.

The firmware is currently under development.

**[💻 View Firmware Source Code](./main.cpp)**

## 🏗️ Mechanical Design

The bracelet enclosure was designed as a custom 3D model to house the electronics and provide access to the physical controls.

The mechanical design focuses on:

- A compact wearable form factor.
- Accessible physical buttons and volume control.
- A USB-C charging port.
- Proper space for the PCB and battery.

### Mechanical Files

- [Full 3D Assembly on Onshape](https://cad.onshape.com/documents/3bd6b4cfeb2b41e224dd819f/w/d73a3a9d2469daf80b615cbf/e/bd991009cba7e1cd4ab621f9)
- [Bracelet Case – STEP](./bracelet%20case.step)
- [Closed Case – STEP](./case%20closed.step)
- [PCB 3D Model – STEP](./music%20bracelet%20schem.step)

## 🛠️ Tools & Technologies

- **KiCad** – PCB design and schematic capture.
- **ESP32-C3** – Main microcontroller.
- **Embedded C/C++** – Firmware development.
- **Onshape** – Mechanical design and 3D modeling.
- **STEP** – 3D model exchange and manufacturing.

## 🚧 Development Roadmap

### Digital Design

The initial digital design includes the PCB, electrical schematic, component selection, BOM, and mechanical enclosure.

### Next Steps

1. Manufacture the custom PCB.
2. Assemble the electronic components.
3. Integrate the PCB and battery into the enclosure.
4. Develop and upload the firmware.
5. Implement Bluetooth media controls.
6. Test charging and battery management.
7. Test the complete system.
8. Finalize the bracelet assembly.

## 🎯 Future Plans

After completing the digital design, the next step is to manufacture the PCB and assemble the bracelet.

The final goal is to have a fully functional wearable device that can connect to a phone and control music reliably.

---

<p align="center">
  **Designed and developed by me.** 🎵
</p>
