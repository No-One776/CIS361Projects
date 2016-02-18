CC = gcc
CFLAGS = -Wall -lm
DEPS = stats.h, queue.h
OBJ = proj2.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

simulation: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

test: sim
sim: 
	./simulation 

