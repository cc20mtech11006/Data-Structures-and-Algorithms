// Search element in a sorted matrix . Matrix is sorted both by rows and columns.
// Ex: 1 4 7 11
//     2 5 8 12
//     3 6 9 16
//    10 13 14 17     target = 13        output: found

#include<iostream>
using namespace std;
int main(){
	int row, col;
	cout<< "Enter Order of  Matrix : ";
	cin >> row>>col;
    
	int a[row][col];	
	// Taking input array elements
	cout<<"Enter elements of matrix: "<<endl;
	for(int i=0;i<row;i++){
		for(int j=0; j<col; j++){
			cin>> a[i][j];
		}
	}
	cout << "Matrix = "<< endl;
	for(int i=0;i<row;i++){
		for(int j=0; j<col; j++){
			cout<<" "<< a[i][j];
		}
		cout<< endl;
	}
	
	int target;
	cout<<"Enter Target number to be found: ";
	cin >> target;
	bool found = false;
	int r = 0, c = col-1;
	while(r<row && c>=0){
		if(a[r][c]==target){
			cout << "Target found";
			found = true;
			break;
		}
		else if(a[r][c]>target){
			c--;
		}
		else r++;
	}
	
	if(found==false){
	cout<< "Target not found";
	}
}
