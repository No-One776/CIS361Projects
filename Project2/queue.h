/* A linked list queue */
#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0

typedef unsigned int		data;
typedef enum {false, true}	boolean;

struct elem {
	data 	d;
	struct elem *next;
};

typedef struct elem	elem;

struct Queue {
	int cnt;
	elem *front;
	elem *rear;
};

typedef struct Queue 	Queue;
void initialize(Queue *q);
void push(data d, Queue *q);
data pop(Queue *q);
boolean empty(const Queue *q);
