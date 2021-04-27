#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "tomcrypt.h"
#include "monocypher.h"

// Loup Valiant is hero
void print_vector(const uint8_t *buf, size_t size)
{
    for(size_t i = 0; i < size; i++) {
        printf("%x%x", buf[i] >> 4, buf[i] & 0x0f);
    }
    printf(":\n");
}

int main(void) {
   uint8_t d[128], out1[64], out2[64];
	int result = 0;

	for(size_t i = 0; i < 128; i++) d[i] = i;

	for(size_t o = 1; o <= 64; o++)
		for(size_t k = 0; k <= 64; k++)
			for(size_t m = 0; m < 128; m++) {
            hash_state md;
            blake2b_init(&md, o, d, k);
            blake2b_process(&md, d, m);
            blake2b_done(&md, out1);
				crypto_blake2b_general(out2, o, d, k, d, m);
				result |= memcmp(out1, out2, o);
			}
	return result;
}
