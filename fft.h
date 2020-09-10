#ifndef FFT_H
#define FFT_H

typedef struct
{	
  int real;
  int imag;
} COMPLEX;


void fft_c(COMPLEX *x);

#endif
