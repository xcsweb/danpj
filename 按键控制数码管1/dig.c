#include <STC89C5xRC.H>
sbit DU=P2^6; //段选p26
sbit WE=P2^7; //位选p27
unsigned int keyValue=22;
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
void keyScan(){
	//矩阵键盘扫描
	P3=0xf0; //列扫描 1111 0000
	if(P3!=0xf0){
		Delay5ms();
		if(P3!=0xf0){
			switch(P3){
				case 0xe0:keyValue=1; //1110 0000
				break;
				case 0xd0:keyValue=2; //1101 0000
				break;
				case 0xb0:keyValue=3; //1011 0000
				break;
				case 0x70:keyValue=4; //0111 0000
				break;
			}
			P3=0x0f; //行扫描 0000 1111
			switch(P3){
				case 0x0e:keyValue=keyValue; //0000 1110
				break;
			case 0x0d:keyValue=keyValue+4; //0000 1101
				break;
			case 0x0b:keyValue=keyValue+8; //0000 1011
				break;
			case 0x07:keyValue=keyValue+12; //0000 0111
				break;
			}
			while(P3!=0x0f);
		}
	}
	//独立按键扫描
	P3=0xff;
	if(P3!=0xff){
		Delay5ms();
		if(P3!=0xff){
			switch(P3){
				case 0xfe:keyValue=16; //1111 1110
				break;
				case 0xfd:keyValue=17; //1111 1101
				break;
				case 0xfb:keyValue=18; //1111 1011
				break;
				case 0xf7:keyValue=19; //1111 0111
				break;
			}
			while(P3!=0xff);
		}
	}
}
void main(){
		P0=0xFF; //清除断码
		WE=1; //位选开启
		P0=0xFE; //选择第一个数码管1111 1110 14
		WE=0; //位选关闭
	while(1){
		keyScan();
		DU=1; //段选开启
		P0=leddata[keyValue]; //显示数字
		DU=0; //段选锁存器关闭
		
	}
}
