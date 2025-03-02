#include <stdio.h>
#define INFINITY 0
#define MAX 10

void Dijkstra(int Graph[MAX][MAX], int n, int start);

void Dijkstra(int Graph[MAX][MAX], int n, int start) {
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  // Printing the distance
  for (i = 0; i < n; i++)
    if (i != start) {
      printf("%d ",distance[i]);
    }
}
int main() {
  int Graph[MAX][MAX], i, j, n, u,m,a,b,c;
  scanf("%d",&n);
  scanf("%d",&m);
  for(int y=0;y<n;y++)
    for(int z=0;z<n;z++)
        Graph[y][z]=0;
  for(int z=0;z<m;z++)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        Graph[a-1][b-1]=c;
    }

  u = 0;
  Dijkstra(Graph, n, u);
  return 0;
}
