// Stack implementation using queue
// Making pop operation costly
#include<iostream>
#include<queue>
using namespace std;

class stk{
	queue<int> q1;
	queue<int> q2;
	int count =0;
	
	public:
		void push(int val){   // Just push every new value into q1.
			q1.push(val);
			count++;
			cout << "Pushed "<< val <<" into stack"<<endl;
		}
		
		void pop(){        // To pop most recent element as in stack, we shift all the elements except most recent or last one into q2 and pop in q1 simultaneously
			if(q1.empty()){
				cout << "Stack Underflow"<<endl;
				return;
			}
			while(q1.front()!=q1.back()){    // Condition to check if the element is the last element entered. As we pop all remaining elements in q1 and push into q2, front = back for last element in q1
				q2.push(q1.front());
				q1.pop();       
			}
			cout << "Popped "<< q1.front() <<" from stack"<<endl;
			q1.pop();             // We pop last element in q1. ----------- Do not push into q2
			count--;
			
			queue<int> temp = q1;
			q1 = q2;
			q2 = temp;
		}
		
		int top(){
			if(q1.empty()){
				cout << "Stack underflow"<<endl;
					return -1;
			}
			else{
				cout << "Top element in stack = "<<q1.back()<<endl;
				return q1.back();
			}
		}
		
		int size(){
			cout << "Size of stack = "<<count<<endl;
			return count;
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
