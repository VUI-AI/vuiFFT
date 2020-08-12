# vuiFFT

/** Compute tables for an FFT */

void *vui_fft_init(int size);

/** Forward (real to half-complex) transform */

void vui_fft(void *table, float *in, float *out);

/** Backward (half-complex to real) transform */

void vui_ifft(void *table, float *in, float *out);
