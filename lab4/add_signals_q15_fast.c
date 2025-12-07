#include <stdint.h>

void add_signals_q15_fast(int size, int16_t *result, int16_t *signal1, int16_t *signal2) {
    for (int i = 0; i < size; i++) {
        int32_t sum = ((int32_t)signal1[i] + (int32_t)signal2[i]) >> 1;
        result[i] = (int16_t)((sum > 32767) ? 32767 : (sum < -32768 ? -32768 : sum));
    }
}
