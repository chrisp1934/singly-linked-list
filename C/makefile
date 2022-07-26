WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
CFLAGS = -g -std=c99 $(WARNING) $(ERROR)

GCC = gcc $(CFLAGS)

INCLUDES = include/singly_linked_list.h includes/singly_linked_list_test.h
SRC = src/singly_linked_list.c
TEST = tests/singly_linked_list_test.c

test: test_build
	./test

test_build:
	$(GCC) $(SRC) $(TEST) -o test

test_valgrind: test_build
	valgrind -q --leak-check=full ./test

clean:
	rm -f test

#%.o: %.c
#    $(GCC) $(CFLAGS) $(INCLUDES) -c $(inputs) -o $(outputs)