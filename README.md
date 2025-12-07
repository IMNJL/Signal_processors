# Signal_processors

This repository contains lab exercises and implementations for digital signal processing (fixed-point Q15 variants), organized per lab folder.

**Scoring Rubric (out of 10)**
- **Main implementation (3 points):** presence of the core algorithm file (e.g., `*_q15.c` or `<name>.c`).
- **Reference implementation (2 points):** presence of a `*_ref.c` file (correct, clear reference).
- **Optimized / Fast implementation (3 points):** presence of a `*_fast.c` or optimized variant.
- **Testbench (2 points):** presence of a `*_tb.c` testbench file.

Points are summed from the above categories (3 + 2 + 3 + 2 = 10).

**Summary Table**

| Lab | Files | Points | Comments |
| --- | --- | ---: | --- |
| [`add_vector`](https://github.com/IMNJL/Signal_processors/tree/main/add_vector) | `add_vector.c`, `add_vector_ref.c`, `add_vector_fast.c`, `add_vector_tb.c` | `/10` | Complete: main, reference, optimized and testbench present, basic realisation of each folder |
| [`lab1`](https://github.com/IMNJL/Signal_processors/tree/main/lab1) | `add_vector_q15.c`, `add_vector_q15_ref.c`, `add_vector_q15_fast.c`, `add_vector_q15_tb.c` | `/10` | Complete. |
| [`lab2`](https://github.com/IMNJL/Signal_processors/tree/main/lab2) | `add_vector_s0_q15.c`, `add_vector_s0_q15_ref.c`, `add_vector_s0_q15_fast.c`, `add_vector_s0_q15_tb.c` | `/10` | Complete. |
| [`lab3`](https://github.com/IMNJL/Signal_processors/tree/main/lab3) | `mul_vector_s0_q15.c`, `mul_vector_s0_q15_ref.c`, `mul_vector_s0_q15_fast.c`, `mul_vector_s0_q15_tb.c` | `/10` | Complete. |
| [`lab4`](https://github.com/IMNJL/Signal_processors/tree/main/lab4) | `add_signals_q15.c`, `add_signals_q15_ref.c`, `add_signals_q15_fast.c`, `add_signals_q15_tb.c` | `/10` | Complete. |
| [`lab5`](https://github.com/IMNJL/Signal_processors/tree/main/lab5) | `mul_vector_s15_q15.c`, `mul_vector_s15_q15_ref.c`, `mul_vector_s15_q15_fast.c`, `mul_vector_s15_q15_tb.c` | `/10` | Complete. |
| [`lab6`](https://github.com/IMNJL/Signal_processors/tree/main/lab6) | `mul_vector_a_q15.c`, `mul_vector_a_q15_ref.c`, `mul_vector_a_q15_fast.c`, `mul_vector_a_q15_tb.c` | `/10` | Complete. |
| [`lab7`](https://github.com/IMNJL/Signal_processors/tree/main/lab7) | `mul_vector_a_cq15.c`, `mul_vector_a_cq15_ref.c`, `mul_vector_a_cq15_fast.c`, `mul_vector_a_cq15_tb.c` | `/10` | Complete. |
| [`lab8`](https://github.com/IMNJL/Signal_processors/tree/main/lab8) | `mul_vector_s15_cq15.c`, `mul_vector_s15_cq15_ref.c`, `mul_vector_s15_cq15_fast.c`, `mul_vector_s15_cq15_tb.c` | `/10` | Complete. |
| [`lab9`](https://github.com/IMNJL/Signal_processors/tree/main/lab9) | `convolution_cq15.c`, `convolution_cq15_ref.c`, `convolution_cq15_tb.c` | `/20` | Missing optimized/fast implementation (`*_fast.c`). |
| [`lab10`](https://github.com/IMNJL/Signal_processors/tree/main/lab10) | `fir_filter_q15.c`, `fir_filter_q15_ref.c`, `fir_filter_q15_tb.c` | `/20` | Missing optimized/fast implementation. |
| [`lab11`](https://github.com/IMNJL/Signal_processors/tree/main/lab11) | `iir_filter_q15.c`, `iir_filter_q15_ref.c`, `iir_filter_q15_tb.c` | `/20` | Missing optimized/fast implementation. |
| [`lab12`](https://github.com/IMNJL/Signal_processors/tree/main/lab12) | `fft256_q15.c`, `fft256_q15_ref.c`, `fft256_q15_tb.c` | `/30` | Missing optimized/fast implementation. |

**Notes & Recommendations**
- The scoring is mechanical and based on the presence of expected files. It does not evaluate correctness or performance. For a grade or automated CI, consider running testbenches and comparing outputs against reference implementations.
- Recommended next steps for labs with lower scores:
	- Implement an optimized `*_fast.c` variant (vectorized or algorithmic optimizations) to gain the missing 3 points.
	- Add comments and simple benchmarks to demonstrate speed/complexity improvements.
- Testbenches: files suffixed with `_tb.c` are present for many labs. To run them you can compile using your toolchain (example):

```bash
gcc -std=c11 -O2 -I. lab1/add_vector_q15.c lab1/add_vector_q15_tb.c -o lab1_tb
./lab1_tb
```
