// DHT11 Temperature & Humidity Sensor with C and F
// Unified Sensor Library Example
// Written by Tony DiCola for Adafruit Industries
// modifide by MRandles for Personal Use on 06/01/2020
// Released under an MIT license.
// REQUIRES the following Arduino libraries:
// - liquidcrystal I2C library:https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
//   https://learn.adafruit.com/dht/overview
// plug lcd SDA pin to jumper marked SDA on back of uno r3 board
//          SCL pin to jumper marked scl on back of uno r3 board
//          vcc pin to 5v on board
//          gnd pin to any ground on board          
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>
//plug output pin of sensor to any pin on arduino and set pin number with DHTPIN below
#define DHTPIN 5  
#define DHTTYPE    DHT11
//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to what ever your lcd address is (use I2C scanner to find out)
             //  addr,colums,lines
DHT_Unified dht(DHTPIN, DHTTYPE); 
uint32_t delayMS;
void setup(){                    
  lcd.init();    // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.begin (16,2);  
  Serial.begin(9600);
  // Initialize device.
  dht.begin();
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay /500;
}
void loop() {
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event); 
   if (isnan(event.temperature)) {
    lcd.println(F("Error reading temperature"));
  }
  else {
    lcd.print(("Temp "));
    lcd.print(event.temperature);
    lcd.print(F(" 'C"));
    lcd.setCursor(5,1);  
    lcd.print(event.temperature*1.8+32);
    lcd.print(F(" 'F"));
    lcd.setCursor(0,0);}
}
