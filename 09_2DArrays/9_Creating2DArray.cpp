//Creating 2D Array O(n) = O(n*m)
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cout<<"Enter no of rows and cols of array: ";
	cin >> n>>m;	
	int a[n][m];	
	cout<<"Enter Elements: ";
	for(int i=0;i<n; i++){
		for(int j=0;j<m; j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n; i++){
		for(int j=0;j<m; j++){
			cout<< " "<< a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
