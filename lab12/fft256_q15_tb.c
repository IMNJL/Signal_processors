#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
typedef struct {
    int16_t real;
    int16_t imag;
} cint16_t;

void fft256_q15(cint16_t *dst, cint16_t *src);
void fft256_q15_ref(cint16_t *dst, cint16_t *src);

void display_result(cint16_t *vec, int size) {
    // Ограничиваем вывод первыми 5 элементами
    for (int i = 0; i < 5 && i < size; i++) {
        printf("Element %d: Real = %d, Imag = %d\n", i, vec[i].real, vec[i].imag);
    }
}

int main() {
    cint16_t src[256];
    cint16_t dst[256];
    cint16_t dst_ref[256];

    // Заполнение тестового сигнала случайными значениями
    for (int i = 0; i < 256; i++) {
        src[i].real = (rand() % 2001) - 1000;  // Случайные значения от -1000 до 1000
        src[i].imag = (rand() % 2001) - 1000;  // Случайные значения от -1000 до 1000
    }

    fft256_q15(dst, src);
    printf("FFT Output:\n");
    display_result(dst, 256);

    fft256_q15_ref(dst_ref, src);
    printf("Reference FFT Output:\n");
    display_result(dst_ref, 256);

    return 0;
}
