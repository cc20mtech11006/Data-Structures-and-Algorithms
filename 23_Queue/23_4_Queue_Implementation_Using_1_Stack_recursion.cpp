// Implementation of queue using 1 stack using recursion
#include<iostream>
#include<stack>
using namespace std;

class que{
	stack<int> s1;   // only one stack 
	
	public:
	void enqueue(int x){
		s1.push(x);           
		cout << x << " pushed into queue"<< endl;
	}
	
	int dequeue(){
		if(s1.empty()){
			cout << "Queue Underflow" << endl;
			return -1;
		}
		int element = s1.top();    // element stores top element of stack in every recursive call
		s1.pop();
		if(s1.empty()){
			return element;        // when stack becomes empty, it returns bottom element (which is to be popped)
		}
		
		int result = dequeue();   // result stores bottom element in stack (which is to be popped) // In every activation record result value will be same.(bottom element)
		s1.push(element);        // every element in initial stack except bottom element are pushed into stack in recursive calls
		return result;		
	}
	
	int empty(){
		if(s1.empty()){
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
	q.empty();
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.empty();
	cout << q.dequeue() << " popped"<< endl;
	cout << q.dequeue() << " popped"<< endl;
	cout << q.dequeue() << " popped"<< endl;
	cout << q.dequeue() << " popped"<< endl;
	q.empty();
}
