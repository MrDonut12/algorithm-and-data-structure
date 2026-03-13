#include <stdio.h>

#define MAX 1005

int adj[MAX][MAX];
int indeg[MAX];
int cand[MAX];

int queue[MAX];
int front = 0, rear = 0;

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++){
        cand[i] = 1;
    }

    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);

        adj[v][u] = 1;
        indeg[u]++;
    }

    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            queue[rear++] = i;
        }
    }

    while(front < rear){

        int u = queue[front++];

        for(int v = 1; v <= n; v++){

            if(adj[u][v]){

                if(cand[v] < cand[u] + 1)
                    cand[v] = cand[u] + 1;

                indeg[v]--;

                if(indeg[v] == 0){
                    queue[rear++] = v;
                }
            }
        }
    }

    long long sum = 0;

    for(int i = 1; i <= n; i++){
        printf("%d ", cand[i]);
        sum += cand[i];
    }

    printf("\n%lld\n", sum);

    return 0;
}
