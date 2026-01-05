#include <stdio.h>

#define MAX_NODES 15

char tree[MAX_NODES];

void init() {
    for (int i = 0; i < MAX_NODES; i++) {
        tree[i] = '-';
    }
}

void root(char key) {
    tree[0] = key;
}

void set_left(char key, int parent_index) {
    int left_index = (2 * parent_index) + 1;
    if (tree[parent_index] == '-') {
        printf("Hata: Ebeveyn %d bulunamadi!\n", parent_index);
    } else if (left_index >= MAX_NODES) {
        printf("Hata: Agac kapasitesi asildi!\n");
    } else {
        tree[left_index] = key;
    }
}

void set_right(char key, int parent_index) {
    int right_index = (2 * parent_index) + 2;
    if (tree[parent_index] == '-') {
        printf("Hata: Ebeveyn %d bulunamadi!\n", parent_index);
    } else if (right_index >= MAX_NODES) {
        printf("Hata: Agac kapasitesi asildi!\n");
    } else {
        tree[right_index] = key;
    }
}

void print_tree() {
    printf("Agacin Dizi Gosterimi: ");
    for (int i = 0; i < MAX_NODES; i++) {
        if (tree[i] == '-') printf("- ");
        else printf("%c ", tree[i]);
    }
    printf("\n");
}

int main() {
    init();
    
    root('A');
    set_left('B', 0);
    set_right('C', 0);
    set_left('D', 1);
    set_right('E', 1);
    set_right('F', 2);

    print_tree();

    return 0;
}
