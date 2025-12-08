#include <stdint.h>

void fir_filter_q15_ref(int m, int n, int16_t *dst, int16_t *taps, int16_t *src) {
    for (int i = 0; i < n; i++) {
        int32_t acc = 0;

        for (int j = 0; j < m; j++) {
            if (i - j >= 0) {
                acc += (int32_t)taps[j] * src[i - j];
            }
        }

        // Округление и масштабирование
        dst[i] = (int16_t)((acc + 16384) >> 15);
    }
}
