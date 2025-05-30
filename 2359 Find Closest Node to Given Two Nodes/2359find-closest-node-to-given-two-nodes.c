#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void dfs(int* edges, int n, int start, int* dist) {
    int visited[n];
    for (int i = 0; i < n; ++i) visited[i] = 0;

    int d = 0;
    while (start != -1 && !visited[start]) {
        dist[start] = d++;
        visited[start] = 1;
        start = edges[start];
    }
}

int closestMeetingNode(int* edges, int n, int node1, int node2) {
    int* dist1 = (int*)malloc(n * sizeof(int));
    int* dist2 = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        dist1[i] = -1;
        dist2[i] = -1;
    }

    dfs(edges, n, node1, dist1);
    dfs(edges, n, node2, dist2);

    int minDist = INT_MAX;
    int result = -1;

    for (int i = 0; i < n; ++i) {
        if (dist1[i] != -1 && dist2[i] != -1) {
            int maxDist = dist1[i] > dist2[i] ? dist1[i] : dist2[i];
            if (maxDist < minDist) {
                minDist = maxDist;
                result = i;
            }
        }
    }

    free(dist1);
    free(dist2);

    return result;
}
