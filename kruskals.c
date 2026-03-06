#include <stdio.h>

int parent[20]; 


int find_root(int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

int main() {
    int n, cost[20][20], i, j;
    int edge_count = 0; 
    int total_cost = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            
            if (cost[i][j] == 0) {
                cost[i][j] = 999; 
            }
        }
    }

    for (i = 1; i <= n; i++) {
        parent[i] = i;
    }

    printf("\n Minimum Spanning Tree \n");

    while (edge_count < n - 1) {
        int min = 999;
        int node1 = 0, node2 = 0;

       
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    node1 = i; 
                    node2 = j; 
                }
            }
        }

        int root1 = find_root(node1);
        int root2 = find_root(node2);

        if (root1 != root2) {
            printf("Edge %d: (%d -> %d) cost = %d\n", edge_count + 1, node1, node2, min);
            total_cost = total_cost + min; 
            parent[root1] = root2;        
            edge_count++;                  
        }

        cost[node1][node2] = 999;
        cost[node2][node1] = 999;
    }

    printf("\nTotal Minimum Cost = %d\n", total_cost);

    return 0;
}