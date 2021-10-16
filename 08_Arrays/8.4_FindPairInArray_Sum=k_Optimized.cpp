// Find a pair in an array such that their sum = k. Return their indices. Assume the array is sorted.
// Ex: a[] =  { 2 4 7 11 14 16 20 21}, k =31 --------- Output: 3 6  (since 11+20 = 31)
// Optimized approach - O(n)   

#include<bits/stdc++.h>
using namespace std;
int pairSum(int a[],int n,int target){
	int st= 0, en = n-1;
	while(st < en){
		if(a[st]+a[en]==target){        // if pair sum = target then print indices
			cout<< st <<" "<<en;
			return 1;
		}
		else if(a[st]+a[en]<target){     // if pair sum <target increment start pointer to one step right
			st++;
		}
		else{                            // if pair sum > target decrement end pointer to one step left
			en--;
		}
	}
	return -1; // if no such pair exist whose sum is target
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
