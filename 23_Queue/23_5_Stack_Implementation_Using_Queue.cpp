// Stack Implementation using queue
// Making Push operation costly
#include<iostream>
#include<queue>
using namespace std;

class stk{
	int count = 0;
	queue<int> q1;
	queue<int> q2;
	
	public:
	void push(int val){       // Making Push operation costly. Everytime we push a value into q2 and all elements of q1 are pushed into q2 making q1 empty. Then q2 and q1 are interchanged
		q2.push(val);         // In queues, push ==> enqueue, pop ==> dequeue
		count++;
		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}
		
		queue<int> temp = q1;
		q1 = q2;
		q2 = temp;
		cout << "Pushed "<< val <<endl;
	}
	
	void pop(){
		if(q1.empty()){
		cout << "Stack underflow"<<endl;
		return;
		}
		else{
		cout << "Popped "<<q1.front()<<endl;
		q1.pop();
		count--;
		}
	}
	
	void top(){
		if(q1.empty()){
		cout << "Stack underflow"<<endl;
		return;
		}
		else{
		cout << "Top element in stack = "<<q1.front()<<endl;
		}
	}
	
	void size(){
		cout << "stack size = "<< count <<endl;
	}
	
};

int main(){
	stk s;
	s.pop();
	s.push(1);
	s.push(2);
	s.size();
	s.top();
	s.pop();
	s.top();
	s.pop();
	s.top();
	s.size();
	
}
