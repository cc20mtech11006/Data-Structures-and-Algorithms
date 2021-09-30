// Tiling Problem
// given a 2xn board and 2x1 tiles. Find the no of ways the tiles can be arranged on the board.

#include<bits/stdc++.h>
using namespace std;
int countWays(int n){
	if(n==0){
		return 0;
	}
	if(n==1){
		return 1;
	}
	if(n==2){
		return 2;
	}
	return countWays(n-1)+countWays(n-2);     // n-1 problem size when we tile vertical, n-2 problem size when we tile horizontal.
}

int main(){
	int DimensionOf_2xn_Board;
	cout << "Enter dimension of 2xn board. Just enter n: ";
	cin >> DimensionOf_2xn_Board;
	cout << "No of tiling ways possible = "<< countWays(DimensionOf_2xn_Board)<<endl;   
	return 0;
}
