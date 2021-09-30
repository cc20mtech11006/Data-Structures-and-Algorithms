// Count number of paths from start point(upper left) to end point(lower right) in a nxn 2D board 
// We can either go 1 step right or 1 step bottom in every step.
// * + +
// + + +
// + + x      Reach from * to x

#include<bits/stdc++.h>
#include<string>
using namespace std;
int countPath(int n,int i, int j){
	if(i==n-1 && j==n-1){   // that means we are 1 step behind the destination. (base case to stop recursion)
		return 1;
	}
	if(i>=n || j>=n){    // we came out of 
		return 0;
	}
	return countPath(n,i+1,j)+countPath(n,i,j+1);
}
	
int main(){
	int DimensionOf2Dboard;
	cout << "Enter dimension of nxn board. Just enter n: ";
	cin >> DimensionOf2Dboard;
	cout << "No of paths possible = "<< countPath(DimensionOf2Dboard, 0, 0)<<endl;   // 0 0 indicate initial i, j where we are standing(upper left)
	return 0;
}
