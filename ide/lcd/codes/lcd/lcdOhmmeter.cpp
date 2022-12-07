#include <Arduino.h>
#include <LiquidCrystal.h>
//Arduino pins connected to LCD
LiquidCrystal lcd (12 ,11 ,5 ,4 ,3 ,2) ; 

// Declarations
// V_out_q is the quantized voltage
int V_out_q =0 ;
// V_in = V_cc
float V_in = 5 , V_out ;
// R1 is known resistance
// R2 is unknown resistance
float R1 =1000 , R2 ;

// the setup function runs once when you press reset or power the board
void setup() {

    //Get the result onto serial monitor
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("-------OHM METER------");
    Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  
	//V_out_q is an integer between 0 and 1023
	V_out_q = analogRead(0) ; 
	Serial.print("V_out_q") ; 
	Serial.println(V_out_q) ; 
	//V_out is the actual voltage at the junction of R1 and R2
	V_out = V_in * V_out_q/1024;
	R2 = R1 * ((V_out)/(V_in-V_out)) ;
//	R2 = R1 * ((V_in)/(V_out) - 1.0 ) ;

	delay (3000);
	Serial.println(R2) ;

	lcd.setCursor(0,1);
	lcd.print("R = ");
	lcd.print(R2);
	lcd.print("Ohm");


}
