// For a Given array and an integer K representing size of subarray, Find the maximum number of perfect numbers out of all  subarrays of size k.
// Perfect number: A number for whom the sum of its proper divisors is equal to the same number  Ex: 6 (since 1+2+3 =6. All proper divisors sum = number)

// Approach
// In orginal array, take every element and if it is a perfect number, replace by 1. Else replace by 0. Now we get a binary array.
// In this binary array, search for subarray of size k that has maximum sum. Return the maximum sum which represents the number of perfect numbers in subarray
// O(n*sqrt(n)) ------- n for replacing by 1, 0. sqrt(n) to check if the number is perfect number.

#include<iostream>
#include<cmath>
using namespace std;

bool perfect(int x){        // Function to check if a given number is a perfect number
	int sum = 1;
	for(int i=2; i<=sqrt(x); i++){
		if(x % i == 0){
			if(i == x/i){
				sum += i;
			}
			else{
				sum += i+x/i;
			}
		}
	}
	if(sum==x && x>1){
		cout << sum << " ";
		return true;
	}
	return false;
}

int maxSum_SubArray(int arr[], int n, int k){      // Function to find maximum sum of subarray of size k
	if(n<k){
		return -1;
	}
	int res =0;
	for(int i=0; i<k; i++){
		res = res + arr[i];
	}
	int sum = res;
	for(int i=k; i< n; i++){
		sum = sum + arr[i] - arr[i-k];
		res = max(res, sum);		
	}
	return res;
}

// Main Function to convert array elements into binary and return max number of perfect numbers in subarray of size k
int Perfects_BinaryArray(int arr[], int n, int k){
	for(int i=0; i<n; i++){
		if( perfect(arr[i]) ){
			arr[i]=1;
		}
		else{
			arr[i]=0;
		}
	}
	return maxSum_SubArray(arr, n, k);
}

int main(){
	int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24};
	int n = 8;
	int k = 4;
	cout << Perfects_BinaryArray(arr, n, k);
}

