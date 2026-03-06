#include <stdio.h>

int main() {
    int n, cost[20][20];
    int visited[20] = {0}; 
    int i, j;
    int edge_count = 0;    
    int total_cost = 0;    

    printf("Enter number of vertices (nodes): ");
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


    visited[1] = 1;

    printf("\n--- Minimum Spanning Tree (Prim's Algorithm) ---\n");

    while (edge_count < n - 1) {
        int min = 999;
        int start_node = 0, end_node = 0;

        
        for (i = 1; i <= n; i++) {
            if (visited[i] == 1) { 
                
                for (j = 1; j <= n; j++) {
                    
                    if (visited[j] == 0 && cost[i][j] < min) {
                        min = cost[i][j];   
                        start_node = i;     
                        end_node = j;       
                    }
                }
            }
        }

        if (visited[end_node] == 0) {
            printf("Edge %d: (%d -> %d) cost = %d\n", edge_count + 1, start_node, end_node, min);
            
            total_cost = total_cost + min; 
            visited[end_node] = 1;         
            edge_count++;                  
        }
    }

    printf("\nTotal Minimum Cost = %d\n", total_cost);

    return 0;
}