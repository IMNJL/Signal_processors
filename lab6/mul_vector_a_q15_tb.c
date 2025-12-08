#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Объявления функций
void mul_vector_a_q15_ref(int n, int32_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_a_q15_fast(int n, int32_t *dst, int16_t *src1, int16_t *src2);

// Генерация случайного вектора
void random_vector_q15(int n, int16_t *v) {
    for (int i = 0; i < n; i++) {
        v[i] = (int16_t)(rand() % 65536 - 32768); // Значения в диапазоне Q15
    }
}

// Сравнение двух массивов
bool compare_results(int n, int32_t *arr1, int32_t *arr2) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

// Вывод массива
void print_array(int n, int32_t *array) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Тестовый стенд
void mul_vector_a_q15_tb(long int seed, unsigned runs) {
    srand(seed);

    for (unsigned run = 0; run < runs; run++) {
        int n = rand() % 10 + 1; // Случайный размер от 1 до 10 (для удобного просмотра)
        int16_t *src1 = (int16_t*) malloc(n * sizeof(int16_t));
        int16_t *src2 = (int16_t*) malloc(n * sizeof(int16_t));
        int32_t *dst_ref = (int32_t*) malloc(n * sizeof(int32_t));
        int32_t *dst_fast = (int32_t*) malloc(n * sizeof(int32_t));

        random_vector_q15(n, src1);
        random_vector_q15(n, src2);

        mul_vector_a_q15_ref(n, dst_ref, src1, src2);
        mul_vector_a_q15_fast(n, dst_fast, src1, src2);

        printf("\nТест %d:\n", run + 1);
        printf("Исходный вектор 1: ");
        for (int i = 0; i < n; i++) printf("%d ", src1[i]);
        printf("\nИсходный вектор 2: ");
        for (int i = 0; i < n; i++) printf("%d ", src2[i]);

        printf("\nРезультат справочной версии: ");
        print_array(n, dst_ref);

        printf("Результат оптимизированной версии: ");
        print_array(n, dst_fast);

        if (compare_results(n, dst_ref, dst_fast)) {
            printf("Результаты совпадают.\n");
        } else {
            printf("Результаты НЕ совпадают!\n");
        }

        free(src1);
        free(src2);
        free(dst_ref);
        free(dst_fast);
    }
}

int main() {
    mul_vector_a_q15_tb(42, 3); // Запуск 3 тестов
    return 0;
}
