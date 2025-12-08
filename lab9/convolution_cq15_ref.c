#include <stdint.h>

typedef struct {
    int16_t real, imag;
} cint16_t;

void convolution_cq15_ref(int m, int n, cint16_t *dst, cint16_t *src1, cint16_t *src2) {
    for (int i = 0; i < m + n - 1; i++) {
        int32_t real_sum = 0;
        int32_t imag_sum = 0;

        for (int j = 0; j < m; j++) {
            if (i - j >= 0 && i - j < n) {
                real_sum += (int32_t)src1[j].real * src2[i - j].real - (int32_t)src1[j].imag * src2[i - j].imag;
                imag_sum += (int32_t)src1[j].real * src2[i - j].imag + (int32_t)src1[j].imag * src2[i - j].real;
            }
        }

        dst[i].real = (int16_t)((real_sum + 16384) >> 15); // Округление и масштабирование
        dst[i].imag = (int16_t)((imag_sum + 16384) >> 15); // Округление и масштабирование
    }
}
