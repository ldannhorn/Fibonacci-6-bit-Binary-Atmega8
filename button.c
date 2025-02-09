// This program outputs 8 bits of the fibonacci sequence on port C0-C5 and D6-D7
// Outputs next number on button press on PB1 (use pull down resistor)
// LEDs on PC0-PC5 & D6-D7

#define F_CPU 16000000 

#include <avr/io.h>
#include <util/delay.h>


int fibonacci_step(int a, int b, int c, uint8_t n) {
    // Provide n=0, 1 or 2 for result=a, b, or c
    uint8_t portd_mask = 0b11000000;
    if (n==0) {
        a = b + c;
	    PORTC = 0b0000000;
	    PORTC |= a;
	    PORTD = 0b0000000;
	    PORTD |= a && portd_mask;
        return a;
    }
    else if (n==1) {
        b = c + a;
	    PORTC = 0b0000000;
	    PORTC |= b;
	    PORTD = 0b0000000;
	    PORTD |= b && portd_mask;
        return b;
    }
    else if (n==2) {
        c = a + b;
	    PORTC = 0b0000000;
	    PORTC |= c;
	    PORTD = 0b0000000;
	    PORTD |= c && portd_mask;
        return c;
    }
    else {
        return 0;
    }
}



int main()
{
 // Setup
 DDRC |= 0b00111111; // set PC0-PC5 to output
 DDRD |= 0b11011000; // set PD6-PD7 & PD3-PD4 to output
 DDRB |= 0b0; // set port B to input


 // Fibonacci
 int a = 0;
 int b = 1;
 int c = 0;
 uint8_t n = 2; // Start with 2 -> first n=3
 
 while (1) {

    if ( (PINB & (1 << PINB1)) == (1 << PINB1) ) {
    //if (1) {
        // blink status led on PD4
        PORTD = 0b00010000;
        _delay_ms(100);
        PORTD = 0b00000000;

        n = (n+1) % 3;

        if (n==0) {
            a = fibonacci_step(a, b, c, n);
        } else if (n==1) {
            b = fibonacci_step(a, b, c, n);
        } else if (n==2) {
            c = fibonacci_step(a, b, c, n);
        } else {
            // blink error led on PD3
            PORTD = 0b00001000;
            _delay_ms(100);
            PORTD = 0b00000000;
        }

        _delay_ms(100); // """debounce"""
    }

 }
 
 return 0; // the program executed successfully
}
