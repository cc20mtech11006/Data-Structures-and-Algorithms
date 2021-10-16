//Creation of queue using array
#include<iostream>
#define n 100
using namespace std;

class queue{
	int* arr;
	int front;
	int back;
	
	public:
		queue(){    // constructor
			arr = new int[n];
			front = -1;
			back = -1;
		}
	
	// Enqueue Function to pust elements to back
	void enqueue(int x){
		if(back == n-1){
			cout << "Queue Overflow"<< endl;
			return;
		}
		else{
			back++;
			arr[back]=x;
			cout << x << " pushed into queue"<<endl;
			
			if(front == -1){      // if very first element is being pushed into queue then this executes
				front++;
			}
		}
	}
	
	// Dequeue function to pop elements at front of queue
	void dequeue(){
		if(front == -1 || front > back){
			cout << " Queue Underflow "<< endl;
			return;
		}
		else{
			front++;
			cout << "Front element popped in queue"<< endl;
		}
	}
	
	// Peek function to view what element is present at front
	int peek(){
		if(front == -1 || front > back){
			cout << " Queue Underflow "<< endl;
			return -1;
		}
		else{
			return arr[front];
		}
	}
	
	// empty function to see if a queue is empty
	bool empty(){
		if(front == -1 || front > back){
			return true;
		}
		else{
			return false;
		}
	}	
};

int main(){
	queue q;
	cout << q.empty()<< endl;
	q.dequeue();
	
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	
	cout << "Front element = "<<q.peek()<< endl;
	
	q.dequeue();
	cout << "Front element = "<<q.peek()<< endl;
	
	q.dequeue();
	cout <<"Front element = "<< q.peek()<< endl;
	
	q.dequeue();
	cout << "Front element = "<<q.peek()<< endl;
	
	cout << q.empty()<< endl;
}
