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

//for controlling interrupts
int upButton = 0;
int downButton = 0;

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

  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);
  digitalWrite(R5,HIGH);
  digitalWrite(R6,HIGH);
  digitalWrite(R7,HIGH);
  digitalWrite(R8,HIGH);
  digitalWrite(C1,LOW);
  digitalWrite(C2,LOW);
  digitalWrite(C3,LOW);
  digitalWrite(C4,LOW);
  digitalWrite(C5,LOW);
  digitalWrite(C6,LOW);
  digitalWrite(C7,LOW);
  digitalWrite(C8,LOW);

  pinMode(B1, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(B1), up, FALLING);
  attachInterrupt(digitalPinToInterrupt(B2), down, FALLING);  
}

void setRow(int row){
  if(row==1) digitalWrite(R1,LOW); else digitalWrite(R1,HIGH);
  if(row==2) digitalWrite(R2,LOW); else digitalWrite(R2,HIGH);
  if(row==3) digitalWrite(R3,LOW); else digitalWrite(R3,HIGH);
  if(row==4) digitalWrite(R4,LOW); else digitalWrite(R4,HIGH);
  if(row==5) digitalWrite(R5,LOW); else digitalWrite(R5,HIGH);
  if(row==6) digitalWrite(R6,LOW); else digitalWrite(R6,HIGH);
  if(row==7) digitalWrite(R7,LOW); else digitalWrite(R7,HIGH);
  if(row==8) digitalWrite(R8,LOW); else digitalWrite(R8,HIGH);
}

void setColumn(int col){
  if(col==1) digitalWrite(C1,HIGH); else digitalWrite(C1,LOW);
  if(col==2) digitalWrite(C2,HIGH); else digitalWrite(C2,LOW);
  if(col==3) digitalWrite(C3,HIGH); else digitalWrite(C3,LOW);
  if(col==4) digitalWrite(C4,HIGH); else digitalWrite(C4,LOW);
  if(col==5) digitalWrite(C5,HIGH); else digitalWrite(C5,LOW);
  if(col==6) digitalWrite(C6,HIGH); else digitalWrite(C6,LOW);
  if(col==7) digitalWrite(C7,HIGH); else digitalWrite(C7,LOW);
  if(col==8) digitalWrite(C8,HIGH); else digitalWrite(C8,LOW);
}

//for interrupt of up button
void up(){
  upButton = 1;
}

//for interrupt of down button
void down(){
  downButton = 1;
}


void loop() {
  if(upButton==1){
    //up button action
    upButton = 0;    
  }
  if(downButton==1){
    //down button action
    downButton = 0;    
  }
}
