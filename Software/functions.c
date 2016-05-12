/*
          file: functions.c
       project: SSX32 
   description: misc. functions

   Changelog:
      01/15/11 This file created


*/


void boundsCheck(int8 s)
{
	if ( servo[s].pwDestination < servo[s].min ) {
	  servo[s].pwDestination = servo[s].min;
	  }

	if ( servo[s].pwDestination > servo[s].max ) {
	  servo[s].pwDestination = servo[s].max;
	  }
}


void servoUpdateStep(int8 i)
{
	if ( servo[i].step == 0 )
	  {
	  servo[i].pwCurrent = servo[i].pwDestination;
	  //servo[i].pwCurrent = 1550; // testing
	  }
	else
	  {
	  if ( servo[i].pwCurrent < servo[i].pwDestination )
	    {
	    servo[i].pwCurrent = servo[i].pwCurrent + servo[i].step;
	    // this is in case of overshoot
	    if ( servo[i].pwCurrent > servo[i].pwDestination )
	      {
 		  servo[i].pwCurrent = servo[i].pwDestination;
		  }
	    }

	  if ( servo[i].pwCurrent > servo[i].pwDestination )
	    {
	    servo[i].pwCurrent = servo[i].pwCurrent - servo[i].step;
	    // this is in case of overshoot
	    if ( servo[i].pwCurrent < servo[i].pwDestination ) 
	      {
		  servo[i].pwCurrent = servo[i].pwDestination;
		  }
	    }
	  }

}


void servoCalcTimeOuts(void)
{
	int8 i;
	#ifdef DEBUG_MSG
	  puts("servoCalcTimeOuts()",debug);
	#endif
	mServoLoop
	  {
	  boundsCheck(i);
	  if ( servo[i].mode == MODE_NORMAL )
	    {
	    servoUpdateStep(i);
	    servo[i].timeOut = servo[i].pwCurrent;
		}
		
	  if ( servo[i].mode == MODE_COPY )
	    {
	    servo[i].timeOut = servo[servo[i].master].pwCurrent;
		}
		
	  if ( servo[i].mode == MODE_MIRROR )
	    {
	    if (servo[servo[i].master].pwCurrent > PW_CENTER)
		  {
		  servo[i].timeOut = PW_CENTER - (servo[servo[i].master].pwCurrent - PW_CENTER);
		  }
		else
		  {
		  servo[i].timeOut = (PW_CENTER - servo[servo[i].master].pwCurrent) + PW_CENTER;
		  }
		}

	  if ( servo[i].mode == MODE_FOLLOW )
	    {
		servo[i].pwDestination = servo[servo[i].master].pwCurrent;
	    servoUpdateStep(i);
	    servo[i].timeOut = servo[i].pwCurrent;
		}
	  }

	// apply offset
	servo[i].timeOut = servo[i].timeOut + servo[i].offset;
	//servo[i].timeOut = servo[i].timeOut; // testing
}



// we area actualy just sorting an index as to the order to turn off the PW
void servoSort(void)
{
	int8 i;
	int8 ndx;
	int8 flagSwap;

	#ifdef DEBUG_MSG
	  puts("servoSort()",debug);
	#endif
	
	mServoLoop 
	  {
	  sorted[i] = i;
	  }

	flagSwap = true;
	while (flagSwap == true)
	  {
	  flagSwap = false;
	  for (i=0; i<(MAX_SERVOS-1); i++) 
	    {
	    if ( servo[sorted[i]].timeout > servo[sorted[i+1]].timeout )
	      {
		  ndx = sorted[i];
		  sorted[i] = sorted[i+1];
		  sorted[i+1] = ndx;
		  flagSwap = true;
		  }
	    }
	  }

	#ifdef DEBUG_MSG
	  mServoLoop 
	    {
	    //fprintf(debug,"S: %02i:%02i T:%Li\r\n",i,sorted[i],servo[sorted[i]].timeout);
	    }	  
	#endif


}


// return the delta of two numbers
int16 retDelta(int16 a, int16 b)
{
	int16 delta;

	delta = 0;

	if (  a < b ) {
	  delta = b-a;
	  }

	if (  b < a ) {
	  delta = a-b;
	  }

	return delta;

}

// returns the step rate to complete a move over time
int16 retStepOverTime(int16 c, int16 d, int16 time)
{
	int16 factor;
	int16 res;
	
	factor = time / MS_FRAME;
	res = retDelta(c,d) / factor;
	return res;
}
