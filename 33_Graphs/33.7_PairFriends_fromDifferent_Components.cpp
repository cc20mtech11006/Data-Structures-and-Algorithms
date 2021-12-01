// Problem is we have a graph containing different connected components. Each node represents a friend.
// We have to pair friends such that each person in a pair must belongs to diffrent connected subgraph
// How many pairs can we form ?
// ---- Same as 33.6, we find the count in each component and do further process to find no of pairs that can be formed from distict components
// Input : 5 3  (nodes, edges)
//         0 1
//         2 3
//         0 4
// Output : 
// Component count = 3
// Component count = 2
// Total pairs that can be formed = 6

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
	int no_of_pairs = 0;
	for(auto i:components){
		no_of_pairs += i * (n-i);
	}
	cout << "Total pairs that can be formed = "<< no_of_pairs/2 <<endl;	
}
