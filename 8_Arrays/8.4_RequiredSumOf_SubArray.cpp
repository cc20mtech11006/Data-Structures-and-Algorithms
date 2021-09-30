// Find start and end index of elements whose subarray sum is equal to given sum. O(n) = n
//Ex : a[]= {1 2 3 7 5}, given sum = 12         ----------- output = 2 4 (2+3+7  = 12 is the subarray)

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
	int s;
	cout << "Enter required sum of subarray: ";
	cin >> s;
	
	int sum=0, i=0, j=0, st=-1, en=-1;
	
	while(j<n && sum+a[j]<s){
		sum = sum + a[j];
		j++	;	
	}
	if(sum==s){
		cout<< i+1 <<" "<<j+1<<endl;
		return 0;
	}
	while(j<n){
		sum = sum + a[j];
		while(sum>s){
			sum = sum - a[i];
			i++;
		}
		if(sum == s){
			st = i+1;
			en = j+1;
			break;
		}
		j++;
	}
	cout<< st << " "<<en;
}
