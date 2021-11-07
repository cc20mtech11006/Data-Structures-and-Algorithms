// Heap STL functions

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
	cout << "Creating Max heap "<< endl;
	priority_queue<int, vector<int>> pq;       // By default priority queue is a max heap.
	pq.push(1);
	pq.push(2);
	pq.push(3);
	
	cout << "Top = "<< pq.top()<< endl;
	pq.pop();
	cout << "Top = "<< pq.top()<< endl;
	pq.pop();
	cout << "Top = "<< pq.top()<< endl;
	
	cout << endl << "Creating Min heap "<< endl;
	priority_queue<int, vector<int>, greater<int>> pq_min;   // By including greater<int> we are converting it to min heap.
	pq_min.push(2);
	pq_min.push(3);
	pq_min.push(1);
	
	cout << "Top = "<< pq_min.top()<< endl;
	pq_min.pop();
	cout << "Top = "<< pq_min.top()<< endl;
	pq_min.pop();
	cout << "Top = "<< pq_min.top()<< endl;
}
