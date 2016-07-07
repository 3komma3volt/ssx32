/*
          file: boot.c
       project: SSX32 
   description: bootup code

   Changelog:
      01/15/11 This file created


*/


void boot(void)
{
	int8 i;

	#ifdef DEBUG_MSG
	  puts("Boot",debug);
	#endif
	
	setup_adc_ports(NO_ANALOGS|VSS_VDD);
	setup_adc(ADC_CLOCK_DIV_2|ADC_TAD_MUL_0);
	//setup_psp(PSP_DISABLED);	pic18f46k20 only
	setup_spi(SPI_SS_DISABLED);
	setup_wdt(WDT_OFF);
	setup_timer_0(RTCC_INTERNAL|RTCC_DIV_16);	// set for 1uSec resolution
	setup_timer_1(T1_INTERNAL|T1_DIV_BY_8); // note, 2x resolution .5uSec
	setup_timer_2(T2_DISABLED,0,1);
	setup_timer_3(T3_DISABLED|T3_DIV_BY_1);
	setup_ccp1(CCP_OFF);
	setup_comparator(NC_NC_NC_NC);
	//setup_oscillator(OSC_16MHZ|OSC_INTRC|OSC_PLL_ON); // defunc, replaced by #use delay(clock=xx)
 
 
	mLED(PW_LED,ON);

	firstUse();	// check if first use, and do stuff if it is

	// set some defaults all all servos
	mServoLoop
	  {
	  servo[i].mode = MODE_OFF;
	  servo[i].pwCurrent = PW_CENTER;
	  servo[i].pwDestination = PW_CENTER;
	  servo[i].step = 0;
	  servo[i].decel = false;
	  servo[i].offset = ee_readOffsetPW(i);
	  servo[i].home = ee_readHomePW(i);
	  servo[i].min = 800;
	  servo[i].max = 2200;
	  servo[i].writeOffset = false;
	  servo[i].writeHome = false;
	  servo[i].writeMin = false;
	  servo[i].writeMax = false;
	  servo[i].master = 0;
	  servo[i].discrete = 0;
	  servo[i].timeOut = 0;
	  
	  if (servo[i].home != 0)
	    {
		servo[i].mode = MODE_NORMAL;
		}
	  }
 
 
	flagAllOff = true;
	
	//setup_uart(9600, ttls0);
	setup_uart(19200, ttls0);
	//setup_uart(38400, ttls0);
	serFlushFifo_ttls0();		// flush/ini the serial drivers

	enable_interrupts(INT_RDA);
	enable_interrupts(GLOBAL);
 
 }