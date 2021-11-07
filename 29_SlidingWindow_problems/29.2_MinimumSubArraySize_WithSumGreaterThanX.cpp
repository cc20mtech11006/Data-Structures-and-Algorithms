// Minimum subarray size with sum > x.
// Ex: a[] = { 1, 4, 45, 6, 10, 19} , given x = 51 -------------  Output = 3 (since {4, 45, 6} is the length of subarray with sum > 51)

#include<iostream>
using namespace std;

int findMinSubArraySize(int a[], int n, int x){
	int start = 0, end = 0, minLength = n+1, sum =0;
	while(end < n){
		while(sum <= x && end < n){    // Starting from 0th index we are moving end pointer and calculating sum
			sum += a[end++];
		}	
		
		while(sum > x && start < n){    // if sum exceeds 51, we move start pointer and decrease elements to reduce window size if sum > 51
			if(end-start < minLength){
				minLength = end-start;  // Updating min Length if we found a smaller window that has sum > 51
			}
			sum -= a[start++];          // update sum and check condition again in while loop
		}
	}
	return minLength;
}
int main(){
	int a[] = { 1, 4, 45, 6, 10, 19};
	int x = 51;          // sum must be greater than 51
	int n = 6 ;          // size of array
	int minLength = findMinSubArraySize(a, n, x);
	if(minLength == n+1){
		cout << "No such subarray exist with sum > 51";
	}
	else{
		cout << "Minimum sub array size with sum > 51 = "<< minLength;
	}
	
}
