/*
          file: firstuse.c
       project: SSX32 
   description: setup eeprom for first use

   Changelog:
      01/15/11 This file created


*/




void setupFirstUse(void)
{
	int8 i;
	write_eeprom(EE_FIRSTUSE, 1);
	#ifdef DEBUG_MSG
	  puts("setupFirstUse()",debug);
	#endif
	mServoLoop
	  {
	  ee_writeHomePW(i,0);
	  ee_writeOffsetPW(i,0);
	  ee_writeMinPW(i,PW_MIN);
	  ee_writeMaxPW(i,PW_MAX);
	  }
}


void firstUse(void)
{
	if ( read_eeprom(EE_FIRSTUSE) == 0xFF ) {
	  setupFirstUse();
	  }
}
