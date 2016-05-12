/*
          file: serial.c
       project: SSX32
   description: handles the serial uart, and isr routines

   Changelog:
      01/15/11 some of this code copied from another project, hence my ttls0 names


*/


#define SERIAL_STR_SIZE 255
#define SERIAL_FIFO_SIZE 255


char serFifo_ttls0[SERIAL_FIFO_SIZE];
unsigned int8 serFifoPntr_ttls0;

char serStrBuffer_ttls0[SERIAL_STR_SIZE];
unsigned int8 serBuffPntr_ttls0;

int1 flagSerOverFlow_ttls0;
int8 cntSerHasStrings_ttls0;

int1 serIsChrReady_ttls0(void);
int1 serIsStrReady_ttls0(void);
int8 serGetChr_ttls0(void);
void serFlushFifo_ttls0(void);
void serGetStr_ttls0(void);


// internal serial port
#int_RDA
void  isr_serRx_ttls0(void)
{
   char data;

   while( kbhit(ttls0) )
   {
   data = fgetc(ttls0);
   if (serFifoPntr_ttls0 < SERIAL_FIFO_SIZE)
     {
     if (data == 0x0D) { cntSerHasStrings_ttls0++; }
     if (data != 0x0A)
	   {
	   serFifo_ttls0[serFifoPntr_ttls0] = data;
       serFifoPntr_ttls0++;
       serFifo_ttls0[serFifoPntr_ttls0] = 0x00;
	   }
     }

   if (serFifoPntr_ttls0 == SERIAL_FIFO_SIZE)
     {
     flagSerOverFlow_ttls0 = TRUE;
     serFlushFifo_ttls0();
	 error_serOverflow();
     }
   }

}



void serFlushFifo_ttls0(void)
{
   serFifoPntr_ttls0 = 0;
   cntSerHasStrings_ttls0 = 0;
   flagSerOverFlow_ttls0 = FALSE;
   serStrBuffer_ttls0[0] = 0x00;
}


int1 serIsChrReady_ttls0(void)
{
   int1 res;
   //puts("serIsChrReady()");
   res = FALSE;
   if (serFifoPntr_ttls0 > 0) {
     res = TRUE;
     }
   return res;
}

int1 serIsStrReady_ttls0(void)
{
   int1 res;
   res = FALSE;
   if ( cntSerHasStrings_ttls0 > 0) {
     res = TRUE;
     }
   return res;
}


int8 serGetChr_ttls0(void)
{
   int8 res;
   int8 i;

   //disable_interrupts(INT_RDA);
   //puts("serGetChr()");
   while (serIsChrReady_ttls0() == 0); // wait for a chr
   res = serFifo_ttls0[0];  // get first chr
   if (res == 0x0D) { cntSerHasStrings_ttls0--; }
   //puts("serGetChr() - chr received");
   //putc(res);
   // rotate the fifo buffer
   for (i=0; i < serFifoPntr_ttls0; i++) {
     serFifo_ttls0[i] = serFifo_ttls0[i+1];
     }
   serFifoPntr_ttls0--;
   //putc(TERM_XON);
   //enable_interrupts(INT_RDA);
   return res;
}



void serGetStr_ttls0(void)
{
   char data;
   int1 flagExit;

   flagExit = 0;
   serBuffPntr_ttls0 = 0;
   serStrBuffer_ttls0[0] = 0x00;

   while (flagExit == 0)
     {
     data = serGetChr_ttls0();

     if (data == 0x0D) {
       flagExit = 1;
       }

     if ( (data > 0x19) && (serBuffPntr_ttls0 < SERIAL_STR_SIZE) ) {
       serStrBuffer_ttls0[serBuffPntr_ttls0] = data;
       serBuffPntr_ttls0++;
       serStrBuffer_ttls0[serBuffPntr_ttls0] = 0x00;
       }

     }

   //printf("serGetStr_res:%s:\r\n",serStrBuffer);

}


