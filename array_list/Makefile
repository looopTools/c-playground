CC = clang
CC_BASE_FLAGS = -std=c17 -Wall -Werror -pedantic
CC_RELEASE_FLAGS = -O3
CC_DEBUG = -g
CC_OBJECT_FLAGS = -c -o

all: release

objs_release:
	$(CC) $(CC_BASE_FLAGS) $(CC_RELEASE_FLAGS) $(CC_OBJECT_FLAGS) array_list.o array_list.c

objs_debug:
	$(CC) $(CC_BASE_FLAGS) $(CC_DEBUG_FLAGS) $(CC_OBJECT_FLAGS) array_list.o array_list.c

static_release: objs_release
	ar r libarray_list.a array_list.o

static_debug: objs_debug
	ar r libarray_list_debug.a array_list.o

release: static_release
	$(CC) $(CC_BASE_FLAGS) $(CC_RELEASE_FLAGS) main.c -L. -larray_list -o main

debug: static_debug
	$(CC) $(CC_BASE_FLAGS) $(CC_DEBUG_FLAGS) main.c -L. -larray_list_debug -o main

valgrind_debug: debug
	valgrind --leak-check=full ./main

valgrind_release: release
	valgrind --leak-check=full ./main

clean:
	rm main
	rm *.a
	rm *.o
