#include <stdint.h>

typedef struct {
    int16_t real, imag;
} cint16_t;

void mul_vector_s15_cq15(int n, cint16_t *dst, cint16_t *src1, cint16_t *src2) {
    for (int i = 0; i < n; i++) {
        int32_t real_part = (int32_t)src1[i].real * (int32_t)src2[i].real - (int32_t)src1[i].imag * (int32_t)src2[i].imag;
        int32_t imag_part = (int32_t)src1[i].real * (int32_t)src2[i].imag + (int32_t)src1[i].imag * (int32_t)src2[i].real;

        dst[i].real = (int16_t)(real_part >> 16);
        dst[i].imag = (int16_t)(imag_part >> 16);
    }
}
