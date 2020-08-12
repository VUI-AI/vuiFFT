// ****************************************************************************
// * Copyright (C) 2018 VUI.AI inc. All rights reserved.
// *
// * Filename: vui_echo_fftwrap.h
// * Description: Echo FFT wrapper functions
// * Author:
// *
// ****************************************************************************



#ifndef __VUI_ECHO_FFTWRAP_H_
#define __VUI_ECHO_FFTWRAP_H_


/** Compute tables for an FFT */
void *vui_fft_init(int size);

/** Forward (real to half-complex) transform */
void vui_fft(void *table, float *in, float *out);

/** Backward (half-complex to real) transform */
void vui_ifft(void *table, float *in, float *out);

#endif //__VUI_ECHO_FFTWRAP_H_

