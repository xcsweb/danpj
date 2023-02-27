#include <STC89.H>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit beep=P2^3;


void main(){
	delay(1000);
	while(1){
		beep=~beep;
		delay(1000);
	}
}