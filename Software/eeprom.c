/*
          file: eeprom.c
       project: SSX32 
   description: eeprom related code

   Changelog:
      01/15/11 I put eeprom related defines here so the defines.h file
				doesnt grow to big


*/


// eeprom related defines
#define EE_FIRSTUSE		0		// pointer to first use byte
#define	EE_BASE_HOME	32		// base address for servo home
#define	EE_BASE_OFFSET	64		// base address for servo home
#define EE_BASE_MIN		96		// base address for servo min
#define EE_BASE_MAX		128		// base address for servo max


int16 ee_readHomePW(int8 wServo)
{
	int16 addr;
	addr = EE_BASE_HOME + (wServo * 2);
	return read_eeprom(addr) + ( read_eeprom(addr + 1) * 256 );
}

void ee_writeHomePW(int8 wServo, int16 wVal)
{
	int16 addr;
	int8 lo, hi;

	addr = EE_BASE_HOME + (wServo * 2);

	lo = wVal & 0x00FF;
	hi = wVal >> 8;
	hi = hi & 0x00FF;

	write_eeprom(addr, lo);
    write_eeprom(addr + 1, hi);
}



int16 ee_readOffsetPW(int8 wServo)
{
	int16 addr;
	addr = EE_BASE_OFFSET + (wServo * 2);
	return read_eeprom(addr) + ( read_eeprom(addr + 1) * 256 );
}

void ee_writeOffsetPW(int8 wServo, int16 wVal)
{
	int16 addr;
	int8 lo, hi;

	addr = EE_BASE_OFFSET + (wServo * 2);

	lo = wVal & 0x00FF;
	hi = wVal >> 8;
	hi = hi & 0x00FF;

	write_eeprom(addr, lo);
    write_eeprom(addr + 1, hi);
}


int16 ee_readMinPW(int8 wServo)
{
	int16 addr;
	addr = EE_BASE_MIN + (wServo * 2);
	return read_eeprom(addr) + ( read_eeprom(addr + 1) * 256 );
}

void ee_writeMinPW(int8 wServo, int16 wVal)
{
	int16 addr;
	int8 lo, hi;

	addr = EE_BASE_MIN + (wServo * 2);

	lo = wVal & 0x00FF;
	hi = wVal >> 8;
	hi = hi & 0x00FF;

	write_eeprom(addr, lo);
    write_eeprom(addr + 1, hi);
}


int16 ee_readMaxPW(int8 wServo)
{
	int16 addr;
	addr = EE_BASE_MAX + (wServo * 2);
	return read_eeprom(addr) + ( read_eeprom(addr + 1) * 256 );
}

void ee_writeMaxPW(int8 wServo, int16 wVal)
{
	int16 addr;
	int8 lo, hi;

	addr = EE_BASE_MAX + (wServo * 2);

	lo = wVal & 0x00FF;
	hi = wVal >> 8;
	hi = hi & 0x00FF;

	write_eeprom(addr, lo);
    write_eeprom(addr + 1, hi);
}



// this writes any servo data to eeprom if needed
void ee_writeServoData(void)
{
	int8 i;
	#ifdef DEBUG_MSG
	  puts("ee_writeServoData()",debug);
	#endif
	mServoLoop
	  {

	  if (servo[i].writeOffset == true) {
	    ee_writeOffsetPW(i,servo[i].offset);
	    servo[i].writeOffset = false; 
		}

	  if (servo[i].writeHome == true) {
	    ee_writeHomePW(i,servo[i].home);
	    servo[i].writeHome = false; 
		}

	  if (servo[i].writeMin == true) {
	    ee_writeMinPW(i,servo[i].min);
	    servo[i].writeMin = false; 
		}

	  if (servo[i].writeMax == true) {
	    ee_writeMaxPW(i,servo[i].max);
	    servo[i].writeMax = false; 
		}

	  }

}