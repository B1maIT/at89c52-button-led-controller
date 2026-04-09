#include <REGX52.H>

void time_short (void)
 {
  unsigned int x,y;
  for(x=0;x<200;x++)
     for(y=0;y<100;y++);
 }
 
 void time_long (void)
 {
  unsigned int x,y;
  for(x=0;x<400;x++)
     for(y=0;y<100;y++);
 }
 
void main(void)
{
    unsigned char button_s;
    bit allow = 1;
    P2 = 0xFF; 
    P1 = 0xFF; 

    while(1)
    {
        button_s = P2 & 0x0F;
			
        if(button_s != 0x0F && allow)
        {
            allow = 0;
            switch(button_s)
            {
                case 0x0E: P1_0 = 0; time_short(); P1_0 = 1; break;
                case 0x0D: P1_1 = 0; time_short(); P1_1 = 1; break;
                case 0x0B: P1_2 = 0; time_long();  P1_2 = 1; break;
                case 0x07: P1_3 = 0; time_long();  P1_3 = 1; break;
            }		
        }
				
        if(button_s == 0x0F)
        {
            allow = 1;
        }
    }
}
						
						

	 