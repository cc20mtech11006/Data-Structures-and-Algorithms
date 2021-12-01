// Cycle detection in undirected graph
#include<bits/stdc++.h>
using namespace std;

bool iscycle(int node, vector<vector<int>> &adj, vector<bool> &visited, int parent){
	visited[node] = true;
	for(auto i: adj[node]){
		if(i != parent){      //since undirected graph we do not consider parent
			if(visited[i]){
				return true;
			}
			if((visited[i]==false) and iscycle(i,adj,visited,node)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n, m;    // n: no of vertices, m: no of edges
	cout << "Enter number n and m and edges ";
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for(int i=0; i<m; i++){          // Creating an adjacency list
		int x,y;
		cin >>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bool cycle = false;
	vector<bool> visited(n, false);
	for(int i=0; i<n; i++){
		if((visited[i]==false) and iscycle(i, adj, visited, -1)){
			cycle = true;
		}	
	}
	if(cycle){
		cout << "Cycle is present";
	}
	else{
		cout << "Cycle is not present";
	}
}
