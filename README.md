# 🌟 AuraLink – Smart Agentic IoT Device

<div align="center">

![team](https://github.com/Chami1103/AuraLink-Smart-Agentic-IoT-Device/blob/main/team.png)
![value](https://github.com/Chami1103/AuraLink-Smart-Agentic-IoT-Device/blob/main/value.png)
![device](https://github.com/Chami1103/AuraLink-Smart-Agentic-IoT-Device/blob/main/device.png)



![AuraLink Banner](https://img.shields.io/badge/AuraLink-Smart_IoT-blue?style=for-the-badge)
![Group ID](https://img.shields.io/badge/Group_ID-62-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

**Transforming Raw Data into Intelligent, Meaningful Insights**

🎓 **IT4030 - Internet of Things** | 📅 **Year 4, Semester 1/2, 2025** | 🏛️ **SLIIT**

[Features](#-features) • [Installation](#-installation-guide) • [Documentation](#-system-architecture) • [Troubleshooting](#-troubleshooting)

</div>

---

## 📖 Table of Contents

<table>
<tr>
<td width="50%">

### 🎯 Getting Started
- [Project Overview](#-project-overview)
- [Team Members](#-team-members)
- [Key Features](#-features)
- [Quick Start](#-quick-start-guide)

</td>
<td width="50%">

### 🔧 Technical Details
- [System Architecture](#-system-architecture)
- [Hardware Setup](#-hardware-requirements)
- [Software Setup](#-software-requirements)
- [Configuration](#-configuration)

</td>
</tr>
<tr>
<td width="50%">

### 📚 Usage & Support
- [Usage Instructions](#-usage-instructions)
- [MQTT Communication](#-mqtt-topics--communication)
- [Troubleshooting](#-troubleshooting)

</td>
<td width="50%">

### 🚀 Advanced
- [Data Formats](#-json-data-formats)
- [Urgency System](#-urgency-level-system)
- [Future Extensions](#-future-extensions)

</td>
</tr>
</table>

---

## 🎯 Project Overview

<table>
<tr>
<td width="60%">

### What is AuraLink?

**AuraLink** is a revolutionary Smart Agentic IoT Device that bridges the gap between raw sensor data and meaningful insights. Unlike traditional IoT devices that merely display numbers, AuraLink uses **Large Language Models (LLM)** to transform environmental readings into:

✨ **Literature-inspired quotes** that provide emotional context  
📧 **Intelligent email summaries** that combat information overload  
🚦 **Visual urgency indicators** for immediate situational awareness

### The Problem We Solve

**Traditional IoT:** "Temperature: 30°C" ❌  
**AuraLink:** "In warmth, life blooms with gentle patience" ✅

</td>
<td width="40%">

```
┌─────────────────────┐
│   🌡️ Sensors        │
│   Temperature       │
│   Humidity          │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│   🤖 AI Brain       │
│   LangChain +       │
│   OpenAI API        │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│   📱 Smart Display  │
│   Quotes + Emails   │
│   LED Urgency       │
└─────────────────────┘
```

</td>
</tr>
</table>

### 🎪 Dual Output Innovation

<table>
<tr>
<th width="50%">🎨 Creative Contextualization</th>
<th width="50%">📊 Information Reduction</th>
</tr>
<tr>
<td>

```
Input:  Temp: 28°C, Humidity: 65%

Output: "In warmth, life blooms 
         with gentle patience"
```

**Transforms** cold data into engaging, context-aware literature

</td>
<td>

```
Input:  15 unread emails (2,453 words)

Output: "3 urgent: Meeting 2pm,
         Project due Friday,
         Client feedback needed"
```

**Reduces** information overload to actionable insights (2-3 sentences)

</td>
</tr>
</table>

---

## 👥 Team Members

<table>
<tr>
<th>Name</th>
<th>Student ID</th>
<th>Role</th>
<th>Responsibilities</th>
</tr>
<tr>
<td>🔧 Fernando M.G.S.S.A</td>
<td>IT19970882</td>
<td>Hardware Lead</td>
<td>ESP32 Firmware, Sensor Integration, Circuit Design</td>
</tr>
<tr>
<td>🤖 Perera B.C.V</td>
<td>IT20196110</td>
<td>AI/Backend Lead</td>
<td>LLM Integration, Email API, Backend Development</td>
</tr>

</table>

---

## 🏗️ System Architecture

### Three-Layer Architecture

```
╔═══════════════════════════════════════════════════════════════════════════════════╗
║                            AURALINK SYSTEM ARCHITECTURE                           ║
╚═══════════════════════════════════════════════════════════════════════════════════╝

┌─────────────────────────┐         ┌──────────────────────┐         ┌──────────────────────────┐
│                         │         │                      │         │                          │
│   📟 IoT DEVICE LAYER   │◄───────►│  📡 COMMUNICATION    │◄───────►│   🧠 BACKEND AI LAYER    │
│                         │         │      LAYER           │         │                          │
│  ┌──────────────────┐   │         │                      │         │  ┌────────────────────┐  │
│  │   ESP32-WROOM    │   │         │   MQTT BROKER        │         │  │   Python Server    │  │
│  │   Wi-Fi Enabled  │   │         │   (Pub/Sub Model)    │         │  │   Flask/FastAPI    │  │
│  └──────────────────┘   │         │                      │         │  └────────────────────┘  │
│                         │         │  📤 Publish Topics:  │         │                          │
│  ┌──────────────────┐   │         │  ├─ sensor/data      │         │  ┌────────────────────┐  │
│  │   DHT22 Sensor   │───┼────┐    │  │                   │         │  │   LangChain Core   │  │
│  │   Temp & Humid   │   │    │    │  📥 Subscribe Topics:│         │  │   + OpenAI API     │  │
│  └──────────────────┘   │    │    │  └─ ai/response      │         │  └────────────────────┘  │
│                         │    │    │                      │         │                          │
│  ┌──────────────────┐   │    │    │  🔐 Protocol:        │         │  ┌────────────────────┐  │
│  │  OLED Display    │◄──┼────┘    │     MQTT v3.1.1      │         │  │  Email API Client  │  │
│  │  128x64 I2C      │   │         │     Port: 1883       │         │  │  Gmail/Outlook     │  │
│  └──────────────────┘   │         │                      │         │  └────────────────────┘  │
│                         │         │  ⚡ Features:        │         │                          │
│  ┌──────────────────┐   │         │  • Lightweight       │         │  ┌────────────────────┐  │
│  │   RGB LED        │◄──┤         │  • Bidirectional     │         │  │   Data Logger      │  │
│  │   Urgency Cue    │   │         │  • QoS Support       │         │  │   + Timestamps     │  │
│  └──────────────────┘   │         │  • Low Latency       │         │  └────────────────────┘  │
│                         │         │                      │         │                          │
└─────────────────────────┘         └──────────────────────┘         └──────────────────────────┘
```

### 🔄 Data Flow Visualization

```
STEP 1: SENSE                STEP 2: PUBLISH              STEP 3: PROCESS
┌──────────┐                ┌──────────┐                ┌──────────┐
│ 🌡️ 28°C  │───────────────►│   MQTT   │───────────────►│    AI    │
│ 💧 65%   │    JSON Data   │  Broker  │  Sensor Data   │  Backend │
└──────────┘                └──────────┘                └──────────┘
  ESP32                                                       │
                                                              │ LLM Processing
                                                              ▼
STEP 6: DISPLAY             STEP 5: RECEIVE              STEP 4: GENERATE
┌──────────┐                ┌──────────┐                ┌──────────┐
│  📱💡    │◄───────────────│   MQTT   │◄───────────────│ ✨📧🎨   │
│ Quote +  │   AI Response  │  Broker  │  AI Outputs    │ Quote +  │
│  Email   │                └──────────┘                │  Summary │
└──────────┘                                            └──────────┘
  OLED + LED                                              LangChain
```

### 📊 Component Interaction Map

```
                                    ┌─────────────────────────┐
                                    │   🌐 User's Gmail       │
                                    │   Inbox (Cloud)         │
                                    └───────────┬─────────────┘
                                                │ Gmail API
                                                ▼
┌───────────────┐    ┌──────────┐    ┌─────────────────────┐    ┌──────────────┐
│   DHT22       │───►│          │───►│                     │───►│              │
│   Sensor      │    │          │    │   Python Backend    │    │   OpenAI     │
└───────────────┘    │          │    │                     │    │   GPT API    │
                     │  ESP32   │    │  • Data Logger      │    │              │
┌───────────────┐    │          │    │  • LangChain        │    └──────────────┘
│   OLED        │◄───│          │◄───│  • Email Fetcher    │
│   Display     │    │          │    │  • Quote Generator  │
└───────────────┘    │          │    └─────────────────────┘
                     │          │              ▲
┌───────────────┐    │          │              │
│   RGB LED     │◄───│          │              │
│   (Urgency)   │    └──────────┘              │
└───────────────┘         │                    │
                          │                    │
                          └────────────────────┘
                              MQTT Protocol
                           (Bidirectional Pub/Sub)
```

---

## ✨ Features

<table>
<tr>
<td width="33%">

### 🔧 Hardware Features

```
✅ Real-time Monitoring
   └─ Temperature (±1°C)
   └─ Humidity (±5%)

✅ Visual Output
   └─ 128x64 OLED Display
   └─ Text word-wrapping
   └─ Auto page switching

✅ Urgency System
   └─ RGB LED Indicator
   └─ 3-level alerting
   └─ Color-coded feedback

✅ Low Power Design
   └─ ESP32 deep sleep
   └─ Efficient sensors
   └─ Smart scheduling
```

</td>
<td width="33%">

### 💻 Software Features

```
✅ Communication
   └─ MQTT Pub/Sub
   └─ JSON serialization
   └─ Auto-reconnection
   └─ QoS level 1

✅ Data Management
   └─ Timestamped logs
   └─ Structured storage
   └─ Error handling
   └─ Buffer management

✅ Display Logic
   └─ Dynamic updates
   └─ Text formatting
   └─ Multi-page views
   └─ Smooth transitions
```

</td>
<td width="33%">

### 🤖 AI Features

```
✅ Quote Generation
   └─ Context-aware
   └─ Literature-style
   └─ Environment-based
   └─ Creative output

✅ Email Intelligence
   └─ Inbox scanning
   └─ Smart summarization
   └─ Urgency detection
   └─ 2-3 sentence output

✅ Learning System
   └─ Pattern recognition
   └─ User preferences
   └─ Adaptive responses
   └─ Continuous improvement
```

</td>
</tr>
</table>

---

## 🔌 Hardware Requirements

### 📦 Components Checklist

<table>
<tr>
<th>Component</th>
<th>Specification</th>
<th>Qty</th>
<th>Price (Est.)</th>
<th>Purpose</th>
</tr>
<tr>
<td>🔷 ESP32 Dev Board</td>
<td>ESP32-WROOM-32</td>
<td>1</td>
<td>$6-10</td>
<td>Main microcontroller with Wi-Fi</td>
</tr>
<tr>
<td>🌡️ DHT22 Sensor</td>
<td>AM2302 (DHT22)</td>
<td>1</td>
<td>$4-8</td>
<td>Temperature & Humidity sensing</td>
</tr>
<tr>
<td>📱 OLED Display</td>
<td>128x64, I2C, SSD1306</td>
<td>1</td>
<td>$3-6</td>
<td>Text output display</td>
</tr>
<tr>
<td>🚦 RGB LED</td>
<td>Common Cathode, 5mm</td>
<td>1</td>
<td>$0.50</td>
<td>Visual urgency indicator</td>
</tr>
<tr>
<td>⚡ Resistors</td>
<td>220Ω, 1/4W</td>
<td>3</td>
<td>$0.30</td>
<td>LED current limiting</td>
</tr>
<tr>
<td>🔌 Breadboard</td>
<td>830 tie-points</td>
<td>1</td>
<td>$2-4</td>
<td>Circuit prototyping</td>
</tr>
<tr>
<td>🔗 Jumper Wires</td>
<td>Male-to-Male, 20cm</td>
<td>15+</td>
<td>$2-3</td>
<td>Component connections</td>
</tr>
<tr>
<td>🔋 USB Cable</td>
<td>Micro-USB or USB-C</td>
<td>1</td>
<td>$2-5</td>
<td>Power & Programming</td>
</tr>
<tr>
<td colspan="3"><strong>TOTAL COST</strong></td>
<td colspan="2"><strong>~$25-40 USD</strong></td>
</tr>
</table>

### 🔌 Pin Connection Diagram

```
╔══════════════════════════════════════════════════════════════════════════════╗
║                         ESP32 PIN CONNECTIONS                                ║
╚══════════════════════════════════════════════════════════════════════════════╝

                        ┌─────────────────────┐
                        │                     │
                        │      ESP32-32S      │
                        │   Development Kit   │
                        │                     │
         ┌──────────────┤ 3V3            GND  ├──────────────┐
         │              │                     │              │
         │              │ GPIO 21 (SDA)  GND  ├──────────────┤
         │              │ GPIO 22 (SCL)       │              │
         │              │                     │              │
         │              │ GPIO 4    (DHT)     │              │
         │              │                     │              │
         │              │ GPIO 25   (LED_R)   │              │
         │              │ GPIO 26   (LED_G)   │              │
         │              │ GPIO 27   (LED_B)   │              │
         │              └─────────────────────┘              │
         │                                                   │
         │                                                   │
    ┌────▼────┐     ┌──────────┐     ┌──────────┐     ┌────▼────┐
    │ DHT22   │     │   OLED   │     │ RGB LED  │     │   GND   │
    │ Sensor  │     │ Display  │     │          │     │  Common │
    └─────────┘     └──────────┘     └──────────┘     └─────────┘


DHT22 SENSOR PINOUT:          OLED DISPLAY PINOUT:       RGB LED PINOUT:
┌───────────────┐             ┌───────────────┐          ┌───────────────┐
│ 1: VCC → 3.3V │             │ VCC → 3.3V    │          │ R → GPIO 25   │
│ 2: DATA→ GP4  │             │ GND → GND     │          │   (via 220Ω)  │
│ 3: NC         │             │ SCL → GPIO 22 │          │ G → GPIO 26   │
│ 4: GND → GND  │             │ SDA → GPIO 21 │          │   (via 220Ω)  │
└───────────────┘             └───────────────┘          │ B → GPIO 27   │
                                                         │   (via 220Ω)  │
                                                         │ - → GND       │
                                                         └───────────────┘
```

### 🎨 Circuit Schematic

```
                    3.3V                     GND
                     │                        │
                     ├────────────────────────┤
                     │                        │
                ┌────┴────┐              ┌───┴───┐
                │ DHT22   │              │ OLED  │
                │ Sensor  │              │ I2C   │
                └────┬────┘              └───┬───┘
                     │                       │
                  GPIO 4                  GPIO 21,22
                     │                       │
        ┌────────────┴───────────────────────┴────────────┐
        │                                                  │
        │                  ESP32-WROOM-32                  │
        │                                                  │
        │  GPIO 25 ──┬─── [220Ω] ──┬─── RED              │
        │  GPIO 26 ──┼─── [220Ω] ──┼─── GREEN    RGB     │
        │  GPIO 27 ──┼─── [220Ω] ──┼─── BLUE     LED     │
        │            │              └──────────────┐      │
        │            │                             │      │
        │           GND ───────────────────────────┴──────┤
        │                                                  │
        └──────────────────────────────────────────────────┘
```

---

## 💻 Software Requirements

### 🛠️ Development Environment Setup

<table>
<tr>
<td width="50%">

### For ESP32 Firmware

**Arduino IDE Configuration:**
```
Arduino IDE Version: 1.8.19+ or 2.x
Board: ESP32 Dev Module
Upload Speed: 921600
Flash Frequency: 80MHz
Flash Mode: QIO
Flash Size: 4MB (32Mb)
Partition Scheme: Default 4MB
```

**Required Libraries:**
| Library | Version | Purpose |
|---------|---------|---------|
| 📶 WiFi | Built-in | Network connectivity |
| 📡 PubSubClient | 2.8.0+ | MQTT communication |
| 🌡️ DHT sensor library | 1.4.4+ | DHT22 reading |
| 📊 Adafruit GFX | 1.11.5+ | Graphics primitives |
| 📱 Adafruit SSD1306 | 2.5.7+ | OLED display driver |
| 📝 ArduinoJson | 6.21.3+ | JSON parsing |

</td>
<td width="50%">

### For Backend Server

**Python Environment:**
```bash
Python Version: 3.8 - 3.11
Package Manager: pip
Virtual Environment: Recommended
Operating System: Linux/Windows/macOS
```

**Required Packages:**
```bash
# Core Framework
flask>=2.3.0
flask-cors>=4.0.0

# MQTT Communication
paho-mqtt>=1.6.1

# AI/LLM Integration
langchain>=0.0.200
openai>=0.27.0

# Email Integration
google-auth>=2.20.0
google-auth-oauthlib>=1.0.0
google-api-python-client>=2.88.0

# Utilities
python-dotenv>=1.0.0
requests>=2.31.0
```

</td>
</tr>
</table>

### 📥 Quick Installation Commands

```bash
# ═══════════════════════════════════════════════════════════
# ESP32 LIBRARY INSTALLATION (Arduino IDE)
# ═══════════════════════════════════════════════════════════
# 1. Go to: Sketch → Include Library → Manage Libraries
# 2. Search and install each library listed above

# ═══════════════════════════════════════════════════════════
# BACKEND INSTALLATION (Terminal/Command Prompt)
# ═══════════════════════════════════════════════════════════

# Create virtual environment
python -m venv auralink_env

# Activate virtual environment
# Windows:
auralink_env\Scripts\activate
# Linux/Mac:
source auralink_env/bin/activate

# Install all dependencies
pip install flask paho-mqtt langchain openai python-dotenv
pip install google-auth google-auth-oauthlib google-api-python-client

# Verify installation
python --version
pip list
```

---

## 🚀 Quick Start Guide

### ⚡ 5-Minute Setup

```
╔═══════════════════════════════════════════════════════════════════════════╗
║  STEP 1: HARDWARE ASSEMBLY (5 minutes)                                   ║
╚═══════════════════════════════════════════════════════════════════════════╝

1. Connect components to ESP32 following pin diagram
2. Double-check all connections
3. Connect USB cable to computer

╔═══════════════════════════════════════════════════════════════════════════╗
║  STEP 2: SOFTWARE UPLOAD (3 minutes)                                     ║
╚═══════════════════════════════════════════════════════════════════════════╝

1. Open Aura_tec.ino in Arduino IDE
2. Update WiFi credentials (lines 33-34)
3. Select Board: "ESP32 Dev Module"
4. Select Port: [Your COM port]
5. Click Upload ⬆️

╔═══════════════════════════════════════════════════════════════════════════╗
║  STEP 3: BACKEND SETUP (5 minutes)                                       ║
╚═══════════════════════════════════════════════════════════════════════════╝

1. Create .env file with API keys
2. Run: python auralink_backend.py
3. Wait for "Backend Ready" message

╔═══════════════════════════════════════════════════════════════════════════╗
║  STEP 4: VERIFICATION (2 minutes)                                        ║
╚═══════════════════════════════════════════════════════════════════════════╝

1. Open Serial Monitor (115200 baud)
2. Check for "AuraLink Ready!" message
3. Verify sensor readings appear
4. Watch OLED display for quotes/emails
5. Confirm LED shows green (normal status)

✅ TOTAL SETUP TIME: ~15 minutes
```

---

## ⚙️ Configuration

### 📝 ESP32 Configuration (Aura_tec.ino)

```cpp
// ═══════════════════════════════════════════════════════════════
// NETWORK CONFIGURATION
// ═══════════════════════════════════════════════════════════════
const char* ssid = "YOUR_WIFI_SSID";           // 🔴 CHANGE THIS
const char* password = "YOUR_WIFI_PASSWORD";   // 🔴 CHANGE THIS

// ═══════════════════════════════════════════════════════════════
// MQTT BROKER CONFIGURATION
// ═══════════════════════════════════════════════════════════════
const char* mqtt_server = "broker.hivemq.com"; // Public broker
const int mqtt_port = 1883;
const char* mqtt_client_id = "AuraLink_ESP32_001";

// ═══════════════════════════════════════════════════════════════
// MQTT TOPICS
// ═══════════════════════════════════════════════════════════════
const char* topic_sensor_data = "auralink/sensor/data";
const char* topic_ai_response = "auralink/ai/response";

// ═══════════════════════════════════════════════════════════════
// TIMING CONFIGURATION (milliseconds)
// ═══════════════════════════════════════════════════════════════
const unsigned long SENSOR_READ_INTERVAL = 10000;  // Read every 10s
const unsigned long DISPLAY_UPDATE_INTERVAL = 5000; // Update every 5s

// ═══════════════════════════════════════════════════════════════
// HARDWARE PIN CONFIGURATION
// ═══════════════════════════════════════════════════════════════
#define DHTPIN 4           // DHT22 data pin
#define LED_RED 25         // RGB LED - Red
#define LED_GREEN 26       // RGB LED - Green
#define LED_BLUE 27        // RGB LED - Blue
```

### 🔐 Backend Configuration (.env file)

```bash
# ═══════════════════════════════════════════════════════════════
# OPENAI API CONFIGURATION
# ═══════════════════════════════════════════════════════════════
OPENAI_API_KEY=sk-proj-xxxxxxxxxxxxxxxxxxxxxxxxxx  # 🔴 REQUIRED
OPENAI_MODEL=gpt-3.5-turbo
OPENAI_TEMPERATURE=0.7
OPENAI_MAX_TOKENS=150

# ═══════════════════════════════════════════════════════════════
# MQTT BROKER CONFIGURATION
# ═══════════════════════════════════════════════════════════════
MQTT_BROKER=broker.hivemq.com
MQTT_PORT=1883
MQTT_TOPIC_SENSOR=auralink/sensor/data
MQTT_TOPIC_RESPONSE=auralink/ai/response
MQTT_QOS=1
MQTT_KEEPALIVE=60

# ═══════════════════════════════════════════════════════════════
# EMAIL API CONFIGURATION (Gmail)
# ═══════════════════════════════════════════════════════════════
GMAIL_CREDENTIALS_FILE=credentials.json  # 🔴 Download from Google Cloud
GMAIL_TOKEN_FILE=token.json
GMAIL_SCOPES=https://www.googleapis.com/auth/gmail.readonly

# ═══════════════════════════════════════════════════════════════
# SYSTEM CONFIGURATION
# ═══════════════════════════════════════════════════════════════
LOG_LEVEL=INFO
LOG_FILE=auralink.log
DEBUG_MODE=False

# ═══════════════════════════════════════════════════════════════
# URGENCY THRESHOLDS
# ═══════════════════════════════════════════════════════════════
TEMP_NORMAL_MIN=18
TEMP_NORMAL_MAX=26
TEMP_ADVISORY_MIN=15
TEMP_ADVISORY_MAX=30
HUMIDITY_NORMAL_MIN=40
HUMIDITY_NORMAL_MAX=60
```

---

## 📡 MQTT Topics & Communication

### 📊 Topic Structure

```
┌────────────────────────────────────────────────────────────┐
│                    MQTT TOPIC HIERARCHY                    │
└────────────────────────────────────────────────────────────┘

auralink/
├── sensor/
│   └── data          📤 ESP32 → Backend (Sensor readings)
│
└── ai/
    └── response      📥 Backend → ESP32 (AI outputs)
```

### 📤 Published Topic: Sensor Data

<table>
<tr>
<td width="30%"><strong>Topic Name</strong></td>
<td width="70%"><code>auralink/sensor/data</code></td>
</tr>
<tr>
<td><strong>Direction</strong></td>
<td>ESP32 ➡️ Backend</td>
</tr>
<tr>
<td><strong>Publish Rate</strong></td>
<td>Every 10 seconds</td>
</tr>
<tr>
<td><strong>QoS Level</strong></td>
<td>1 (At least once)</td>
</tr>
<tr>
<td><strong>Retained</strong></td>
<td>No</td>
</tr>
</table>

**Payload Format:**
```json
{
  "device_id": "AuraLink_ESP32_001",
  "temperature": 28.5,
  "humidity": 65.0,
  "timestamp": 1729845600000
}
```

### 📥 Subscribed Topic: AI Response

<table>
<tr>
<td width="30%"><strong>Topic Name</strong></td>
<td width="70%"><code>auralink/ai/response</code></td>
</tr>
<tr>
<td><strong>Direction</strong></td>
<td>Backend ➡️ ESP32</td>
</tr>
<tr>
<td><strong>Trigger</strong></td>
<t
