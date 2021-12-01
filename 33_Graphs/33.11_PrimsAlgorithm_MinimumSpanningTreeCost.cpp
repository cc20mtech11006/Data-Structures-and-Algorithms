// Prims Algorithm
//  4 5   0 1 10   1 2 15   0 2 5   3 1 2   3 2 40

#include<bits/stdc++.h>
using namespace std;

const int N = 10e5 +3;
vector<vector<int>> adj[N];   // Adjacency list to store weight, vertex of adjacent nodes
int cost = 0;
vector<int> dist(N), parent(N);
vector<bool> visited(N);
const int INF = 10e6;

void primsMST(int source){   // source is the node from where we start our prims algorithm
	for(int i=0; i<N; i++){
		dist[i] = INF;       // For all nodes set distance = inf
	}
	dist[source] = 0;        // For source node set distance = 0
	
	set<vector<int>> set_wv;   // Initialize a set where we store weight, vertex of all reachable node
	set_wv.insert({0, source});

	while(!set_wv.empty()){
		auto x = *(set_wv.begin()); //set is always sorted by weights x[0]. So take that first edge with lowest weight
		set_wv.erase(x);
		visited[x[1]] = true;  
		int u = x[1];
		int v = parent[x[1]];    // in vector default value = 0 so parent[0] = 0
		int w = x[0];
		//cout << "Edges inserted in MST :"<< endl;
		cout << u << " "<< v << " "<<w  << endl;
		cost += w;
		
		for(auto it: adj[x[1]]){
			if(visited[it[1]]){
				continue;
			}
			if(dist[it[1]] > it[0]){   // it[0] represent weight, it[1] represent vertex
				set_wv.erase({dist[it[1]], it[1]});
				dist[it[1]] = it[0];
				set_wv.insert({dist[it[1]], it[1]});
				parent[it[1]] = x[1];
			}
		}	
	}
}


int main(){
	cout << "Enter number of nodes and edges : ";
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int u, v, w;
		cin >> u>> v>> w;
		adj[u].push_back({w,v});
		adj[v].push_back({w,u});
	}
	cout << endl;
	primsMST(0);
	cout << "Cost of Minimum Spanning tree = " << cost <<endl;
}









