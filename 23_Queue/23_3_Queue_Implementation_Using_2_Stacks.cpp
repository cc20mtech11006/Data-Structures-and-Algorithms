// Queue Implementation using two stacks
#include<iostream>
#include<stack>
using namespace std;

class que{
	stack<int> s1;
	stack<int> s2;
	
	public:
	void enqueue(int x){
		s1.push(x);            // enqueue takes place in s1
		cout << x << " pushed into queue"<< endl;
	}
	
	void dequeue(){          // dequeue takes place in s2
		if(s1.empty() && s2.empty()){
			cout << "No elements in queue to pop"<<endl;
			return;
		} 
		if(s2.empty()){         // if s2 is empty, then push s1 elements into s2 and pop in s1 simultaneously. So s2 will be reverse of s1 at the end
			while(!s1.empty()){
				int top_element = s1.top();
				s2.push(top_element);
				s1.pop();
			}
		}
		int dequeue_element = s2.top();   // now s2 is not empty. top element in s2 must be popped
		s2.pop();
		cout << dequeue_element << " popped from queue"<< endl;
	}
	
	int empty(){
		if(s1.empty() && s2.empty()){
			cout << "Queue is empty"<<endl;
			return 1;
		} 
		else{
			cout << "Queue is not empty"<< endl;
			return -1;
		}
	}
};

int main(){
	que q;
	q.enqueue(1);
	q.enqueue(2);
	q.empty();
	
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.empty();
}
