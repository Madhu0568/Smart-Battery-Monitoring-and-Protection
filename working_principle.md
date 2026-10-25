# Working Principle

## 1. Input
A potentiometer connected between 5 V and GND provides an adjustable signal to analog pin A0. This is only a simulated sensor input.

## 2. Analog-to-digital conversion
Arduino Uno's `analogRead(A0)` returns an integer from 0 to 1023, representing the input across the ADC reference range. With an assumed 5.0 V reference:

`inputVoltage = adcCount × 5.0 / 1023`

Example: if `adcCount = 512`, the estimate is approximately 2.50 V.

## 3. Threshold logic
- If the estimate is below 2.0 V, print an undervoltage warning.
- If it is above 4.0 V, print an overvoltage warning.
- Otherwise, print normal status.

These thresholds are illustrative for the simulated input and must not be treated as real battery specifications.

## 4. Output
The Serial Monitor prints the ADC count, estimated input voltage, and state. An LED on D8 turns on for either warning and turns off for normal status.

## 5. Update interval
`delay(500)` pauses for 500 milliseconds between readings, so the loop updates roughly twice per second.

## Block diagram
Potentiometer (simulated sensor) -> Arduino A0 / ADC -> Voltage estimate -> Threshold comparison -> Serial warning + LED

## What this demo does not do
It does not measure a real battery safely, disconnect a battery, measure current or temperature, balance cells, or provide certified protection. A real implementation requires a properly designed sensing front end and protection hardware.
