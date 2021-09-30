// N Queen problem. We have to place n queens on a nxn board such that no two queens attck each other.
#include<iostream>
using namespace std;

// isSafe function to check if a position (x, y) is safe to place a queen
bool isSafe(int** a, int x, int y, int n){
	
	// Checking north direction of (x,y) if any queen is placed. So we see from row 0 to row x-1 if any 1 is placed in y column.
	for(int row=0; row<x;row++){
		if(a[row][y]==1){
			return false;
		}
	}
	
	// Checking North west diagonal of (x,y) if any queen is placed. So we check from (x row to 0 row) and (y col to 0 col)
	int row =x, col =y;
	while(row>=0 && col>=0){
		if(a[row][col]==1){
			return false;
		}
		row--;
		col--;
	}
	
	// Checking North east diagonal of (x,y) if any queen is placed. So we check from (x row to 0 row) and (y col to (n-1 or last) col)
	row =x, col =y;
	while(row>=0 && col<n){
		if(a[row][col]==1){
			return false;
		}
		row--;
		col++;
	}
	
	return true;  // all positions(N, NW, NE) are clear return true and the position x,y is safe.	
}

// -----------------------------------------------------------------------------------------------------------------------------------------------------

// Main backtracking function
bool nQueen(int** a, int x, int n){    // Here we do not give argument int y because each queen occupies distinct row. Later we find y for a particular x
	if(x>=n){       // implies we placed all queens and reached end of board.
		return true;
	}
	for(int col=0;col<n;col++){
		if(isSafe(a,x,col,n)){
			a[x][col]=1;
			
			if(nQueen(a,x+1,n)){       // Recursively place other queens
				return true;
			}
			a[x][col]= 0;    // BackTracking. If we are not able to place other queens
		}
	}
	return false;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------

int main(){
	cout << "Enter size of board. Enter n: ";
	int n;
	cin >> n;
	
	// Creating an 2D array of size nxn and initializing with 0.
	int** arr = new int* [n];
	for(int i=0;i<n;i++){
		arr[i]= new int [n];
		for(int j=0; j<n;j++){
			arr[i][j]=0;
		}
	}
	
	// Printing solution of nQueen if it exist
	if(nQueen(arr, 0, n)){                      // 0 indicate row number. We are starting from row 0. n is size of array(nxn)
		cout << "Solution of "<< n <<" Queen problem: "<< endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout << arr[i][j]<< " ";
			}cout << endl;
		}
	}
}
