// Name: Tirth Hihoriya
// Roll no.: 18bce244
// Prac-9 : Write a program to find the maximum clique from a given graph


#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int clique[MAX], vertices;
int graph[MAX][MAX];
  
bool is_clique(int b)
{
    for (int i = 1; i <= b; i++)
        for (int j = i + 1; j <= b; j++)
            if (graph[clique[i]][clique[j]] == 0)
                return false;
    return true;
}


int max_cliques(int i, int len)
{
    int max_length = 0;
  
    for (int j = i+1; j <= vertices; j++) {
  
        clique[len] = j;
  
        if (is_clique(len)) {
  
            max_length = max(max_length, len);
            max_length = max(max_length, max_cliques(j, len+1));
        }
    }
    return max_length;
}


int main()
{
    /*     GRAPH
    
            1 ----------- 2 ---------5
            | \         / |        /
            |   \     /   |      /
            |     / \     |    /
            |  /      \   | /
            3 ----------- 4
    
    */
    int edges[][2] = { { 1, 2 }, { 2, 3 }, { 3, 1 }, {4,5}, //{3,5},{1,5},
                       { 4, 3 }, { 4, 2 }, { 4, 1 }, { 2, 5}};
    int size = sizeof(edges) / sizeof(edges[0]);

    vertices = 5;

    for (int i = 0; i < size; i++) {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
    }

    cout<<"\nMaximum clique is : "<< max_cliques(0, 1) << endl;

    return 0;
}
