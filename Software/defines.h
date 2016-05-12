/*
          file: defines.h
       project: SSX32 
   description: some defines
   
   Changelog:
	  09/17/11 Allowed adressing multiple devices with same ID
	  01/25/11 Moved pin defs to new file (pins.h)
      01/15/11 This file created


*/


// this is the @daisy ID for this project
#ifdef SSX32
	#define DEVICE_ID		"@SSX32"
	#define _BUILD_PROJECT "SSX32" 
	#define	MAX_SERVOS		32		// number of servos this for this controller
	#define BANK0_S			0
	#define BANK0_E			7
	#define BANK1_S			8
	#define BANK1_E			15
	#define BANK2_S			16
	#define BANK2_E			23
	#define BANK3_S			24
	#define BANK3_E			31
	#endif

#ifdef SSX16
	#define DEVICE_ID		"@SSX16"
	#define _BUILD_PROJECT "SSX16" 
	#define	MAX_SERVOS		16		// number of servos this for this controller
	#define BANK0_S			0
	#define BANK0_E			7
	#define BANK1_S			8
	#define BANK1_E			15
	#endif

#ifdef SSX8
	#define DEVICE_ID		"@SSX8"
	#define _BUILD_PROJECT "SSX8" 
	#define	MAX_SERVOS		8		// number of servos this for this controller
	#define BANK0_S			0
	#define BANK0_E			7
	#endif






#define FRAME_RATE		32000	// .5 uSec steps for frame rate. 16ms is a fast for analogs
#define MS_FRAME		16		// mSec in a frame (used to compute moves over time)

//#define FRAME_RATE		40000	// .5 uSec steps for frame rate. 16ms is a fast for analogs
//#define MS_FRAME		20		// mSec in a frame (used to compute moves over time)


#define PW_CENTER		1500	// uSec for servo center (I know, some are 1520, get over it)
#define PW_MIN			800		// default min/max
#define PW_MAX			2200

// misc defines
#define LOW				0
#define HIGH			1

#define OFF				0
#define ON				1

// mode of operation for the servos
#define MODE_OFF		0x00
#define MODE_NORMAL		0x01
#define MODE_COPY		0x02
#define MODE_MIRROR		0x03
#define MODE_FOLLOW		0x04


#define FRAME_WAIT		0x01
#define FRAME_ALLOFF	0x02


// some macros
#define mForever		for(;;)
#define mServoLoop		for (i=0; i<MAX_SERVOS; i++)


#define mOutputSXHigh(i)		output_high(servoPins[i])
#define mOutputSXLow(i)			output_low(servoPins[i])
#define mOutputDiscrete(i)		output_bit(servoPins[i], servo[i].discrete)

#define mBeginFrame		set_timer1(0);
#define mWaitFrame		while(get_timer1() < FRAME_RATE); 		// important ; at end of line


#define mLED(pin,s)		output_bit(pin,s)

#ifndef CMP_EQ
   #define CMP_LT -1
   #define CMP_EQ 0
   #define CMP_GT 1
   #endif





