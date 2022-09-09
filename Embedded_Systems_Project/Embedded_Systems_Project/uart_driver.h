/*
 * square_wave.h
 */ 

#pragma once

// Global constants
#define F_CPU 4915200 // CPU clock frequency
#define BAUDRATE 9600
#define BAUD_PRESCALLER ( ( F_CPU / BAUDRATE / 16) - 1) // UBRR Value calculation formula

// Declare functions
void UART_init(void);// Initializes USART communication
unsigned char UART_receive(void);// Receives unsigned character from MCU
void UART_send(unsigned char data);// Sends unsigned character "data" to MCU