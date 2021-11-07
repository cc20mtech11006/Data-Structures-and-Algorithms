// Find the minimum length of subsequence in array with sum >= K
// Ex: {1,1,5,3,8} K= 9 -------------- output : 2 (since {5,8} sum > 9 )

#include<iostream>
#include<queue>
using namespace std;

int main(){
	cout << "Enter number of elements: ";
	int n;
	cin >> n;
	vector<int> a(n);
	
	int k;
	cout << "Enter K : ";                // Input K, our key
	cin >>k;
	
	cout << "Enter array elements :";        
	for(int i =0; i<n;i++){                // Input array elements
		cin >>a[i];
	}
	
	priority_queue<int,vector<int>> pq;   // Initialize a max heap and push all array elements
	for(int i=0; i<n;i++){
		pq.push(a[i]);
	}
	int sum =0, count =0;                 // initialize sum , to check if sum >=k , and count to increment by 1 if a number is added to sum
	while(!pq.empty()){
		sum += pq.top();   // Add heap top value to sum
		pq.pop();
		
		count++;          // increment count which says number of array elements added so far
		if(sum >= k){     // if sum > =k  break
			break;
		}
	}
	
	if(sum < k){
		cout << -1;    // if all elements are added and still sum < k ===> No subsequence exist with sum >=k
	}
	else{
		cout << "Minimum length of subsequence with sum > k = "<<count;    // print cout, the minimum subsequence length with sum >=k
	}
	return 0;
}
