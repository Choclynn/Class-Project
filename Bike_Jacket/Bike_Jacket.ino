/*
 This code is ment to work a jacket with 2 different 
 turn indicators and brake lights to simulate that of
 a car. Each inidicator has it's own button that controls
 it by pushing it. There is a third button that controls 
 the brake lights, however this light must be held in order for
 the brake lights to be on. 
 */
 //constants to be used in the program
 const int right1 = 5;  //
 const int right2 = 4;  //these four variables are meant to control
 const int right3 = 3;  //the right turn signal. Right1, 2 and 3
 const int right4 = 2;  //all control 2 lights

 const int left1 = 6; //
 const int left2 = 7; //these four variables are meant to control
 const int left3 = 8; //the left turn signal. Left1, 2 and 3
 const int left4 = 9; //all control 2 lights

 const int rLED = 13; //controls LED that helps indicate the right button pushed
 const int lLED = 12; //controls LED that helps indicate the left button pushed

 const int stopLED = 11; //controls the brake light LEDs

 const int rButton = A5;  //button that controls right signal
 const int lButton = A4;  //button that controls left signal
 const int stopButton = A3;  //button that controls stop lights

 //variables to be used in the program
 int RCount = 0;
 int LCount = 0;
 int BCount = 0;
 int Ncount = 0;
 int wait = 75;
 
 void setup() 
 {
  //initialize all LEDs as outputs
  pinMode(right1, OUTPUT);
  pinMode(right2, OUTPUT);
  pinMode(right3, OUTPUT);
  pinMode(right4, OUTPUT);
  pinMode(left1, OUTPUT);
  pinMode(left2, OUTPUT);
  pinMode(left3, OUTPUT);
  pinMode(left4, OUTPUT);
  pinMode(rLED, OUTPUT);
  pinMode(lLED, OUTPUT); 
  pinMode(stopLED, OUTPUT);
 }

void loop() 
{
  turnRight();
  turnLeft();
  brake();
}

void turnRight()
{
  if (analogRead(rButton) == 0) //if button is pressed
  {
    while(analogRead(rButton) == 0) //while pressed check to see if other is pressed
    {
      if (analogRead(lButton) == 0) //if both pressed
      {
        NCount++;
        nightTime(); //activate nightTime mode
        return;
      }
    }
   RCount++;
  }
  while(RCount == 1)
  {
   digitalWrite(rLED, HIGH);
   digitalWrite(right1, HIGH);
   delay(wait);
   digitalWrite(right1, LOW);
   delay(wait);
   digitalWrite(rLED, LOW);
   digitalWrite(right2, HIGH);
   delay(wait);
   digitalWrite(right2, LOW);
   delay(wait);
   digitalWrite(rLED, HIGH);
   digitalWrite(right3, HIGH);
   delay(wait);
   digitalWrite(right3, LOW);
   delay(wait);
   digitalWrite(right4, HIGH);
   delay(wait);
   digitalWrite(right4, LOW);
   digitalWrite(rLED, LOW);
   delay(wait);

   if(analogRead(rButton) == 0)
   {
    RCount++;
   }
  }
  RCount = 0;
  delay(500);
}

void turnLeft()
{
  if (analogRead(lButton) == 0) //if button is pressed
  {
    while (analogRead(lButton) == 0)
    {
      if (analogRead(rButton) == 0)
      {
        NCount++;
        nightTime();
        return;
      }
    }
   LCount++;
  }
  while(LCount == 1)
  {
   digitalWrite(lLED, HIGH);
   digitalWrite(left1, HIGH);
   delay(wait);
   digitalWrite(left1, LOW);
   delay(wait);
   digitalWrite(lLED, LOW);
   digitalWrite(left2, HIGH);
   delay(wait);
   digitalWrite(left2, LOW);
   delay(wait);
   digitalWrite(lLED, HIGH);
   digitalWrite(left3, HIGH);
   delay(wait);
   digitalWrite(left3, LOW);
   delay(wait);
   digitalWrite(left4, HIGH);
   delay(wait);
   digitalWrite(left4, LOW);
   digitalWrite(lLED, LOW);
   delay(wait);

   if(analogRead(lButton) == 0)
   {
    LCount++;
   }
  }
  LCount = 0;
  delay(500);
}

void brake()
{
  if (analogRead(stopButton) == 0) //if button is pressed
  {
   BCount++;
  }
  while(BCount == 1)
  {
   digitalWrite(stopLED, HIGH);
   digitalWrite(rLED, HIGH);
   delay(wait*2);
   digitalWrite(rLED, LOW);
   delay(wait*2);
  
   
   if(analogRead(stopButton) == 0)
   {
    BCount++;
   }
  }
  digitalWrite(stopLED, LOW);
  BCount = 0;
  delay(500);
}

void nightTime()
{
  while (NCount == 1)
  {
   digitalWrite(stopLED, LOW);
   digitalWrite(rLED, HIGH);
   digitalWrite(lLED, HIGH);
   digitalWrite(right1,HIGH);
   digitalWrite(left1, HIGH);
   delay(wait);
   digitalWrite(rLED, LOW);
   digitalWrite(lLED, LOW);
   digitalWrite(right1,LOW);
   digitalWrite(left1, LOW);
   delay(wait);
   digitalWrite(stopLED, HIGH);
   digitalWrite(rLED, HIGH);
   digitalWrite(lLED, HIGH);
   digitalWrite(right2,HIGH);
   digitalWrite(left2, HIGH);
   delay(wait);
   digitalWrite(rLED, LOW);
   digitalWrite(lLED, LOW);
   digitalWrite(right2,LOW);
   digitalWrite(left2, LOW);
   delay(wait);
   digitalWrite(stopLED, LOW);
   digitalWrite(rLED, HIGH);
   digitalWrite(lLED, HIGH);
   digitalWrite(right3,HIGH);
   digitalWrite(left3, HIGH);
   delay(wait);
   digitalWrite(rLED, LOW);
   digitalWrite(lLED, LOW);
   digitalWrite(right3,LOW);
   digitalWrite(left3, LOW);
   delay(wait);
   digitalWrite(stopLED, HIGH);
   digitalWrite(rLED, HIGH);
   digitalWrite(lLED, HIGH);
   digitalWrite(right4,HIGH);
   digitalWrite(left4, HIGH);
   delay(wait);
   digitalWrite(rLED, LOW);
   digitalWrite(lLED, LOW);
   digitalWrite(right4,LOW);
   digitalWrite(left4, LOW);
   delay(wait);
 

   if (analogRead(rButton) == 0 || analogRead(lButton) == 0)
   {
    NCount++;
   }
  }
  digitalWrite(stopLED, LOW);
  NCount = 0;
  delay(500);
}

