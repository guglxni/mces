#include<lpc214x.h>
#define SW2 (IO1PIN & 1<<18)
#define SW3 (IO1PIN & 1<<19)
#define SW4 (IO1PIN & 1<<20)

short int value;
void delay(unsigned int i)
{
	int j,x;
	for(j=0;j<i;j++){
		for(x=0;x<10000;x++);
	}
}

int main(){
IO0DIR|=0x00FF0000;
while(1){
if(!SW2){
	value=0;
	while(value!=1023)
	{
	DACR=((1<<16)|value<<6);
		value++;
	}
	while(value!=0){
		DACR=((1<<6)|value<<6);
		value--;
	}

	}
if(!SW3){
	value=0;
	while(value!=1023)
	{
	DACR=((1<<16)|value<<6);
		value++;
	}

	}
if(!SW4){
	value=0;
	DACR=((1<<16)|value<<6);
	delay(1);
	
	value=1023;
	DACR=((1<<6)|value<<6);
	delay(1);	
	}
}
}