#include <stdint.h>

void multiply_vectors(int n, int16_t *result, int16_t *vector1, int16_t *vector2) {
    for (int i = 0; i < n; i++) {
        int32_t product = (int32_t)vector1[i] * (int32_t)vector2[i];
        int16_t upper_half = (int16_t)(product >> 15);
        if (upper_half > 32767) {
            result[i] = 32767;
        } else if (upper_half < -32768) {
            result[i] = -32768;
        } else {
            result[i] = upper_half;
        }
    }
}
