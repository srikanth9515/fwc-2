#include <Arduino.h>
//int n=13;
void setup() {
  // put your setup code here, to run once:
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);            
}

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

void loop() {
// put your main code here, to run repeatedly:

  //Output 1	
  sevenseg(1,0,0,1,1,1,1);  
  delay(500);
  
  //Output 2	
  sevenseg(0,0,1,0,0,1,0);  
  delay(500);
  
  //Output 3 	
  sevenseg(0,0,0,0,1,1,0);  
  delay(500);
  
  //Output 4
  sevenseg(1,0,0,1,1,0,0);  
  delay(500);
  
  //Output 5
  sevenseg(0,1,0,0,1,0,0);  
  delay(500);
  
  //Output 6
  sevenseg(0,1,0,0,0,0,0);  
  delay(500);
  
  //Output 7
  sevenseg(0,0,0,1,1,1,1);  
  delay(500);
  
  //Output 8 
  sevenseg(0,0,0,0,0,0,0);  
  delay(500);

  //Output 9 
  sevenseg(0,0,0,0,1,0,0);  
  delay(500);

  //Output 0 
  sevenseg(0,0,0,0,0,0,1);  
  delay(500);

}
