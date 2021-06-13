// Name: Tirth Hihoriya
// Roll no.: 18bce244
// Prac-10 : Write a program to find the chromatic number of a given graph. 

#include<bits/stdc++.h>
using namespace std;
 
int n,e,i,j;
vector<vector<int> > graph;
vector<int> color;
set<int> colorset;
bool vis[100011];
 
void chromatic_number()
{
    color[0]  = 0;
    for (i=1;i<n;i++)
        color[i] = -1;
 
    bool unused[n];
 
    for (i=0;i<n;i++)
        unused[i]=0;
 
    for (i = 1; i < n; i++)
    {
        for (j=0;j<graph[i].size();j++)
            if (color[graph[i][j]] != -1)
                unused[color[graph[i][j]]] = true;
        int cr;
        for (cr=0;cr<n;cr++)
            if (unused[cr] == false)
                break;
 
        color[i] = cr; 
 
        for (j=0;j<graph[i].size();j++)
            if (color[graph[i][j]] != -1)
                unused[color[graph[i][j]]] = false;
    }
}
 
int main()
{
    int x,y;
    cout << "\n==== Enter inputs ==== \n";
    cin>>n>>e;
    graph.resize(n);
    color.resize(n);
    memset(vis,0,sizeof(vis));

    for(i=0; i<e; i++)
    {
        cin>>x>>y;
        x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    chromatic_number();
    set<int> colorset(color.begin(), color.end()); 

    cout<<"\nChromatic number of a given graph is : "<<colorset.size()<<"\n\n";

    for(i=0;i<n;i++)
    {
        cout<<"Vertex "<<i+1<<" is coloured "<<color[i]+1<<"\n";
    }
}

// INPUT

//---------- Square ----------
// 4 3
// 1 2
// 2 3
// 3 4
// 1 4


//---------- K5 -----------
// 5 10
// 1 2
// 2 3
// 3 4
// 4 5
// 1 5
// 1 3
// 1 4
// 2 5
// 2 4
// 3 5