#include <Servo.h>
Servo the_stick;
int trap_ready = 180;
int trap_closed = 90;


#define trigPin 13
#define echoPin 12
#define servo_pin 10


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  the_stick.attach(servo_pin);
  the_stick.write(trap_ready);

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance >= 200 || distance <= 0) {
    Serial.println ("Out of Range");
  }
  if (distance <= 10 && distance >= 1) {
    Serial.println("You trapped a Leprechaun!!!");
    the_stick.write(trap_closed);

  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
