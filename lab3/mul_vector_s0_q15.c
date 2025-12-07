#include <stdint.h>

// Основная функция умножения в формате Q15
void mul_vector_s0_q15(int n, int16_t *dst, int16_t *src1, int16_t *src2) {
    for (int i = 0; i < n; i++) {
        // Умножение двух Q15 чисел
        int32_t product = (int32_t)src1[i] * (int32_t)src2[i];

        // Сдвиг на 15 бит для масштабирования обратно в Q15
        int32_t result = product >> 15;

        // Ограничение результата в пределах Q15
        if (result > 32767) {
            dst[i] = 32767;
        } else if (result < -32768) {
            dst[i] = -32768;
        } else {
            dst[i] = (int16_t)result;
        }
    }
}
