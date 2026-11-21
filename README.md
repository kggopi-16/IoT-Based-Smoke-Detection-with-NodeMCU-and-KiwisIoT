#  IoT-Based Smoke Detection with NodeMCU and KiwisIoT

I built this IoT smoke and gas detection system using a **NodeMCU (ESP8266)**, an **MQ-2 gas sensor**, and the **KiwisIoT** platform to provide both local alarms and remote browser-based monitoring.

📖 **Read the Full Step-by-Step Build Guide:** [IoT-Based Smoke Detection with NodeMCU and KiwisIoT on Hackster.io](https://www.hackster.io/kggopi666/iot-based-smoke-detection-with-nodemcu-and-kiwisiot-4bbbd8)

---

## Key Features
* **Real-Time Smoke & Gas Tracking:** Maps raw MQ-2 sensor values (`0–1023`) to a clean `0–100%` scale.
* **Local Audio & Visual Alerts:** Triggers a 2kHz piezo buzzer and red LED when smoke crosses the `450` threshold.
* **Browser-First Dashboard:** Utilizes KiwisIoT gauge and status widgets accessible via any web browser.
* **Hysteresis Stability:** Employs separate danger (`450`) and safe (`350`) thresholds to prevent rapid alarm flickering.

---

## Hardware Components & Pin Mapping

| Component | Qty | NodeMCU Pin | Notes |
| :--- | :---: | :---: | :--- |
| **NodeMCU ESP8266 (ESP-12E)** | 1 | — | Main Wi-Fi microcontroller |
| **MQ-2 Gas/Smoke Sensor** | 1 | `A0` | Power VCC from `VIN` (5V) for stable heater readings |
| **Piezo Buzzer** | 1 | `D5` | Positive to `D5`, negative to `GND` |
| **5mm Red LED + 220Ω Resistor** | 1 | `D6` | Current-limiting resistor connected to `GND` |
| **Breadboard & Jumper Wires** | 1 | — | Prototyping setup |

> **Tip:** Avoid using `D3` and `D8` for outputs to prevent NodeMCU boot mode interference.

---

##  Getting Started

### 1. Clone This Repository
```bash
git clone https://github.com/kggopi-16/IoT-Based-Smoke-Detection-with-NodeMCU-and-KiwisIoT.git
cd IoT-Based-Smoke-Detection-with-NodeMCU-and-KiwisIoT
```

### 2. Configure the KiwisIoT Dashboard
1. Sign in at **[kiwisiot.in](https://kiwisiot.in)** and create a panel to obtain your **Topic ID**.
2. Add a **Gauge Widget** on Channel 1 (`Smoke Level`, unit `%`) and a **Status / LED Widget** on Channel 2 (`Alert Status`).

### 3. Install Libraries & Upload Code
1. Install the ESP8266 board package in the Arduino IDE and add the **[KiwisIoT Arduino Library](https://github.com/Kiwistron/KiwisIoT)** via ZIP.
2. Update `SmokeDetection_KiwisIoT.ino` with your Wi-Fi credentials and KiwisIoT Topic ID, then upload to the NodeMCU at 115200 baud after allowing 30 seconds for sensor warm-up.

---

##  Helpful Links & Resources
* **Full Project Tutorial:** [Hackster.io Project Blog](https://www.hackster.io/kggopi666/iot-based-smoke-detection-with-nodemcu-and-kiwisiot-4bbbd8)
* **This GitHub Repository:** [kggopi-16/IoT-Based-Smoke-Detection-with-NodeMCU-and-KiwisIoT](https://github.com/kggopi-16/IoT-Based-Smoke-Detection-with-NodeMCU-and-KiwisIoT.git)
* **KiwisIoT Arduino SDK:** [Kiwistron/KiwisIoT](https://github.com/Kiwistron/KiwisIoT)
* **More KiwisIoT Projects:** [Kiwistron/KiwisIoT-Projects](https://github.com/Kiwistron/KiwisIoT-Projects)

---

##  Safety Note & License
* **Safety:** This is an educational prototype and not a certified life-safety smoke detector; always keep a certified alarm installed.
* **License:** Released under the **MIT License**.
