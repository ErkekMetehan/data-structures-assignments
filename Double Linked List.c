#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


void traversal(struct Node* head) {
    struct Node* temp = head;
    printf("Liste: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Onceki dugum NULL olamaz!\n");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;


    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    prev_node->next = new_node;


    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}


void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL) return;


    if (*head_ref == del) {
        *head_ref = del->next;
    }


    if (del->next != NULL) {
        del->next->prev = del->prev;
    }


    if (del->prev != NULL) {
        del->prev->next = del->next;
    }

    free(del);
}


void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

int main() {
    struct Node* head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    
    printf("Baslangic ");
    traversal(head);

    printf("20'den sonra 25 ekleniyor...\n");
    insertAfter(head->next, 25);
    traversal(head);

    printf("20 siliniyor...\n");
    deleteNode(&head, head->next); 
    traversal(head);

    return 0;
}
