#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    int16_t real;
    int16_t imag;
} Complex16;

typedef struct {
    int32_t real;
    int32_t imag;
} Complex32;

void multiplyVectors(int n, Complex32 *result, Complex16 *input1, Complex16 *input2);
void referenceMultiplyVectors(int n, Complex32 *result, Complex16 *input1, Complex16 *input2);
void fastMultiplyVectors(int n, Complex32 *result, Complex16 *input1, Complex16 *input2);

bool compareResults(int n, Complex32 *result1, Complex32 *result2) {
    for (int i = 0; i < n; i++) {
        if (result1[i].real != result2[i].real || result1[i].imag != result2[i].imag) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 3;
    Complex16 input1[] = {{1, 2}, {3, 4}, {5, 6}};
    Complex16 input2[] = {{7, 8}, {9, 10}, {11, 12}};
    Complex32 referenceResult[3], fastResult[3];

    referenceMultiplyVectors(n, referenceResult, input1, input2);
    printf("Reference results:\n");
    for (int i = 0; i < n; i++) {
        printf("Result[%d]: real = %d, imag = %d\n", i, referenceResult[i].real, referenceResult[i].imag);
    }

    fastMultiplyVectors(n, fastResult, input1, input2);
    printf("Fast results:\n");
    for (int i = 0; i < n; i++) {
        printf("Result[%d]: real = %d, imag = %d\n", i, fastResult[i].real, fastResult[i].imag);
    }

    if (compareResults(n, referenceResult, fastResult)) {
        printf("Results match.\n");
    } else {
        printf("Results do not match.\n");
    }

    return 0;
}
