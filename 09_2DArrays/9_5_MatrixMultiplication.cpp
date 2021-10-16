// Matrix Multiplication ------ O(n^3)
#include<iostream>
using namespace std;
int main(){
	int x1, y1, x2, y2;
	cout<< "Enter Order of First Matrix : ";
	cin >> x1>>y1;
	cout<< "Enter Order of Second Matrix : ";
	cin >> x2>>y2;
	if(y1!=x2){
		cout<<"Matrix multiplication not possible ";
		return 0;
	}
	// Taking input array elements
	int A[x1][y1],B[x2][y2];
	cout<<"Enter elements of 1st matrix: "<<endl;
	for(int i=0;i<x1;i++){
		for(int j=0; j<y1; j++){
			cin>> A[i][j];
		}
	}
	cout<<"Enter elements of 2nd matrix: "<<endl;
	for(int i=0;i<x2;i++){
		for(int j=0; j<y2; j++){
			cin>> B[i][j];
		}
	}
	// Printing array elements
	cout << "A = "<< endl;
	for(int i=0;i<x1;i++){
		for(int j=0; j<y1; j++){
			cout<<" "<< A[i][j];
		}
		cout<< endl;
	}
		cout << "B = "<< endl;
	for(int i=0;i<x2;i++){
		for(int j=0; j<y2; j++){
			cout<<" "<< B[i][j];
		}
		cout<< endl;
	}
	int C[x1][y2];
	for(int i=0;i<x1;i++){
		for(int j=0; j<y2; j++){
			C[i][j]=0;                // setting all 0's to result matrix
		}
	}
    // Matrix Multiplication
    for(int i =0; i<x1;i++){
    	for(int j=0; j<y2; j++){
    		for(int k=0; k<y1; k++){
    			C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	cout<< "Matrix multiplication result : "<<endl;
	for(int i=0;i<x1;i++){
		for(int j=0; j<y2; j++){
			cout<<" "<< C[i][j];
		}
		cout<< endl;
	}
}
