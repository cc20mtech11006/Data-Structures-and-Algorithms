// Find a pair in an array such that their sum = k. Return their indices. 
// Ex: a[] =  { 2 4 7 11 14 16 20 21}, k =31 --------- Output: 3 6  (since 11+20 = 31)
// Brute Force approach - O(n^2)   

#include<bits/stdc++.h>
using namespace std;
int pairSum(int a[],int n,int target){
	for(int i=0; i<n-1 ;i++){
		for(int j=i+1; j<n; j++){
			if(a[i]+a[j]==target){
				cout<<"indices are : "<<i <<" "<<j;
				return 1;
			}
		}
	}
	return -1;
}
int main(){
	int n, target;
	cout<<"Enter size of array: ";
	cin >> n;	
	int a[n];	
	for(int i=0;i<n; i++){
		cin>>a[i];
	}
	cout<<"Enter target value to find pair sum : ";
	cin>>target;
	
	if(pairSum(a,n,target)==1){
		return 0;
	}
	else {
		cout<< "No such pair exist in array.";
}}
