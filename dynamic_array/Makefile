CC = clang

all: main

objs:

	$(CC) -c -o libdynamic_arr.o dynamic_arr.c -fPIC

static: objs
	ar r libdynamic_arr.a libdynamic_arr.o

main: static

	$(CC) main.c -L. -ldynamic_arr -o main
