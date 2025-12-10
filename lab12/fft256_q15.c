#include <stdint.h>
#include <math.h>

// Комплексное число в формате Q15
typedef struct {
    int16_t real;
    int16_t imag;
} cint16_t;

// Таблица синусов и косинусов для 256-точечного FFT
static const cint16_t twiddle_factors[128] = {
    // Предварительно вычисленные значения
    {32767, 0}, {32758, -402}, {32729, -804}, {32680, -1206}, {32610, -1607}, {32521, -2007},
    {32412, -2405}, {32283, -2802}, // ... остальные значения
};

void fft256_q15(cint16_t *dst, cint16_t *src) {
    cint16_t temp[256];
    for (int i = 0; i < 256; i++) {
        temp[i] = src[i];
    }

    // Основной алгоритм FFT
    int step = 1;
    for (int stage = 0; stage < 8; stage++) {
        int jump = step * 2;
        for (int i = 0; i < 256; i += jump) {
            for (int j = 0; j < step; j++) {
                cint16_t twiddle = twiddle_factors[(j * 128) / step];
                cint16_t a = temp[i + j];
                cint16_t b = temp[i + j + step];

                int32_t real = ((b.real * twiddle.real - b.imag * twiddle.imag) + 16384) >> 15;
                int32_t imag = ((b.real * twiddle.imag + b.imag * twiddle.real) + 16384) >> 15;

                temp[i + j].real = a.real + real;
                temp[i + j].imag = a.imag + imag;

                temp[i + j + step].real = a.real - real;
                temp[i + j + step].imag = a.imag - imag;
            }
        }
        step *= 2;
    }

    for (int i = 0; i < 256; i++) {
        dst[i] = temp[i];
    }
}
