//Finding Maximum Sum of sub arrays. Kadane's Algorithm ------------- O(n) 
// Ex : a[] = {-1 4 -6 7 -4}------------ Output: 7 (7 is the max sum of all sub arrays)
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
	int max_sum = INT_MIN;
	int cummulative_sum = 0;
	
	for(int i=0;i<n;i++){
		cummulative_sum= cummulative_sum+a[i];
		if(cummulative_sum<0){
			cummulative_sum=0;
		}
		max_sum = max(max_sum, cummulative_sum);
	}
	cout << "maximum sum of sub array = "<< max_sum;
}
