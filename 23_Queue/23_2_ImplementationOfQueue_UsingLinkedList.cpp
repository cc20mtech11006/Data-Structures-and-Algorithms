// Implementation of queue using Linked List
#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
	
	
		node(int val){
			data = val;
			next = NULL;
		}
};

class queue{
	node* front;
	node* back;
	public:
		queue(){        // Constructor
			front = NULL;
			back = NULL;
		}
		
		void enqueue(int x){        // Enqueue function to push elements at the back of queue
			node* n = new node(x);
			if(front == NULL){        // if no elements exist in queue then update boyh front and back
				front = n;
				back = n;
				cout << x << " Pushed into queue"<< endl;
				return;
			}
			back->next = n;
			back = n;
			cout << x << " Pushed into queue"<< endl;
		}
		
		void dequeue(){               // Dequeue function to pop elements from the front of queue
			if(front == NULL){        // if front is null (no elements added or all previous elements are pop and front comes right side to back. In both cases its null)
				cout << " No elements in queue "<<endl;
				return;
			}
			node* todelete = front;
			front = front->next;
			delete todelete;
			cout << "Element at front popped"<<endl;
		}
		
		void peek(){          // Peek function to print front element in queue
			if(front == NULL){        // if front is null (no elements added or all previous elements are pop and front comes right side to back. In both cases its null)
				cout << " No elements in queue "<<endl;
				return;
			}
			cout << "Front Element = "<< front->data <<endl;
			return;
		}
		 
		void empty(){           // empty function to check if queue is empty or not
			if(front == NULL){        // if front is null (no elements added or all previous elements are pop and front comes right side to back. In both cases its null)
				cout << " Queue Empty "<< endl;
				return;
			}
			else{
				cout << " Queue not empty" << endl;
				return;
			}
		}			 	
};

int main(){
	queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.empty();
	q.dequeue();
	q.peek();
	q.dequeue();
	q.peek();
	q.dequeue();
	q.peek();
	q.dequeue();
	q.empty();
}
