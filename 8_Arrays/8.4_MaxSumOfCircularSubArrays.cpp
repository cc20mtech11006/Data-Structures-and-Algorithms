// Finding Maximum Sum of **Circular sub arrays** using Kadane's Algorithm ------------- O(n) 
// Ex : a[] = {4 -4 6 -6 10 -11 12}------------ Output: 22 (12+4+-4+6+-6+10 = 22 is the max sum of all sub arrays)
#include<bits/stdc++.h>
using namespace std;
int kadane(int a[],int n){
	int max_sum = INT_MIN;
	int cummulative_sum = 0;
	
	for(int i=0;i<n;i++){
		cummulative_sum= cummulative_sum+a[i];
		if(cummulative_sum<0){
			cummulative_sum=0;
		}
		max_sum = max(max_sum, cummulative_sum);
	}
	return max_sum;
}

int main(){
	int n;
	cout<<"Enter size of array: ";
	cin >> n;	
	int a[n];	
	for(int i=0;i<n; i++){
		cin>>a[i];
	}
    int wrapSum=0, nonWrapSum=0, max_sum = INT_MIN;
    wrapSum = kadane(a,n);
    
    int totalSum =0;
    for(int i=0;i<n; i++){
		totalSum = totalSum+a[i];      // Finding total sum of given array
		a[i]= -a[i];                   // Changing the sign of each element in array 
	}
    nonWrapSum = totalSum + kadane(a,n);   // Total sum of given array - (- (max sum of sub array in sign changed array = non contributing elements))
    
    max_sum = max(wrapSum, nonWrapSum);
    cout<< "maximum sum of circular sub array = "<<max_sum;
}
