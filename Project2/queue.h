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

struct queue {
	int cnt;
	elem *front;
	elem *rear;
};

typedef struct queue 	queue;
void initialize(queue *q);
void push(data d, queue *q);
data pop(queue *q);
boolean empty(const queue *q);
