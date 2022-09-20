#include <REG51.h>
void delay_time(unsigned int time)
{
  unsigned int i,j; 
  for(i=time;i>0;i--)
  {
  	for(j=0;j<20;j++);
  }
    
}

void delay_ramp(unsigned int time)
{
  unsigned int i; 
  for(i=time;i>=0;i--);
     
}


void send_dac(unsigned int dat)
{
	P1 = temp;
}
void main(void)
{
  unsigned int a,state=0xFF;

   while(1)
   {
  	// rising ramp edge
	 for(a=0;a<0xFF;a++)
	 {
	 	send_dac(a);
	//	delay_ramp(0);
	 }
  	// high state
	 send_dac(0xFF);
	 delay_time(100);
  	// falling ramp edge
	 for(a=0xFF;a>0;a--)
	 {
	 	send_dac(a);
	//	delay_ramp(0);
	 }
  	// low state
  	 send_dac(0x00);
	 delay_time(100); 
	}
}
