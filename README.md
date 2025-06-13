#  Money Counting Machine

> 🎓 **This is a graduation project**, and I, **Mohamed Mokhtar**, served as the **mentor** for the student team behind it.


> ## 📚 Table of Contents

- [💡 Project Overview](#-project-overview)
- [📸 Project Photo](#-project-photo)
- [🎯 Features](#-features)
- [🧰 Components Used](#-components-used)
- [🚀 How It Works](#-how-it-works)
- [📲 Bluetooth Commands](#-bluetooth-commands-example)
- [📺 LCD Display Example](#-lcd-display-example)
- [🛠️ Notes](#️-notes)
- [🔮 Future Enhancements](#-future-enhancements)
- [🎓 Graduation Project Team](#-graduation-project-team)

---

- ## 💡 Project Overview

The **Money Counting Machine** is a smart embedded system designed to count Egyptian paper currency efficiently. It uses an **IR sensor** to detect each note and **two DC motors with gears** to feed the notes one at a time. Users can select the currency category using **8 physical buttons** or via **Bluetooth**. An **LCD screen** displays the total value and number of notes per denomination.

---

## 📸 Project Photo
<p align="center">
  <img src="https://github.com/user-attachments/assets/ee401eec-7032-4928-b533-1533c8e9860d" alt="Money Counting Machine Hardware" width="600"/>
</p>


---

## 🎯 Features

- 🧮 Automatic counting of paper currency via IR sensor  
- ⚙️ Gear-driven system with 2 DC motors for note-by-note feeding  
- 🔘 8-button interface:
  - 6 buttons to choose currency (5, 10, 20, 50, 100, 200 EGP)
  - 1 button to clear totals
  - 1 button to cycle through denomination stats  
- 📱 Bluetooth module for wireless category selection  
- 📟 Real-time LCD display showing:
  - Total amount
  - Selected denomination
  - Number of notes per category  

---

## 🧰 Components Used

- STM32F401RCT6 Microcontroller  
- IR Sensor  
- 2x DC Motors + Gears  
- 8 Push Buttons  
- 16x2 LCD Display  
- Bluetooth Module (HC-05 or HC-06)  
- Power Supply (Battery or Adapter)  
- Wires, Breadboard, Resistors  

---
## 🚀 How It Works

1. **Currency Insertion**: Notes are inserted one at a time via motorized gear system.
2. **Detection**: IR sensor detects and triggers a counter per note.
3. **Denomination Selection**:
   - Use physical button or send command via Bluetooth.
4. **Display Output**:
   - LCD shows total amount, selected category, and note count.
5. **Clear Function**: Resets the full count and statistics.

---

## 📲 Bluetooth Commands (Example)

| Command | Action                         |
|---------|--------------------------------|
| `5`     | Select 5 EGP                   |
| `10`    | Select 10 EGP                  |
| `20`    | Select 20 EGP                  |
| `50   ` | Select 50 EGP                  |
| `100`   | Select 100 EGP                 |
| `200`   | Select 200 EGP                 |

Use a Bluetooth terminal app like **Serial Bluetooth Terminal** to send these commands.

---

## 📺 LCD Display Example

ex :
Total: 115 EGP
Category: 20 EGP
Count: 3 Notes

---

## 🛠️ Notes

- Button input should be debounced to prevent false triggers.
- IR sensor should be connected to an interrupt pin for accurate counting.
- UART is used for Bluetooth communication.
- LCD is dynamically updated based on system changes.

---

## 🔮 Future Enhancements

- 🕵️ Detect counterfeit currency using image sensors or UV light  
- 🎯 Improve accuracy with better filtering and calibration  
- 📱 Build a custom mobile app for Bluetooth control  
- 🧠 Use AI to auto-detect denominations without manual selection  

---

## 🎓 Graduation Project Team

| Name                      | Email                       |
|---------------------------|-----------------------------|
| **Mohamed Mokhtar** *(Mentor)* | mohamedmokhrat1@gmail.com |
| Salem Kamal *(Leader)*           | salemkamal977@gmail.com         |
| Mohamed Samir *(Co Leader)*            | Mohammedsamiragamy@gmail.com       |
| Esraa Ashraf *(Electrical member)*            | esraaashraf2213@gmail.com        |
| Saad  Radwan *(Electrical member)*           | saadradwan76@gmail.com        |
| Ahmed Abbas  *(Mechanical member)*          | ahmedalabs23@gmail.com        |
| Arwa Mohamed *(Mechanical member)*            | arwazakria2003@gmail.com         |
| Amany Ismail *(Mechanical member)*           | amanyyasser626@gmail.com        |
