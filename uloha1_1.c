
/*Humanitárny konvoj sa presúva na Ukrajinu do hlavného mesta Kyjev, aby pomohol tunajším ľuďom. Ako jeden z organizátorov si sa dozvedel, že konvoj má prechádzať cez most s nosnosťou N. Vieš, že na most sa nezmestí viac ako K vozidiel súčasne. Zároveň poznáš hmotnosť každého vozidla. (Naopak nevieš vopred povedať akým spôsobom budú vozidlá cez most prechádzať). Tvojou úlohou je zistiť, či je prejazd cez most pre konvoj bezpečný, alebo nie.

Na vstupe je niekoľko riadkov, každý obsahuje čísla N, K, M a M čísel h[i], ktoré určujú hmotnosť vozidiel konvoja. Pre každý riadok na vstupe vypíšte Ano ak konvoj môže bezpečne prejsť cez most bez ohľadu nato v akom poradí budú vozidlá cez most prechádzať, inak vypíšte Nie

Obmedzenia:
1 <= N <= 10000,
1 <= K <= M,
1 <= M <= 9,
1 <= h[i] <= 1000

Ukážka vstupu:
1234 3 4 1000 200 4 30
20 4 5 10 10 10 10 10
Výstup pre ukážkový vstup:
Ano
Nie*/
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// jednoducha funkcia na swapovanie dvoch prvkov
void swap(int* a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


// quick sort spraveny rekurzivne
void bubbleSort(int* h, int size) {
    int i = 0;
    short reset = 1;
    while(1){
        if (i + 1 == size) {
            if (reset == 1) return;
            i = 0;
            reset = 1;
        }

        if (h[i+1] >= h[i]) {
            swap(&h[i+1], &h[i]);
            reset = 0;
        }
        ++i;
    }
}

void printRes(int* h, int size){
    for (int i = 0; i < size; ++i){
        printf("%d ", h[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    if (argc < 5) {
        printf("Lack of arguments!\n");
        return 1;
    }
    // zapiseme argumenty do premennych
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int m = atoi(argv[3]);
    // inicializujeme dynamicky array
    int* h = (int*)malloc(m*sizeof(int));
    // inicializujeme dynamicky array
    for(int i = 0; i < m; ++i){
        h[i] = atoi(argv[i+4]);
    }

    // spravime bubble sort
    bubbleSort(h, m);
    // vypiseme vysledok
    printRes(h, m);

    // spocitajme sucet najtazsych k vozidiel
    int sum = 0;
    for(int l = 0; l < k; ++l){
        sum += h[l];
    }
    // vypiseme vysledok
    if(sum > n) printf("Nie");
    else  printf("Ano");
    // uvolnime pamat
    free(h);

    return 0;
}