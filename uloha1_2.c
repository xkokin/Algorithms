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

int contains(int target, int* array, int size){
    if (target == 0) return 1;

    for(int i = 0; i < size; i++){

        if (array[i] == target) return 0;
    }
    return 1;
}

int countKamions(int* h, int size){
    int res = 0;
    int* banned = (int*) calloc (size, sizeof(int));
    int bannedCnt = 0;
    int match = 0;
    int nextBan = -1;

    for(int i = 0; i < size; i++){
        if(contains(i, banned, size) == 0) {
            //printf("h[i]: %d is already used\n", h[i]);
            continue;
        }

        if (i + 1 == size) return res + 1;

        if (h[i] >= 200) {
            res++;
            //printf("too many boxes to pair +1\n");
        }
        else {
            for(int j = i+1; j < size; j++){
                if (h[j] >= 200) continue;

                if (contains(h[j], banned, size) == 0)continue;

                if (h[j] > match && h[j] <= 300 - h[i]) {
                    match = h[j];
                    nextBan = j;
                }
            }
            //printf("%d: found next match: %d on position %d\n", i+1, match, nextBan+1);
            match = 0;
            banned[bannedCnt] = nextBan;
            bannedCnt++;
            res++;
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
        for(int i = 0; i < n; i++) {
            h[i] = atoi(token);
            token = strtok(NULL, " ");
        }

        printf("%d\n", countKamions(h, n));
        free(h);
    }
}