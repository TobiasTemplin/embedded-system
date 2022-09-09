/*
 * square_wave.c
 *
 * Created: 09.09.2022 08:53:30
 * Author : sigfridb
 */ 


#define F_CPU 4915200

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    
	DDRB = 0x01; // set lowermost bit in Port B as output
	
    while (1) 
    {
		PORTB = 0x01;// Set lowermost bit in Port B to high, others to low
		_delay_ms(100);
		PORTB = 0x00;// Set all bits in Port B to low
		_delay_ms(100);
    }
}

