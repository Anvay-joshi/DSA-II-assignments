#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdbool.h>
#include "singly_LL.h"

typedef struct queue{
    SLL_node* front;
    SLL_node* rear;
    int length;
}queue;

void enqueue(queue*, DTYPE);
void dequeue(queue*);
queue init_Q(DTYPE);
DTYPE front_queue(queue);
bool isempty_queue(queue);

#endif

