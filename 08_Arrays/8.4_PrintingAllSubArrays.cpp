// Printing all subarrays in an array. Ex: a[] = {-1 4 7 2}

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
	
	for(int i =0; i<n;i++){
		for(int j = i; j<n; j++){
			for(int k=i;k<=j;k++){
				cout<<" "<< a[k];
			}
			cout<<endl;
		}
	}
}
