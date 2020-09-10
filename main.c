#include <stdio.h>
#include <stdlib.h>
#include "fft.h"
 

#define BUFFSIZE 256

short inBuf[BUFFSIZE];
FILE *inFileHdlr = NULL;
char inFilename[1024] = "test.raw";


int main(){

     inFileHdlr = fopen(inFilename, "rb");
     fread(inBuf, sizeof(short), BUFFSIZE, inFileHdlr);

     COMPLEX XXX[BUFFSIZE];

     for(int i=0; i<BUFFSIZE; i++)
     {
          XXX[i].real = inBuf[i]; //test value
          printf("%d   ", XXX[i].real);
     }

     fft_c(XXX);

     for(int i=0; i<BUFFSIZE; i++)
     {
          printf("%d   ", XXX[i].real);
          printf("%d\n", XXX[i].imag);
     }

     return 0;

}
