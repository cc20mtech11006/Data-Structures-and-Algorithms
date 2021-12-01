// Optimal Merge Patterns. Given n files with computation times for merging in an array. Find the minimum time required to merge the files.
// Approach - sort the array and insert in min heap. and keep adding smallest 2 elements in the minheap and insert the sum back to minheap. Repeat until 1 element remain

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
	cout << "Enter number of files: ";
	int n;
	cin >> n;
	cout << "Enter merging times for each file: ";
	vector<int> MergeTimes(n);
	for(int i=0; i<n; i++){
		cin >> MergeTimes[i];
	}
	int ans =0;
	priority_queue<int, vector<int>, greater<int> > minheap;
	
	for(int i=0; i<n; i++){ 
		minheap.push(MergeTimes[i]);      //push all elements to min heap
	}
	
	while(minheap.size()>1){
		int t1 = minheap.top();         // take top 2 min elements and add, add result to ans and push the addition result to minheap
		minheap.pop();
		int t2 = minheap.top();
		minheap.pop();
		ans += t1+t2;
		minheap.push(t1+t2);
	}
	
	cout << "Optimal Merge time = "<<ans;
}
