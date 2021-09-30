// To find if a given array is sorted or not using Recursion
#include<iostream>
using namespace std;
bool sorted(int a[],int n){
	if(n==1){
		return true;
	}
	if(a[n-2]<=a[n-1]){          // a from 0 to n-1.    if last element > before last element, take the sorted function from 0 to n-2  (n-1 elements)
		return sorted(a,n-1);
	}
	else{
		return false;
	}
}

int main(){
	cout << "Enter size of array: ";
	int n;
	cin >>n;
	int a[n];
	cout << "Enter array elements: ";
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(sorted(a,n)){
		cout << "Array is sorted";
	}
	else
	{cout << "Array is not sorted";}	
}
