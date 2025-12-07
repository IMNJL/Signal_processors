#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

void add_signals_q15(int size, int16_t *result, int16_t *signal1, int16_t *signal2);
void add_signals_q15_ref(int size, int16_t *result, int16_t *signal1, int16_t *signal2);
void add_signals_q15_fast(int size, int16_t *result, int16_t *signal1, int16_t *signal2);

void generate_random_signal(int size, int16_t *signal) {
    for (int i = 0; i < size; i++) {
        signal[i] = (int16_t)(rand() % 65536 - 32768);
    }
}

void test_add_signals_q15(long seed, unsigned iterations) {
    srand(seed);

    for (unsigned iteration = 0; iteration < iterations; iteration++) {
        int size = rand() % 1024 + 1;
        int16_t *signal1 = (int16_t *)malloc(size * sizeof(int16_t));
        int16_t *signal2 = (int16_t *)malloc(size * sizeof(int16_t));
        int16_t *result = (int16_t *)malloc(size * sizeof(int16_t));
        int16_t *reference_result = (int16_t *)malloc(size * sizeof(int16_t));

        generate_random_signal(size, signal1);
        generate_random_signal(size, signal2);

        add_signals_q15(size, result, signal1, signal2);
        add_signals_q15_ref(size, reference_result, signal1, signal2);

        int errors = 0;
        for (int i = 0; i < size; i++) {
            if (result[i] != reference_result[i]) {
                printf("Ошибка на позиции %d: результат = %d, ожидалось = %d\n", i, result[i], reference_result[i]);
                errors++;
            }
        }

        if (errors == 0) {
            printf("Тест %d: размер = %d, все значения совпали.\n", iteration + 1, size);
        } else {
            printf("Тест %d: размер = %d, количество ошибок = %d.\n", iteration + 1, size, errors);
        }

        free(signal1);
        free(signal2);
        free(result);
        free(reference_result);
    }
}

int main() {
    test_add_signals_q15(42, 10);
    return 0;
}
