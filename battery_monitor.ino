/*
  Smart Battery Monitoring and Protection System - Simulation
  Board: Arduino Uno
  Input: potentiometer wiper on A0 (simulated sensor signal)
  Warning LED: D8 (optional)

  IMPORTANT:
  This is an educational simulation, not a real battery protection system.
  Do not connect a real battery directly to A0.
*/

const int VOLTAGE_SENSOR_PIN = A0;
const int WARNING_LED_PIN = 8;

const float ADC_REFERENCE_VOLTAGE = 5.0;  // Assumes a 5 V ADC reference
const int ADC_MAX_COUNT = 1023;

// Example thresholds for the simulated sensor input, not universal battery limits.
const float LOW_THRESHOLD_V = 2.0;
const float HIGH_THRESHOLD_V = 4.0;

void setup() {
  pinMode(WARNING_LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Smart Battery Monitoring - Simulation");
  Serial.println("Input is simulated using a potentiometer; not a real battery.");
}

void loop() {
  int adcCount = analogRead(VOLTAGE_SENSOR_PIN);

  // Convert 10-bit ADC count (0-1023) into an estimated 0-5 V input.
  float inputVoltage = adcCount * (ADC_REFERENCE_VOLTAGE / ADC_MAX_COUNT);

  Serial.print("ADC count: ");
  Serial.print(adcCount);
  Serial.print(" | Simulated input voltage: ");
  Serial.print(inputVoltage, 2);
  Serial.print(" V | ");

  if (inputVoltage < LOW_THRESHOLD_V) {
    Serial.println("WARNING: UNDERVOLTAGE (simulated input)");
    digitalWrite(WARNING_LED_PIN, HIGH);
  } else if (inputVoltage > HIGH_THRESHOLD_V) {
    Serial.println("WARNING: OVERVOLTAGE (simulated input)");
    digitalWrite(WARNING_LED_PIN, HIGH);
  } else {
    Serial.println("Status: NORMAL (simulated input)");
    digitalWrite(WARNING_LED_PIN, LOW);
  }

  delay(500);  // Update twice per second
}
