// Sliding window problems
// Find the sum of subarray of size k that has the highest sum and the sum must be less than a number x.

#include<iostream>
using namespace std;

int findMaxSubArraySum(int arr[], int n, int k, int x){
	int sum =0, ans =0;
	
	for(int i=0; i<k; i++){         // Calculating first window size
		sum+= arr[i];
	}
	
	if(sum < x && sum > ans){
		ans = sum;                 //Assigning first window size to ans.
	}
	
	for(int i=k; i<n;i++){
		sum = sum - arr[i-k] + arr[i];     // Moving the window by 1 element and calculating sum
		
		if(sum < x && sum > ans){
			ans = sum;                  // updating ans to highest sum
		}
	}
	return ans;
}
int main(){
	int arr[] = {5,7,4,6,8,9};
	int k = 3;  // size of window or sub array
	int x =20;  // Sum of subarray shouldn't exceed x;
	int n = 5;  // number of elements in array
	cout << findMaxSubArraySum(arr, n, k, x); //0 - starting index, 5 - last index, 6- number of elements
}
