# Wiring Guide (Simulation)

Use Arduino Uno and a potentiometer in Tinkercad Circuits.

| Part | Connection |
|---|---|
| Potentiometer outer pin | 5V |
| Potentiometer other outer pin | GND |
| Potentiometer middle pin (wiper) | A0 |
| Optional LED anode (+) | D8 through a 220 Ω resistor |
| Optional LED cathode (-) | GND |

If you do not add an external LED, you can still inspect the Serial Monitor. For an LED circuit, include the current-limiting resistor.

**Safety:** The potentiometer is only a simulated signal source. Do not connect a real battery directly to Arduino A0. A real battery-voltage measurement requires an appropriately designed divider/sensor and protection, with values selected for the specific battery and board.
