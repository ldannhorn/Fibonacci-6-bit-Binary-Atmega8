// This program outputs 8 bits of the fibonacci sequence on port C0-C5 and D6-D7
// LEDs on PC0-PC5 & D6-D7

#define F_CPU 16000000 

#include <avr/io.h>
#include <util/delay.h>


int main()
{
 // Setup
 DDRC |= 0b00111111; // set PC0-PC5 to output
 DDRD |= 0b11000000; // set PD6-PD7 to output


 // Fibonacci
 int a = 0;
 int b = 1;
 int c = 0;
 
 while (1) {
	c = a + b;
	_delay_ms(150);
	PORTC = 0b0000000;
	PORTC |= c;
	PORTD = 0b0000000;
	PORTD |= c;
	
	//
	
	a = b + c;
	_delay_ms(150);
	PORTC = 0b0000000;
	PORTC |= a;
	PORTD = 0b0000000;
	PORTD |= a;
	
	//
	
	b = c + a;
	_delay_ms(150);
	PORTC = 0b0000000;
	PORTC |= b;
	PORTD = 0b0000000;
	PORTD |= b;
 }
 
 return 0; // the program executed successfully
}
