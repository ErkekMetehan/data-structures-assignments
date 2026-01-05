#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int enBuyuk = i; 
    int sol = 2 * i + 1;
    int sag = 2 * i + 2;

    if (sol < n && arr[sol] > arr[enBuyuk])
        enBuyuk = sol;


    if (sag < n && arr[sag] > arr[enBuyuk])
        enBuyuk = sag;


    if (enBuyuk != i) {
        swap(&arr[i], &arr[enBuyuk]);
        maxHeapify(arr, n, enBuyuk);
    }
}

void heapOlustur(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void diziYazdir(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Normal Dizi: ");
    diziYazdir(arr, n);

    heapOlustur(arr, n);

    printf("Max Heap Hali: ");
    diziYazdir(arr, n);

    return 0;
}
