// Quick sort
// When an array is given, we fix a pivot(generally end number in array). We bring pivot to its correct position. 
// All elements less than pivot will come before pivot. All elements greater than pivot will come after pivot in the array.
// We divide the array into 2 parts at pivot position and do quicksort recursively for these 2 small arrays.
// O(n) = n^2 when array is sorted (worst case when pivot is in its correct place at end). 
// O(n) = nlogn (best case when pivot correct place is in the middle)

#include<iostream>
using namespace std;

void swap(int a[],int i, int j){
	int temp = a[i];
	a[i]=a[j];
	a[j]=temp;
}

int partition(int a[], int l, int r){
	int i = l-1;    
	int pi = r;     // setting pivot to last element in array
	
	for(int j=l;j<r;j++){
		if(a[j]<a[pi]){
			i++;
			swap(a,i,j);
		}
	}
	swap(a,i+1,pi);  // pivot comes to correct position. elements l to i are less that pivot element, pivot is at i+1, elements greater than pivot are at i+2 to j
	return i+1;
}


void QuickSort(int a[],int l, int r){
	if(l<r){
		int pi = partition(a,l,r);  // With partition function we find correct position of pivot. All elements<pi goes to left and All elements > pi goes to right.
		
		QuickSort(a, l, pi-1);        // quicksort for left side array (before pivot) 
		QuickSort(a, pi+1, r);      // quicksort for right side array (after pivot)
	}	
}

int main(){
	cout << "Enter no of elements in array : ";
	int n;
	cin >> n;
	int a[n];
	cout << "Enter array elements:  ";
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	QuickSort(a,0, n-1);
	
	cout << endl<< "Sorted Array : "<< endl;
	for(int i=0;i<n;i++){
		cout << a[i]<<" ";
	}
	return 0;
}
