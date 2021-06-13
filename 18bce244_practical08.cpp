// Name: Tirth Hihoriya
// Roll no.: 18bce244
// Prac-8 : Write a program to check whether the graph is planar or not.

#include<bits/stdc++.h>
using namespace std;
int flag;
vector<int>graph[100];
int vis[101];

void circuit(int i){
	vis[i]=1;
	if(flag!=0)return;
	for(auto &x:graph[i]){
		if(vis[x]==1){
			flag++;
			return;
		}
		else{
			circuit(x);
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			circuit(i);
			if(flag!=0)break;
		}
	}

	if(flag!=0){
		if(m<=(3*n-6)){
			cout<<"\nIt is a PLANAR Graph.\n";
		}
		else{
			cout<<"\nIt is a NonPLANAR Graph.\n";
		}
	}
	else{
		if(m<=(2*n-4)){
			cout<<"\nIt is a PLANAR Graph.\n";
		}
		else{
			cout<<"\nIt is a NonPLANAR Graph.\n";
		}
	}
}

// INPUT

//---------- Square ( PLANER ) ----------
// 4 3
// 1 2
// 2 3
// 3 4
// 1 4


// ---------- K5 ( NONPLANER ) -----------
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
