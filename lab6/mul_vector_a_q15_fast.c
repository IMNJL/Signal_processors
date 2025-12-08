#include <stdint.h>

void mul_vector_a_q15_fast(int n, int32_t *dst, int16_t *src1, int16_t *src2) {
    for (int i = 0; i < n; i++) {
        dst[i] = __builtin_mul_overflow((int32_t)src1[i], (int32_t)src2[i], &dst[i]) ? 0x7FFFFFFF : dst[i];
    }
}
