/*
 * square_wave.c
 *
 * Created: 09.09.2022 08:53:30
 * Author : sigfridb
 */ 


#define F_CPU 4915200

#include <avr/io.h>
#include <util/delay.h>
#include "uart_driver.h"


int square_wave();
int uart_communication();
int test_latch_with_leds();

int main(void)
{
	//square_wave();

	/*UART_init();
	uart_communication();
*/
	
	test_latch_with_leds();

}

int test_latch_with_leds() {
	/*
	PORT A and PORT C are both connected to the same 8 data input pins of the latch.
	PA0 and PC0 are connected to the same pin on the latch, and so on and so forth.
	
	PORT A (multiplex) is used for the transmitted data + the lower part of the 16-bit adress.
	PORT C is the upper part of the adress.
	*/
	DDRA = 0xFF; // PORT A: Set all Pins PA0 - PA7 to output
	DDRC = 0xFF; // PORT C: Set all Pins PC0 - PC7 to output
	
	//To enable the latch: use PE1 (ALE)
	DDRE = 0x05;
	//PORTE
	
	//Conect OE to Ground!
	
	//Try to light up on specific led.
	PORTA = 0b10000000; //set one pin at a time to 1.
	PORTE = 0b00000101;
	
	return 0;
}


int uart_communication(){
	
	//Example for Exercise 1
	
	printf("Hello, my friend. This is great\n");
	unsigned int x = 65536-1;
	printf("%u\n", x);
	x = x + 1;
	printf("%u\n", x);
	
	char* message = "Hello, This is a variable.\n";
	printf(message);
	
	
	
	//UART_init(); ==> Do it in the main function before using this function. We had the problem, that we initialized several times.
	char c;
	while(1){
		//UART_send('d');
		c = UART_receive();
		if (c != '\n') {
			printf("I received: %c\n", c);
		}
	}
	return 0;
}

int square_wave()
{
	DDRB = 0x01; // set lowermost bit in Port B as output
	
    while (1) 
    {
		PORTB = 0x01;// Set lowermost bit in Port B to high, others to low
		_delay_ms(100);
		PORTB = 0x00;// Set all bits in Port B to low
		_delay_ms(100);
    }
	return 0;
}
