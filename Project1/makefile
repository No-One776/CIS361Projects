CC = gcc
CFLAGS = -Wall
DEPS = autoCeaserCipherBreaker.h
OBJ = autoCeaserCipherBreaker.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

go: $(OBJ)
	gcc $(CFLAGS) -o $@ $^

test: breaker
breaker: 
	./go

