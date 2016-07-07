/*
          file: globals.h
       project: SSX32 
   description: global variables

   Changelog:
      01/15/11 This file created


*/



struct strServo
{
	int8			mode;				// current mode for this servo
	int16			pwCurrent;			// current pw
	int16			pwDestination;		// desired pw
	int16			step;				// uSec step value per second
	int8			decel;				// flag for deceleration
	signed int16	offset;				// offset value
	int16			home;				// home position
	int16			min;				// min pw
	int16			max;				// max pw
	int8			writeOffset;		// flag if we need to write offset value
	int8			writeHome;			// flag if we need to write home value
	int8			writeMin;			// flag if we need to write min values
	int8			writeMax;			// flag if we need to write min values
	int8			master;				// used for follow or mirror
	int8			discrete;			// discrete value, if discrete mode
	int16			timeOut;			// used to denote when to end pw. also alows update durring frame
} ;


struct strServo	servo[MAX_SERVOS];

int8	sorted[MAX_SERVOS];		// holds a list of servos, in order, for PW to be turned off

// these are used durring input parseing
int8	modalServo;
int16	modalTime;
int8	flagAllOff;
int8	flagSin;