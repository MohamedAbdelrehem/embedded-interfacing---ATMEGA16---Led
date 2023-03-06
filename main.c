/*
 * GccApplication1.c
 *
 * Created: 10/16/2022 10:27:17 AM
 * Author : Mohamed
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA=0b00000110;		//0b11111111  //0xFF or be specific and output the pins needed only
	DDRD=0b00001100;		//0b11111111  //0xFF		,,	,,	,,	,,	,,	,,	,,	,,	,,
    
	PORTA=0x00;		//low all pins
	PORTD=0x00;		//low all pins
	
    while (1) 
    {	
		PORTA = DDRA & (1<<2);		//PORTA |= (1<<PINA2);		//PORTA = (1<<2);
		PORTD = 0x00;
		_delay_ms(1000);
		PORTA = DDRA & (1<<1);		//PORTA |= (1<<PINA1);		//PORTA = (1<<1);
		_delay_ms(1000);
		PORTA = 0x00;
		PORTD = DDRD & (1<<2);
		_delay_ms(1000);
		PORTD = DDRD & (1<<3);
		_delay_ms(1000);
		PORTA = 0x0F;
		PORTD = 0x0F;
		_delay_ms(1000);
		PORTA = 0x00;
		PORTD = 0x00;
		_delay_ms(1000);
		
    }
}
/*
	LEDs L 1 to L 4 shall toggle by the following sequence
	1.
		L 1 is ON others OFF, then L 2 is ON others OFF, then L 3 is ON others OFF, then L 4 is ON others OFF
	2.
		All LEDS are ON
	3.
		All LEDS are OFF
	4.
		Each step have a delay of 1 sec
	5.
		Repeat
*/
