// Print index of first repeating element  in array. 
// Constraints: O(n) must be less than O(n^2) preferably O(n) , space complexity can be O(n), N= 10^6
//Ex : a[] = {1 5 3 4 3 5 7 }           ----------- Output = 2 (since 5 is the first repeating element)

#include<iostream>
#include<climits>
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
	
	int N = 1e3+2;
	int idx[N];     //Just like bucket sort, we are creating an array to replace it with index value in a[i]th cell of idx[N]	
	for(int i=0;i<N; i++){
		idx[i]=-1;
	} 
	
	int min_index = INT_MAX;   // result will be stored in this
	
	for(int i=0;i<n;i++){
		if(idx[a[i]] != -1){
			min_index = min(min_index,idx[a[i]]);
		}
		else{
			idx[a[i]]=i;
		}
	}
	if(min_index == INT_MAX){
		cout << -1;
	}
	else{
	    cout<< min_index+1<< endl;
	}
	return 0;
}
