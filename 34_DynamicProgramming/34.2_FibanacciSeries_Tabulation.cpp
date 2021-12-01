// Fibanacci series using dynamic programming ---- Tabulation ------- O(n)
// Using recursion without dynamic programming is O(2^n)
#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> dp(n);
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	
	for(int i=3; i<=n; i++){
		dp[i] = dp[i-1]+dp[i-2];      // from bottom to top approach, solve smaller problems first, store it and use it in higher problems
	}
	
	cout << dp[n]<<endl;
}
