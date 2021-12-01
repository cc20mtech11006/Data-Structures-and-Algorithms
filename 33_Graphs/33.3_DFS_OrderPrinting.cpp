// Depth First Search Order printing
// Input : 7 7   1 2  1 3  2 4  2 5  2 6  2 7  7 3

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
int vis[N];
vector<int> adj[N];

void dfs(int node){
	// preorder part
	vis[node]=1;
	cout << node << " ";
	
	//inorder
	vector<int> :: iterator it;
	for(it = adj[node].begin(); it!=adj[node].end(); it++){
		if(vis[*it]);
		else{
			dfs(*it);
		}
	}
	
	//postorder
	// cout << node << " ";   Write this code here instead of inside preorder part to print postorder sequence of DFS
}
int main(){
	int n, m;
	cout << "Enter number n and m and edges ";
	cin >> n>>m;
        // square braces ==> array of vectors
	for(int i=0; i<m; i++){
		int x,y;
		cin >>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	for(int i=0; i<N; i++){
		vis[i] = 0;
	}
	
	dfs(1);
}
