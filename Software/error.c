/*
          file: error.c
       project: SSX32 
   description: error status on the led

   Changelog:
      01/31/11 This file created


*/

void error_serOverflow(void)
{
	mForever
	  {
	  mLED(PW_LED,OFF);
	  delay_ms(100);
	  mLED(PW_LED,ON);
	  delay_ms(100);
	  }
}
