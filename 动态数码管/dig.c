#include <STC89C5xRC.H>
sbit DU=P2^6; //段选p26
sbit WE=P2^7; //位选p27
sbit PO0=P0^0;
void Delay5ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 9;
	j = 244;
	do
	{
		while (--j);
	} while (--i);
}

//数码管段选表
unsigned char code leddata[]={ 
                0x3F,  //"0"
                0x06,  //"1"
                0x5B,  //"2"
                0x4F,  //"3"
                0x66,  //"4"
                0x6D,  //"5"
                0x7D,  //"6"
                0x07,  //"7"
                0x7F,  //"8"
                0x6F,  //"9"
                0x77,  //"A"
                0x7C,  //"B"
                0x39,  //"C"
                0x5E,  //"D"
                0x79,  //"E"
                0x71,  //"F"
                0x76,  //"H"
                0x38,  //"L"
                0x37,  //"n"
                0x3E,  //"u"
                0x73,  //"P"
                0x5C,  //"o"
                0x40,  //"-"
                0x00,  //熄灭
                0x00  //自定义
 };
void display(unsigned int i){
	unsigned int bai=i/100;
	unsigned int shi=i%100/10;
	unsigned int ge=i%10;
	P0=0xFF; //清除断码
	WE=1; //位选开启
	P0=0xFE; //选择第一个数码管1111 1110 14
	WE=0; //位选关闭
	DU=1; //段选开启
	P0=leddata[bai]; //显示数字1
	DU=0; //段选锁存器关闭
	
	Delay5ms();
	P0=0xFF; //清除断码
	WE=1; //位选开启
	P0=0xFD; //选择第二个数码管1111 1101 8+4+1 13
	WE=0; //位选关闭
	DU=1; //段选开启
	P0=leddata[shi]; //显示数字2
	DU=0; //段选锁存器关闭
	
	Delay5ms();
	P0=0xFF; //清除断码
	WE=1; //位选开启
	P0=0xFB; //选择第二个数码管1111 1011 8+2+1 11
	WE=0; //位选关闭
	DU=1; //段选开启
	P0=leddata[ge]; //显示数字3
	DU=0; //段选锁存器关闭
	Delay5ms();
}

void main(){
	while(1){
		display(321);
	}
}