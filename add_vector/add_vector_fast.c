#include "dsp-lecture.h"

void
add_vector_fast (int_fast16_t n, int16_t *dst, int16_t * src1, int16_t * src2)
{
  int_fast16_t i;

  int16x2_t * src1x2 = (int16x2_t *) src1;
  int16x2_t * src2x2 = (int16x2_t *) src2;
  int16x2_t * dstx2 = (int16x2_t *) dst;
  
  for (i=0; i<n; i+=2) {
    assert ((int16_t*)src1x2 == src1+i);
    assert ((int16_t*)src2x2 == src2+i);
    assert ((int16_t*)dstx2 == dst+i);
    *dstx2++ = __sadd16(*src1x2++, *src2x2++);
  }
  if (i<n)
    dst[i] = src1[i] + src2[i];
}


