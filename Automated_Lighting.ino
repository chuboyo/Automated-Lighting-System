#include <LowPower.h>
#include <EEPROM.h>

/* 
 *  Automated Lighting Control System
 *  By Akoji Timothy and Akoji Chubi
 *  16th May, 2022
 
 *  This system automatically turns ON a lighting source based on the current amount of daylight brightness
 *  
 *  Inputs: Light Dependent Resistor (Analog) connected to A0
 *  Outputs: Indicator LED (Pin 7), Relay Module (pin 8)
*/
// Variable Definitions
int LDR_sensor = A1;
int relay_pin = 10;
int LED_pin = 6;
int address = 0;
// Define the rest here 

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(LDR_sensor, INPUT); // set A0 as input
  pinMode(relay_pin, OUTPUT);
  pinMode(LED_pin, OUTPUT);
  digitalWrite(relay_pin, LOW);
  digitalWrite(LED_pin, HIGH); 
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
      int LDR_reading = analogRead(LDR_sensor);
      // place the rest of the code here:
      if (LDR_reading < 40 ){
          digitalWrite(relay_pin, HIGH);
        }
      else {
        digitalWrite(relay_pin, LOW);
        }
      
      // print out the state of the button:
      //Serial.println(LDR_reading);
      //Serial.println("*****************");
      if (address < EEPROM.length()){
        EEPROM.write(address, LDR_reading/4);
        address += 1; 
        }
             // Get reading every 10 seconds
  for (int i = 0; i < 30; i++){
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  }

} 
