#include <stdint.h>

typedef struct {
    int16_t real;
    int16_t imag;
} Complex16;

typedef struct {
    int32_t real;
    int32_t imag;
} Complex32;

void fastMultiplyVectors(int n, Complex32 *result, Complex16 *input1, Complex16 *input2) {
    Complex16 *ptr1 = input1;
    Complex16 *ptr2 = input2;
    Complex32 *ptrResult = result;

    for (int i = 0; i < n; i++) {
        int16_t a = ptr1->real;
        int16_t b = ptr1->imag;
        int16_t c = ptr2->real;
        int16_t d = ptr2->imag;

        ptrResult->real = (int32_t)(a * c - b * d);
        ptrResult->imag = (int32_t)(a * d + b * c);

        ptr1++;
        ptr2++;
        ptrResult++;
    }
}
