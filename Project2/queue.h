/* A linked list queue */
#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define FULL 1000

typedef int			data;
typedef enum {false, true}	boolean;

struct elem {
	data 	d;
	struct elem *next;
};

struct Queue {
	int cnt;
	elem *front;
	elem *rear;
};

typedef struct elem	elem;
typedef struct Queue 	Queue;

void initialize(Queue *q);
void push(data d, Queue *q);
data pop(Queue *q);
boolean empty(const Queue *q);
boolean full(const Queue *q);
