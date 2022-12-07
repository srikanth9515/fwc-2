#include <Arduino.h>
//Declaring all variables as integers
int A,B,C,D;
int a,b,c,d,e,f,g ; 
//Code released under GNU GPL.  Free to use for anything.
void sevenseg(int a,int b,int c,int d,int e,int f,int g)
{
  digitalWrite(2, a); 
  digitalWrite(3, b); 
  digitalWrite(4, c); 
  digitalWrite(5, d); 
  digitalWrite(6, e); 
  digitalWrite(7, f);     
  digitalWrite(8, g); 
}
// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);  
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, INPUT);
    pinMode(10, INPUT);
    pinMode(11, INPUT);
    pinMode(12, INPUT);
    
}

// the loop function runs over and over again forever
void loop() {
  
A = digitalRead(9);//LSB  
B = digitalRead(10);  
C = digitalRead(11);  
D = digitalRead(12);//MSB  
  
  a = (!D&&!C&&!B&&A) || (!D&&C&&!B&&!A) ; 
  b = (!D&&C&&!B&&A) || (!D&&C&&B&&!A); 
  c = (!D&&!C&&B&&!A); 
  d = (!D&&!C&&!B&&A) || (!D&&C&&!B&&!A) || (!D&&C&&B&&A);
  e = (!D&&A) || (!C&&!B&&A) || (!D&&C&&!B) ; 
  f = (!D&&!C&&A) || (!D&&!C&&B) ||  (!D&&B&&A) ; 
  g = (!D&&!C&&!B) ||  (!D&&C&&B&&A) ; 
  
sevenseg(a,b,c,d,e,f,g); 
delay(500) ;

/*
W = A ; 
X = B ; 
Y = C ; 
Z = D ; 


disp_7447(Z,Y,X,W);
delay(200); */
}
