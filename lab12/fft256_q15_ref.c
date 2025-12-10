#include <stdint.h>
#include <math.h>

// Комплексное число в формате Q15
typedef struct {
    int16_t real;
    int16_t imag;
} cint16_t;

void fft256_q15_ref(cint16_t *dst, cint16_t *src) {
    // Прямая реализация дискретного преобразования Фурье
    for (int k = 0; k < 256; k++) {
        int32_t real_sum = 0;
        int32_t imag_sum = 0;
        for (int n = 0; n < 256; n++) {
            int32_t angle = (k * n * 32768) / 256;
            int16_t cos_val = cos(angle);
            int16_t sin_val = -sin(angle);

            real_sum += (src[n].real * cos_val - src[n].imag * sin_val) >> 15;
            imag_sum += (src[n].real * sin_val + src[n].imag * cos_val) >> 15;
        }
        dst[k].real = real_sum > 32767 ? 32767 : (real_sum < -32768 ? -32768 : real_sum);
        dst[k].imag = imag_sum > 32767 ? 32767 : (imag_sum < -32768 ? -32768 : imag_sum);
    }
}
