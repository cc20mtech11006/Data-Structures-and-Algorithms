// Reduce the given array.
// That means from lowest value element to highest value element in array, replace it by 0 to n-1.
// Ex: a[] = { 10 16 7 14 5 3 12 9} -------------- Output : { 4 7 2 6 1 0 5 3}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool myCompare(pair<int, int> p1, pair<int,int> p2){
	return p1.first < p2.first;
}
int main() {
	int arr[] = {10, 16, 7, 14, 5, 3, 12, 9};
	vector<pair<int ,int>> v;
	
	for(int i=0; i< (sizeof(arr)/sizeof(arr[0])); i++){
		v.push_back(make_pair(arr[i],i));                     // Making array elements pair with corresponding indexes
	}
	
	sort(v.begin(),v.end(),myCompare);      // Sorting all pairs based on array element values
	
	for(int i=0; i<v.size();i++){
		arr[v[i].second]=i;          // Reducing array elements
	}
	
	for(int i=0; i<v.size();i++){
		cout << arr[i] <<" ";           // printing reduced array
	}
}
