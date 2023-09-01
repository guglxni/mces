#include<lpc214x.h>
void delay(unsigned int i)
{
	int j,x;
	for(j=0;j<i;j++){
		for(x=0;x<10000;x++);
	}
}

int main(){
unsigned int ack=100,ck=100;
IO0DIR|=0X00FF0000;
do{
IO0CLR=0X000F0000;IO0SET=0X00010000;delay(10);if(--ck==0)break;
IO0CLR=0X000F0000;IO0SET=0X00020000;delay(10);if(--ck==0)break;
IO0CLR=0X000F0000;IO0SET=0X00040000;delay(10);if(--ck==0)break;
IO0CLR=0X000F0000;IO0SET=0X00080000;delay(10);if(--ck==0)break;
}while(1);

do{
IO0CLR=0X000F0000;IO0SET=0X00080000;delay(10);if(--ack==0)break;
IO0CLR=0X000F0000;IO0SET=0X00040000;delay(10);if(--ack==0)break;
IO0CLR=0X000F0000;IO0SET=0X00020000;delay(10);if(--ack==0)break;
IO0CLR=0X000F0000;IO0SET=0X00010000;delay(10);if(--ack==0)break;
}while(1);
IO0CLR=0X00FF0000;
while(1);
}