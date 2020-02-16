//DO NOT TOUCH THESE 3 VARIABLES
const int SETUP_TIME = 5000;
const int AUTONOMOUS_TIME = 15000;
const int STOP_TIME = 2000;

int photoFront=A1;
int photoRight=A2;
int photoBack=A3;
int photoLeft=A4;
int motorRF=10;
int motorRB=11;
int motorLF=5;
int motorLB=6;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorRF,OUTPUT);
  pinMode(motorRB,OUTPUT);
  pinMode(motorLF,OUTPUT);
  pinMode(motorLB,OUTPUT);
  pinMode(photoFront,INPUT);
  pinMode(photoRight,INPUT);
  pinMode(photoBack,INPUT);
  pinMode(photoLeft,INPUT);
}
void test()
{
  analogWrite(motorRF,0);
  analogWrite(motorRB,255);
  analogWrite(motorLF,255);
  analogWrite(motorLB,0);
}
void forward()
{
  analogWrite(motorRF,255);
  analogWrite(motorRB,0);
  analogWrite(motorLF,140);
  analogWrite(motorLB,0);
}
void right()
{
  analogWrite(motorRF,255);
  analogWrite(motorRB,0);
  analogWrite(motorLF,0);
  analogWrite(motorLB,255);
}
void left()
{
  analogWrite(motorRF,0);
  analogWrite(motorRB,255);
  analogWrite(motorLF,255);
  analogWrite(motorLB,0);
}
void back()
{
  analogWrite(motorRF,0);
  analogWrite(motorRB,255);
  analogWrite(motorLF,0);
  analogWrite(motorLB,255);
}
void lightTest()
{
  int psForward = analogRead(photoFront);
  Serial.print("psForward: ");
  Serial.println(psForward);

  int psBack = analogRead(photoBack);
  Serial.print("psBack: ");
  Serial.println(psBack);

  int psLeft = analogRead(photoLeft);
  Serial.print("psLeft: ");
  Serial.println(psLeft);

  int psRight = analogRead(photoRight);
  Serial.print("psRight: ");
  Serial.println(psRight);
  Serial.println("");
}
void lightMoveTest()
{
  int photoStateForward=analogRead(photoFront);
  int photoStateBack=analogRead(photoBack);
  int photoStateLeft=analogRead(photoLeft);
  int photoStateRight=analogRead(photoRight);
  
  if(photoStateForward>700)
  {
    forward();
  }
  else if(photoStateLeft>800)
  {
    left();
  }
  else if(photoStateRight>820)
  {
    right();
  }
  else if(photoStateBack>700)
  {
    back();
  }
  else
  {
    fullStop();
  }
}
//============================================================
//DO NOT WRITE CODE IN THE LOOP METHOD.
void loop() 
{
  //DO NOT TOUCH THIS CODE
  //test();
  //forward();
  //lightTest();
  //lightMoveTest();
  long mil = millis();
  if(mil<SETUP_TIME)
  {
    //LEAVE THIS BLANK
  }
  else if(mil<AUTONOMOUS_TIME+SETUP_TIME)
  {
    autonomousMode();
  }
  else if(mil<AUTONOMOUS_TIME+SETUP_TIME+STOP_TIME)
  {
    fullStop();
  }
  else
  {
    teleOpMode();
  }
}
//============================================================

//WRITE CODE IN HERE:  YOUR AUTONOMOUS CODE GOES IN HERE.  PART 1 OF RACE
void autonomousMode(){
    
    forward();
}
//WRITE CODE IN HERE:  YOUR TELEOP CODE GOES IN HERE.  PART 2 OF RACE
//you MUST write this method
void teleOpMode(){
  int photoStateForward=analogRead(photoFront);
  int photoStateBack=analogRead(photoBack);
  int photoStateLeft=analogRead(photoLeft);
  int photoStateRight=analogRead(photoRight);

  
  
  if(photoStateForward>700)
  {
    forward();
  }
  else if(photoStateLeft>800)
  {
    left();
  }
  else if(photoStateRight>820)
  {
    right();
  }
  else if(photoStateBack>700)
  {
    back();
  }
  else
  {
    fullStop();
  }
  
  
}

//WRITE CODE IN HERE:  YOU SHOULD MAKE EVERY MOTOR STOP 
//you MUST write this method
void fullStop(){
  analogWrite(motorRF,0);
  analogWrite(motorRB,0);
  analogWrite(motorLF,0);
  analogWrite(motorLB,0);
}

//Feel free to add more methods.
