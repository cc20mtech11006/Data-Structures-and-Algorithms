// Merge Sort -------------- O(n) = nlogn
// Given array is split into half recursively and then it is sorted and merged to get final sorted array

#include<iostream>
using namespace std;

void Merge(int a[],int l, int mid, int r){
	int n1 = mid-l+1;    // No of elements in left sorted array   
	int n2 = r-mid;      // No of elemts in right sorted array  
	int temp1[n1];
	int temp2[n2];
	
	for(int i=0; i<n1;i++){      // Filling temp1[] with elements of left sorted array
		temp1[i]=a[l+i];
	}
	for(int i=0; i<n2;i++){      // Filling temp2[] with elements of right sorted array
		temp2[i]=a[mid+1+i];
	}
	
	int i=0, j=0, k=l;
	while(i<n1 && j<n2){
		if(temp1[i]<temp2[j]){
			a[k]= temp1[i];
			k++;i++;
		}
		else{
			a[k]=temp2[j];
			k++;j++;
		}
	}
	while(i<n1){
		a[k]=temp1[i];
		k++; i++;
	}
	while(j<n2){
		a[k]= temp2[j];
		k++;j++;
	}
}

void MergeSort(int a[],int l, int r){
	if(l<r){
		int mid = (l+r)/2;
		MergeSort(a, l, mid);
		MergeSort(a, mid+1, r);
		
		Merge(a,l,mid,r);
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
	MergeSort(a,0, n-1);
	cout << endl<< "Sorted Array : "<< endl;
	for(int i=0;i<n;i++){
		cout << a[i]<<" ";
	}
	return 0;
}
