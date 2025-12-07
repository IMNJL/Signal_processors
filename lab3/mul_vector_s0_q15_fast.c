#include <stdint.h>

// Оптимизированная версия функции умножения в формате Q15
void mul_vector_s0_q15_fast(int n, int16_t *dst, int16_t *src1, int16_t *src2) {
    for (int i = 0; i < n; i++) {
        int32_t product = (int32_t)src1[i] * (int32_t)src2[i];

        // Сдвиг на 15 бит и насыщение в одной строке
        dst[i] = (int16_t)((product > 32767 << 15) ? 32767 :
                           (product < -32768 << 15) ? -32768 :
                           (product >> 15));
    }
}
