# 🧠 FSM-Based Operator Skill Detection System

A behavior-driven embedded system that evaluates operator skill in real-time using Finite State Machine (FSM) logic and dynamically adapts system safety and access.

---

## 📌 Project Overview
This project implements a smart safety layer between a human operator and a machine.

It:
- Verifies correct startup procedure  
- Monitors operator behavior  
- Computes a confidence score  
- Classifies operator skill level  
- Detects panic / unsafe actions  

---

## 🔧 Hardware Required
- Arduino Uno  
- 3 Push Buttons  
- 1 Potentiometer (10kΩ)  
- LEDs (White x3, Green, Yellow, Red)  
- Resistors (220Ω)  
- Breadboard & Jumper wires  

---

## 🔌 Connections
Buttons:
BTN1 → D2 → GND  
BTN2 → D3 → GND  
BTN3 → D4 → GND  

LEDs:
W1 → D5  
W2 → D6  
W3 → D7  
RED → D8  
YELLOW → D9  
GREEN → D10  

Potentiometer:
Middle → A0  
Sides → 5V & GND  

---

## 🔄 FSM Flow
INIT → WAIT_SEQUENCE → SKILL_ACTIVE  
           ↓                ↓  
        ERROR ←─────────────

---

## 🧠 Working
1. Correct button sequence required  
2. Potentiometer used for behavior  
3. Confidence score calculated  
4. LEDs indicate skill level  
5. Panic triggers system lock  

---

## 🦾 Future Scope
- Servo safety gate  
- Motor control  
- Data logging  

---

## 📌 Author
Mehul 🚀
