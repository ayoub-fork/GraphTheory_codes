// Name: Tirth Hihoriya
// Roll no.: 18bce244
// Prac-6 : Floyd-Warshall Algorithm for all pair shortest path  TC: O(n^3)

#include <iostream>
using namespace std;

#define V 5

#define INF 9999

void printMatrix(int graph[][V]) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (graph[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", graph[i][j]);
    }
    printf("\n");
  }
}


void floyd_warshall(int graph[][V]) {
  int i, j, k;

  for (k = 0; k < V; k++) {
    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        if (graph[i][k] + graph[k][j] < graph[i][j])
          graph[i][j] = graph[i][k] + graph[k][j];
      }
    }
    cout << "\nA" << k+1 << " = "<<'\n'; 
    printMatrix(graph);
    cout << '\n';
  }

cout <<"\n--------------------\n";
cout <<"All Pair Shortest Path\n";
cout <<"--------------------\n";
printMatrix(graph);
cout << '\n';
}



int main() {
  int graph[V][V] = { {0,     2,   1, INF,   3},
                      {INF,   0, INF,   4, INF},
                      {INF,   1,   0, INF,   1},
                      {1  , INF,   3, INF,   5},
                      {INF, INF, INF, INF,   0}};
  floyd_warshall(graph);
}