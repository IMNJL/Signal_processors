#include <stdint.h>

// Основная функция сложения в формате Q15
void add_vector_s0_q15(int n, int16_t *dst, int16_t *src1, int16_t *src2) {
    for (int i = 0; i < n; i++) {
        int32_t sum = (int32_t)src1[i] + (int32_t)src2[i];

        // Насыщение (ограничение значения)
        if (sum > 32767) {
            dst[i] = 32767;
        } else if (sum < -32768) {
            dst[i] = -32768;
        } else {
            dst[i] = (int16_t)sum;
        }
    }
}
