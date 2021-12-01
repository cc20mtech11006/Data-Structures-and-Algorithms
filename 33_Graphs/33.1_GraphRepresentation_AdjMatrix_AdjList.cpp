// Graph Representation - Adjacency matrix and Adjacency list
// inputs:
// 7 7   1 2  1 3  2 4  2 5  2 6  2 7  7 3
// 7 7   1 2  1 3  2 4  2 5  2 6  2 7  7 3
#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
const int N= 1e5+2;
vi adj[N];

int main(){
	cout << "Enter number n and m: ";
	int n, m;     // Number of nodes, edges
	cin >> n>> m;
	
	vector<vector<int>> adjmatrix(n+1, vector<int>(n+1,0));  //Adj matrix initialised by all 0's
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		adjmatrix[x][y] = 1;
		adjmatrix[y][x] = 1;    //Replacing 0 to 1 whenever we see an edge both in X-Y and Y-X
	}
	
	cout << "Adjacency matrix of above graph is given by: "<<endl;
	for(int i=1; i<n+1;i++){          // Printing adjmatrix
		for(int j=1; j<n+1;j++){
			cout << adjmatrix[i][j]<<" ";
		}
		cout << endl;
	}
	
	if(adjmatrix[3][7]==1){
		cout << "there is a edge between 3 and 7"<<endl;
	}
	else{
		cout << "No edge"<<endl;
	}
	
	// ------------------------Adj List Creation----------------------------------
	cin >> n>>m;
	for(int i=0; i<m; i++){
		int x,y;
		cin >>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout << "adjacency list of the above graph is given by: "<<endl;
	
	for(int i=1; i<n+1;i++){
		cout << i<< " -> ";
		for(int x: adj[i]){
			cout << x<< " ";
		}
		cout << endl;
	}
}
