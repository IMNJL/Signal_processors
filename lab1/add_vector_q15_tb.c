#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

// Объявления функций
void add_vector_q15(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void add_vector_q15_ref(int n, int16_t *dst, int16_t *src1, int16_t *src2);

// Функция для генерации случайного вектора в диапазоне Q15 (-32768 до 32767)
void random_vector_q15(int n, int16_t *v) {
    for (int i = 0; i < n; i++) {
        v[i] = (int16_t)(rand() % 65536 - 32768);
    }
}

// Тестовый стенд для проверки add_vector_q15
void add_vector_q15_tb(long int seed, unsigned runs) {
    srand(seed);

    for (unsigned run = 0; run < runs; run++) {
        int n = rand() % 10 + 1;  // Случайный размер вектора от 1 до 10 для удобства тестов
        int16_t *src1 = (int16_t*) malloc(n * sizeof(int16_t));
        int16_t *src2 = (int16_t*) malloc(n * sizeof(int16_t));
        int16_t *dst = (int16_t*) malloc(n * sizeof(int16_t));
        int16_t *dst_ref = (int16_t*) malloc(n * sizeof(int16_t));

        // Генерация случайных значений для src1 и src2
        random_vector_q15(n, src1);
        random_vector_q15(n, src2);

        // Вызов основной и эталонной функций
        add_vector_q15(n, dst, src1, src2);
        add_vector_q15_ref(n, dst_ref, src1, src2);

        // Заголовок для текущего теста
        printf("\n=== Тест %d ===\n", run + 1);
        printf("Размер вектора: %d\n", n);
        printf("Исходные данные:\n");
        printf("Index\tSrc1\tSrc2\tDst\tDst_Ref\n");

        // Сравнение результатов
        int errors = 0;
        for (int i = 0; i < n; i++) {
            printf("%d\t%d\t%d\t%d\t%d\n", i, src1[i], src2[i], dst[i], dst_ref[i]);
            if (dst[i] != dst_ref[i]) {
                printf("Ошибка: Позиция %d, dst = %d, dst_ref = %d\n", i, dst[i], dst_ref[i]);
                errors++;
            }
        }

        if (errors == 0) {
            printf("Результат: Тест %d пройден успешно.\n", run + 1);
        } else {
            printf("Результат: Тест %d завершен с %d ошибками.\n", run + 1, errors);
        }

        free(src1);
        free(src2);
        free(dst);
        free(dst_ref);
    }
}

int main() {
    add_vector_q15_tb(42, 5);  // Запуск тестового стенда с начальным значением 42 и 5 тестами
    return 0;
}
