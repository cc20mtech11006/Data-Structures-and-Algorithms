// Insertion Sort - 20/9/2021   ----------------------------- O(n) - n^2
#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter size of array: ";
	cin >> n;	
	int a[n];
	for(int i=0;i<n; i++){
		cin>>a[i];
	}
	
	for(int i = 1; i<n; i++){
		int current = a[i];
		int j = i-1;
		while(a[j]>current && j>=0){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]= current;
	}
	cout << "Sorted Array using insertion sort: ";
	for(int i=0;i<n; i++){
		cout<< a[i] << " ";
	}
	return 0;
}
