#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

// Объявления функций
void mul_vector_s0_q15(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_s0_q15_ref(int n, int16_t *dst, int16_t *src1, int16_t *src2);

// Генерация случайного вектора в диапазоне Q15
void random_vector_q15(int n, int16_t *v) {
    for (int i = 0; i < n; i++) {
        v[i] = (int16_t)(rand() % 65536 - 32768);
    }
}

// Тестовый стенд
void mul_vector_s0_q15_tb(long int seed, unsigned runs) {
    srand(seed);

    for (unsigned run = 0; run < runs; run++) {
        int n = rand() % 10 + 1;  // Случайный размер от 1 до 10 (уменьшен для удобства вывода)
        int16_t *src1 = (int16_t *)malloc(n * sizeof(int16_t));
        int16_t *src2 = (int16_t *)malloc(n * sizeof(int16_t));
        int16_t *dst = (int16_t *)malloc(n * sizeof(int16_t));
        int16_t *dst_ref = (int16_t *)malloc(n * sizeof(int16_t));

        // Генерация случайных значений
        random_vector_q15(n, src1);
        random_vector_q15(n, src2);

        // Вызов функций
        mul_vector_s0_q15(n, dst, src1, src2);
        mul_vector_s0_q15_ref(n, dst_ref, src1, src2);

        // Вывод результатов
        printf("Тест %d:\n", run + 1);
        printf("  Индекс | SRC1       | SRC2       | DST (факт.) | DST (ожид.)\n");
        printf("  -------+------------+------------+-------------+------------\n");

        int errors = 0;
        for (int i = 0; i < n; i++) {
            printf("  %6d | %10d | %10d | %11d | %10d\n",
                   i, src1[i], src2[i], dst[i], dst_ref[i]);
            if (dst[i] != dst_ref[i]) {
                errors++;
            }
        }

        if (errors == 0) {
            printf("Результат: Тест успешно пройден.\n");
        } else {
            printf("Результат: Тест завершился с %d ошибками.\n", errors);
        }
        printf("\n");

        free(src1);
        free(src2);
        free(dst);
        free(dst_ref);
    }
}

int main() {
    mul_vector_s0_q15_tb(42, 3);  // Запуск с seed 42 и 3 итерациями
    return 0;
}
