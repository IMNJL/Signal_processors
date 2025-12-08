#include <stdio.h>
#include <stdint.h>

void fir_filter_q15(int m, int n, int16_t *dst, int16_t *taps, int16_t *src);
void fir_filter_q15_ref(int m, int n, int16_t *dst, int16_t *taps, int16_t *src);

void display_result(int16_t *vec, int size) {
    for (int i = 0; i < size; i++) {
        printf("Element %d: %d\n", i + 1, vec[i]);
    }
}

int main() {
    int m = 3, n = 5;

    int16_t taps[3] = {16384, 8192, 4096}; // Пример коэффициентов фильтра
    int16_t src[5] = {1000, 2000, 3000, 4000, 5000}; // Пример входного сигнала
    int16_t dst[5];
    int16_t dst_ref[5];

    fir_filter_q15(m, n, dst, taps, src);
    printf("Main Function Output:\n");
    display_result(dst, n);

    fir_filter_q15_ref(m, n, dst_ref, taps, src);
    printf("Reference Function Output:\n");
    display_result(dst_ref, n);

    return 0;
}
