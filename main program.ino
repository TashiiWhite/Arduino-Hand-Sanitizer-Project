#include <Servo.h>
Servo myservo;// create servo object to control servo

int trigPin = 9;//ultrasonic trig on pin 9
int echoPin = 8;//ultrasonic echo on pin 8
long distance;
long duration;
 
void setup() 
{
myservo.attach(7);//attach servo on pin 7 to the servo object
 pinMode(trigPin, OUTPUT);//sets echopin as an output
 pinMode(echoPin, INPUT);//sets echopin as an input
 Serial.begin(9600); //start serial communication
}
 
void loop() {
  ultra();
  myservo.write(0);//set servo to an initial 0 degrees
  if(distance <= 10){
  myservo.write(180);// set servo to 180 degrees
  }
}
 
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin, HIGH);//set trigpin on high for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);//set trigpin on low
  duration = pulseIn(echoPin, HIGH); //echo pin is read and returns to sound wave travel time in micro seconds
  distance = duration*0.034/2;
  }
