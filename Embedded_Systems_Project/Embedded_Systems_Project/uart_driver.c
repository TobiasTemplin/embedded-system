/*
 * uart_driver.c
 */ 

// Include libraries
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "uart_driver.h"


// Define functions

void UART_init(void){
	//Register UCSR0A
	
	//BAUD_PRESCALE is the value that we have to load in the UBRR register to set the defined baud rate.
	UBRR0L = (uint8_t)(BAUD_PRESCALLER);
	UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);
	
	UCSR0B = (1 << RXEN0)|(1 << TXEN0); /* Turn on transmission and reception */
	UCSR0C = (1 << URSEL0)|(1 << USBS0)|(3 << UCSZ00); /* Use 8-bit char size */
	
	
	fdevopen(&UART_send, &UART_receive);
}

char UART_receive(void){
	/*
	  Bit 7 – RXC: USART Receive Complete
	  This flag bit is set when there is unread data in UDR. The RXC Flag can be used to generate a Receive Complete interrupt.
	*/
	
	//The program stays in the while loop until the data is received completely. Then we exit the loop and return the data.
	while(!(UCSR0A & (1 << RXC0)));
	
	//we have received something.
	//TODO: generate a feedback that we received something.
	//.. => feedback not here. We do when we call the function.	
	
	//UCSR0A &= !(1 << RXC0); REMOVE?
	return UDR0;
}

void UART_send(unsigned char data){
	
	//transmit buffer (UDR)
	//TXC Flag bit is automatically cleared
	
	/*
	Bit 5 – UDRE: USART Data Register Empty
	if UDRE is set to 1 => The buffer is empty and new data can be sent.
	*/
	while(!(UCSR0A & (1 << UDRE0))); //waiting for the transmit buffer is empty and can receive new data. ==> Ex. 9(a)
		
	//The buffer is empty and we write new data.
	UDR0 = data;
}