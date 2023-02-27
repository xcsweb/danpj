#include <STC89.H>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
void delay(uint z){
	uint x,y;
	for(x=z;x>0;x--)
		for(y=114;y>0;y--);
}


void main(){
	uchar temp=0x01;
	uchar xTemp;
	uint i=0;
	xTemp=~temp;
	P1=xTemp;
	delay(1000);
	while(1)
	{
		if(i<7)
		{
			i++;
			xTemp=temp<<i; //左移i位
			P1=~xTemp; //取反控制当前灯亮
			delay(1000);
		}else{
			i=0;
			temp=0x01;
			xTemp=temp;
			P1=~xTemp;
			delay(1000);
		}
	}
}