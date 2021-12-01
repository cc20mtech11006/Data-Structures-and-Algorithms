// Dijkstra's Algorithm - Single source shortest path
// Input :
/* 	4 4
	1 2 24
	1 4 20
	3 1 3
	4 3 12
	1
*/
// Output:
/*  1 -> 1 cost = 0
	1 -> 2 cost = 24
	1 -> 3 cost = 3
	1 -> 4 cost = 15 */

#include<bits/stdc++.h>
using namespace std;

const int inf = 1e7;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> dist(n+1, inf);
	vector<vector<pair<int, int>>> adj(n+1);
	
	for(int i=0; i<m; i++){
		int u, v,w;
		cin >> u >> v>> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	int source;
	cin >> source;
	dist[source] = 0;
	
	set<pair<int, int>> set_wv;	
	set_wv.insert({0, source});
	
	while(!set_wv.empty()){
		auto x = *(set_wv.begin());      // x -> {weight, vertex}
		set_wv.erase(x);
		for(auto it : adj[x.second]){    // it -> {vertex, weight}
			if(dist[it.first] > dist[x.second]+it.second){
				set_wv.erase({dist[it.first], it.first});
				dist[it.first] = dist[x.second] + it.second;
				set_wv.insert({dist[it.first],it.first});
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		if(dist[i] < inf){
			cout << source << " -> "<<i << " cost = "<<dist[i] <<endl;
		}
		else{
			cout << source << " -> "<<i << " cost = "<< "INF";
		}
	}
}
