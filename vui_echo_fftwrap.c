// ****************************************************************************
// * Copyright (C) 2018 VUI.AI inc. All rights reserved.
// *
// * Filename: fftwrap.c
// * Description: c file
// * Author:
// *
// ****************************************************************************


#include <stdio.h>
#include <stdlib.h>
#define MAX_FFT_SIZE 2048

#include "vui_echo_smallft.h"
#include <math.h>

void *vui_fft_init(int size)
{
   struct drft_lookup *table;
   table = calloc(sizeof(struct drft_lookup), 1);
   vui_drft_init((struct drft_lookup *)table, size);
   return (void*)table;
}

void vui_fft(void *table, float *in, float *out)
{
   if (in==out)
   {
      int i;
      printf("FFT should not be done in-place");
      float scale = (float)(1./((struct drft_lookup *)table)->n);
      for (i=0;i<((struct drft_lookup *)table)->n;i++)
         out[i] = scale*in[i];
   } else {
      int i;
      float scale = (float)(1./((struct drft_lookup *)table)->n);
      for (i=0;i<((struct drft_lookup *)table)->n;i++)
         out[i] = scale*in[i];
   }
   vui_drft_forward((struct drft_lookup *)table, out);
}

void vui_ifft(void *table, float *in, float *out)
{
   if (in==out)
   {
      printf("FFT should not be done in-place");
   } else {
      int i;
      for (i=0;i<((struct drft_lookup *)table)->n;i++)
         out[i] = in[i];
   }
   vui_drft_backward((struct drft_lookup *)table, out);
}


