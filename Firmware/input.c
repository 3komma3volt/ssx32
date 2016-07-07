/*
          file: input.c
       project: SSX32
   description: processing of the input strings

   Changelog:
	  02/25/11 added the SIN function/command !SIN
      01/15/11 this file created


*/


#define PARAM_SIZE	20		// max param string size
char strParam[PARAM_SIZE];

int8 ndxPointer;
int8 flagFinished;


void shiftParam(void)
{
	char c;
	int8 i;

	#ifdef DEBUG_INPUT
	  fprintf(ttls0,"shiftParam(%s:",strParam);
	#endif
	
	i=1;
	c = strParam[i];
	while (c != 0x00)
	  {
	  strParam[i-1] = c;
	  i++;
	  c = strParam[i];
	  }
	  strParam[i-1] = 0x00;

	#ifdef DEBUG_INPUT
	  fprintf(ttls0,"%s)\r\n",strParam);
	#endif
	  
}

void parseSubStr(void)
{
	int8 i;
	char p;
	signed int16 val;
	float sinVal;
	int16 sinCenter;
	
	#ifdef DEBUG_INPUT
	  fprintf(ttls0,"parseSubStr(%s)\r\n",strParam);
	#endif
	
	p = strParam[0];
	shiftParam();	// kill leading chr.
	val = atol(strParam);
	
	#ifdef DEBUG_INPUT
	  fprintf(ttls0,"(value=%Li)\r\n",val);
	#endif
	
	switch (p)
	  {
		case '#':
			modalServo = val-1;	// since our board silkscreen is numbered 1-32, we -1
			break;

		case 'T':
			modalTime = val;
			break;

		case 'P':
			servo[modalServo].mode = MODE_NORMAL;
			if (flagSin == true)
			  {
			  // is !SIN mode is on, then readjust the value
			  //fprintf(ttls0,"(value=%Li)\r\n",val);
			  sinCenter = ( (servo[modalServo].max - servo[modalServo].min) / 2 ) + servo[modalServo].min;
			  //fprintf(ttls0,"sinCenter: %Li\r\n",sinCenter);
			  sinVal = sin(val/57.2957795);
			  //fprintf(ttls0,"sinVal: %f\r\n",sinVal);
			  val = (sinVal * (servo[modalServo].max - sinCenter) ) + sinCenter;
			  }
			//fprintf(ttls0,"(value=%Li)\r\n",val);
			servo[modalServo].pwDestination = val;
			boundsCheck(modalServo);
			if ( modalTime !=0 )
			  {
			  // set a step size based on modal time
			  servo[modalServo].step = retStepOverTime(servo[modalServo].pwCurrent,servo[modalServo].pwDestination,modalTime);			  
			  }
			break;

		case 'I':
			servo[modalServo].pwDestination += val;
			boundsCheck(modalServo);
			break;

		case '-':
			servo[modalServo].min = val;
			servo[modalServo].writeMin = true;
			boundsCheck(modalServo);
			break;

		case '+':
			servo[modalServo].max = val;
			servo[modalServo].writeMax = true;
			boundsCheck(modalServo);
			break;

		case 'S':
			servo[modalServo].step = val;
			break;

		case 'C':
			servo[modalServo].mode = MODE_COPY;
			servo[modalServo].master = val-1;
			break;

		case 'F':
			servo[modalServo].mode = MODE_FOLLOW;
			servo[modalServo].master = val-1;
			break;

		case 'M':
			servo[modalServo].mode = MODE_MIRROR;
			servo[modalServo].master = val-1;
			break;

		case 'O':
			servo[modalServo].offset = val;
			servo[modalServo].writeOffset = true;
			break;

		case 'H':
			servo[modalServo].home = val;
			servo[modalServo].writeHome = true;
			break;

		case 'R':
			servo[modalServo].pwDestination = servo[modalServo].home;
			break;

		case '!':
			if ( strcmp(strParam, "DON") == CMP_EQ )
			  {
			  servo[modalServo].decel = true;
			  }
			if ( strcmp(strParam, "ON") == CMP_EQ )
			  {
			  flagAllOff = false;
			  }
			if ( strcmp(strParam, "OFF") == CMP_EQ )
			  {
			  flagAllOff = true;
			  mServoLoop
			    {
			    servo[modalServo].mode = MODE_OFF;
			    }
			  }
			if ( strcmp(strParam, "HOME") == CMP_EQ )
			  {
			  flagAllOff = false;
			  mServoLoop
			    {
			    servo[modalServo].mode = MODE_NORMAL;
				servo[modalServo].pwCurrent = servo[modalServo].home;
				servo[modalServo].pwDestination = servo[modalServo].home;
			    }
			  }
			if ( strcmp(strParam, "SIN") == CMP_EQ )
			  {
			  //fprintf(ttls0,"SIN MODE\r\n");
			  flagSin = true;
			  }
			break;

	  }
	
}


void getSubStr(void)
{
	char c;
	int8 i;

	#ifdef DEBUG_INPUT
	  fprintf(ttls0,"getSubStr(%i)\r\n",ndxPointer);
	#endif

	i = 0;
	c = serStrBuffer_ttls0[ndxPointer];
	while ( (c != 0x20) && (c != 0x00) )
	  {
	  strParam[i] = c;
	  strParam[i+1] = 0x00;
	  i++;
	  ndxPointer++;
	  c = serStrBuffer_ttls0[ndxPointer];
	  }
	ndxPointer++; // point to chr after space
	if (c == 0x00)
	  {
	  flagFinished = true;
	  }

}



void parseInput(void)
{
	unsigned int8 ttl;
	#ifdef DEBUG_INPUT
	  puts("parseInput()",ttls0);
	#endif
	serGetStr_ttls0();	// get string into buffer
	ndxPointer = 0;
	flagSin = false;	// this is only valid once per line
	flagFinished = false;

	#ifdef DEBUG_ECHO
	  fprintf(ttls0,"parseInput(%s)\r\n",serStrBuffer_ttls0);
	#endif
	

	// is it addressed to this device?
	getSubStr();		// get the first substr
	if ( strcmp(strParam, DEVICE_ID) != CMP_EQ )
	  {
	  // since its not this device, send out buffer
	  fprintf(ttls0,"%s\r\n",serStrBuffer_ttls0);
	  flagFinished = true;
	  }

	// at this point, right device, right address?
	getSubStr();		// get the first substr
	if ( strcmp(strParam, "$1") != CMP_EQ )
	  {
	  // not right address, so decriment address.
	  strParam[0] = '0';	// replaces $ with 0, so $24 will read 025
	  ttl = atoi(strParam) - 1;
	  //send out device ID and new TTL address
	  fprintf(ttls0,"%s ", DEVICE_ID);
	  fprintf(ttls0,"$%ui", ttl);
	  // loop through and send out all paramaters on this command
	  while (flagFinished == false)
	    {
	    getSubStr();	// get the substr, each item is seperated by a space
	    fprintf(ttls0,"%s ",strParam);
	    }
	    fprintf(ttls0,"\r\n");	// end of command
	  }
	


	modalTime = 0;
	modalServo  = 0;
	while (flagFinished == false)
	  {
	  getSubStr();		// get the substr, each item is seperated by a space
	  parseSubStr();	// parse the substr
	  }
}


void procInput(void)
{
	#ifdef DEBUG_INPUT
	  //puts("procInput()",ttls0);
	#endif
	if (serIsStrReady_ttls0() == true) {
	  parseInput();
	  }

}



