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

int main(void)
{
	//square_wave();
	
	//uart_communication();

	UART_init();
	printf("Hello, my friend. This is great\n");
	unsigned int x = 65536-1;
	printf("%u\n", x);
	x = x + 1;
	printf("%u\n", x);
	
	char* message = "Hello, This is a variable.\n";
	printf(message);
	
	uart_communication();

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

int uart_communication(){
	//UART_init(); ==> Do it in the main function before using this function. We had the problem, that we initialized several times.
	char c;
	while(1){
		//UART_send('d');
		c = UART_receive();
		if (c != '\n') {
			printf("I received: %c\n", c);	
		}
	}
}
