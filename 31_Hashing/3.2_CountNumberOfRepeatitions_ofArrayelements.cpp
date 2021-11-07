// Given an array of repeated values, we have to find what numbers have repeated how many times
// EX; a[] = { 2,2,2,3,3,2,4,3,4,5}   Output : 2 4,  3 3,  4 2, 5 1

#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
	
	vector<int> arr;
	cout << "Enter array elements :";
	for(int i=0; i<n; i++){
		int inp;
		cin >> inp;
		arr.push_back(inp);
	}
	
	map<int,int> freq;
	for(int i=0; i<n;i++){
		freq[arr[i]]++;        // Initially the value at all keys s will be 0. We are updating value when ever we see a key
	}
	
	map<int,int> :: iterator iter;
	for(iter = freq.begin(); iter!=freq.end();iter++){
		cout << (*iter).first <<" "<<(*iter).second <<endl;
	}
}
