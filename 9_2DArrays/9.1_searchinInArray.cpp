//Searching element in 2D Array O(n) = O(n*m)

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
	int target;
	cout<<"Enter target: ";
	cin>> target;
	bool flag = false;
	for(int i=0;i<n; i++){
		for(int j=0;j<m; j++){
			if(a[i][j]==target){	
			cout<< i <<" "<<j;
			flag = true;}
		}
	}
	if(flag ){
		cout<<"Target found in array.";	}
	else cout<<"Target not found in array.";
	return 0;
}
