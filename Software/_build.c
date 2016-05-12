/*
          file: _build.c
       project: standard include
   description: Use for tracking build date and time and setting
                the output hex file name
   written by : Michael Bradley

   Changelog:
		    10/03/11 Modified for use with SSX 
            08/31/09 This module created


   USE:
      // optional, these control the hex file name
      #define _BUILD_PROJECT "Prj_Name"   
      #define _BUILD_VERSION "v1.0"

      #include "_build.c"
   
   REFERENCE:
   19 bytes of ROM are used to store the build date and time
   _build[] string format: "31-Aug-09 23:55:18"

*/


//const char _build[19] = {__DATE__ " " __TIME__};

#ifdef _BUILD_PROJECT
   #define _BUILD_FILE "bin/" _BUILD_PROJECT "-" _BUILD_VERSION "-" __DATE__ ".hex"
   #export (file=_BUILD_FILE, HEX)
#endif


