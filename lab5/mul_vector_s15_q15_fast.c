#include <stdint.h>

void optimized_multiply(int n, int16_t *result, int16_t *vector1, int16_t *vector2) {
    for (int i = 0; i < n; i++) {
        int32_t product = (int32_t)vector1[i] * (int32_t)vector2[i];
        result[i] = (int16_t)((product >> 15) & 0xFFFF);
    }
}
