#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "tomcrypt.h"
#include "monocypher.h"

void print_vector(const uint8_t *buf, size_t size)
{
    for(size_t i = 0; i < size; i++) {
        printf("%02x", buf[i]);
    }
    printf("\n");
}

int main(void) {
   uint8_t d[128], out1[64], out2[64];
	int result = 0;

	for(size_t i = 0; i < 128; i++) d[i] = i;

   hash_state s2;
   blake2s_init(&s2, 32, NULL, 0);
   blake2s_done(&s2, out1);
   // OK 69217a3079908094e11121d042354a7c1f55b6482ca1a51e1b250dfd1ed0eef9
   print_vector(out1, 32);

   hash_state b2;
   blake2b_init(&b2, 64, NULL, 0);
   blake2b_done(&b2, out1);
   // OK 786a02f742015903c6c6fd852552d272912f4740e15847618a86e217f71f5419d25e1031afee585313896444934eb04b903a685b1448b755d56f701afe9be2ce
   print_vector(out1, 64);

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
