// ****************************************************************************
// * Copyright (C) 2018 VUI.AI inc. All rights reserved.
// *
// * Filename: vui_echo_smallft.h
// * Description: Echo small fft defines
// * Author:
// *
// ****************************************************************************



#ifndef __VUI_ECHO_SMALLFFT_H_
#define __VUI_ECHO_SMALLFFT_H_


#ifdef __cplusplus
extern "C" {
#endif

/** Discrete Rotational Fourier Transform lookup */
struct drft_lookup{
  int n;
  float *trigcache;
  int *splitcache;
};

extern void vui_drft_forward(struct drft_lookup *l,float *data);
extern void vui_drft_backward(struct drft_lookup *l,float *data);
extern void vui_drft_init(struct drft_lookup *l,int n);

#ifdef __cplusplus
}
#endif

#endif //__VUI_ECHO_SMALLFFT_H_
