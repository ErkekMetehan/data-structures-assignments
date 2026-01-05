#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traversal(struct Node* head) {
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }
    struct Node* temp = head;
    printf("Liste: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Bas: %d)\n", head->data);
}


void insertAfter(struct Node* head, int target, int new_data) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        if (temp->data == target) {
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = new_data;
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    
    printf("%d degeri listede bulunamadi.\n", target);
}


void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL) return;

    struct Node *curr = *head_ref, *prev = NULL;


    if (curr->data == key) {

        if (curr->next == *head_ref) {
            free(curr);
            *head_ref = NULL;
            return;
        }

        struct Node* last = *head_ref;
        while (last->next != *head_ref) last = last->next;
        
        *head_ref = curr->next;
        last->next = *head_ref;
        free(curr);
        return;
    }


    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return;
        }
    } while (curr != *head_ref);
}


void push(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;

    if (*head_ref != NULL) {
        struct Node* temp = *head_ref;
        while (temp->next != *head_ref) temp = temp->next;
        temp->next = new_node;
    } else {
        new_node->next = new_node;
    }
    *head_ref = new_node;
}

int main() {
    struct Node* head = NULL;

    push(&head, 30);
    push(&head, 20);
    push(&head, 10);
    
    printf("Ilk hali: ");
    traversal(head);

    printf("20'den sonra 25 ekleniyor...\n");
    insertAfter(head, 20, 25);
    traversal(head);

    printf("30 siliniyor...\n");
    deleteNode(&head, 30);
    traversal(head);

    return 0;
}
