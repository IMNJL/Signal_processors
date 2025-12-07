#ifndef DSP_LECTURE_H
#define DSP_LECTURE_H

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

/* Include ARM headers when available. Use __has_include when supported. */
#if defined(__has_include)
# if __has_include(<arm_acle.h>)
#  include <arm_acle.h>
# endif
# if __has_include(<arm_neon.h>)
#  include <arm_neon.h>
# endif
#else
/* Older compilers: try the ARM headers unguarded (may fail to compile) */
# include <arm_acle.h>
# include <arm_neon.h>
#endif

/* Fallbacks: if the ARM types or intrinsics are not available, provide
 * small portable replacements so the example code compiles on hosts
 * without vendor headers. The fallbacks implement packed 16-bit
 * additions with saturation for two lanes (int16x2_t / __sadd16).
 */
#ifndef __INT16X2_T_DEFINED
typedef int32_t int16x2_t;
#define __INT16X2_T_DEFINED 1
#endif

#ifndef __SADD16_DEFINED
static inline int32_t __sadd16(int32_t a, int32_t b)
{
	int16_t a0 = (int16_t)(a & 0xFFFF);
	int16_t a1 = (int16_t)((a >> 16) & 0xFFFF);
	int16_t b0 = (int16_t)(b & 0xFFFF);
	int16_t b1 = (int16_t)((b >> 16) & 0xFFFF);
	int32_t r0 = (int32_t)a0 + (int32_t)b0;
	int32_t r1 = (int32_t)a1 + (int32_t)b1;
	if (r0 > INT16_MAX) r0 = INT16_MAX; else if (r0 < INT16_MIN) r0 = INT16_MIN;
	if (r1 > INT16_MAX) r1 = INT16_MAX; else if (r1 < INT16_MIN) r1 = INT16_MIN;
	return (int32_t)(((uint32_t)((uint16_t)r1) << 16) | (uint16_t)r0);
}
#define __SADD16_DEFINED 1
#endif

#define N_MAX 65535

typedef struct { int16_t real,imag; } cint16_t;
typedef struct { int32_t real,imag; } cint32_t;

void add_vector (int_fast16_t n, int16_t *dst, int16_t * src1, int16_t * src2);
void add_vector_ref (int_fast16_t n, int16_t *dst, int16_t * src1, int16_t * src2);
void add_vector_fast (int_fast16_t n, int16_t *dst, int16_t * src1, int16_t * src2);

#endif /* DSP_LECTURE_H */
