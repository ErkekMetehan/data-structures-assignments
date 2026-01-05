#include <stdio.h>

#define MAX_SIZE 100


void diziYazdir(int arr[], int n) {
    printf("Dizi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int elemanEkle(int arr[], int *n, int eleman, int indis) {

    if (*n >= MAX_SIZE) {
        printf("Hata: Dizi dolu!\n");
        return -1;
    }

    if (indis < 0 || indis > *n) {
        printf("Hata: Gecersiz indis!\n");
        return -1;
    }

    for (int i = *n; i > indis; i--) {
        arr[i] = arr[i - 1];
    }

    arr[indis] = eleman;
    (*n)++;
    return 1;
}


int elemanSil(int arr[], int *n, int indis) {
    
    if (*n <= 0) {
        printf("Hata: Dizi zaten bos!\n");
        return -1;
    }
    
    if (indis < 0 || indis >= *n) {
        printf("Hata: Gecersiz indis!\n");
        return -1;
    }

    for (int i = indis; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }


    (*n)--;
    return 1;
}

int main() {
    int arr[MAX_SIZE] = {10, 20, 30, 40, 50};
    int n = 5;

    diziYazdir(arr, n);

    printf("Indis 2'ye 25 ekleniyor...\n");
    elemanEkle(arr, &n, 25, 2;
    diziYazdir(arr, n);

    printf("Indis 3'teki eleman siliniyor...\n");
    elemanSil(arr, &n, 3);
    diziYazdir(arr, n);

    return 0;
}
