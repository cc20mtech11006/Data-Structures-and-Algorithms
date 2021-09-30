// Printing in spiral order of elements in 2D array.
//Ex: 1  5   7  9  10  11
//    6  10 12 13  20  21
//    9  25 29 30  32  41
//    5  59 55  63  68 70
 //   40 70  79 81  95 105
// Spiral Order Output: 1 5 7 9 10 11 21 41 70 105 95 81 79 70 40 5 9 6 10 12 13 20 32 68 63 55 59 25 29 30

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
	
	int row_start = 0, row_end = n-1,col_start =0, col_end = m-1;
	int count = m*n;
	
	while(row_start <= row_end && col_start <= col_end && count>=1){
		//For first row traversal
		for(int i = col_start; i <= col_end ;i++){
			cout<< a[row_start][i]<<" ";
			--count;
		}
		row_start++;
		
		//For last column traversal
		for(int i = row_start; i <= row_end ;i++){
			cout<< a[i][col_end]<<" ";
			--count;
		}
		col_end--;
		
		//For last row traversal
		for(int i = col_end; i >= col_start ;i--){
			cout<< a[row_end][i]<<" ";
			--count;
		}
		row_end--;
		
		//For first column traversal
		for(int i = row_end; i >= row_start ;i--){
			cout<< a[i][col_start]<<" ";
			--count;
		}
		col_start++;		
	}
	return 0;
}
