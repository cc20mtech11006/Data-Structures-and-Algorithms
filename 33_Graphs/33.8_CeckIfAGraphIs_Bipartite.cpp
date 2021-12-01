// Find if a given graph is bipartite.
// A bipartite graph is graph in which the vertices can be divided into disjoint sets. if x is present in set 1 if their exist x-y edge, then y belongs to set 2.
// The graph is 2 colorable

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
bool bipartite = true;

void colour(int node, int curr){       //curr is current color which we are trying to assign
	if(col[node]!=-1 and col[node]!=curr){   // if node is already coloured and it is not same as the color we wish to assign
		bipartite = false;
		return;
	}
	col[node]= curr;      // Otherwise assign curr colour to node
	if(vis[node]==true){  // if node already visstited return
		return;
	}
	else{	
		vis[node]= true;            
		for(auto i: adj[node]){   // if node not previously visted, assign diffrent colour to all its adjacent nodes
			colour(i, curr xor 1);
		}
	}
}
int main(){
	int n, m;    // n: no of vertices, m: no of edges
	cout << "Enter number n and m and edges ";
	cin >> n >> m;
	adj = vector<vector<int>>(n);
	vis = vector<bool>(n,false);
	col = vector<int>(n, -1);
	for(int i=0; i<m; i++){          // Creating an adjacency list
		int x,y;
		cin >>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=0; i<n; i++){
		if(vis[i]==false){
			colour(i,0);   // for every unvisited node we are trying to color it with color 0 by using function colour
		}
	}
	
	if(bipartite){
		cout <<"The graph is bipartite";
	}
	else{
		cout << "the graph is not bipartite";
	}
}
