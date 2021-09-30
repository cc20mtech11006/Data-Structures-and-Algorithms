// 0-1 knapsack problem
// Given n objects along with weight and value of each object. Given a knapsack which can hold a weight of W. 
// Find the maximum value that can be obtained by placing objects(0or1 no division) in knapsack.

#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int value[],int n, int W){
	if(n==0||W==0){
		return 0;
	}
	if(wt[n-1]>W){
		return knapsack(wt, value, n-1, W);
	}
	return max(knapsack(wt, value, n-1, W-wt[n-1])+value[n-1], knapsack(wt, value, n-1, W));
}
int main(){
	int wt[]= {10, 20, 30};  // weight of each object
	int value[]= { 100, 50, 150};   // value of each object
	int W = 50;   // Maximum weight that can be held by knapsack
	cout << "Maximum value that can be obtained by placing objects in knapsack = "<<knapsack(wt, value, 3 , W)<<endl;
}
