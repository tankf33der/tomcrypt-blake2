all:
	gcc -O3 -Wall -Wextra *.c -ltomcrypt && ./a.out
clean:
	rm -rf *.o *.out
