#include <STC89.H>
sbit DIO=P3^4;
sbit S_CLK=P3^5; //移位寄存器时钟
sbit R_CLK=P3^6; //输出锁存器时钟
unsigned char arr[]={0xFF,0x93,0x01,0x83,0xC7,0xEF,0xFF,0xFF};
void sendByte(unsigned char dat){
	unsigned int i;
	R_CLK=0;
	for(i=0;i<8;i++){
		S_CLK=0;
		if(dat&0x01){
			//按位与，和0x01与，得到值位0x01或者0x00,0x01为真,0x00为假
			DIO=1;
		}else{
			DIO=0;
		}
		dat>>=1;//右移，让DIO取最后一位,
		S_CLK=1;
	}
}
//行特别注意点阵屏高位在上，只需要一行高电平比如0x80(1000000)
//列特别注意本来都是高电平，只需要一个低电平显示0xfe(0111111),最高位在点阵屏最右
void main(){
		unsigned int i;
		//逐行输出高电平
		unsigned char row;
		while(1){
			row=0x80;//1000 0000
			for(i=0;i<8;i++){
				sendByte(arr[i]);
				sendByte(row);
				row>>=1;//进行右移
				R_CLK=1; //输出完成1个字
			}
		}
}
