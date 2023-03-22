#include <stdio.h>
#include <stdlib.h>

#define INF 1e9

int N, **cost, **dp, **prev;

int min(int a, int b) {
    return a < b ? a : b;
}

int tsp(int i, int S) {
    if (dp[i][S] != -1) {
        return dp[i][S];
    }
    if (S == (1 << N) - 1) {
        dp[i][S] = cost[i][0];
        return dp[i][S];
    }
    int min_effort = INF;
    for (int j = 0; j < N; j++) {
        if ((S & (1 << j)) == 0) {
            int curr_effort = cost[i][j] + tsp(j, S | (1 << j));
            if (curr_effort < min_effort) {
                min_effort = curr_effort;
                prev[i][S] = j;
            }
        }
    }
    dp[i][S] = min_effort;
    return min_effort;
}

void get_sequence(int i, int S, int *sequence) {
    if (S == (1 << N) - 1) {
        sequence[N-1] = i;
        return;
    }
    sequence[N - __builtin_popcount(S) - 1] = i;
    int j = prev[i][S];
    get_sequence(j, S | (1 << j), sequence);
}

int main() {
    scanf("%d", &N);
    cost = malloc(N * sizeof(int *));
    dp = malloc(N * sizeof(int *));
    prev = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        cost[i] = malloc(N * sizeof(int));
