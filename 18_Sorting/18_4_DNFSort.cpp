// DNF SORT ---- (DNF- dutch national flag contains 3 colours blue white red----- 0 indicate blue, 1 indicate white, 2 indicate red).
// Our array must contain only 0's, 1's, 2's
// O(n) = n
#include<iostream>
using namespace std;

void swap(int a[], int i, int j){
	int temp = a[i];
	a[i]= a[j];
	a[j]= temp;
}

void DNFSort(int a[], int n){
	int low=0, mid =0, high = n-1;  // Creating 3 pointers low, mid, high to compare elements
	while(mid<=high){
		if(a[mid]==0){
			swap(a,low, mid);
			low++, mid++;             // all zeros goes to left of low
		}
		else if(a[mid] == 1){
			mid++;                   // all 1's goes from low+1 to mid
		}
		else{                  // all 2's goes to the right of mid
			swap(a, mid, high);
			high--;
		}
	}
}
int main(){
	int a[]= { 1, 1, 2, 0, 2, 1, 0, 0, 1, 2, 0,2};
	DNFSort(a,12);
	for(int i=0; i<12; i++){
		cout << a[i]<< " ";
	}
	return 0;
}
