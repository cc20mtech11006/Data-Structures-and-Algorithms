// Find number of connected components in a graph
// Input : 5 3  (nodes, edges)
//         0 1
//         2 3
//         0 4
// Output : 
// Component count = 3
// Component count = 2
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> components;
vector<bool> vis;

int get_comp(int node){
	if(vis[node]==true){
		return 0;
	}
	vis[node] = true;
	int ans =1;
	for(auto i: adj[node]){
		if(vis[i]==false){
			ans += get_comp(i);
			vis[i]=true;
		}
	}
	return ans;
}

int main(){
	int n, m;    // n: no of vertices, m: no of edges
	cout << "Enter number n and m and edges ";
	cin >> n >> m;
	adj = vector<vector<int>>(n);
	vis = vector<bool>(n,false);
	for(int i=0; i<m; i++){          // Creating an adjacency list
		int x,y;
		cin >>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=0; i<n; i++){
		if(!vis[i]){
			components.push_back(get_comp(i));
		}
	}
	for(auto i: components){
		cout <<"Component count = " << i << endl;
	}
	
}
