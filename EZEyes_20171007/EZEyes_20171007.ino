/* EZEyes - Blind Assistive Technology; CC.BY.SA altLab 2017
 * X3msnake, João Silva, Gustavo Funk, Fernando Carvalho
 */

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

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
 * 
 * VIBRATION MOTOR (Phone Junk)
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
