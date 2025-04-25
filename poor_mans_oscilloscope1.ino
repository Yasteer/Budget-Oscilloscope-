#include <LiquidCrystal.h>

// Create the LCD object: (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2); // Initialize a 16x2 LCD
  lcd.print("Hello");
  lcd.setCursor(0, 1); // Move to second line
  lcd.print("Oscilloscope!");
  delay(1000);
  lcd.clear();
}

void loop() {
  float VoltageMeasurementRange = 5.0;	//	Volts
  float ADCResolution = 1023;
  
  int InputMeasurement = analogRead(A2);
  
  float voltage = InputMeasurement * VoltageMeasurementRange / ADCResolution;
  
  // Clear previous LCD content.
  lcd.clear();
  
  // Display the raw ADC reading on the first line.
  lcd.setCursor(0, 0);
  lcd.print("A2: ");
  lcd.print(InputMeasurement);
  
  // Display the voltage (with 2 decimal precision) on the second line.
  lcd.setCursor(0, 1);
  lcd.print("V: ");
  lcd.print(voltage, 2);
  
  // A short delay to allow the reading to settle.
  delay(200);
}
