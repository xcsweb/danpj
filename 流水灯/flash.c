#include <STC89.H>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char

uchar temp;
void delay(uint z){
	uint x,y;
	for(x=z;x>0;x--)
		for(y=114;y>0;y--);
}

void main(){
	temp=0xFE;
	P1=temp;
	delay(1000);
	while(1){
		temp=_crol_(temp,1); //循环左移
		P1=temp;
		delay(1000);
	}
}