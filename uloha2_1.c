//Bernard a Chryzostom majú na stole veľa ceruziek. Keďže nemajú papier, tak si vymysleli hru, ktorou by sa zabavili.
// Na striedačku si berú ceruzky a ten, kto zoberie posledné zvyšné ceruzky vyhráva.
// Aby to ale nebolo také nudné, obmedzili si možné ťahy.
// Hru sa hrajú na viac krát a v každej hre môžu mať inú množinu povolených ťahov.
// Povolený ťah je počet ceruziek, koľko môžu zobrať na jeden ťah.
//
//Na vstupe je niekoľko hier. Pre každú hru je najprv zadané celé číslo
// N - počet povolených ťahov. Nasleduje N celých čísel T_i vyjadrujúcich povolené
// ťahy a dve celé čísla A a B. V každej hre spočítajte pre koľko čísel X (A <= X <= B)
// vyhrá Bernard, ak by sa hrali hru s X ceruzkami a Bernard by ťahal ako prvý.
//
//Obmedzenia:
//1 <= N <= 50,
//1 <= T_i <= 100,
//1 <= A <= B,
//1 <= B <= 100000
//
//Ukážka vstupu:
/*
1
1
1000 1000
10
1 2 3 4 5 6 7 8 9 10
1 100000
4
1 3 7 19
1 100000
Výstup pre ukážkový vstup:
0
90910
50000
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int countWins(int N, int* T, int A, int B){
    char* table = (char*) calloc(B, sizeof(char));
    int res = 0;
    table[0]='P';

    for (int i = 1; i < B; i++){
        int revizia = 0;
        for (int j = 0; j < N; j++){
            if(i - T[j] >= 0 && table[i-T[j]] == 'P') table[i] = 'V';
            else if (i - T[j] >= 0 && table[i-T[j]] == 'R') revizia = 1;
        }
        if (table[i] == 0 && revizia == 1) table[i] = 'R';
        else if (table[i] == 0 && revizia == 0) table[i] = 'P';
    }


    for(int i = A-1; i < B; i++) {
       if (table[i] == 'V') res++;
    }

    free(table);
    return res;
}


int main(){
    while(1) {

        int N, A, B;
        scanf("%d\n", &N);

        if(N == 0) return 0;

        //parsing
        char *token;
        char input[512];
        int *T = (int *) calloc(N, sizeof(int));
        fgets(input, 512, stdin);
        token = strtok(input, " ");
        for (int i = 0; i < N; i++) {
            T[i] = atoi(token);
            token = strtok(NULL, " ");
        }

        scanf("%d %d", &A, &B);

        printf("result: %d\n", countWins(N, T, A, B));
        free(T);
    }
}