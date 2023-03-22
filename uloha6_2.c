
#include <stdio.h>
#include <limits.h>

#define MAX_N 20

int n;
int dist[MAX_N][MAX_N];
int visited[MAX_N];
int min_dist = INT_MAX;
int min_path[MAX_N];

void dfs(int current, int visited_count, int dist_so_far, int path[MAX_N]) {
    visited[current] = 1;
    path[visited_count-1] = current+1;

    if (visited_count == n) {
        // We have visited all houses, update the minimum distance and path
        if (dist_so_far < min_dist) {
            min_dist = dist_so_far;
            for (int i = 0; i < n; i++) {
                min_path[i] = path[i];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int new_dist_so_far = dist_so_far + dist[current][i];
                if (new_dist_so_far < min_dist) {
                    dfs(i, visited_count+1, new_dist_so_far, path);
                }
            }
        }
    }

    visited[current] = 0;
}

int main() {
    scanf("%d", &n);

    // Read the distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    // Start from house 1 and visit all other houses
    int path[MAX_N];
    dfs(0, 1, 0, path);

    // Print the minimum distance and path
    printf("%d\n", min_dist);
    for (int i = 0; i < n; i++) {
        printf("%d ", min_path[i]);
    }
    printf("\n");

    return 0;
}
