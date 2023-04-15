#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int Data;
struct Elem
{
	Data val;
	struct Elem *next;
};

typedef struct Elem Node;

typedef int Data;
struct Elem {
Data val;
struct Elem * next ;
};

typedef struct Elem Node ;

void deleteStack(Node**top);
int isEmptyStack(Node*top);
Data pop(Node**top);
void push(Node**top, Data v);
Data top(Node *top);