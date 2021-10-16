// Sliding Window maximum. Find the largest element of all subarrays of size 'K' and print them ------- Using doubly ended queue (deque)
//EX; a[] = {12, 1, 78, 90, 57, 89, 56}, K = 3 --------------> Output: {78, 90, 90, 90, 89}

#include<iostream>
#include<deque>
using namespace std;

void SlidingWindowMax(int arr[], int n, int k){
	deque<int> dq(k);    // Creating a dequeue that stores useful "indices". (it doesn't store LHS values that are smaller than current value)
	
	// Processing for first window
	int i;
	for(i=0;i<k;i++){
		while(!dq.empty() && arr[i]>=arr[dq.back()]){       
			dq.pop_back();
		}
		dq.push_back(i);
	}
	
	// Processing for rest of elements in array
	for(;i<n;i++){
		cout << arr[dq.front()]<<" ";  // In every window we have to print dq.front() which gives maximum in that window
		
		// Remove all indices that doesn't belong to current window
		while(!dq.empty() && (dq.front()<= (i-k))){
			dq.pop_front();
		}
		
		// Remove all elements smaller than the currently being added element (remove useless elements) and pushback useful element index
		while(!dq.empty() && (arr[i]>=arr[dq.back()])){
			dq.pop_back();
		}
		dq.push_back(i);		
	}
	
	cout << arr[dq.front()];   // Print maximum element of last window	
}

int main()
{
    int arr[] = {12, 1, 78, 90, 57, 89, 56}; //{ 8, 5, 10, 7, 9, 4, 15, 12, 90, 13 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;          // K is window size of sliding window
    SlidingWindowMax(arr, n, k);
    return 0;
}
