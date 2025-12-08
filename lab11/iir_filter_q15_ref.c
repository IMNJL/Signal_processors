#include <stdint.h>

void iir_filter_q15_ref(int k, int m, int n, int16_t *dst, int16_t *bwtaps, int16_t *fwtaps, int16_t *src) {
    int32_t acc;
    for (int i = 0; i < n; i++) {
        acc = 0;

        // Прямые нажатия
        for (int j = 0; j < m; j++) {
            if (i - j >= 0) {
                acc += (int32_t)fwtaps[j] * src[i - j];
            }
        }

        // Обратные нажатия
        for (int j = 1; j < k; j++) {
            if (i - j >= 0) {
                acc -= (int32_t)bwtaps[j] * dst[i - j];
            }
        }

        acc = (acc + 16384) >> 15;

        if (acc > 32767) {
            acc = 32767;
        } else if (acc < -32768) {
            acc = -32768;
        }

        dst[i] = (int16_t)acc;
    }
}

