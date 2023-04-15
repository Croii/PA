#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Data;

typedef struct Elem{
	Data val;
	struct Elem *next;
} Node;

void addAtBeginning(Node **head, Data v);
void addAtEnd(Node** head, Data v);
void display(Node *head);
Node* search_note(Node *head, Node **last, char sequence[]);
void repeat(Node *first_note, Node *last_note);
void modify(Node *head, Data newData, int pos);
void incrementare_valori(Node *head);
void addAtPos(Node **head, Data v, int pos);
void update(Node *head, int value, int pos);