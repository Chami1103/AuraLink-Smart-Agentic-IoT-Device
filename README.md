# 🌟 AuraLink – Smart Agentic IoT Device

<div align="center">

**Transforming Raw Data into Intelligent, Meaningful Insights**

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![ESP32](https://img.shields.io/badge/Hardware-ESP32-blue.svg)](https://www.espressif.com/en/products/socs/esp32)
[![Python](https://img.shields.io/badge/Python-3.8+-green.svg)](https://www.python.org/)
[![OpenAI](https://img.shields.io/badge/AI-OpenAI-412991.svg)](https://openai.com/)

🎓 **IT4030 - Internet of Things** | 📅 Year 4, Semester 1/2, 2025 | 🏛️ SLIIT

[Features](#-features) • [Architecture](#️-system-architecture) • [Quick Start](#-quick-start-guide) • [Troubleshooting](#-troubleshooting)

---

<svg viewBox="0 0 800 600" xmlns="http://www.w3.org/2000/svg">
  <!-- Background -->
  <rect width="800" height="600" fill="#1a1a2e"/>
  
  <!-- Title -->
  <text x="400" y="40" font-family="Arial, sans-serif" font-size="28" font-weight="bold" fill="#00d9ff" text-anchor="middle">
    AuraLink Smart Agentic IoT Device
  </text>

  ---
  
![device](https://github.com/Chami1103/AuraLink-Smart-Agentic-IoT-Device/blob/main/Sample_preview.png)

## 📖 Table of Contents

- [Project Overview](#-project-overview)
- [Features](#-features)
- [System Architecture](#️-system-architecture)
- [Hardware Requirements](#-hardware-requirements)
- [Software Requirements](#-software-requirements)
- [Quick Start Guide](#-quick-start-guide)
- [MQTT Topics & Payloads](#-mqtt-topics--payloads)
- [Configuration](#️-configuration)
- [Troubleshooting](#-troubleshooting)
- [Future Extensions](#-future-extensions)
- [Files & Downloads](#-files--downloads)
- [License](#-license)

---

## 🎯 Project Overview

**AuraLink** is a Smart Agentic IoT Device that transforms raw environmental sensor data and email communications into intelligent, context-aware insights using an LLM backend. The system employs an ESP32 with DHT22/BME280 sensors, communicates via MQTT, and uses a Python backend (LangChain + OpenAI) to generate literature-style quotes and concise email summaries.

### Key Highlights
- 📊 Real-time environmental monitoring
- 🤖 AI-powered insight generation
- 📧 Intelligent email summarization
- 🎨 Visual urgency indicators
- 📱 Compact OLED display interface

> 📄 Full technical report available in the repository.

---

## ✨ Features

| Feature | Description |
|---------|-------------|
| 🌡️ **Environmental Monitoring** | Real-time temperature & humidity tracking |
| 📝 **Literary Quotes** | LLM-generated contextual quotes based on sensor data |
| 📧 **Email Intelligence** | Secure OAuth2-based email summarization (Gmail/Outlook) |
| 🚦 **Urgency Indicator** | RGB LED status (🟢 Green / 🟡 Yellow / 🔴 Red) |
| 📺 **OLED Display** | 128×64 display with automatic paging and text wrapping |
| 📡 **MQTT Communication** | Low-latency bidirectional messaging |

---

## 🏗️ System Architecture

```
┌─────────────┐      MQTT       ┌──────────────┐      API      ┌─────────────┐
│   ESP32     │ ◄────────────► │ MQTT Broker  │ ◄───────────► │   Backend   │
│ (Sensors)   │  Pub/Sub        │              │               │ (LangChain) │
│ DHT22/BME   │                 │              │               │  + OpenAI   │
│ OLED + LED  │                 │              │               │  + Gmail    │
└─────────────┘                 └──────────────┘               └─────────────┘
```

**Data Flow:**
1. ESP32 reads sensor data → Publishes to `auralink/sensors/data`
2. Backend receives data → Processes with LLM + Email API
3. Backend publishes response → `auralink/display/output`
4. ESP32 displays quote on OLED + Sets LED urgency color

> Detailed architecture diagrams available in the technical report.

---

## 🔌 Hardware Requirements

### Core Components

| Component | Specification | Quantity | Notes |
|-----------|--------------|----------|-------|
| **ESP32 Dev Board** | ESP32-WROOM-32 | 1 | Main microcontroller |
| **Temperature Sensor** | DHT22 or BME280 | 1 | Temp & humidity |
| **OLED Display** | 128×64 SSD1306 (I2C) | 1 | Visual output |
| **RGB LED** | Common Cathode, 5mm | 1 | Urgency indicator |
| **Resistors** | 220Ω | 3 | For RGB LED |
| **Breadboard** | Standard | 1 | Prototyping |
| **Jumper Wires** | Male-to-Male | ~20 | Connections |
| **USB Cable** | Micro-USB or USB-C | 1 | Power & programming |

**Estimated Total Cost:** ~$25–40 USD

### Pin Configuration

| Component | ESP32 Pin |
|-----------|-----------|
| DHT22 Data | GPIO 4 |
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |
| RGB LED (Red) | GPIO 25 (via 220Ω) |
| RGB LED (Green) | GPIO 26 (via 220Ω) |
| RGB LED (Blue) | GPIO 27 (via 220Ω) |

---

## 💻 Software Requirements

### ESP32 Firmware (Arduino IDE)

**Required Libraries:**
- `PubSubClient` (MQTT communication)
- `DHT sensor library` (DHT22 support)
- `Adafruit GFX` (Graphics primitives)
- `Adafruit SSD1306` (OLED display driver)
- `ArduinoJson` (JSON parsing)

**Installation:**
```
Arduino IDE → Tools → Manage Libraries → Search and install above
```

### Backend (Python 3.8+)

**Setup Virtual Environment:**
```bash
python -m venv auralink_env
source auralink_env/bin/activate  # On Windows: auralink_env\Scripts\activate
```

**Install Dependencies:**
```bash
pip install flask paho-mqtt langchain openai python-dotenv \
            google-auth google-auth-oauthlib google-api-python-client requests
```

---

## 🚀 Quick Start Guide

### Step 1: Hardware Assembly
1. Connect DHT22 data pin to GPIO 4
2. Wire OLED display (SDA→21, SCL→22)
3. Connect RGB LED through 220Ω resistors (R→25, G→26, B→27)
4. Power ESP32 via USB

### Step 2: ESP32 Firmware
1. Open `Aura_tec.ino` in Arduino IDE
2. Update Wi-Fi credentials and MQTT broker address
3. Select **Board:** ESP32 Dev Module
4. Upload firmware to ESP32

### Step 3: Backend Configuration
1. Create `.env` file with credentials:
   ```env
   OPENAI_API_KEY=sk-...
   MQTT_BROKER=broker.hivemq.com
   GMAIL_CREDENTIALS_FILE=credentials.json
   ```
2. Set up Google Cloud OAuth credentials
3. Run backend: `python auralink_backend.py`

### Step 4: Verification
1. Check serial monitor (115200 baud) for connection status
2. Verify MQTT messages using MQTT Explorer
3. Observe OLED display and LED indicators

**⏱️ Total Setup Time:** ~15 minutes

---

## 📡 MQTT Topics & Payloads

### Topic Hierarchy
```
auralink/
├── sensors/
│   └── data          # ESP32 → Backend (sensor readings)
└── display/
    └── output        # Backend → ESP32 (AI responses)
```

### Published: Sensor Data
**Topic:** `auralink/sensors/data`  
**QoS:** 1  
**Payload Example:**
```json
{
  "device_id": "AuraLink_ESP32_001",
  "temperature": 28.5,
  "humidity": 65.0,
  "timestamp": 1729845600000
}
```

### Subscribed: AI Response
**Topic:** `auralink/display/output`  
**Payload Example:**
```json
{
  "quote": "In warmth, life blooms with gentle patience",
  "summary": "3 urgent: Meeting 2pm; Project due Fri; Client feedback",
  "urgency": "red"
}
```

**Urgency Levels:**
- `green` → Low priority (0-2 urgent emails)
- `yellow` → Medium priority (3-5 urgent emails)
- `red` → High priority (6+ urgent emails)

---

## ⚙️ Configuration

### ESP32 Configuration (`Aura_tec.ino`)

```cpp
// Wi-Fi Configuration
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// MQTT Configuration
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;

// Hardware Pins
#define DHTPIN 4
#define LED_RED 25
#define LED_GREEN 26
#define LED_BLUE 27
```

### Backend Configuration (`.env`)

```env
# OpenAI Configuration
OPENAI_API_KEY=sk-...
OPENAI_MODEL=gpt-3.5-turbo

# MQTT Configuration
MQTT_BROKER=broker.hivemq.com
MQTT_TOPIC_SENSOR=auralink/sensors/data
MQTT_TOPIC_RESPONSE=auralink/display/output

# Gmail Configuration
GMAIL_CREDENTIALS_FILE=credentials.json
GMAIL_TOKEN_FILE=token.json
```

---

## 🛠 Troubleshooting

### Device Won't Connect
- ✅ Verify Wi-Fi credentials in firmware
- ✅ Check serial monitor output (115200 baud)
- ✅ Ensure router allows ESP32 connection
- ✅ Try restarting ESP32 and router

### MQTT Issues
- ✅ Use MQTT Explorer to inspect topics
- ✅ Verify broker address and port
- ✅ Check QoS settings (should be 1)
- ✅ Ensure topic names match exactly

### LLM Timeouts
- ✅ Verify OpenAI API key validity
- ✅ Check internet connection
- ✅ Consider implementing prompt caching
- ✅ Increase timeout values in backend

### Gmail OAuth Errors
- ✅ Download fresh `credentials.json` from Google Cloud
- ✅ Run OAuth flow once to generate `token.json`
- ✅ Check API scopes in Google Cloud Console
- ✅ Ensure Gmail API is enabled

---

## 🔭 Future Extensions

### Planned Features
- 🌡️ **BME280 Integration** – Add pressure sensing
- 💨 **Air Quality Monitoring** – CO₂ sensors
- 📊 **Predictive Analytics** – Trend analysis and alerts
- 🔊 **Voice Output** – Text-to-speech responses
- 📜 **E-Paper Display** – Low-power alternative
- 🤖 **Multi-Agent System** – Separate agents for sensors, emails, and urgency

### Scalability
- Cloud deployment (AWS IoT / Azure IoT Hub)
- Fleet management for multiple devices
- Historical data analytics dashboard
- Mobile app integration

---

## 📁 Files & Downloads

### Project Files
- `Aura_tec.ino` – ESP32 firmware
- `auralink_backend.py` – Python backend
- `.env.example` – Configuration template
- `requirements.txt` – Python dependencies

### Documentation
- 📊 [Architecture Diagram](auralink_architecture.png)
- 📄 [Technical Report](IoT_Final_Report.pdf)
- 📋 [Project Proposal](Project_Proposal.pdf)
- 📝 [Assignment Brief](IT4030_Assignment.pdf)

---

## 👥 Team

**AuraLink Team (Group 62)**  
IT4030 - Internet of Things  
SLIIT - Year 4, Semester 1/2, 2025

---

## 🧾 License

MIT License © 2025 AuraLink Team

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED.

---

<div align="center">

**⭐ Star this repo if you find it helpful!**

Made with ❤️ by the AuraLink Team

</div>
