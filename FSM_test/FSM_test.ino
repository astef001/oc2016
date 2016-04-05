#include <FiniteStateMachine.h>

#define fata 13
#define stanga 12
#define dreapta 11

void fataDrept(){
  digitalWrite(fata, HIGH);
  digitalWrite(stanga, LOW);
  digitalWrite(dreapta, LOW);
}

void fataDreapta(){
  digitalWrite(fata, HIGH);
  digitalWrite(stanga, LOW);
  digitalWrite(dreapta, HIGH);
}

void fataStanga(){
  digitalWrite(fata, HIGH);
  digitalWrite(stanga, HIGH);
  digitalWrite(dreapta, LOW);
}

void stopDrept(){
  digitalWrite(fata, LOW);
  digitalWrite(stanga, LOW);
  digitalWrite(dreapta, LOW);
}

void stopStanga(){
  digitalWrite(fata, LOW);
  digitalWrite(stanga, HIGH);
  digitalWrite(dreapta, LOW);
}

void stopDreapta(){
  digitalWrite(fata, LOW);
  digitalWrite(stanga, LOW);
  digitalWrite(dreapta, HIGH);
}

State S0 = State(fataDrept);
State S1 = State(fataDreapta);
State S2 = State(fataStanga);
State S3 = State(stopDrept);
State S4 = State(stopDreapta);
State S5 = State(stopStanga);

FSM Test = FSM(S0);
void setup() {
  // put your setup code here, to run once:
  pinMode(fata, OUTPUT);
  pinMode(stanga, OUTPUT);
  pinMode(dreapta, OUTPUT);
}

void loop() {
  if (Test.isInState(S0))
    Test.transitionTo(S1);
    
  if (Test.isInState(S1))
    Test.transitionTo(S2);
    
  if (Test.isInState(S2))
    Test.transitionTo(S3);
    
  if (Test.isInState(S3))
    Test.transitionTo(S4);
    
  if (Test.isInState(S4))
    Test.transitionTo(S5);
    
  if (Test.isInState(S5))
    Test.transitionTo(S0);

delay(10000);
Test.update();
}
