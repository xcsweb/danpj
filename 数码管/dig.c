#include <STC89C5xRC.H>
sbit DU=P2^6; //段选p26
sbit WE=P2^7; //位选p27
sbit PO0=P0^0;
void main(){
	WE=1; //位选开启
	P0=0xFE; //选择第一个数码管
	WE=0; //位选关闭
	DU=1; //段选开启
	P0=0x06; //显示数字1
	DU=0; //段选锁存器关闭
	
}