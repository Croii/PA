#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int Data;

typedef struct Elem
{
    Data val;
    struct Elem *next;
} Node;

void addAtBeginning(Node **head, Data v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = *head;
    *head = newNode;
}

void addAtEnd(Node **head, Data v)
{
    Node *aux = *head;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = v;
    if (*head == NULL)
        addAtBeginning(&*head, v);
    else
    {
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = newNode;
        newNode->next = NULL;
    }
}

void display(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

Node *search_note(Node *head, Node **last, char sequence[])
{
    *last = NULL;
    while (head->next != NULL)
    {
        if (head->val == sequence[0] && (head->next)->val == sequence[1])
        {
            *last = (head->next)->next;
            while (*last != NULL)
            {
                if ((*last)->val == sequence[2])
                    return head;
                *last = (*last)->next;
            }
        }
        head = head->next;
    }
    return NULL;
}

void repeat(Node *first_note, Node *last_note)
{
    Node *fix_node = (last_note)->next;
    Node *last_note_copy = last_note;

    while (first_note != last_note_copy)
    {
        Node *aux = (Node *)malloc(sizeof(Node));
        aux->next = NULL;
        aux->val = first_note->val;
        last_note->next = aux;
        last_note = last_note->next;
        first_note = first_note->next;
    }

    Node *aux = (Node *)malloc(sizeof(Node));
    aux->next = NULL;
    aux->val = first_note->val;
    last_note->next = aux;
    last_note = last_note->next;
    first_note = first_note->next;
    last_note->next = fix_node;
}

void modify(Node *head, Data newData, int pos)
{
    // newData valoarea noua a elementului de pe pozitia pos
    Node *aux = head;
    int p = 0;
    while (head != NULL && p < pos)
    {
        aux = head;
        head = head->next;
        p++;
    }
    // modifica info din elementul de pe pozitia pos
    if (aux != NULL)
        aux->val = newData;
}

void addAtPos(Node **head, Data v, int pos)
{
    Node *aux, *headcopy = *head;
    int p = 0; // folosit la cautarea pozitiei pos
    if (*head != NULL)
    {
            Node *newNode = (Node*)malloc(sizeof(Node));
            newNode->val = v;
        // cat timp nu s-a ajuns la final sau la pozitia dorita
        while (headcopy != NULL && p < pos)
        {
            aux = headcopy;
            headcopy = headcopy->next;
            p++; // actualizeaza pozitia curenta
        }
        if (pos == 0)
            addAtBeginning(head, v);
        else {
            aux->next = newNode;
            newNode->next = headcopy;
        }
    }
    else if (pos == 0) addAtBeginning(head, v);
}

void incrementare_valori(Node *head)
{
    if (head->next == NULL)
        return;
    incrementare_valori(head->next);
    (head->val) += (head->next)->val;
}
void update(Node *head, int value, int pos) {
    for (int i = 0; i < pos && head != NULL; i++, head = head->next)
        head->val += value;
    if (head->next != NULL)
        head->val += head->next->val; 
    //printf("%d", head->val);    

}