#include "dsp-lecture.h"

void
add_vector_ref (int_fast16_t n, int16_t *dst, int16_t * src1, int16_t * src2)
{
  int_fast16_t i;
  for (i=0; i<n; i++)
    dst[i] = src1[i] + src2[i];
}


