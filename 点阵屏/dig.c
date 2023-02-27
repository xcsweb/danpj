#include <STC89.H>
sbit DIO=P3^4;
sbit S_CLK=P3^5; //移位寄存器时钟
sbit R_CLK=P3^6; //输出锁存器时钟
void main(){
		unsigned int i;
		unsigned char dat;
		dat=0xfe; //11111110
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
		dat=0x80;
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
		R_CLK=1;
		while(1);
}
