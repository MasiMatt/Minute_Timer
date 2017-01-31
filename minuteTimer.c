#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main(void)
{
	 int a, b, c, d, i, j, x = 0, set =0, sel= 0, u;
	 int num[10] = {125, 96, 62, 122, 99, 91, 95, 112, 127, 123};
	 int buff1 =0, buff2 =0, buff3 =0, buff4 =0;

	DDRB = 0x00;
	DDRC = 0xFF;
	DDRD = 0xFF;

	set = PINB & 0x0f;
	sel = PINB & 0xf0;

while(1)
{	
	while(sel != 0x80)
	{
	for(u =0; u<2; u++)
	{
		set = PINB & 0x0f;
		sel = PINB & 0xf0;

		PORTC = 1;
		if(sel== 0x10)
		{
			PORTD = num[set];
			buff1 = set;
		}		
		_delay_ms(1);
		PORTD = num[buff2];	
		PORTC = 2;
		if(sel== 0x30)
		{
			PORTD = num[set];
			buff2 = set;
		}
		_delay_ms(1);
		PORTD = num[buff3];	
		PORTC = 4;
		if(sel== 0x70)
		{
			PORTD = num[set];
			buff3 = set;
		}
		_delay_ms(1);
		PORTD = num[buff4];	
		PORTC = 8;
		if(sel== 0xF0)
		{
			PORTD = num[set];
			buff4 = set;
		}
		_delay_ms(1);
		PORTD = num[buff1];	
	}
	}
		
		for(a=buff4; a>=0; a--)
			{
			sel = PINB & 0xf0;
			if(sel== 0xC0)
				a++;
				if(sel == 0xE0)
					break;
				for(b=buff3; b>=0; b--)
				{
				sel = PINB & 0xf0;
				if(sel== 0xC0)
					b++;
					if(sel == 0xE0)
						break;
					for(c=buff2; c>=0; c--)
					{
					sel = PINB & 0xf0;
					if(sel== 0xC0)
						c++;
						if(sel == 0xE0)
							break;
						for(d=buff1; d>=0; d--)
						{
						sel = PINB & 0xf0;
						if(sel== 0xC0)
							d++;
							if(sel == 0xE0)
								break;
							for(i =0; i<249; i++)
							{
							sel = PINB & 0xf0;
							if(sel== 0xC0)
								i++;
								if(sel == 0xE0)
									break;	
							PORTC = 1;
							PORTD = num[d];
							_delay_ms(1);

							PORTC = 2;
							PORTD = num[c];
							_delay_ms(1);

							PORTC = 4;
							PORTD = num[b];
							_delay_ms(1);

							PORTC = 8;
							PORTD = num[a];
							_delay_ms(1);
								buff1 = 9;
								buff2 = 5;
								buff3 = 9;
								buff4 = 5;
							}
						}
	
					}
				}
			}
			buff1 = 0;	
			buff2 = 0;
			buff3 = 0;
			buff4 = 0;							
	}	

}
