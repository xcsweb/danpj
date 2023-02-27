#include <STC89.H>
sbit PO0=P0^0;
sbit key_s2=P3^0;
sbit flag=P3^7;
void Delay20ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 36;
	j = 217;
	do
	{
		while (--j);
	} while (--i);
}


void int1() interrupt 2{
	P1=~P1;
}

 
void main()
{
	EA=1; //开总中断
	EX1=1;//开外部中断1
	IT1=1;//外部中断1下降沿触发
	while(1){
		if(key_s2==0){
			//按键按下
			Delay20ms();//按键按下去除波形抖动
			if(key_s2==0){
				flag=1;
				flag=0;
				while(!key_s2); //按键弹起
			}
		}
	}
}