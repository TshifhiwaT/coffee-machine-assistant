// ESP32 + DS18B20 + Potentiometer + LEDs + Buzzer

#include <OneWire.h>
#include <DallasTemperature.h>

// Pin Definitions
#define ONE_WIRE_BUS 4       // DS18B20 data pin
#define POT_PIN 34           // Ingredient level simulation

#define LED_READY 18         // Green: Coffee ready
#define LED_LOW 19           // Red: Ingredient low
#define LED_ERROR 21         // Yellow: Sensor error
#define BUZZER 22            // Buzzer

// Objects
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Thresholds
const float TEMP_READY = 90.0;     // Coffee ready temperature
const int INGREDIENT_LOW = 1000;   // Ingredient threshold (ADC value)

// Setup
void setup() {
  Serial.begin(115200);
  sensors.begin();

  pinMode(LED_READY, OUTPUT);
  pinMode(LED_LOW, OUTPUT);
  pinMode(LED_ERROR, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.println("Smart Café Assistant Starting...");
}

// Read Temperature
float readTemperature() {
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);

  if (temp == DEVICE_DISCONNECTED_C) {
    Serial.println("DS18B20 sensor disconnected!");
    digitalWrite(LED_ERROR, HIGH);
    return -1;
  }

  digitalWrite(LED_ERROR, LOW);
  return temp;
}

// Read Ingredient Level
int readIngredientLevel() {
  return analogRead(POT_PIN); // 0–4095
}

// Buzzer Beep Function
void beepBuzzer() {
  tone(BUZZER, 1000);  // Start beep
  delay(200);          // Beep duration
  noTone(BUZZER);      // Stop beep
}

// Update System State
void updateSystem(float temp, int ingredientLevel) {
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C | Ingredient: ");
  Serial.println(ingredientLevel);

  bool alert = false;

  // Check ingredient low
  if (ingredientLevel < INGREDIENT_LOW) {
    digitalWrite(LED_LOW, HIGH);
    Serial.println("Ingredient LOW! Refill needed.");
    alert = true;
  } else {
    digitalWrite(LED_LOW, LOW);
  }

  // Check coffee ready
  if (temp >= TEMP_READY) {
    digitalWrite(LED_READY, HIGH);
    Serial.println("Coffee READY!");
    alert = true; // Trigger buzzer
  } else {
    digitalWrite(LED_READY, LOW);
  }

  // Buzzer only if any alert
  if (alert) {
    beepBuzzer();
  } else {
    noTone(BUZZER);
  }
}

// Main Loop
void loop() {
  float temperature = readTemperature();
  int ingredientLevel = readIngredientLevel();

  if (temperature != -1) {
    updateSystem(temperature, ingredientLevel);
  }

  Serial.println("----------------------");
  delay(2000); // Update every 2 sec
}