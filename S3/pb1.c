#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Data;

typedef struct Elem{
	Data val;
	struct Elem *next;
};

typedef struct Elem Node;

void addAtBeginning(Node **head, Data v)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->val = v;
	newNode->next = *head;
	*head = newNode;
}

void addAtEnd(Node** head, Data v)
{
	Node *aux=*head;
	Node* newNode = (Node*)malloc(sizeof(Node)); 
	newNode->val = v; 
	if (*head == NULL) addAtBeginning(&*head, v);
	else{  
		while (aux->next!=NULL) aux = aux->next;
		aux->next = newNode;  
		newNode->next = NULL; 
	}
}

void display(Node *head)
{
	while (head!=NULL){
		printf ("%c ", head->val);
		head=head->next;
	}
	printf("\n");
}

Node* search_note(Node *head, Node **last, char sequence[]) {
    *last = NULL;
    while (head->next != NULL) {
        if (head->val == sequence[0] && (head->next)->val == sequence[1]) {
            *last = (head->next)->next;
            while(*last != NULL) {
                if ((*last)->val == sequence[2])
                    return head;
                *last = (*last)->next;
            }

        }
        head = head->next;
    }
    return NULL;
}

void repeat(Node *first_note, Node *last_note) {
    Node *fix_node = (last_note)->next;
    Node *last_note_copy = last_note;

    while (first_note != last_note_copy) {
        Node *aux = (Node*)malloc(sizeof(Node));
        aux->next = NULL;
        aux->val = first_note->val;
        last_note->next = aux;
        last_note = last_note->next;
        first_note = first_note->next;
    }
    
    Node *aux = (Node*)malloc(sizeof(Node));
    aux->next = NULL;
    aux->val = first_note->val;
    last_note->next = aux;
    last_note = last_note->next;
    first_note = first_note->next;
    last_note->next = fix_node;

}

int main() {
    
    char music_notes[] = "DDGGAFCDFC";
    char sequence[] = "GAD";
    Node *head = NULL;
    for (int i = 0; i < strlen(music_notes); i++) 
        addAtEnd(&head, music_notes[i]);

    Node *last_note = NULL;
    Node *first_note = search_note(head, &last_note, sequence);
    if (first_note == NULL) {
        printf("Secventa nu a fost gasita!!");
        exit(1);
    }

    //printf("%c %c\n", first_note->val, last_note->val);
    display(head);
    repeat(first_note, last_note);
    display(head);
    return 0;
}
