// Name: Tirth Hihoriya
// Roll no.: 18bce244
// Topic : Imlplementation of Pruffer sequence from a spanning tree

#include <bits/stdc++.h>
using namespace std;
 
vector<int> generate_prufer_sequence(int v, int e, int edge[][2], int degree[])
{
    int min, pendent;
    vector<int> prufer(v-2);
    for(int i = 0; i < v-2; i++)
	{
		min = 99999;
		for(int j = 0; j < e; j++)
		{
			if(degree[edge[j][0]] == 1)
			{
				if(edge[j][0] < min)
				{
					min = edge[j][0];
					pendent = j;
				}
			}
			if(degree[edge[j][1]] == 1)
			{
				if(min > edge[j][1])
				{
					min = edge[j][1];
					pendent = j;
				}
			}
		}

        // Decrement the degree of pendent vertex & vertex adjecent to it.
		degree[edge[pendent][0]]--;
		degree[edge[pendent][1]]--;
 
		if(degree[edge[pendent][0]] == 0)
			prufer[i] = edge[pendent][1];
		else
			prufer[i] = edge[pendent][0];
    }
    return prufer;
}


int main()
{
	int v, e;
	cout<<"\nEnter the number of vertexes of the spanning tree: ";
	cin>>v;
 
	e = v-1;
	int edge[e][2], degree[v+1] = {0};
 
	cout<<"\nFor "<<v<<" vertexes this spanning tree must have exactly "<<e<<" edges.";
	cout<<"\nEnter "<<e<<" edges for the spanning tree.\n";
	for(int i = 0; i < e; i++)
	{
		cin>>edge[i][0];
		cin>>edge[i][1];
 
		degree[edge[i][0]]++;
		degree[edge[i][1]]++;
	}

    vector<int> prufer_seq = generate_prufer_sequence(v, e, edge, degree);

    cout << "\nThe Prufer sequence for the spanning tree is: (";
    for(auto p : prufer_seq)
    {
        cout << ' ' << p;
    }
    cout << " )\n\n";
 
	
 
	return 0;
}

// ----INPUT------
// 7
// 1 7
// 1 2
// 1 6
// 3 7
// 4 6
// 5 6


// ---------
// 8
// 1 2
// 1 6
// 1 7
// 3 6
// 4 6
// 4 8
// 5 6