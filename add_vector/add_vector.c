#include "dsp-lecture.h"

#include <stdio.h>

void
add_vector (int_fast16_t n, int16_t * dst, int16_t * src1, int16_t * src2)
{
  int_fast16_t i;
  
  int16_t * ref = (int16_t *) alloca (n*sizeof(int16_t));

  add_vector_ref(n, ref, src1, src2);
  add_vector_fast(n, dst, src1, src2);

  for (i=0; i<n; i++)
    if (dst[i] != ref[i]) {
      fprintf (stderr, "Error: dst[%d] ref=0x%4.4x res=0x%4.4x\n",
	       i, ref[i], dst[i]);
      exit(1);
    }

}
