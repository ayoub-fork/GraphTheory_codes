// Name: Tirth Hihoriya
// Roll no.: 18bce244
// Prac-5 : Dijkstra's algorithm for single source shortest path

#include <limits.h>
#include <iostream> 
using namespace std;

#define V 10


int minDistance(int dist[], bool included[]) 
{ 
	
	int min = INT_MAX, min_index; 

	for (int i = 0; i < V; i++) 
		if (included[i] == false && dist[i] <= min) 
			min = dist[i], min_index = i; 

	return min_index; 
} 


void dijkstra(int graph[V][V], int src) 
{ 
	int dist[V];
	bool included[V]; 
 
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, included[i] = false; 
 
	dist[src] = 0; 

	for (int i = 0; i < V-1; i++) 
	{ 
		int u = minDistance(dist, included); 
		included[u] = true; 

		for (int v = 0; v < V; v++) 
			if (!included[v]  &&  graph[u][v]  &&  dist[u]!=INT_MAX  &&  dist[u]+graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 

	cout <<"\n--------------------\n";
	cout <<"Vertex      Distance\n";
	cout <<"--------------------\n"; 
	for (int i = 0; i < V; i++) 
		cout << "  " << i << "    --->    " <<  dist[i] << "\n";
	cout << '\n';
} 

int main() 
{
	int graph[V][V] =	 {  { 0, 6, 4, 4, 8, 3, 4, 0, 2, 6 },
							{ 6, 0, 0, 9, 6, 3, 3, 1, 2, 4 },
							{ 4, 0, 0, 5, 4, 1, 2, 8, 4, 8 },
							{ 4, 9, 5, 0, 5, 6, 7, 2, 1, 7 },
							{ 8, 6, 4, 5, 0, 0, 2, 1, 6, 3 },
							{ 3, 3, 1, 6, 0, 0, 4, 2, 0, 0 },
							{ 4, 3, 2, 7, 2, 4, 0, 9, 8, 7 },
							{ 0, 1, 8, 2, 1, 2, 9, 0, 2, 3 },
							{ 2, 2, 4, 1, 6, 0, 8, 2, 0, 7 },
							{ 6, 4, 8, 7, 3, 0, 7, 3, 7, 0 } };

	int source = 4;
	cout <<"\nSource vertex = " << source <<'\n';

	dijkstra(graph, source);
	return 0; 
} 
