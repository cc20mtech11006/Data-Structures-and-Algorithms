// Given an array of integers. And given an integer K.
// We have to check if a subarray of size k exist such that concatenation of numbers in subarray is divisible by 3.
// Ex: a[] = {8, 23, 45, 12, 56, 82}, K= 3 ------------- Output : 12 56 82 --- (since 125682  is divisible by 3)

#include<iostream>
#include<vector>
using namespace std;

void findSubArray(vector<int> a, int k){
	pair<int, int> ans;     // A apir that stores starting and ending indices of subarray if subarray satisfies condition
	int sum =0;
	for(int i=0; i<k; i++){
		sum = sum+a[i];     // Calculating sum of first subarray of size k.  // A number is divisible by 3 if sum of digits or group of digits is divisible by 3
	}
	
	bool found = false;
	if(sum%3 == 0){
		found = true;
		ans = make_pair(0,k-1);
	}
	
	for(int j=k; j < a.size(); j++){
		if(found == true){
			break;
		}
		sum = sum + a[j] - a[j-k];    // Removing starting element and adding next element  to create next window
		if(sum%3 ==0){
			found = true;
			ans = make_pair(j-k+1,j);
		}
	}
	if(!found){
		ans = make_pair(-1,0);
	}
	
	if(ans.first == -1){
		cout << "Subarray doesn't exist"<<endl;
	}
	else{
		for(int i= ans.first; i<=ans.second; i++){
			cout<< a[i]<<" ";
		}
	}
}

int main(){
	vector<int> a = {8, 23, 45, 12, 56, 82};
	int k = 3;
	findSubArray(a,k);	
}

