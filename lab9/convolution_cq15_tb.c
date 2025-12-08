#include <stdio.h>
#include <stdint.h>

typedef struct {
    int16_t real, imag;
} cint16_t;

void convolution_cq15(int m, int n, cint16_t *dst, cint16_t *src1, cint16_t *src2);
void convolution_cq15_ref(int m, int n, cint16_t *dst, cint16_t *src1, cint16_t *src2);

void display_result(cint16_t *vec, int size) {
    for (int i = 0; i < size; i++) {
        printf("Element %d: R = %d, I = %d\n", i + 1, vec[i].real, vec[i].imag);
    }
}

int main() {
    int m = 3, n = 3;

    cint16_t src1[3] = {
        {1000, 2000},
        {1500, 2500},
        {2000, 3000}
    };

    cint16_t src2[3] = {
        {3000, 1000},
        {2500, 1500},
        {2000, 2000}
    };

    cint16_t dst[5];
    cint16_t dst_ref[5];

    convolution_cq15(m, n, dst, src1, src2);
    printf("Main Function Output:\n");
    display_result(dst, m + n - 1);

    convolution_cq15_ref(m, n, dst_ref, src1, src2);
    printf("Reference Function Output:\n");
    display_result(dst_ref, m + n - 1);

    return 0;
}
