#include<lpc214x.h>

void delay(unsigned int i)
{
	int j,x;
	for(j=0;j<i;j++){
		for(x=0;x<10000;x++);
	}
}

unsigned char alpha7(unsigned char alphachar)
{
switch(alphachar){
	case 'f':return 0x8e;
	case 'i':return 0xf9;
	case 'r':return 0xce;
	case 'e':return 0x86;
	default : break;
	
}
}

void alpha7segdisplay(char *buf){
unsigned char temp=0,alpha;
unsigned char i,j;
	for(i=0;i<5;i++)
	{
	alpha=alpha7(*(buf+i));
	for(j=0;j<8;j++){
		temp=alpha&0x80;
		if(temp==0x80)
			IO0SET|=1<<19;
		else
			IO0CLR|=1<<19;
		
		IO0SET=1<<20;
		delay(10);
		IO0CLR=1<<20;
		alpha=alpha<<1;
	}
	}
IO0SET = 1<<30;
delay(10);
IO0CLR = 1<<30;
}

int main(){
IO0DIR|=1U<<19|1U<<20|1U<<30;
	while(1){
		alpha7segdisplay("fire");
		
	}
}
