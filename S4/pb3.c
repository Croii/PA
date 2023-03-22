#include "listelib.h"


int main() {
    Node *head;
    int nr_elemente = 5;
    int aux;
    
    for (int i = 0; i < nr_elemente; i++) {
        printf("Timpul functiei %d: ", i+1);
        scanf("%d", &aux);
        addAtEnd(&head, aux);
    }
    incrementare_valori(head);
    display(head);

    int pos, value;
    printf("Pozitia la care doriti inserarea: ");
    scanf("%d", &pos);
    printf("Valoarea pe care o inserati: ");
    scanf("%d", &value);
    addAtPos(&head, value, pos);
    display(head);
    update(head, value, pos);
    display(head);
}
