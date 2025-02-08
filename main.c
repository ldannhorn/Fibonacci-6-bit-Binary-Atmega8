// This program outputs 6 bits of the fibonacci sequence on port C
// LEDs on PC0-PC5

#define F_CPU 16000000 

#include <avr/io.h>
#include <util/delay.h>


int main()
{
 // Setup
 DDRC |= 0b00111111; // set PC0-PC5 to output


 // Fibonacci
 int a = 0;
 int b = 1;
 int c = 0;
 
 while (1) {
	c = a + b;
	_delay_ms(2000);
	PORTC = 0b0000000;
	PORTC |= c;
	
	//
	
	a = b + c;
	_delay_ms(2000);
	PORTC = 0b0000000;
	PORTC |= a;
	
	//
	
	b = c + a;
	_delay_ms(2000);
	PORTC = 0b0000000;
	PORTC |= b;
 }
 
 return 0; // the program executed successfully
}
