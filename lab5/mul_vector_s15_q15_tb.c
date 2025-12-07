#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

void multiply_vectors(int n, int16_t *result, int16_t *vector1, int16_t *vector2);
void reference_multiply(int n, int16_t *result, int16_t *vector1, int16_t *vector2);
void optimized_multiply(int n, int16_t *result, int16_t *vector1, int16_t *vector2);

void generate_random_vector(int n, int16_t *vector) {
    for (int i = 0; i < n; i++) {
        vector[i] = (int16_t)(rand() % 65536 - 32768);
    }
}

void compare_and_print(int n, int16_t *reference, int16_t *optimized, int test_num) {
    int errors = 0;
    for (int i = 0; i < n; i++) {
        if (reference[i] != optimized[i]) {
            errors++;
        }
    }
    printf("Test %d: First Value = Ref: %d, Opt: %d - %s\n", test_num, reference[0], optimized[0], errors == 0 ? "PASSED" : "FAILED");
}

void test_multiplication(long seed, unsigned runs) {
    srand(seed);
    for (unsigned run = 0; run < runs; run++) {
        int n = rand() % 1024 + 1;
        int16_t *vector1 = (int16_t *)malloc(n * sizeof(int16_t));
        int16_t *vector2 = (int16_t *)malloc(n * sizeof(int16_t));
        int16_t *ref_result = (int16_t *)malloc(n * sizeof(int16_t));
        int16_t *opt_result = (int16_t *)malloc(n * sizeof(int16_t));

        generate_random_vector(n, vector1);
        generate_random_vector(n, vector2);

        reference_multiply(n, ref_result, vector1, vector2);
        optimized_multiply(n, opt_result, vector1, vector2);

        compare_and_print(n, ref_result, opt_result, run + 1);

        free(vector1);
        free(vector2);
        free(ref_result);
        free(opt_result);
    }
}

int main() {
    test_multiplication(42, 10);
    return 0;
}
