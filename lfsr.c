#include <stdio.h>
#include <stdint.h>

unsigned lfsr_fib();
unsigned random_256();

void main() {
	unsigned p = lfsr_fib();
	printf("\nPeriod = %u\n\n", p);
}

// Function comes from: https://en.wikipedia.org/wiki/Linear-feedback_shift_register
unsigned lfsr_fib() {
	//uint16_t start_state = 0xACE1u;
	uint16_t start_state = 0x00001;
	uint16_t lfsr = start_state;
	uint16_t bit;
	unsigned period = 0;

	do {
		bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1u;
		lfsr = (lfsr >> 1) | (bit << 15);
		++period;
	}
	while (lfsr != start_state);

	return period;	
}

unsigned random_256() {
	return 1u;
}
