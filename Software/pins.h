/*
          file: pins.h
       project: SSX32 
   description: pin defines
   
   Changelog:
	  09/17/11 Updated for 8/16/32 chanel devices
      01/25/11 This file created


*/


// power led
#ifdef SSX32
	#define PW_LED	PIN_C5
	#endif

#ifdef SSX16
	#define PW_LED	PIN_C5
	#endif

#ifdef SSX8
	#define PW_LED	PIN_C5
	#endif


// servo output pins
#ifdef SSX32
const int16 servoPins[MAX_SERVOS] = {
					PIN_D4, PIN_D5, PIN_D6, PIN_D7, PIN_B0, PIN_B1, PIN_B2, PIN_B3,
					PIN_B4, PIN_B5, PIN_B6, PIN_B7, PIN_A0, PIN_A1, PIN_A2, PIN_A3,
					PIN_C4, PIN_D3, PIN_D2, PIN_D1, PIN_D0, PIN_C3, PIN_C2, PIN_C1,
					PIN_C0, PIN_A6, PIN_A7, PIN_E2, PIN_E1, PIN_E0, PIN_A5, PIN_A4
					} ;
#endif

#ifdef SSX16
const int16 servoPins[MAX_SERVOS] = {
					PIN_A0, PIN_A1, PIN_A2, PIN_A3, PIN_A4, PIN_A5, PIN_A7, PIN_A6,
					PIN_C0, PIN_C1, PIN_C2, PIN_C3, PIN_C4, PIN_B0, PIN_B1, PIN_B2,
					} ;
#endif

#ifdef SSX8
const int16 servoPins[MAX_SERVOS] = {
					PIN_A0, PIN_A1, PIN_A2, PIN_A3, PIN_A4, PIN_A5, PIN_A7, PIN_A6,
					} ;
#endif
