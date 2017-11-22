/*
 This code is ment to work a jacket with 2 different 
 turn indicators and brake lights to simulate that of
 a car. Each inidicator has it's own button that controls
 it by pushing it. There is a third button that controls 
 the brake lights. Should both of the indicator buttons
 be pushed at the same time then a night time visability
 function will start that blinks all lights in a fashion
 that helps increase visability. 
 One note is that both the right turn and stopping
 buttons are located on hte right sleeve of the jacket
 this program will control.
 Another important note is that in all functions they
 will only stop at the end of their cycle and not in the
 middle or whenever the button is pressed. It is coded in
 a way that only checks the buttons status at the end of 
 the while thus it will only turn off at the end of the 
 functions cycle.

 This code is made by Quinten Ruckaber on Nov.22/17 
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
 int RCount = 0;      //counter used to control the right turn function
 int LCount = 0;      //counter used to control the left turn function
 int BCount = 0;      //counter used to control the brake function
 int Ncount = 0;      //counter used to control the nightTime function
 int wait = 75;       //a delay used to control the pace of light commands
 
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

/*
 This function will turn on the right indicator to alert those
 around the biker that they intend to make a right turn.
 */
void turnRight()
{
  if (analogRead(rButton) == 0) //if button is pressed
  {
    while(analogRead(rButton) == 0) //while pressed check to see if other is pressed
    {
      if (analogRead(lButton) == 0) //if both pressed
      {
        NCount++; //up night counter by 1
        nightTime(); //activate nightTime mode
        return; //exit this function at this point once nightTime function is ended
      }
    }
   RCount++;  //if only the right button is pressed, up right counter by 1
  }
  while(RCount == 1)  //as long as right counter is 1, do the following
  {
   //this will turn on the right indicator in a fashion that blinks 1 column at a time
   //starts at the inner-most light and work towards the tip of the arrow
   digitalWrite(rLED, LOW);    //right hand LED off
   digitalWrite(right1, HIGH);
   delay(wait);
   digitalWrite(right1, LOW);
   delay(wait);
   digitalWrite(rLED, HIGH);     //right hand LED on
   digitalWrite(right2, HIGH);
   delay(wait);
   digitalWrite(right2, LOW);
   delay(wait);
   digitalWrite(rLED, LOW);    //right hand LED off
   digitalWrite(right3, HIGH);
   delay(wait);
   digitalWrite(right3, LOW);
   delay(wait);
   digitalWrite(rLED, HIGH);     //right hand LED on
   digitalWrite(right4, HIGH);
   delay(wait);
   digitalWrite(right4, LOW);
   delay(wait);

   if(analogRead(rButton) == 0) //check to see if the right button is pushed
   {
    //if so increase right counter by 1, this causes an exit of the while loop 
    RCount++;
   }
  }
  //turn off hand LED as it was left on
  digitalWrite(rLED, LOW);
  //reset right counter so re-entry of function will work properly
  RCount = 0;
  delay(500);
}

/*
 This function will turn on the left indicator to alert those
 around the biker that they intend to make a left turn.
 */
void turnLeft()
{
  if (analogRead(lButton) == 0) //if button is pressed
  {
    while (analogRead(lButton) == 0)  //while pressed, check to see if both are pressed
    {
      if (analogRead(rButton) == 0) //if both pressed 
      {
        NCount++; //up night counter by 1
        nightTime();  //activate nightTime mode
        return; //exit this function at this point once nightTime function is ended
      }
    }
   LCount++;  //if only left button is pressed, up left counter by 1
  }
  while(LCount == 1)  //as long as left counter is 1, do the following
  {
   //this will turn on the left indicator in a fashion that blinks 1 column at a time
   //starts at the inner-most light and work towards the tip of the arrow
   digitalWrite(lLED, LOW);   //left hand LED off
   digitalWrite(left1, HIGH);
   delay(wait);
   digitalWrite(left1, LOW);
   delay(wait);
   digitalWrite(lLED, HIGH);  //left hand LED on
   digitalWrite(left2, HIGH);
   delay(wait);
   digitalWrite(left2, LOW);
   delay(wait);
   digitalWrite(lLED, LOW);   //left hand LED off
   digitalWrite(left3, HIGH);
   delay(wait);
   digitalWrite(left3, LOW);
   delay(wait);
   digitalWrite(lLED, HIGH);  //left hand LED on
   digitalWrite(left4, HIGH);
   delay(wait);
   digitalWrite(left4, LOW);
   delay(wait);

   if(analogRead(lButton) == 0) //check to see if left button is pushed 
   {
    //if pressed, up the left counter, this causes exit of the while loop
    LCount++;
   }
  }
  //turn of left hand LED as it was left on
  digitalWrite(lLED, LOW);
  //reset left counter so re-entry to this function will work properly
  LCount = 0;
  delay(500);
}

/*
 This function will turn on the brake lights to alert those
 around the biker that they intend to brake or are braking.
 */
void brake()
{
  if (analogRead(stopButton) == 0) //if button is pressed
  {
   BCount++;  //up the brake counter by 1
  }
  while(BCount == 1)  //as long as brake counter is 1, do the following
  {
   //this turns on the brake lights until the loop is exited, but blinks hand
   //LED so the biker is aware it's on and working
   digitalWrite(stopLED, HIGH);
   digitalWrite(rLED, HIGH);      //right hand LED on
   delay(wait*2);
   digitalWrite(rLED, LOW);       //right hand LED off
   delay(wait*2);
  
   
   if(analogRead(stopButton) == 0)  //check to see if brake button is pressed
   {
    //if so, up brake count by 1, this causes exit of the while loop
    BCount++;
   }
  }
  //turn off brake lights as they were left on
  digitalWrite(stopLED, LOW);
  //reset brake counter to allow re-entry of this function to work properly
  BCount = 0;
  delay(500);
}

/*
 This function turns on and off all LEDs in the pattern below.
 The purpose is to help improve visability of the biker in the 
 dark by having all LEDs blink on and off. No braking of turn functions
 allowed while this function is on.
 */
void nightTime()
{
  while (NCount == 1) //as long as the night counter is 1, do the following
  {
   //this will turn on both indicators in a fashion that blinks 1 column at a time
   //starts at the inner-most light and work towards the tip of the arrow
   //while also doing the patterns below as described
   digitalWrite(stopLED, LOW);  //turn off brake lights
   digitalWrite(rLED, HIGH);      //
   digitalWrite(lLED, HIGH);      //turn on both hand LEDs
   digitalWrite(right1,HIGH);
   digitalWrite(left1, HIGH);
   delay(wait);
   digitalWrite(rLED, LOW);     //
   digitalWrite(lLED, LOW);     //turn off both hands LEDs
   digitalWrite(right1,LOW);
   digitalWrite(left1, LOW);
   delay(wait);
   digitalWrite(stopLED, HIGH); //turn on brake lights
   digitalWrite(rLED, HIGH);      //
   digitalWrite(lLED, HIGH);      //turn on both hand LEDs
   digitalWrite(right2,HIGH);
   digitalWrite(left2, HIGH);
   delay(wait);
   digitalWrite(rLED, LOW);     //
   digitalWrite(lLED, LOW);     //turn off both hands LEDs
   digitalWrite(right2,LOW);
   digitalWrite(left2, LOW);
   delay(wait);
   digitalWrite(stopLED, LOW);  //turn off brake lights
   digitalWrite(rLED, HIGH);      //
   digitalWrite(lLED, HIGH);      //turn on both hand LEDs
   digitalWrite(right3,HIGH);
   digitalWrite(left3, HIGH);
   delay(wait);
   digitalWrite(rLED, LOW);     //
   digitalWrite(lLED, LOW);     //turn off both hands LEDs
   digitalWrite(right3,LOW);
   digitalWrite(left3, LOW);
   delay(wait);
   digitalWrite(stopLED, HIGH); //turn on brake lights
   digitalWrite(rLED, HIGH);      //
   digitalWrite(lLED, HIGH);      //turn on both hand LEDs
   digitalWrite(right4,HIGH);
   digitalWrite(left4, HIGH);
   delay(wait);
   digitalWrite(rLED, LOW);     //
   digitalWrite(lLED, LOW);     //turn off both hands LEDs
   digitalWrite(right4,LOW);
   digitalWrite(left4, LOW);
   delay(wait);
 
   //check to see if either indicator button is pressed
   if (analogRead(rButton) == 0 || analogRead(lButton) == 0)
   {
    //if so, up night counter by 1, this causes an exit of the while loop
    NCount++;
   }
  }
  //turn off brake lights as they were left on
  digitalWrite(stopLED, LOW);
  NCount = 0;
  delay(500);

  //the end of this function takes you back to one of the turn functions
  //that is the reason why the return is placed after the function call in both cases
}

