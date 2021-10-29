// Find a peak element in an array.
// An array element is a peak if it is NOT smaller than its neighbours. For corner elements (first and last), we need to consider only one neighbour. 

#include<iostream>
using namespace std;

int findPeak(int arr[], int start, int end, int n){
	int mid = start + (end - start)/2;   // best practice in CP. Some times (start+end)/2 can exceed range
	
	if((mid==0 || arr[mid] >= arr[mid-1]) && (mid == n-1 || arr[mid]>=arr[mid+1])){
		return arr[mid];
	}
	else if(mid > 0 && arr[mid] < arr [mid-1]){
		return findPeak(arr, start, mid-1, n);
	}
	else{
		return findPeak(arr, mid+1, end, n);
	}
}
int main(){
	int arr[] = {0,6,8,5,7,9};
	cout << findPeak(arr, 0, 5, 6); //0 - starting index, 5 - last index, 6- number of elements
}
