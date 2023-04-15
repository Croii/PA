
typedef int Data;

struct Elem_Q
{
    Data val;
    struct Elem_Q *next;
};

typedef struct Elem_Q Node_Q;

struct Q
{
    Node_Q *front, *rear;
};
typedef struct Q Queue;

Queue *createQueue();
void enQueue(Queue *q, Data v);
Data deQueue(Queue *q);
int isEmptyQueue(Queue *q);
void deleteQueue(Queue *q);