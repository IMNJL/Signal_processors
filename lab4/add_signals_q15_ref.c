#include <stdint.h>

void add_signals_q15_ref(int size, int16_t *result, int16_t *signal1, int16_t *signal2) {
    for (int i = 0; i < size; i++) {
        int32_t sum = (int32_t)signal1[i] + (int32_t)signal2[i];
        sum = sum >> 1;

        if (sum > 32767) {
            result[i] = 32767;
        } else if (sum < -32768) {
            result[i] = -32768;
        } else {
            result[i] = (int16_t)sum;
        }
    }
}
