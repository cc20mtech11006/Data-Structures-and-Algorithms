// Max till i index in an array
// EX: a[] = {0, -9, 1, 3,  -4, 5}   Output = 0, 0, 1, 3, 3, 5

#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;

int main(){
	int n;
	cout<<"Enter size of array: ";
	cin >> n;	
	int a[n];
	for(int i=0;i<n; i++){
		cin>>a[i];
	}
	
	int maxNo = INT_MIN;
	for(int i=0; i<n; i++){
		maxNo = max(maxNo, a[i]);
		cout<<maxNo <<" ";
	}
}
