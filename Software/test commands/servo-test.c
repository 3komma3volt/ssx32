/*
          file: servo-test.c
       project: SSX32 
   description: preset some servos for testing

   Changelog:
      01/15/11 This file created


*/

void sevoTest(void)
{	
	servo[0].mode = MODE_NORMAL;
	servo[0].pwCurrent = 500;
	servo[0].pwDestination = 1500;
	servo[0].step = 10;
	servo[0].offset = 0;
	servo[0].home = 1500;

	servo[1].mode = MODE_NORMAL;
	servo[1].pwCurrent = 900;
	servo[1].pwDestination = 1500;
	servo[1].step = 5;
	servo[1].offset = 0;
	servo[1].home = 1500;

	servo[2].mode = MODE_COPY;
	servo[2].offset = 0;
	servo[2].step = 1;
	servo[2].home = 1500;
	servo[2].master = 0;
}
