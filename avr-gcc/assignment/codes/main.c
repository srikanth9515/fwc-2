//assignment to implement a 2 bit counter for 0->2>1>3->0 state transitions
#include <avr/io.h>

#include <util/delay.h>

#include <stdbool.h>




int main (void)

{
 bool A,B;

 bool W, X ;

//identifyinng pins 8,9 as inputs and pin13 as output 
 DDRB = 0b11111100;

//identifyinng pins 2,3 as ouputs  
 DDRD = 0b00001100;

 //PORTD = 0b11000000;

 //PORTB = 0b00000011;

 while(1){

   
  //Gnerate clock
  PORTB = ((1 <<  PB5));

  _delay_ms (500L);

  //Read inputs
  W = (PINB & (1 << PINB0)) == (1 << PINB0);

  X = (PINB & (1 << PINB1)) == (1 << PINB1);
  
  //Implement combinational logicto havedesired state trnsitios
  B=(!X);
  A=((W&&(!X))|| ((!W)&&X)) ;

//Write to the output
  PORTD = (A << 2);
  PORTD |= (B << 3);

  //Generate clock
  PORTB = ((0 <<  PB5));
  _delay_ms (500L);

 }
return 0;

}
