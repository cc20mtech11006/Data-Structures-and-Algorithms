// Finding median of running stream
// We are inserting numbers into vector, At each insert of element, we have to print the median of vector elements
// Ex: v = {10}                ---- Output : Median = 10
// Ex: v = {10, 15}            ---- Output : Median = 12.5
// Ex: v = {10, 15, 21}        ---- Output : Median = 15
// Ex: v = {10, 15, 21, 18}    ---- Output : Median = 16.5
// Ex: v = {10, 15, 21, 18, 19}---- Output : Median = 18.  In this way we insert an element into vector and find median of vector elements

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

priority_queue<int, vector<int>> max_heap;                 // First half elements of sorted vector are always in max heap
priority_queue<int, vector<int>, greater<int>> min_heap;   // Second half elements of sorted vector are always in min heap

void insert(int x){
	if(max_heap.size() == min_heap.size()){
		
		if(max_heap.size() == 0){   // Starting element always goes into max heap
			max_heap.push(x);
			return;
		}
		if(x >= max_heap.top()){     // if x > max heap top ==> x belongs to min heap or 2nd half
			min_heap.push(x);
		}
		else{
			max_heap.push(x);       // if x < max heap top ==> x belongs to max heap or 1st+ half
		}
	}
	
	else if(max_heap.size() != min_heap.size()){
		// Two cases 1) Max heap size is greater,  2) Min heap size is greater
		
		if(max_heap.size() > min_heap.size()){         // Case -1
			if(x >= max_heap.top()){
				min_heap.push(x);
			}
			else{
				int temp = max_heap.top();
				max_heap.pop();
				min_heap.push(temp);
				max_heap.push(x);
			}
		}
		
		else if(max_heap.size() < min_heap.size()){   // Case-2
			if(x <= min_heap.top()){
				max_heap.push(x);
			}
			else{
			     int temp = min_heap.top();
			     min_heap.pop();
			     max_heap.push(temp);
			     min_heap.push(x);
			}
		}
			
	}
}

double findMedian(){
	if(min_heap.size()==max_heap.size()){
		return (min_heap.top()+max_heap.top())/2.0;
	}
	else if(max_heap.size() > min_heap.size()){
		return max_heap.top();
	}
	else{
		return min_heap.top();
	}
}

int main(){
	insert(10);
	cout << findMedian()<< endl;
	insert(15);
	cout << findMedian()<< endl;
	insert(21);
	cout << findMedian()<< endl;
	insert(30);
	cout << findMedian()<< endl;
	insert(18);
	cout << findMedian()<< endl;
	insert(19);
	cout << findMedian()<< endl;
}
