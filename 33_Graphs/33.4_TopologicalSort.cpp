// Topological sort in a directed acyclic graph.
// Input
// 4 4
// 0 1
// 1 2
// 2 3
// 3 4
// output : 0 1 2 3

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;    // n: no of vertices, m: no of edges
	cout << "Enter number n and m and edges ";
	cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<int> indegree(n,0);
	for(int i=0; i<m; i++){          // Creating an adjacency list
		int x,y;
		cin >>x>>y;
		adj[x].push_back(y);
		indegree[y]++;
	}
	queue<int> q;
	for(int i=0; i<n; i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		cout << x << " ";
		for(auto itr: adj[x]){
			indegree[itr]--;
			if(indegree[itr]==0){
				q.push(itr);
			}
		}
	}
}
