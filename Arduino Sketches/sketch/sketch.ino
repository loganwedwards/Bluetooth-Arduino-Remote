#include <Servo.h>
// Hardware component with bluetooth control
//---------------------------------------------------
// TODO
// 1. Send feedback on pin state back to client
// 2. Test char reading via BT
// 3. Logic to handle toggling fwd/rev on motor and
//    using off position
//---------------------------------------------------
// 4 Channel relay
// 1) + Raise motor
// 2) - Lower motor
// 3) Toggle
// 4) Toggle

int relay1 = 4;
int relay1Val = 1;
int relay2 = 5;
int relay2Val = 1;
int relay3 = 6;
int relay3Val = 1;
int relay4 = 7;
int relay4Val = 1;

// Servo
Servo servo;
int servoPos = 30;
int servoFWD = 90;
int servoREV = 30;
int servoOff = 60;

// serial read
char val;

// output feedback
int ledPin = 13;

void setup() {
  // Relay board
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  
  Serial.begin(9600);
  
  // Servo
  servo.attach(2);
  
}

void loop () {
  val = 'X';
  if (Serial.available()) {
    val = Serial.read(); 
  }
  
  if (val == 'F') {
    servo.write(servoFWD); 
    delay(100);
  }
  else if ( val == 'R') {
    servo.write(servoREV); 
    delay(100);
  }
  
  // momentary on for channel 1
  else if (val == 'A') {
    digitalWrite(relay1, LOW);
    delay(250);
    digitalWrite(relay1, HIGH);  
  }
  // toggle channel 2
  else if (val == 'B') {
    relay2Val = digitalRead(relay2);
    if (relay2Val == 1) {
      digitalWrite(relay2, LOW);
    }
    else {
      digitalWrite(relay2, HIGH);
    }
    delay(250);
  }
  // toggle channel 3
  else if (val == 'C') {
    relay3Val = digitalRead(relay3);
    if (relay3Val == 1) {
      digitalWrite(relay3, LOW);
    }
    else {
      digitalWrite(relay3, HIGH);
    }
    delay(250);
  }
  
  // toggle channel 4
  else if (val == 'D') {
    relay4Val = digitalRead(relay4);
    if (relay4Val == 1) {
      digitalWrite(relay4, LOW);
    }
    else {
      digitalWrite(relay4, HIGH);
    }
    delay(250); 
  }
  else {
     delay(100);
  }
  
}
