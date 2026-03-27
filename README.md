# Coffee Machine Assistant

A smart coffee assistant simulation using **ESP32** on **Wokwi**. Monitors coffee temperature and ingredient levels, provides LED indicators, and triggers a buzzer alert for coffee readiness or low ingredients.

---

## Features

- Monitors coffee temperature using a **DS18B20 temperature sensor**
- Tracks ingredient levels (simulated with a potentiometer)
- LED indicators:
  - **Green** → Coffee ready
  - **Red** → System error
  - **Yellow** → Ingredient low
- Buzzer alerts for:
  - Coffee ready (temperature ≥ 90°C)
  - Ingredient low (below threshold)
- Fully simulated in Wokwi — no physical hardware required

---

## Hardware / Simulation Components

| Component       | Pin/Connection |
|-----------------|----------------|
| ESP32           | Main microcontroller |
| DS18B20 Sensor  | Data → GPIO4, VCC → 3.3V, GND → GND |
| Potentiometer   | Middle pin → GPIO34, Sides → 3.3V & GND |
| Green LED       | GPIO18 |
| Red LED         | GPIO19 |
| Yellow LED      | GPIO21 |
| Buzzer          | GPIO22 |

> All connections are simulated in Wokwi.

---

## How to Run (Wokwi)

1. Open the simulation link: [Run in Wokwi]([https://wokwi.com/projects/XXXX](https://wokwi.com/projects/459507003140108289))  
2. Click **Start Simulation**.  
3. Adjust the potentiometer to simulate ingredient levels.  
4. Watch LEDs and buzzer respond automatically:
   - Green LED + buzzer → coffee ready (≥ 90°C)
   - Red LED + buzzer → ingredient low
   - Yellow LED → sensor error  

---

## How to Run Locally (Arduino IDE / ESP32)

1. Download or clone this repository.  
2. Open `sketch.ino` in **Arduino IDE**.  
3. Select **ESP32 Dev Module** under Tools → Board.  
4. Upload the sketch to your ESP32.  
5. Connect your components according to the pin table above.  
6. Monitor serial output for temperature and ingredient readings.

---

## Tech Stack

- **ESP32** microcontroller  
- **Arduino C++**  
- **DS18B20 Temperature Sensor**  
- **LEDs & Buzzer**  
- **Wokwi** simulator  

---

## Portfolio / GitHub Notes

- The repository contains:
  - `sketch.ino` → Main code  
  - `wokwi.json` → Wokwi simulation file  

- Wokwi simulation link can be used to **run the project in a browser** without hardware.

---

## License

This project is **open-source** and available for educational and portfolio purposes.
