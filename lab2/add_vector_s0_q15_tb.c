#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

// Объявления функций
void add_vector_s0_q15(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void add_vector_s0_q15_ref(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void add_vector_s0_q15_fast(int n, int16_t *dst, int16_t *src1, int16_t *src2);

// Функция для генерации случайного Q15 вектора
void generate_random_q15_vector(int n, int16_t *v) {
    for (int i = 0; i < n; i++) {
        v[i] = (int16_t)(rand() % 65536 - 32768);  // Диапазон от -32768 до 32767
    }
}

// Тестовый стенд
void add_vector_s0_q15_tb(long seed, unsigned runs) {
    srand(seed);

    for (unsigned run = 0; run < runs; run++) {
        int n = rand() % 16 + 1;  // Размер вектора от 1 до 16 для компактного вывода
        int16_t *src1 = (int16_t *)malloc(n * sizeof(int16_t));
        int16_t *src2 = (int16_t *)malloc(n * sizeof(int16_t));
        int16_t *dst = (int16_t *)malloc(n * sizeof(int16_t));
        int16_t *dst_ref = (int16_t *)malloc(n * sizeof(int16_t));

        // Генерация входных данных
        generate_random_q15_vector(n, src1);
        generate_random_q15_vector(n, src2);

        // Вызов основной и справочной функций
        add_vector_s0_q15(n, dst, src1, src2);
        add_vector_s0_q15_ref(n, dst_ref, src1, src2);

        // Вывод векторов
        printf("Тест %d\n", run + 1);
        printf("Вектор src1: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", src1[i]);
        }
        printf("\n");

        printf("Вектор src2: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", src2[i]);
        }
        printf("\n");

        printf("Результат dst: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", dst[i]);
        }
        printf("\n");

        printf("Результат dst_ref: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", dst_ref[i]);
        }
        printf("\n");

        // Сравнение результатов
        int errors = 0;
        for (int i = 0; i < n; i++) {
            if (dst[i] != dst_ref[i]) {
                printf("Ошибка: индекс %d, dst = %d, dst_ref = %d\n", i, dst[i], dst_ref[i]);
                errors++;
            }
        }

        if (errors == 0) {
            printf("Тест %d: успешно\n\n", run + 1);
        } else {
            printf("Тест %d: %d ошибок\n\n", run + 1, errors);
        }

        free(src1);
        free(src2);
        free(dst);
        free(dst_ref);
    }
}

int main() {
    add_vector_s0_q15_tb(42, 5);  // Запуск тестов с seed 42 и 5 итерациями
    return 0;
}
