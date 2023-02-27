#include <STC89.H>
unsigned int i;
void main()
{
	P1=0; //p1 light
	i=65535; 
	while(i--);
	P1=0xff;//dark
	i=65535;
	while(i--);
}