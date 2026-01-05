#include <stdio.h>

void hanoi(int n, char kaynak, char hedef, char yardimci) {
    if (n == 1) {
        printf("Disk 1'i %c direginden %c diregine tasi\n", kaynak, hedef);
        return;
    }

    hanoi(n - 1, kaynak, yardimci, hedef);

    printf("Disk %d'yi %c direginden %c diregine tasi\n", n, kaynak, hedef);

    hanoi(n - 1, yardimci, hedef, kaynak);
}

int main() {
    int disk_sayisi;

    printf("Disk sayisini giriniz: ");
    scanf("%d", &disk_sayisi);

    printf("%d disk icin tasima adimlari:\n", disk_sayisi);
    
    hanoi(disk_sayisi, 'A', 'C', 'B');

    return 0;
}
