#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char sourcekata[1000][100] = {"MUJAIR", "KAMBING", "CICAK", "LEOPARD", "ANJING"};
char clue[100][100] = {"Binatang ini adalah binatang yang menaruh telur di dalam mulutnya untuk menetaskannya",
                        "Hewan bertanduk yang takut dengan air",
                        "Hewan ini bisa berjalan di dinding",
                        "Hewan ini memiliki kecepatan yang sangat tinggi dan memiliki motif kulit yang sangat indah",
                        "Hewan yang terkenal dengan kesetiaan kepada tuannya"};


void keluar();
void permainanbaru();

int main() {
    char key;
    do {
        system("cls");
        printf("\tSelamat datang dalam Permainan Kata\n\n");
        printf("\tMenu :\n");
        printf("\t1. Permainan Baru\n");
        printf("\t2. Skor Tinggi\n");
        printf("\t3. Petunjuk\n");
        printf("\t4. Kredit\n");
        printf("\t0. Keluar\n");
        printf("\n\tMasukkan pilihan menu anda : ");
        key = getch();
        if (key == '1') {
            system("cls");
            permainanbaru();
            getch();
        }
    } while (key != '0');
    keluar();
    return 0;
}

void permainanbaru() {
    int nyawa = 10, isBerhasil = 0, skor = 0, i, isLengkap, index=(rand()%sizeof(sourcekata)/(4*5000));
    char *secretword = sourcekata[index];
    char guessword[100];
    char tebakkarakter;
    for (i=0; i<strlen(secretword); i++)
        guessword[i] = '_';
    while (nyawa > 0) {
        system("cls");
        isLengkap = 1;
        isBerhasil = 0;
        printf("\t%s\n\n\t", clue[index]);
        for (i=0; i<strlen(secretword); i++) {
            printf("%c ", guessword[i]);
            if (guessword[i] == '_')
                isLengkap = 0;
        }
        printf("\n\n\tNyawa anda : %d\n", nyawa);
        if (!isLengkap) {
            tebakkarakter = getch();
            for (i=0; i<strlen(secretword); i++) {
                if (secretword[i] == tebakkarakter) {
                    isBerhasil=1;
                    guessword[i] = tebakkarakter;
                }
                else if (secretword[i] == tebakkarakter-32){
                    isBerhasil = 1;
                    guessword[i] = tebakkarakter-32;
                }
            }
            if (!isBerhasil)
                nyawa--;
        }
        if (isLengkap) {
            skor++;
            nyawa = 10;
            index=rand()%(sizeof(sourcekata)/(4*5000));
            secretword = sourcekata[index];
            for (i=0; i<strlen(secretword); i++)
                guessword[i] = '_';
            printf("\n\n\tANDA BERHASIL!!!!!\n");
            printf("\tSKOR ANDA : %d\n", skor);
            getch();
        }
    }
}

void keluar() {
    system("cls");
    printf("\tTerimakasih telah menggunakan Aplikasi ini.\n");
    printf("\n\n\tSalam saya, DAVID BEZALEL ANGGI SYAH PUTRA LAOLI\n");
}
