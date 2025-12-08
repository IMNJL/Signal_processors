#include <stdint.h>

typedef struct {
    int16_t real;
    int16_t imag;
} Complex16;

typedef struct {
    int32_t real;
    int32_t imag;
} Complex32;

void multiplyVectors(int n, Complex32 *result, Complex16 *input1, Complex16 *input2) {
    for (int i = 0; i < n; i++) {
        int16_t a = input1[i].real;
        int16_t b = input1[i].imag;
        int16_t c = input2[i].real;
        int16_t d = input2[i].imag;

        result[i].real = (int32_t)(a * c - b * d);
        result[i].imag = (int32_t)(a * d + b * c);
    }
}
