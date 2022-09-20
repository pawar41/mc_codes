#include <REG51.h>

unsigned int lut[20]={0,10,17,25,35,42,50,57,65,71,77,82,87,91,95,97,99,100,100};

void delay_time(unsigned int time)
{
  unsigned int i,j; 
  for(i=time;i>0;i--)
  {
  	for(j=0;j<50;j++);
  }
    
}


void send_dac(unsigned int dat)
{
  P1 = temp;
}

void main(void)
{
  signed char ang=0;

   while(1)
   {
   				//0-90 deg
       for(ang = 0;ang < 90; ang+=5)
	  {
	   	send_dac(lut[ang/5]+0x7F);
	    delay_time(0);
	  }
				//90-180 deg
	   for(ang = 90;ang > 0; ang-=5)
	  {
	  	  	send_dac(lut[ang/5]+0x7F);
		   delay_time(0);
	  }
				//180-270 deg
	   for(ang = 0;ang < 90; ang+=5)
	  {
	  	  	send_dac(-lut[ang/5]-0x7F);
		   delay_time(0);
	  }

				 //270-360 deg
	   for(ang = 90;ang > 0; ang-=5)
	  {
	  	  	send_dac(-lut[ang/5]-0x7F);
		   delay_time(0);
	  }
	  
	}
}  

 /*
void main(void)
{
  signed char ang=0;

   while(1)
   {
   				//0-90 deg
     	  for(ang = 0;ang < 90; ang+=5)
	  {
	  	  	send_dac(lut[ang/5]);
		   delay_time(0);
	  }
				//90-180 deg
	   for(ang = 90;ang > 0; ang-=5)
	  {
	  	  	send_dac(lut[ang/5]);
		   delay_time(0);
	  }
				//180-270 deg
	   for(ang = 0;ang < 90; ang+=5)
	  {
	  	  	send_dac(-lut[ang/5]);
		   delay_time(0);
	  }

				 //270-360 deg
	   for(ang = 90;ang > 0; ang-=5)
	  {
	  	  	send_dac(-lut[ang/5]);
		   delay_time(0);
	  }
	}
}  
*/