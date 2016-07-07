/*
          file: main.c
       project: SSX32
	   version: 1.1
              : Open source 32/16/8 channel serial servo controller
			  : using a daisy chain protocol
   description: Main source file
   written by : Michael Bradley

	       PIC: 18F46K20 (SSX32) and PIC18F26K20 (SSX16 and SSX8)
	       IDE: Programers Notepad
	  compiler: CCS C v 4.106
       crystal: none (internal rc)

   Changelog:
	  09/17/11 Created 32/16/8 ch versions and added addressing
	  02/25/11 Added sin mode, and #include <math.h>
      01/15/11 This file created


*/

#define _BUILD_VERSION "v1.1"

// **** SELECT PRODUCT HERE 8/16/32 ****
// this is is for the conditional compiling!

#define SSX32
//#define SSX16
//#define SSX8



//#define DEBUG_MSG 1
//#define DEBUG_INPUT 1
//#define DEBUG_PRESET 1
//#define DEBUG_FRAMES 1
//#define DEBUG_ECHO 1

#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "defines.h"
#include "_build.c"
#include "pins.h"
#include "globals.h"
#include "functions.c"
#include "error.c"
#include "eeprom.c"
#include "firstuse.c"
#include "serial.c"
#include "input.c"
#include "frame.c"
#include "boot.c"

#ifdef DEBUG_PRESET
  #include "servo-test.c"
  #endif

void main()
{
	#ifdef DEBUG_FRAMES
	  int8 frameCount;
	  frameCount = 0;
	  #endif

	//delay_ms(2000); // used durring debugging
	boot();

	#ifdef DEBUG_PRESET
	  sevoTest();
	  #endif

	#ifdef DEBUG_MSG
	  puts("Entering loop",debug);
	  #endif
	  
	mForever
      {
	  if (flagAllOff == false)
	    {
	    servoCalcTimeOuts();		// calc the timeouts for each servo
	    servoSort();				// sort the timeout order
	    mWaitFrame;					// wait for end of prior frame
	    mBeginFrame;				// start of frame
	    outputFrame();				// output the frame
		#ifdef DEBUG_FRAMES
	      frameCount++;
		  if (frameCount == 10) { for(;;); } // stop if we hit 4 frames
	      #endif
		}
	  procInput();					// process any input that may have come in
	  ee_writeServoData();			// we write servo data to eeprom outside of a frame
      }


}
