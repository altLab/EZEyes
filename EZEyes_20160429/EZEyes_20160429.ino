/*
HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 13 Trig to Arduino pin 12
Motor to Arduino pin 11
*/

#include "TimerOne.h"

#define trigPin 13
#define echoPin 12
#define motPin 11

int n,m,flagdist, ndistance;
long duration,distance, xdist, wait;
unsigned long ntime;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motPin, OUTPUT);
  
  Timer1.attachInterrupt(MEASUREdistance,10);
}

void MEASUREdistance()
{
  if(millis()-ntime>60+1*distance)
  {
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = (duration/2) / 29.1;
  
  

//Serial.print(n);Serial.print(" - ");Serial.print(distance/100);Serial.print(" - ");Serial.print(distance);Serial.print(" - ");Serial.println(flagdist);
//Serial.print(xdist);Serial.print(" - ");Serial.println(distance);

if(distance>0&&distance<=400)
{
  m=2*distance/100+2; //Precisão na detecção, sensibilidade á variação da distância
 
if (distance>=xdist+m||distance<=xdist-m) //Distância actual é diferente da dist^nacia anterior mais/menos a sensibilidade
{
  ndistance=distance/100; //distância em metros
  xdist=distance;         //Guarda o valor da distância para posterior comparação
  if(distance<100)
  {flagdist=4;}   //Número de ciclos antes de parar se a distância não variar, 4 ciclos até 1m e 1 ciclo em 3m
  else
  {flagdist=1;}
}
}
else
{distance=xdist;}

ntime=millis();
  }
}

void Motor()
{
  if(flagdist>0)
  {

for (n=0;n<=ndistance;n++)
{  
Serial.print(n);Serial.print(" ");Serial.print(distance/100);Serial.print(" ");Serial.print(distance);Serial.print(" ");Serial.println(flagdist);
  
//analogWrite(motPin,255-distance/4);
analogWrite(motPin,255-distance/8);
//delay (150+distance/4);
//delay (100+distance/2);
delay (40);
//MEASUREdistance();
analogWrite(motPin,0);
//delay (150+distance/4);
//delay (100+distance/2);
delay (100);
//MEASUREdistance();
Serial.print(n);Serial.print(" + ");Serial.print(distance/100);Serial.print(" ");Serial.print(distance);Serial.print(" ");Serial.println(flagdist);

}
wait=distance*2;
delay(wait);
flagdist=flagdist-1;
}
  //Serial.print(distance);Serial.print(" ");Serial.println(flagdist);
}


void loop() {
  
  Motor();
}
