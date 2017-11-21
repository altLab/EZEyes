 // Wiring/Arduino code:
 // Read data from the serial and turn ON or OFF a light depending on the value
 
 int val; // Data received from the serial port
 int ledPin = 9; // Set the pin to digital I/O

 
 void setup() {
 pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
 Serial.begin(9600); // Start serial communication at 9600 bps
 }
 
 void loop() {
 while (Serial.available()) { // If data is available to read,
 val = Serial.read(); // read it and store it in val
 }
 if (val == 'L' || val == 'l') { // If H was received
 digitalWrite(ledPin, LOW); // turn the LED on
 }
 if (val == 'H' || val == 'h') { // If H was received
 digitalWrite(ledPin, HIGH); // Otherwise turn it OFF
 }
 Serial.write(val);
 delay(1); // Wait 100 milliseconds for next reading
 }
