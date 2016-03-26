#include <FiniteStateMachine.h>


/*Mai usor de modificat:
 * 
 */


#define motorP 1 //P din tabelul de control al motorului
#define motorN 2 //N din tabelul de control al motorului
#define stanga 3 //1 stanga, 0 fata
#define dreapta 4 //1 dreapta, 0 fata
#define sProx 5 // senzorul de proximitate
#define RF0 6 //ultimii 2 biti de la RFID
#define RF1 7 //
#define BS 8 // baliza sonora


//States
void Start_() {digitalWrite(BS, LOW);}
void EngineForward() {digitalWrite(motorN, HIGH); digitalWrite(motorP, LOW);}
void EngineBackwards() {digitalWrite(motorN, LOW); digitalWrite(motorP, HIGH);}
void Right() {digitalWrite(stanga, LOW); digitalWrite(dreapta, HIGH);}
void Front() {digitalWrite(stanga, LOW); digitalWrite(dreapta, LOW);}
void Left() {digitalWrite(stanga, HIGH); digitalWrite(dreapta, LOW);}
void Station() {digitalWrite(motorN, LOW); digitalWrite(motorP, LOW); digitalWrite(stanga, LOW); digitalWrite(dreapta, LOW);}
void LeaveStation() {digitalWrite(BS, HIGH);}


//Initialize the states
State S0 = State(Start_);
State S1 = State(EngineForward);
State S2 = State(EngineBackwards);
//State S3 = State(IntermediateState);
State S4 = State(Right);
State S5 = State(Front);
State S6 = State(Left);
State S7 = State(Station);
State S8 = State(LeaveStation);

FSM Control = FSM(S0);

void setup() {
  // put your setup code here, to run once:
  pinMode(motorP, OUTPUT);
  pinMode(motorN, OUTPUT);
  pinMode(stanga, OUTPUT);
  pinMode(dreapta, OUTPUT);
  pinMode(BS, OUTPUT);
  pinMode(sProx, INPUT);
  pinMode(RF0, INPUT);
  pinMode(RF1, INPUT);
}

void loop() {
  //State Transitions:
    if(Control.isInState(S0)){
      Control.transitionTo(S1);
      }
      
    else if(Control.isInState(S1)){
      if(digitalRead(sProx) == HIGH) 
         Control.transitionTo(S2);
         else{
              if(digitalRead(RF0) == LOW && digitalRead(RF1) == LOW)
                 Control.transitionTo(S5);
              else if(digitalRead(RF0) == LOW && digitalRead(RF1) == HIGH)
                 Control.transitionTo(S4);
              else if(digitalRead(RF0) == HIGH && digitalRead(RF1) == LOW)
                 Control.transitionTo(S6);
              else if(digitalRead(RF0) == HIGH && digitalRead(RF1) == HIGH)
                 Control.transitionTo(S7);
                  }
    }
    
    else if(Control.isInState(S2)) 
       if(digitalRead(sProx) == LOW)
         Control.transitionTo(S1);
         
    else if(Control.isInState(S4) || Control.isInState(S5) || Control.isInState(S6))
       Control.transitionTo(S1);
       
    else if(Control.isInState(S7)){
      delay(30000); 
      Control.transitionTo(S8);
    }
    
    else if(Control.isInState(S8)){
      delay(5000); 
      Control.transitionTo(S0);
    }
    
    Control.update();
}

