  #include<REG51.h>

void delay_time(unsigned int time)
{
  unsigned int i,j; 
  for(i=time;i>0;i--)
  {
  	for(j=0;j<2000;j++);
  }
 
    
}

void send_dac(unsigned int dat)
{
	P1 = dat;
}


void main(void)
{
 unsigned int delay=0xFF;
 unsigned char state=0xFF;
 send_dac(0x7F);
 while(1)
 {
	send_dac(state);
	delay_time(delay);
    send_dac(~state);
	delay_time(delay); 
 }
}
