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
	./go LetFreq.txt data.enc > data.dec
	diff -s data.txt data.dec
	./go LetFreq.txt data2.enc > data2.dec
	diff -s data2.txt data2.dec

