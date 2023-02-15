/*
Skupina Iron Maiden po koncerte na Topfeste sa vracia naspäť domov do Londýna. Teraz sa potrebujú zbaliť. Majú veľa vecí
 - kostýmy, aparatúru, gitary, bicie, pareničky a korbáčiky,... K dispozícii majú ľubovoľný počet kamiónov, no keďže
 zaplatenie každého kamiónu niečo stojí, chcú minimalizovať celkové náklady. Každý kamión má nosnosť 300 krabíc.
 Keďže chcú mať vo veciach poriadok, balia ich spolu do väčších balíkov, každý pojme 101 až 300 krabíc.
 Tvojou úlohou je zistiť koľko najmenej kamiónov potrebujú na úspešné prepravenie vecí
 (zabalených vo väčších balíkoch) domov.

Každý riadok obsahuje celé číslo N predstavujúce počet väčších balíkov do ktorých sú zabalené veci,
 a N čísel x[i], kde x[i] je počet krabíc zabalených v i-tom balíku.
 Pre každý riadok vypíšte jedno číslo - minimálny počet kamiónov,
 ktoré musíme zaplatiť na prevezenie všetkých krabíc (ktoré sú balené vo väčších balíkoch).

Obmedzenia:
1 <= N <= 50,
101 <= x[i] <= 300

Ukážka vstupu:
5 150 150 150 150 150
9 101 101 101 101 101 101 101 101 101
Výstup pre ukážkový vstup:
3
5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// jednoducha funkcia na swapovanie dvoch prvkov
void swap(int* a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// primitivny bubble sort casova zlozitost O(n^2)
void bubbleSort(int* h, int size) {
    int i = 0;
    short reset = 1;
    while(1){
        //dojdeme do konca, overime marker reset, ak nie je 1 tak znamena to ze v
        // tomto prechode cez array sme spravily swap
        // inac mozeme skoncit cyclus
        if (i + 1 == size) {
            if (reset == 1) return;
            i = 0;
            reset = 1;
        }
        //swapujeme ak dalsi element je vacsi za aktualny,
        // tym padom budeme mat descending sorted array
        // a ostava sa nam scitat sucet prvych k prvkov
        if (h[i+1] > h[i]) {
            swap(&h[i+1], &h[i]);
            reset = 0;
        }
        // iterujeme cez array
        ++i;
    }
}

int countKamions(int* h, int size){
    int res = 0;
    for(int i = 0; i < size; i++){
        if (i + 1 == size) return res + 1;

        if (h[i] > 150) res++;
        else {
            res++;
            i++;
        }

    }
    return res;
}

int main(){
    int n = 0;
    while(1) {
        char input[256];
        char *token;

        scanf("%d", &n);
        fgets(input, 256, stdin);

        if (strcmp(input, "x") == 0) return 0;

        int* h = (int*) calloc (n, sizeof(int));

        token = strtok(input, " ");
        for(int i = 0; i < n; i++){
            h[i] = atoi(token);
            token = strtok(NULL, " ");
        }

        bubbleSort(h, n);

        printf("%d\n", countKamions(h, n));
    }
}