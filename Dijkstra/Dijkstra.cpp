#include <stdio.h>
#include<stdlib.h>

#define INF 9999


int COUNTER = 0;
void display(int* array, int N){
    printf("\n");
    for(int i=0; i<N; i++){
        printf("%d, ", array[i]);
    }
}
int minDist(int* visited, int* dist, int N){
    int min;
    int minVal = INF;
    for(int i =0; i < N; i++){
        if(visited[i]!=1){
            if(dist[i] <= minVal){
                min = i;
                minVal = dist[i];
            }
        }
    }
    return min;
}
void dijkstra(int** graph, int source, int N){
    printf("\nDijkstra");
    int* dist   = (int*)malloc(sizeof(int)*N);
    int* visited= (int*)malloc(sizeof(int)*N);
    int*  parent= (int*)malloc(sizeof(int)*N);
    for(int i =0; i < N; i++){
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = source;
    }
    dist[source] = 0;
    for(int i =0; i< N-1 ; i++){
        int u = minDist(visited, dist, N);
        visited[u] = 1;
        printf("\n Min vertex is : %d", u);
        
        for(int v = 0; v < N; v++){
            COUNTER++;
            if(graph[u][v]){
                if(!visited[v]){
                    if(dist[u] + graph[u][v] < dist[v]){
                        dist[v] = dist[u] + graph[u][v];
                        printf("\nCost of moving from %d to %d updated to %d", u,v, dist[v]);
                        printf("\n Updated distances :");
                        display(dist, N);
                        parent[v] = u;
                    }
                }
            }
        }
    }
    
    int k = N-1;
    int cost = dist[k];
    printf("\n");
    do{
        printf("%d<-", k);
        k = parent[k];
    }while(k != source);
    printf("%d", source);
    printf("\nTotal cost to reach end is : %d", cost);
}

int main()
{
 
    int N;
    printf("\nEnter number of vertices: ");
    scanf("%d", &N);
    
    int** graph = (int**)calloc(N, sizeof(int*));
    
    for(int i = 0; i < N; i++){
        graph[i] = (int*)calloc(N, sizeof(int*));
    }
    
    // Enter values by row and seperated by one comma | for example : 2, 3, 4, 5

    printf("\nEnter adjacency matrix : ");
    for(int u = 0; u < N; u++){
        for(int v = 0; v < N; v++){
            scanf("%d ", &graph[u][v]);   
        }
    }
    
   
   
   
    dijkstra(graph, 0, N);
   printf("\n COUNTER : %d", COUNTER);
}