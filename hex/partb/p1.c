#include<lpc214x.h>
#define SW2 (IO0PIN & (1 << 14))
#define SW3 (IO0PIN & (1U << 15))
#define SW4 (IO1PIN & (1U << 18))
#define SW5 (IO1PIN & (1U << 19))
void delay_ms(unsigned int x);
void reset_values(int y);
int contUP = 0;
int contDN = 99;
unsigned int rightSFT = 0x80;
unsigned int leftSFT = 0x01;
int main()
{
	IO0DIR |= 0xFF<<16;
	while(1)
	{
	if(!SW2)
	{
		reset_values(0);
		IO0SET = 0xFF<<16;
		IO0CLR |= ((contUP/10)<<4 | (contUP%10))<<16;
		contUP++;
		if(contUP > 99) contUP = 0;
	}
	if(!SW3)
	{
		reset_values(1);
		IO0SET = 0xFF<<16;
		IO0CLR |= ((contDN/10)<<4 | (contDN%10))<<16;
		contDN--;
		if(contDN<0) contDN =99;
	}
	if(!SW4)
	{
		reset_values(2);
		IO0SET = 0xFF<<16;
		IO0CLR |= leftSFT<<16;
		leftSFT<<=1;
		if(leftSFT>0x80) leftSFT=0x01;
	}
	if(!SW5)
	{
		reset_values(3);
		IO0SET = 0xFF<<16;
		IO0CLR |= rightSFT<<16;
		rightSFT>>=1;
		if(rightSFT<0x01) rightSFT=0x80;
	}
delay_ms(300);
	}
}
void reset_values(int y)
{
switch(y)
{
case 0: contDN = 99;
rightSFT = 1U<<7;
leftSFT = 1;
break;
case 1: contUP = 0;
rightSFT = 1U<<7;
leftSFT = 1;
break;
case 2: contUP = 0;
contDN = 99;
rightSFT = 1U<<7;
break;
case 3: contUP = 0;
contDN = 99;
leftSFT = 1;
break;
}
}
void delay_ms(unsigned int ms) {
for(int i = 0; i < ms; i++) {
for(int x = 0; x < 10000; x++);
}
}
