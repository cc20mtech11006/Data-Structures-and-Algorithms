// Transpose of square matrix

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
	cout << "Printing Original Matrix: "<<endl;
	for(int i=0;i<n; i++){
		for(int j=0;j<m; j++){
			cout<< " "<< a[i][j];
		}
		cout<<endl;
	}
	//Swapping elements of upper diagonal elements with lower diagonal elements
	int temp;
	for(int i=0;i<n; i++){
		for(int j=i;j<m; j++){
			temp =	a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
	}
	cout<< "Transposed matrix: "<<endl;
	for(int i=0;i<n; i++){
		for(int j=0;j<m; j++){
			cout<< " "<< a[i][j];
		}
		cout<<endl;
	}
}
	

