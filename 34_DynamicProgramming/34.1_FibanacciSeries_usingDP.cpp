// Fibanacci Series Using dunamic Programming.------------- Memoization ------ O(n) 
// Using recursion without dynamic programming is O(2^n)

#include<iostream>
using namespace std;

const int N = 10e5+6;
int dp[N];                // This is a memo

int fib(int n){
	if(n == 0 || n==1 ){
		return 0;
	}
	if(n==2){
		return 1;
	}
	 
	if(dp[n] != -1){        // if nth fibanacci is available in dp[n] then return dp[n]
		return dp[n];
	}
	
	dp[n] = fib(n-1)+fib(n-2);    // Storing nth fibanacci in dp[n] ----     Top down approach to start with nth fibanacci and go towards smaller problems
	return dp[n];
}
int main(){
	int n;
	cin >> n;
	
	for(int i=0; i<N; i++){    // Initially fill memo with -1s
		dp[i] = -1;
	}
	cout << fib(n)<<endl;
}


