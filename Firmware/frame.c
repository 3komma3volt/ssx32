/*
          file: frame.c
       project: SSX32 
   description: outputs the servo frame
				starts all outputs at once, and turns off at end of each pw,
				this will actualy stager the motor start slightly from one another,
				and allows for driving 32 servos in a single frame [of time]
   
   Changelog:
	  02/03/11 Split frame into groups, having issues with timming
      01/15/11 This file created


*/



void outputGroup(int8 s, int8 e)
{
	int8 i;
	int8 ndx;

	set_timer0(0);	// set the pw timer to 0
	
	for (i=s;i<=e;i++)
	  {
	  ndx = sorted[i];
	  mOutputSXHigh(ndx);
	  }

	  // here we follow our sorted index for the order of the servos
	for (i=s;i<=e;i++)
	  {
	  ndx = sorted[i];
	  while( get_timer0() < servo[ndx].timeout );  // just wait for this period, notice the ; at the end
	  mOutputSXLow(ndx);
	  }	  
	  
}



// This is a little sad looking, but I had to output in groups of 4 servos
// this is used to allow servos to come on at different times, and
// to tell you the truth, I was having a hard time with later pw servos
// waiting for others to turn off.
void outputFrame(void)
{
	outputGroup(0,3);
	outputGroup(4,7);
	outputGroup(8,11);
	outputGroup(12,15);
	outputGroup(16,19);
	outputGroup(20,23);
	outputGroup(24,27);
	outputGroup(28,31);
}




