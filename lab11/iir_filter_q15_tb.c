#include <stdio.h>
#include <stdint.h>

void iir_filter_q15(int k, int m, int n, int16_t *dst, int16_t *bwtaps, int16_t *fwtaps, int16_t *src);
void iir_filter_q15_ref(int k, int m, int n, int16_t *dst, int16_t *bwtaps, int16_t *fwtaps, int16_t *src);

void display_result(int16_t *vec, int size) {
    for (int i = 0; i < size; i++) {
        printf("Element %d: %d\n", i + 1, vec[i]);
    }
}

int main() {
    int k = 3, m = 3, n = 5;

    int16_t bwtaps[3] = {16384, -8192, 4096}; // Пример коэффициентов обратных нажатий
    int16_t fwtaps[3] = {16384, 8192, 4096};  // Пример коэффициентов прямых нажатий
    int16_t src[5] = {1000, 2000, 3000, 4000, 5000}; // Пример входного сигнала
    int16_t dst[5];
    int16_t dst_ref[5];

    iir_filter_q15(k, m, n, dst, bwtaps, fwtaps, src);
    printf("Main Function Output:\n");
    display_result(dst, n);

    iir_filter_q15_ref(k, m, n, dst_ref, bwtaps, fwtaps, src);
    printf("Reference Function Output:\n");
    display_result(dst_ref, n);

    return 0;
}
