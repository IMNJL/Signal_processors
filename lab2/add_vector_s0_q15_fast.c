#include <stdint.h>

// Оптимизированная версия функции сложения в формате Q15
void add_vector_s0_q15_fast(int n, int16_t *dst, int16_t *src1, int16_t *src2) {
    for (int i = 0; i < n; i++) {
        int32_t sum = (int32_t)src1[i] + (int32_t)src2[i];

        // Ограничение результата
        dst[i] = (int16_t)((sum > 32767) ? 32767 : (sum < -32768 ? -32768 : sum));
    }
}
