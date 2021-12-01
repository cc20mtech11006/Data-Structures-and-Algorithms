// Breadth First Search order printing
// Input : 7 7   1 2  1 3  2 4  2 5  2 6  2 7  7 3
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cout << "Enter number n and m and edges ";
	cin >> n>>m;
	int N = 10e3+2;
	vector<int> adj[N];         // square braces ==> array of vectors
	for(int i=0; i<m; i++){
		int x,y;
		cin >>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	vector<int> vis(N);
	for(int i=0; i<N; i++){
		vis[i] = 0;
	}
		
	queue<int> q;
	q.push(1);
	vis[1] = true;
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		cout << node << " ";
		vector<int> :: iterator it;
		for(it = adj[node].begin(); it!= adj[node].end(); it++){
			if(!vis[*it]){
				q.push(*it);
				vis[*it] = 1;
			}
		}
	}
}
