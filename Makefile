CFLAGS=-std=c11 -g -static -Wall -Werror

9cc: 9cc.c

test: 9cc
	./test.sh

clean:
	rm -f 9cc tmp*

.PHONY: test clean
