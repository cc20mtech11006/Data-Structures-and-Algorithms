// Longest arithmetic subarray length ---  20/9/2021  ------  arithmetic subarray ===> the different betwwen consecutive elements in subarray is same/constant.
// Ex: a[] = {10 7 4 6 8 10 11} ---------- difference = { 3 3 2 2 2 1} ====> answer = 4 ({4 6 8 10} is longest arithmetic subarray)

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
	int longest_len = 2; //the shortest subarray length possible for being an arithmetic subarray. When all differences are distinct
	int diff = a[0]-a[1];
	int i =2;
	int curr_len = 2;
	
	while(i<n){
		if(diff == a[i]-a[i-1]){
		curr_len++;
		}
		else{
			diff = a[i]-a[i-1];
			curr_len = 2;
		}
		longest_len = max(longest_len,curr_len);
		i++;
	}
	cout<< "Longest arithmetic subarray length = " <<longest_len;
	return 0;
}
	
	
