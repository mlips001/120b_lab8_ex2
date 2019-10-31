/*
 * Lab8_ex2.c
 *
 * Created: 10/29/2019 12:22:24 PM
 * Author : Matthew L
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
	
void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; 
	DDRB = 0xFF; PORTB = 0x00; 
	DDRD = 0xFF; PORTD = 0x00; 
	
	ADC_init();
	
    /* Replace with your application code */
    while(1){
	    unsigned short x = ~ADC; 
	    unsigned char lower8 = (char)x;
	    PORTB = lower8;
	    unsigned char upper2 = (char)(x >> 8);
	    PORTD = upper2;
	}
}

