#define threshold 500

int leftIRPin = A0; //select pin for left IR sensor
int rightIRPin = A1; //select pin for right IR sensor
int IRleft = 0; //initialise variable to store left IR sensor value
int IRright = 0; //initialise variable to store right IR sensor value
int lmotorA = 2; //select pin for left motor A pin
int lmotorB = 3; //select pin for left motor B pin
int rmotorA = 4; //select pin for right motor A pin
int rmotorB = 5; //select pin for right motor B pin

void stopmotors(){
  digitalWrite(lmotorA, LOW);
  digitalWrite(lmotorB, LOW);
  digitalWrite(rmotorA, LOW);
  digitalWrite(rmotorB, LOW);
}

void frwd(){
  digitalWrite(lmotorA, HIGH);  
  digitalWrite(lmotorB, LOW);
  digitalWrite(rmotorA, HIGH);
  digitalWrite(rmotorB, LOW);
}

void left(){
  digitalWrite(lmotorA, LOW);
  digitalWrite(lmotorB, HIGH);
  digitalWrite(rmotorA, HIGH);
  digitalWrite(rmotorB, LOW);
}

void right(){
  digitalWrite(lmotorA, HIGH);
  digitalWrite(lmotorB, LOW);
  digitalWrite(rmotorA, LOW);
  digitalWrite(rmotorB, HIGH);
}

void reverse(){
  digitalWrite(lmotorA, LOW);
  digitalWrite(lmotorB, HIGH);
  digitalWrite(rmotorA, LOW);
  digitalWrite(rmotorB, HIGH);
}

void setup(){
  pinMode(lmotorA, OUTPUT);
  pinMode(lmotorB, OUTPUT);
  pinMode(rmotorA, OUTPUT);
  pinMode(rmotorB, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  frwd();
  pinMode(13, OUTPUT);
}

void loop(){
  analogWrite(9, 100);
  analogWrite(6, 100);
  IRleft = analogRead(leftIRPin);
  IRright = analogRead(rightIRPin);
  if( IRright > threshold && IRleft < threshold){
    digitalWrite(13, HIGH);
    left();
  }  
  else {
    if( IRleft > threshold && IRright < threshold){
      digitalWrite(13, HIGH);
      right();
    }
    else {
      if( IRleft > threshold && IRright > threshold){
        digitalWrite(13, HIGH);
        stopmotors();
      }
      else{
        digitalWrite(13, LOW);
        frwd();
      }
    }
  }
}

