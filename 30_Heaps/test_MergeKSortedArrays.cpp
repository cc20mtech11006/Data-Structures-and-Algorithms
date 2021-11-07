
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> ppi;

vector<int> mergeKSortedArrays(vector<vector<int>> arr){
	vector<int> output;
	
	priority_queue<ppi,vector<ppi>, greater<ppi>> pq;
	
	for(int i=0; i< arr.size(); i++){
		pq.push({arr[i][0], {i, 0}});
	}
	
	while(!pq.empty()){
		ppi curr = pq.top();
		pq.pop();
		
		int i = curr.second.first;
		int j = curr.second.second;
		
		output.push_back(curr.first);
		
		if(j+1 <arr[i].size()){
			pq.push({arr[i][j+1], {i, j+1}});
		}
	}
	return output;
}

int main(){	
	// Taking input for 2D vectors
/*	int k;
	cout << "Enter Number of arrays : ";
	cin >> k;
	
	vector<vector<int>> a(k);
	
	for(int i=0; i<k; i++){
		cout << "Enter " <<i+1 <<" th Array size : ";
		int n;
		cin >> n;
		a[i] = vector<int>(n);
		
		for(int j=0; j<n; j++){
			cin >> a[i][j];
		}
	}  */
	
	// hardcode taking input
	vector<vector<int>> arr = {{1,2,3}, {3,6,8}, {0,4,5}};
	vector<int> output = mergeKSortedArrays(arr);
	for(int i=0; i<output.size(); i++){
		cout << output[i]<<" ";
	}
	return 0;
}
