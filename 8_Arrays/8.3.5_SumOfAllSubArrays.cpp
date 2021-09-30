// Sum of all subarrays in an array - Total n(n+1)/2 subarrays
// Sub array - subset of array which are contiguous

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<"Enter size of array: ";
	cin >> n;	
	int a[n];
	for(int i=0;i<n; i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		int sum = 0;
		for(int j=i;j<n;j++){
			sum = sum+a[j];
			cout<<sum<<endl;
		}
	}}
