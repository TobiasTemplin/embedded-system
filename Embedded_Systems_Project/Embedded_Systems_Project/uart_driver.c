/*
 * UART_driver.c
 */ 

// Include libraries
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "uart_driver.h"

int main(void)
{
	UART_init();
	//while (1)
	//{
	//	UART_print('d');
	//}
	while(1){
		UART_send("d");
		_delay_ms(200);
	}
}


// Define functions

void UART_init(void){
	UBRR0L = (uint8_t)(BAUD_PRESCALLER);
	UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);
	UCSR0B = (1 << RXEN0)|(1 << TXEN0);
	UCSR0C = (1 << URSEL0)|(1 << USBS0)|(3 << UCSZ00);
}

unsigned char UART_receive(void){
	while(!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

void UART_send(unsigned char data){
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

void UART_print(unsigned char data){
	int delay = 200;
	UART_send(data);
	_delay_ms(delay);
	UART_receive();
	_delay_ms(delay);
}
