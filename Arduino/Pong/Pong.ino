#include"project.h"

//ROWS
#define R1 4
#define R2 5
#define R3 6
#define R4 7
#define R5 8
#define R6 9
#define R7 10
#define R8 11
//COLUMNS
#define C1 12
#define C2 13
#define C3 A0
#define C4 A1
#define C5 A2
#define C6 A3
#define C7 A4
#define C8 A5
//BUTTONS
#define B1 2
#define B2 3
#define B3 1
#define B4 0

//for controlling interrupts
int upButton = 0;
int downButton = 0;

Ball ball = Ball();
int time = 0;
int state1 = 0, state2=0;


void setup() {
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  pinMode(R5, OUTPUT);
  pinMode(R6, OUTPUT);
  pinMode(R7, OUTPUT);
  pinMode(R8, OUTPUT);

  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(C5, OUTPUT);
  pinMode(C6, OUTPUT);
  pinMode(C7, OUTPUT);
  pinMode(C8, OUTPUT);

  digitalWrite(R1,LOW);
  digitalWrite(R2,LOW);
  digitalWrite(R3,LOW);
  digitalWrite(R4,LOW);
  digitalWrite(R5,LOW);
  digitalWrite(R6,LOW);
  digitalWrite(R7,LOW);
  digitalWrite(R8,LOW);
  digitalWrite(C1,HIGH);
  digitalWrite(C2,HIGH);
  digitalWrite(C3,HIGH);
  digitalWrite(C4,HIGH);
  digitalWrite(C5,HIGH);
  digitalWrite(C6,HIGH);
  digitalWrite(C7,HIGH);
  digitalWrite(C8,HIGH);

  pinMode(B1, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(B1), up_right, RISING);
  attachInterrupt(digitalPinToInterrupt(B2), down_right, RISING);
  pinMode(B3, INPUT_PULLUP);
  pinMode(B4, INPUT_PULLUP);

  for(int i = 0; i < X_SIZE_OF_LED; i++){
    for(int j = 0; j < Y_SIZE_OF_LED; j++){
        array[i][j] = 0;
    }
  }
  ball.ballInit();
  left.controllerInit();
  right.controllerInit();
}

void setRow(int row){
  if(row==1) digitalWrite(R1,HIGH); else digitalWrite(R1,LOW);
  if(row==2) digitalWrite(R2,HIGH); else digitalWrite(R2,LOW);
  if(row==3) digitalWrite(R3,HIGH); else digitalWrite(R3,LOW);
  if(row==4) digitalWrite(R4,HIGH); else digitalWrite(R4,LOW);
  if(row==5) digitalWrite(R5,HIGH); else digitalWrite(R5,LOW);
  if(row==6) digitalWrite(R6,HIGH); else digitalWrite(R6,LOW);
  if(row==7) digitalWrite(R7,HIGH); else digitalWrite(R7,LOW);
  if(row==8) digitalWrite(R8,HIGH); else digitalWrite(R8,LOW);
}

void setLEDInActiveRow(int col, int state){
  if(col==1) digitalWrite(C1,1 - state);
  if(col==2) digitalWrite(C2,1 - state);
  if(col==3) digitalWrite(C3,1 - state);
  if(col==4) digitalWrite(C4,1 - state);
  if(col==5) digitalWrite(C5,1 - state);
  if(col==6) digitalWrite(C6,1 - state);
  if(col==7) digitalWrite(C7,1 - state);
  if(col==8) digitalWrite(C8,1 - state);
}

void updateLED(){
  for(int i = 0; i < Y_SIZE_OF_LED; i++){
    setRow(i + 1);
    for(int j = 0; j < X_SIZE_OF_LED; j++){ 
      setLEDInActiveRow(j + 1, array[j][i]);
    }
    delay(1);    
  }
}

//for interrupt of up button
void up_right(){
  right.go_up();
}

//for interrupt of down button
void down_right(){
  right.go_down();
}

void checkLeftController(){
  if(digitalRead(B3) == HIGH){
    if(state1 == 0){
      state1 = 1;
      left.go_up();
    }
  }
  else{
    if(state1 == 1){
      state1 = 0;
    }        
  }
  if(digitalRead(B4) == HIGH){
    if(state2 == 0){
      state2 = 1;
      left.go_down();
    }
  }
  else{
    if(state2 == 1){
      state2 = 0;
    }        
  }
}


void loop() {
  checkLeftController();
  if(time%70 == 0)
    ball.move();
  updateLED();
  time++;
}
