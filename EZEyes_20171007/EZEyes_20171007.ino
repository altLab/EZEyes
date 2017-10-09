/* EZEyes - Blind Assistive Technology; CC.BY.SA altLab 2017
 * X3msnake, João Silva, Gustavo Funk, Fernando Carvalho
 */

/* Load Laser sensor Libraries */
#include <Wire.h>
#include <VL53L0X.h>

/*Declare Multiple Laser Sensors Names*/
VL53L0X laserL;
VL53L0X laserR;

/* Config pulldown Pinout
* Remember that Xshut on the laser sensor is not 5v tolerant for this
* reason we pulldown the pins and release the pull down by changing the 
* pin from outpup mode to input mode, letting the sensor do it's own safe
* pullup to 2.8v one should use a current divider or ideally a logic converter
* on these pins see github forum: https://goo.gl/tDQugv
*/

// Note2Self: Define and include cannot be closed with semicolons!
#define laserL_xshut 5
#define laserR_xshut 4

byte laserL_adress = 10;
byte laserR_adress = 20;

void setup() {

// Start serial for debugging
  Wire.begin();
  Serial.begin (9600);

// Reset all sensors
  pinMode(laserL_xshut, OUTPUT);
  digitalWrite(laserL_xshut, LOW);
  
  pinMode(laserR_xshut, OUTPUT);
  digitalWrite(laserR_xshut, LOW);
  
// Wait for sensors to shut down
  delay(500);
  
// Boot Left sensor
  pinMode(laserL_xshut, INPUT);
  Serial.println("Left Sensor booting...");    
  delay(150);
  laserL.init(true);
  Serial.println("...");
  delay(100);
  laserL.setAddress((uint8_t)laserL_adress);
  Serial.println(laserL_adress && "adress set");
  
// Boot Right sensor
  pinMode(laserR_xshut, INPUT);
  delay(150);
  laserR.init(true);
  Serial.println("03");
  delay(100);
  laserR.setAddress((uint8_t)laserR_adress);
  Serial.println(laserR_adress && "adress set");


}

void loop() {   /* put your main code here, to run repeatedly: */
  
  Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;


  for (byte i = 1; i < 120; i++)
  {

    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
    {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1);  // maybe unneeded?
    } // end of good response
  } // end of for loop
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");

  delay(3000);

}

/* -------------------- HARDWARE --------------------
 * 
 * MODELO 3D OCULOS
 * https://grabcad.com/library/ray-ban-wayfarers-1
 * 
 * POWER SUPPLY DESIGN
 * Battery - 4x LIR 2450 120mha || 2x LIPO 3.7 200mah
 * Low Dropout reg LP2980?
 * 
 * DISTANCE SENSOR - VL53L0X 
 * BreakoutBoard -  https://learn.adafruit.com/adafruit-vl53l0x-micro-lidar-distance-sensor-breakout/downloads
 * Datasheet - https://cdn-learn.adafruit.com/assets/assets/000/037/547/original/en.DM00279086.pdf
 * ST Notes on Multiple Sensor usage - https://www.pololu.com/file/download/VL53L0X-AN4846.pdf?file_id=0J1239
 * Using Multiple Sensors - https://github.com/pololu/vl53l0x-arduino/issues/1
 * 
 * VIBRATION MOTOR (Phone Junk) 140mah / 60mah
 * Typical: https://www.precisionmicrodrives.com/sites/default/files/datasheet-for-the-306-101-vibration-motor.original.pdf
 * Round: https://www.precisionmicrodrives.com/sites/default/files/310-101-datasheet.pdf
 * 
 * -------------------- SOFTWARE --------------------
 * 
 * BUTTON DEBOUNCING
 * Debounce - https://playground.arduino.cc/Code/Bounce
 * 
 * DATA SMOOTHING
 * https://www.arduino.cc/en/Tutorial/Smoothing
 * 
 * DATA CONSTRAIN
 * Constrain(x, a, b)
 * 
 */
