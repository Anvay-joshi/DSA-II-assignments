#include <stdbool.h>
#include <stdio.h>
#include "singly_LL.h"
#include "queue.h"
#include "binaryTree.h"

queue init_Q(DTYPE num){
    queue Q;
    Q.front = createNode_SLL(num);
    Q.length = 1;
    Q.rear = Q.front;

    return Q;
}


void enqueue(queue* Q, DTYPE num){
    if(Q->front == NULL){
        Q->front = createNode_SLL(num);
        Q->rear = Q->front;
    }
    else{
        (Q->rear)->next = createNode_SLL(num);
        Q->rear = (Q->rear)->next;
    }
    Q->length ++;
}

void dequeue(queue* Q){
    if(Q->length == 1){
        Q->front = NULL;
        Q->rear = Q->front;
    }
    else{

        deleteHead_SLL(&(Q->front));
    }
    Q->length -=1;
}

DTYPE front_queue(queue Q){
    return ((Q.front)->data);
}

bool isempty_queue(queue Q){
    if(Q.length == 0){
        return true;
    }
    else{
        return false;
    }
}
