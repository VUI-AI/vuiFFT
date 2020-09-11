#vuifft
input stucture:

typedef struct
{	
  int real;
  int imag;
} COMPLEX;

This program will read a raw data audio file and do fft in-place
The in buffer parameter in test.raw contains stereo raw pcm data, format of 16k sampling rate, 16bit little-endian integer.

After fft process, the program will print real and image value for first frame. 