#include <lpc214x.h>
void delay_ms(unsigned int j);
unsigned char getAlphaCode(unsigned char alphachar);
void alphadisp7SEG(char *buf);
int main()
{
 IO0DIR |= 1U << 19 | 1U << 20 | 1U << 30 ;
 while(1)
{
 alphadisp7SEG("fire ");
 delay_ms(500);
 alphadisp7SEG("help ");
 delay_ms(500);
}
}
unsigned char getAlphaCode(unsigned char alphachar)
{ 
switch (alphachar)
{
// dp g f e d c b a - common anode: 0 segment on, 1 segment off
case 'f':return 0x8e; 
case 'i':return 0xf9;
case 'r':return 0xce;
case 'e':return 0x86; // 1000 0110
case 'h':return 0x89;
case 'l':return 0xc7;
case 'p':return 0x8c;
case ' ': return 0xff;
//simmilarly add for other digit/characters
default : break;
}
return 0xff;
}
void alphadisp7SEG(char *buf)
{
unsigned char i,j;
unsigned char seg7_data,temp=0;
for(i=0;i<5;i++) 
 {
seg7_data = getAlphaCode(*(buf+i));
for (j=0 ; j<8; j++)
{
temp = seg7_data & 0x80;
if(temp == 0x80)
IOSET0 |= 1 << 19; //IOSET0 | 0x00080000;
else
IOCLR0 |= 1 << 19; //IOCLR0 | 0x00080000;
//send one clock pulse
IOSET0 |= 1 << 20; //IOSET0 | 0x00100000;
 delay_ms(100); 
IOCLR0 |= 1 << 20; //IOCLR0 | 0x00100000;
 seg7_data = seg7_data << 1; // get next bit into D7 position
}
IOSET0 |= 1 << 30; //IOSET0 | 0x40000000;
delay_ms(100); //nop();
IOCLR0 |= 1 << 30; //IOCLR0 | 0x40000000;
 }
// send the strobe signal

return;
 }
void delay_ms(unsigned int j)
{
 unsigned int x,i;
 for(i=0;i<j;i++)
 {
 for(x=0; x<10000; x++); 
 }
}