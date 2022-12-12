#include <Arduino.h>
//Declaring all variables as integers
int Z,Y,X,W;
int D,C,B,A;

//Code released under GNU GPL.  Free to use for anything.
void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(2, A); //LSB
  digitalWrite(3, B); 
  digitalWrite(4, C); 
  digitalWrite(5, D); //MSB

}
// the setup function runs once when you press reset or power the board
void setup() {

    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(8, INPUT);
    pinMode(9, INPUT);
}

// the loop function runs over and over again forever
void loop() {

  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);                       // wait for a second

  //Read the 7474 outputs
  W = digitalRead(8); //LSB
  X = digitalRead(9);//MSB

  //Add combinational logic for desired state transitions
  B=!X;
  A=(W&&!X) || (!W&&X);

  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);                         // wait for a second
  
  disp_7447(0,0,B,A); 

}
//&& is the AND operation
// || is the OR operation
// ! is the NOT operation
