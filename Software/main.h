/*
          file: main.h
       project: SSX32 
   description: selects correct pic device (header files) to use

   Changelog:
		09/17/11	Replaced original main.h file with this, and made
					each device, fuse, etc... its own pic-xxxx.h file


*/

#ifdef SSX32
	#include "pic-ssx32.h"
	#endif

#ifdef SSX16
	#include "pic-ssx16.h"
	#endif

#ifdef SSX8
	#include "pic-ssx8.h"
	#endif


#use rs232(baud=9600, bits=8, parity=n, stop=1, xmit=PIN_C6, rcv=PIN_C7, stream=ttls0)
#use rs232(baud=9600, bits=8, parity=n, stop=1, xmit=PIN_B7, rcv=PIN_B7, stream=debug)

