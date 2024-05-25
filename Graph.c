#include <stdio.h>
#include <stdlib.h>

int a[10][10], n, m, i, j, source, s[10], vis[10], visited[10], count;

void create() {
    printf("\nEnter the number of vertices of the digraph: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix of the graph:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
        visited[i] = 0; // Move this line here
    }
}

void bfs() {
    int q[10], u, front = 0, rear = -1;
    printf("\n Enter the source vertex: ");
    scanf("%d", &source);
    q[++rear] = source;
    visited[source] = 1;
    printf("\nThe reachable vertices are: ");
    while (front <= rear) {
        u = q[front++];
        for (i = 1; i <= n; i++) {
            if (a[u][i] == 1 && visited[i] == 0) {
                q[++rear] = i;
                visited[i] = 1;
                printf("\n%d", i);
            }
        }
    }
}

void dfs(int source) {
    int v;
    vis[source] = 1;
    for (v = 1; v <= n; v++) {
        if (a[source][v] == 1 && vis[v] == 0) {
            count++;
            dfs(v);
        }
    }
}

int main() { // Changed return type from void to int
    int ch;
    printf("\n1.Create\n2.BFS\n3.Check graph connected or not(DFS)\n4.Exit");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                bfs();
                break;
            case 3:
                count = 1;
                for (i = 1; i <= n; i++)
                    if (vis[i] == 0)
                        dfs(i);
                if (count == n)
                    printf("\nGraph is Connected");
                else
                    printf("\nGraph is not Connected");
                break;
            default:
                exit(0);
        }
    }
    return 0;
}

