// Count Sort
// given an array, first calculate maximum element. And create a count array with size of maximum element.
// In count array store the frequencies of numbers in original array in corresponding index. 
// O(n) = max(A, n) , where A is the maximum element in array(since we need to create count array of that size), n is no of elements(since we need to traverse)
#include<iostream>
using namespace std;
void countSort(int a[], int n){
	int k=0;    
	for(int i=0; i<n;i++){
		k = max(k, a[i]);          // Storing Maximum element in a[] inside k.
	}
	
	int count[k];                  // Creating a count array to store frequencies of elements in a[] in corresponding indices
	for(int i=0; i<=k;i++){
		count[i]=0;               // Initializing every element in count with 0
	}
	for(int i=0; i<n;i++){
		count[a[i]]++;            // Storing frequencies of elements in count
	}
	
	for(int i=1;i<=k;i++){
		count[i]= count[i]+count[i-1];        // Cumulatively Adding up previous frequencies in count array to get index numbers of where we should store an element in output array.
	}
	
	int output[n];
	for(int i=n-1; i>=0; i--){         // Back traversing a[]
		output[--count[a[i]]] = a[i];  // Storing elements in correct index to get sorted array
	}
	for(int i=0; i<n;i++){
		a[i]= output[i];             // storing output content in a[].
	}
}

int main(){
	int a[]= { 1, 3 , 4 ,2, 4, 3, 6, 7, 5, 6 , 4, 7};
	countSort(a,12);
	for(int i=0; i<12; i++){
		cout << a[i]<< " ";
	}
	return 0;
}
