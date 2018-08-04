//motor A connected between A01 and A02
//motor B connected between B01 and B02
//5v connected vcc
//GND connected GND and power(-)
//

int pinAIN1 = 9;  // direction control
int pinAIN2 = 8;  // direction control 
int pinPWMA = 3;  // speed control

int pinBIN1 = 11;
int pinBIN2 = 12;
int pinPWMB = 5;


int pinSTBY = 10;

int pinSWITCH = 7;

static boolean turnCW = 0;
static boolean turnCCW = 1;
static boolean motor1 = 0;
static boolean motor2 = 1;

int  switchmode = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinPWMA,OUTPUT);
  pinMode(pinAIN1,OUTPUT);
  pinMode(pinAIN2,OUTPUT);

  pinMode(pinPWMB,OUTPUT);
  pinMode(pinBIN1,OUTPUT);
  pinMode(pinBIN2,OUTPUT);

  pinMode(pinSTBY,OUTPUT);

  pinMode(pinSWITCH,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

if (digitalRead(pinSWITCH) == LOW)
  {
    switchmode = 0;
  } else {
    switchmode = 1;
  }

if(switchmode == 1){

  digitalWrite(pinAIN1,LOW);
  digitalWrite(pinAIN2,HIGH);
  analogWrite(pinPWMA,1000);

  digitalWrite(pinBIN1,LOW);
  digitalWrite(pinBIN2,HIGH);
  analogWrite(pinPWMB,1000);

  digitalWrite(pinSTBY,HIGH);

  delay(3000);

  digitalWrite(pinAIN1,HIGH);
  digitalWrite(pinAIN2,LOW);
  analogWrite(pinPWMA,1000);

  digitalWrite(pinBIN1,HIGH);
  digitalWrite(pinBIN2,LOW);
  analogWrite(pinPWMB,1000);

  delay(3000);


//if (digitalRead(pinSWITCH) == HIGH) {
  
//  motorDrive(motor1,turnCW,255);
//  motorDrive(motor2,turnCW,255);

//  delay(2000);

//  motorStop(motor1);
//  motorStop(motor2);

//  delay(2000);

//  motorDrive(motor1,turnCW,192);
//  delay(250);

//  motorsStandby();
//  delay(1000);

//  motorDrive(motor1,turnCCW,192);

//  delay(2000);

//  motorStop(motor1);

//  delay(2000);

//  motorDrive(motor1,turnCCW,255);
//  motorDrive(motor2,turnCCW,255);

//  delay(2000);

//  motorStop(motor1);
//  motorStop(motor2);

//  delay(2000);
  
//  motorBrake(motor1);

//  motorsStandby();

//  delay(5000);

//}else{}

}else{
  digitalWrite(pinAIN1,LOW);
  digitalWrite(pinAIN2,LOW);
  digitalWrite(pinBIN1,LOW);
  digitalWrite(pinBIN2,LOW);
}

}


void motorDrive(boolean motorNumber,boolean motorDirection , int motorSpeed)
{

  boolean pinln1;

  if(motorDirection == turnCW){
    pinln1 = HIGH;
  }else{
    pinln1 = LOW;
  }

   if(motorNumber==motor1)
   {
    digitalWrite(pinAIN1,pinln1);
    digitalWrite(pinAIN2,!pinln1);
    analogWrite(pinPWMA,motorSpeed);
   }
   else
   {
    digitalWrite(pinBIN1,pinln1);
    digitalWrite(pinBIN2,!pinln1);
    analogWrite(pinPWMB,motorSpeed);
   }

   digitalWrite(pinSTBY,HIGH);
}

void motorBrake(boolean motorNumber)
{
  if(motorNumber == motor1)
  analogWrite(pinPWMA,0);
  else
  analogWrite(pinPWMB,0);
}

void motorStop(boolean motorNumber)
{
  if(motorNumber == motor1){
    digitalWrite(pinAIN1,LOW);
    digitalWrite(pinAIN2,LOW);
  }
  else
  {
    digitalWrite(pinBIN1,LOW);
    digitalWrite(pinBIN2,LOW);
  }
}

void motorsStandby()
{
  digitalWrite(pinSTBY,LOW);
}
