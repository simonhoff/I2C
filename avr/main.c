
#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "display.h"
#include "I2C.h"

//TWI0 ext1
#define TWI_SDA PC1 //ext1 pin9
#define TWI_SCL PC0 //ext1 pin10
//LED OLED XPLAINED ext4
#define LED1 PINB3
#define LED2 PIND4
#define LED3 PINA3

int main(){
	DDRA |= (1 << LED3);
	DDRB |= (1 << LED1);
	DDRD |= (1 << LED2);

	PORTA |= (1 << LED3);
	PORTB |= (1 << LED1);
	PORTD |= (1 << LED2);

	//TWI0 setup registers
	TWAR0 = 0b00000010; //set TWI address to 0000001 (=1), and TWGCE to 0 (read)
	TWCR0 = 0b01000000;
	TWSR0
	TWCR0 |= (1 << TWEN); //TWI enable

	//Interrupt setup
	TWCR |= (1 << TWIE); //Enable interrupt when TWINT flag is high
	sei(); //set interrupt

	while (1){
		//this should probably work
		if (ADDR_REC == TWAR){
			//dostuff
		}

	}
}

ISR(TWI_something){

}