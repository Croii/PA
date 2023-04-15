#include "stive.h"

Data top(Node *top)
{
	if (isEmptyStack(top))
		return INT_MIN;
	return top->val;
}

void push(Node **top, Data v)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->val = v;
	newNode->next = *top;
	*top = newNode;
}

Data pop(Node **top)
{
	if (isEmptyStack(*top))
		return INT_MIN;
	Node *temp = (*top);
	Data aux = temp->val;
	*top = (*top)->next;
	free(temp);
	return aux;
}

int isEmptyStack(Node *top)
{
	return top == NULL;
}

void deleteStack(Node **top)
{
	Node *temp;
	while (!isEmptyStack(*top))
		temp = *top;
	*top = (*top)->next;
	free(temp);
}

