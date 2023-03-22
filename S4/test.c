#include "listelib.h"

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