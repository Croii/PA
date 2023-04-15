#include "cozi.h"
#include "stive.c"
#include <stdio.h>
#include <stdlib.h>

void reverseQueue(Queue *q) {
    Node *stackTop = NULL;
    while(isEmptyQueue(q) != 0) {
        push(&stackTop, deQueue(q));
    }

    while(isEmptyStack(stackTop) != 0) {
        enQueue(q, pop(&stackTop));
    }
}

int main() {    
    int elementeCoada[] = {1, 2, 3, 4, 5};
    Queue *q = createQueue();
 
    printf("1");
    for (int i = 0; i < sizeof(elementeCoada) / sizeof(int); i++)  {
        enQueue(q, elementeCoada[i]);
    }
  
    
    reverseQueue(q);
    while (isEmptyQueue(q) != 0) {
        printf("%d", deQueue(q));
    }    

}