#include <stdint.h>
#include <stdio.h>

void mul_vector_a_q15_ref(int n, int32_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_a_q15_fast(int n, int32_t *dst, int16_t *src1, int16_t *src2);

void mul_vector_a_q15(int n, int32_t *dst, int16_t *src1, int16_t *src2) {
    printf("Результат справочной версии:\n");
    mul_vector_a_q15_ref(n, dst, src1, src2);
    for (int i = 0; i < n; i++) {
        printf("%d ", dst[i]);
    }
    printf("\nРезультат оптимизированной версии:\n");
    mul_vector_a_q15_fast(n, dst, src1, src2);
    for (int i = 0; i < n; i++) {
        printf("%d ", dst[i]);
    }
    printf("\n");
}
