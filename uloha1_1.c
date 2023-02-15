
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

char* uloha1_1(int n, int k, int m, const int* h) {
    printf("n: %d, k: %d, m: %d\n", n, k, m);
    int sum = 0;
    for(int i = 0; i < m; ++i){
        sum = h[i];
        for (int cur = i+1; cur < m; ++cur){
            for (int j = cur; j < k-1; ++j) {
                if (i + j > m - 1) {
                    printf("starting num: %d, sum: %d, n: %d\n", i, sum, n);
                    if (sum > n) return "Nie";
                    sum = h[i];
                    break;
                }
                sum += h[i + j];
            }
            printf("starting num: %d, sum: %d\n", i, sum);
            if (sum > n) return "Nie";
            sum = h[i];
        }


    }

    return "Ano";
}

int main(int argc, char* argv[]){
    if (argc < 5) {
        printf("Lack of arguments!\n");
        return 1;
    }
    int* h = (int*)malloc(atoi(argv[3])*sizeof(int));

    for(int i = 0; i < atoi(argv[3]); ++i){
        h[i] = atoi(argv[i+4]);
    }

    printf("%s", uloha1_1(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), h));
    free(h);
    return 0;
}