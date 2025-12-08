#include <stdio.h>
#include <stdint.h>

typedef struct {
    int16_t real, imag;
} cint16_t;

void mul_vector_s15_cq15(int n, cint16_t *dst, cint16_t *src1, cint16_t *src2);
void mul_vector_s15_cq15_ref(int n, cint16_t *dst, cint16_t *src1, cint16_t *src2);
void mul_vector_s15_cq15_fast(int n, cint16_t *dst, cint16_t *src1, cint16_t *src2);

void display_result(cint16_t *vec, int n) {
    for (int i = 0; i < n; i++) {
        printf("Element %d: R = %d, I = %d\n", i + 1, vec[i].real, vec[i].imag);
    }
}

int main() {
    int n = 3;

    cint16_t src1[3] = {
        {1200, 1500},
        {2000, 2500},
        {3000, 3500}
    };

    cint16_t src2[3] = {
        {4000, 4500},
        {5000, 5500},
        {6000, 6500}
    };

    cint16_t dst_main[3];
    cint16_t dst_ref[3];
    cint16_t dst_fast[3];

    mul_vector_s15_cq15(n, dst_main, src1, src2);
    printf("Main Function Output:\n");
    display_result(dst_main, n);

    mul_vector_s15_cq15_ref(n, dst_ref, src1, src2);
    printf("Reference Function Output:\n");
    display_result(dst_ref, n);

    mul_vector_s15_cq15_fast(n, dst_fast, src1, src2);
    printf("Fast Function Output:\n");
    display_result(dst_fast, n);

    return 0;
}
