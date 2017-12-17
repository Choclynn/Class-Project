# Biking Jacket

As the above title suggests this project is a jacket that is meant
to be worn when going out for a bike ride. This jacket will provide
the wearer four basic functions. A turn left signal, a turn right
signal, brake lights, and finally a night time visability mode.
This particular project is controlled by an Ardunio Uno.

# Project Picture
![final project](https://github.com/Choclynn/Class-Project/blob/master/IMG_1929.JPG)

# List of Materials
The materials I ended up using include:
* Ardunio Uno
* external arduino battery pack
* five AA batteries
* zip-up hoodie
* one spool of conductive thread (3ply)
* Three resistors (10,000ohm)
* pair of scissors
* various needles
* sewable LEDs (3 colours)
* electrical tape
* three basic push buttons
* wires to connect to Arduino 

# The Build
Technically this build is actually fairly simple. It is just an assortment
of LEDs and a few buttons. On a breadboard or something of the like it is
super simple. Putting this onto the jacket however provides one with a much
more difficult task as grounding becomes a much harder task just as an example. I recommend that 
some planning occur before actually sewing stuff to the jacket. I will provide
a simple picture showing how to set up an LED and a push button but won't
give a view of the jacket as it rather messy and I can't draw very well.
I will however give a picture showing which of my LEDs are linked together to
give one and idea of how wiring may work.

![LED and Button Pic](https://github.com/Choclynn/Class-Project/blob/master/LED%20and%20Button%20Arduino.png)
![Jacket LEDs](https://github.com/Choclynn/Class-Project/blob/master/Jacket%20LEDs.png)

The LEDs joined by a red line are linked together or in other words are treated like a single LED.
Note that the brake lights are considered a single LED. Each sleeve has a single LED as well. Each
arrow however is split into 4 sections to allow for a different or unique blinking pattern to 
occur rather than the entire arrow blink at one time!




# Using the Jacket
I would say the device works in a rather simple fashion. All one must do is upload
the code once and it is good to go. From that point just power must be given to
the Arduino to run the jacket, that is why the external power pack is also sewn to
the jacket. Here is a breakdown of the four functions and how to work them.
1. ### Right turn
To turn on this function all one has to do is press the right signal button
that I have located on the right cuff of the jacket. Doing so will cause the 
right signal to blink in its fashion until the button is pressed again. The code 
I have doesn't read for the off button push until the signal does a full blink
so the button may have to be held for a little bit for it to work.

2. ### Left Turn
This is identical to the right turn in every way except this button is located 
on the left cuff rather than the right. otherwise functioanlly the same where it 
remains blinking left signal until the button is pressed again.

3. ### Brake
Again this is activated by pressing the other button located on the right cuff 
of the jacket, I differentiated the two by having different button colours.
This will then have the brake lights turn on and stay on until the button is pressed
once again.

4. ### Night time Mode
This function is activated by pressing both the left and right signal buttons at the 
same time. Once both are pressed simultaneously then all the lights will blink in the fashion
prescribed by the code. Again they will blink until either the right or left button is
pressed. As well, it doesn't read for the push until the end of the blink cycle so the 
button may have to be held for a little. 

## Important Note
Each sleeve has an indicator LED near the cuff. Whenever a function is entered it
blinks to notify the wearer that a function has been entered. Each function has its
own pattern/pace of blinking to help further notify the wear which function is on. For
example the left hand blinks during the left turn, right light for the right turn, both
for night time and the right again at a faster pace for brake. 

# The Team
This was essentially a one man project done by Quinten Ruckaber. However it is 
important to note that he has a girlfriend (Paige Sabados) who was kind enough to help out
with a large portion of the sewing as he is not/was not very good or fast
when it came to sewing!

# Credits
The main inspiration and start point for the build came from:
* Leah Buechley - http://www.instructables.com/id/turn-signal-biking-jacket/

A commentor however also did something similar and provided help with
more of the code aspect of the jacket:
* Chris Ruppel - https://chrisruppel.com/blog/lilypad-arduino-biking-jacket/
