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
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);
    pinMode(9, INPUT);
}

// the loop function runs over and over again forever
void loop() {

  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);                       // wait for a second

  //Read the 7474 outputs
  W = digitalRead(6);//LSB
  X = digitalRead(7);
  Y = digitalRead(8);
  Z = digitalRead(9);//MSB

  //Increment the input read
  A=!W;
  B=(W&&!X&&!Z) || (!W&&X);
  C=(W&&X&&!Y) || (!X&&Y) || (!W&&Y);
  D = (W&&X&&Y)||(!W&&Z);

  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);                         // wait for a second
  
  disp_7447(D,C,B,A); 

}
//&& is the AND operation
// || is the OR operation
// ! is the NOT operation
