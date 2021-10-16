//Finding Maximum Sum of sub arrays. ------------- O(n^3) --Very bad. We will see better version of this in kadane's algo
// Ex : a[] = {-1 4 7 2}------------ Output: 13 (4+7+2 = 13 is the max sum of all sub arrays)
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
	int sum =0, max_sum = INT_MIN;
	
	for(int i =0; i<n;i++){
		for(int j = i; j<n; j++){
			sum =0;
			for(int k=i;k<=j;k++){
				sum = sum + a[k];
			}
			max_sum =max(max_sum, sum);			 
		}
	}
	cout <<" Maximum sum of sub arrays : "<<max_sum;
}
