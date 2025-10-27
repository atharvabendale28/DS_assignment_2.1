CC = gcc
CFLAGS = -Wall -Wextra -O2

SRCS = tree.c primes.c solver.c main.c
OBJS = $(SRCS:.c=.o)
DEPS = tree.h primes.h solver.h

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o main
