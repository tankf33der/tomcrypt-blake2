all:
	gcc -O3 -Wall -Wextra main.c monocypher.c -ltomcrypt && ./a.out
clean:
	rm -rf *.o *.out
