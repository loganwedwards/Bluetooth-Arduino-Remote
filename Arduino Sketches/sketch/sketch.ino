// Hardware component with bluetooth control
//---------------------------------------------------
// TODO
// 1. Send feedback on pin state back to client
// 2. Test char reading
//---------------------------------------------------
// 4 Channel relay
// 1) + Raise motor
// 2) - Lower motor
// 3) Toggle
// 4) Toggle

int relay1 = 4;
int relay1Val = 0;
int relay2 = 5;
int relay2Val = 0;
int relay3 = 6;
int relay3Val = 0;
int relay4 = 7;
int relay4Val = 0;

// bluetooth read
char val;

// output feedback
int ledPin = 13;

void setup() {
  
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop () {
  
  if (Serial.available()) {
    val = Serial.read(); 
  }
  
  // raise motor
  if (val == 'U') {
    digitalWrite(relay1, HIGH);  
  }
  // lower motor
  else if (val == 'D') {
    digialWrite(relay2, HIGH); 
  }
  // turn channel 3 on
  else if (val == 'A') {
    relay3Val = digitalRead(relay3);
    if (relay3Val == 1) {
      digitalWrite(relay3, LOW);
    }
    else {
      digitalWrite(relay3, HIGH);
    }
    delay(250);
  }
  
  // turn channel 4 on
  else if (val == 'B') {
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
     delay(1000);
  }
  
}
