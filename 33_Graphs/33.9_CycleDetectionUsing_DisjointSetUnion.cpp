#include<iostream>
#include<vector>
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
	int n, m;    // n: no of vertices, m: no of edges
	cout << "Enter number n and m and edges ";
	cin >> n >> m;
	int u, v;
	vector<vector<int>> edges;
	for(int i=0; i<m; i++){
		cin >> u >> v;
		edges.push_back({u,v});
	}
	bool cycle = false;
	
	for(auto i: edges){   
		u = i[0];
		v = i[1];
		int a = find_set(u);
		int b = find_set(v);
		if(a==b){
			cycle = true;
		}
		else{
			union_set(a,b);
		}
	}
	if(cycle==true){
		cout << "Cycle present"<< endl;
	}
	else{
		cout << "Cycle not present";
	}
}


