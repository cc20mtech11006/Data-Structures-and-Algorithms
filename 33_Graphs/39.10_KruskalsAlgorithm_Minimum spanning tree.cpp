// Kruskals algorithm To find minimum spanning tree
// Sort edges by weight. Include an edge in tree if it doesn't form a cycle. repeat the procedure untill all nodes are connected.
// Input : 8 9   7 8 1   4 3 2   1 2 5   3 5 5   2 3 6  6 7 7   1 4 9   5 6 10   8 5 1
// Output : Minimum spanning tree cost = 27
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 10e5;
vector<int> parent(N);
vector<int> siz(N);

void make_set(int v){
	parent[v] = v;
	siz[v] = 1;
}

int find_set(int v){
	if(parent[v]==v){
		return v;
	}
	return parent[v] = find_set(parent[v]);
}
void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		if(siz[a]<siz[b]){
			swap(a,b);
		}
		parent[b]= a;
		siz[a] += siz[b];
	}
}

int main(){
	for(int i=0; i<N; i++){
		make_set(i);
	}
	
	cout << "Enter number of nodes and edges :";
	int n,m;
	cin >> n >> m;
	vector<vector<int>> edges;
	int x, y, w;
	cout << "Enter Node1 - Node2 - Corresponding Weight"<< endl;
	for(int i=0; i<m; i++){
		cin >> x>>y>>w;
		edges.push_back({w,x,y});
	}
	
	sort(edges.begin(), edges.end());
	int cost =0;
	for(auto i:edges){
		int weight = i[0];
		int node1 = i[1];
		int node2= i[2];
		int a = find_set(node1);
		int b = find_set(node2);
		if(a==b){
			continue;
		}
		else{
			union_set(a,b);
			cost += weight;
			cout << node1 <<" "<< node2<<endl;		
			}
	}
	cout << "Cost of minimum spanning tree = "<< cost<<endl;
}
