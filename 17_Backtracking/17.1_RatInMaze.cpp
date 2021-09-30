// Rat in maze. Given a 2D array representing a maze with obstacles represented by 0.
// We have to find a path using backtracking from upper left corner to lower right corner and print the solution path as a matrix.
// WE can either move 1 step east or 1 step south.

// Ex Input:        Ex Output:
// 1 0 1 0 1		1 0 0 0 0
// 1 1 1 1 1		1 1 1 1 0
// 0 1 0 1 0		0 0 0 1 0
// 1 0 0 1 1		0 0 0 1 1
// 1 1 1 0 1		0 0 0 0 1

#include<iostream>
using namespace std;

bool  isSafe(int** a,int x, int y, int n){     // Function to check if we are running into obstacle or borders of maze.
	if(x<n && y<n && a[x][y]==1){
		return true;
	}
	return false;
}

//------------------------------------------------------------------------------------------------------

bool  ratInMaze(int** arr, int x, int y, int n, int** solArr){
	if(x== n-1 && y== n-1){   // to check if we have reached destination lower right corner.
		solArr[x][y]=1;      
		return true;
	}
	
	if(isSafe(arr, x, y, n)){
		solArr[x][y]=1;
		if(ratInMaze(arr, x+1,y,n, solArr)){
			return true;
		}
		if(ratInMaze(arr, x, y+1, n, solArr)){
			return true;
		}
		solArr[x][y]=0;
		return false;
	}
	
	return false;
}

// -------------------------------------------------------------------------------------------------------------------------

int main(){
	cout << "Enter size of array. Enter n : ";
	int n;
	cin >> n;
	
	int** arr = new int* [n];    // Creating array of n pointers dinamycally in heap and storing address of n[0] in pointer x.
	for(int i=0; i<n;i++){
		arr[i]= new int [n];   // Creating n number of n dimentions arrays dynamically that can store our 2D matrix.
	}
	
	cout << "Enter matrix elements: ";
	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++){
			cin >> arr[i][j];      // Giving input matrix in created memory locations.
		}
	}
	
	//Creating solution array and initializing it with all 0's
	int** solArr = new int* [n];    
	for(int i=0; i<n;i++){
		solArr[i]= new int [n];  
		for(int j=0;j<n;j++){
			solArr[i][j]=0;
		}
	}
	
	if(ratInMaze(arr, 0, 0, n, solArr)==1){    // 0, 0, n indicate starting position of upper left corner(0,0) and size of matrix nxn.
	    cout <<endl << "Printing solution path: "<<endl;
		for(int i=0; i<n;i++){
		for(int j=0; j<n;j++){
			cout << solArr[i][j]<< " ";      // Giving input matrix in created memory locations.
		}cout << endl;
	}
	}
	else{
		cout << "Solution not found. Path doesn't exist."<<endl;
	}
	return 0;
}
