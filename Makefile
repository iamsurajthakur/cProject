CC = gcc  # Use gcc instead of clang
CFLAGS = -ggdb3 -gdwarf-4 -O0 -std=c11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LDFLAGS = -lm

filter: filter.c helpers.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o filter filter.c helpers.c 