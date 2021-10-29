// Find an element in sorted rotated array. The rotation happened at a pivot point.
// Ex { 50, 60, 70, 80, 90, 10, 20, 30, 40}        // The sorted array is rotated from 50 which is pivot point
// We have to find index of a key in this sorted rotated array
// Ex: key = 30 ------------> Output : 7

#include<iostream>
using namespace std; 

int findKeyIn_SRArray(int arr[], int key, int left, int right){
	if(left > right){          // if left < right ==> array completed by key not found
		return -1;
	}
	int mid = (left + right)/2;   // Calculating mid
	if(key == arr[mid]){          // if mid element == key, return mid index
		return mid;
	}
	
	if(arr[left] <= arr[mid]){     // if left sub array is sorted
		if(key >= arr[left] && key <= arr[mid]){
			return findKeyIn_SRArray(arr, key, left, mid-1);  // if key lies in left sub array then recurse to find key
		}
		return findKeyIn_SRArray(arr, key, mid+1, right);     // if key lies in right sub array then recurse to find key
	}
	else{                         // if right subarray is sorted
		if(key >= arr[mid] && key <= arr[right]){
			return findKeyIn_SRArray(arr, key, mid+1, right); // if key lies in right sub array then recurse to find key
		}
		return findKeyIn_SRArray(arr, key, left, mid-1);      // if key lies in left sub array then recurse to find key
	}
}

int main(){
	int arr[]= {50, 60, 70, 80, 90, 10, 20, 30, 40};
	int key = 30;
	cout << "Index of key = "<< findKeyIn_SRArray(arr, key, 0, 8);
}
