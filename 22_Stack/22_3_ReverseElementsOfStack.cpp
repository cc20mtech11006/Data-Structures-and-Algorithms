// Reverse elements of stack
#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int element){
	if(st.empty()){
		st.push(element);
		return;
	}
	int topelement = st.top();
	st.pop();                          // pops all elemts in stack and inserts (element) at the bottom of stack and again pushes all previous elements of stack
	insertAtBottom(st, element);
	st.push(topelement);
}

void reverse(stack<int> &st){
	if(st.empty()){
		return;                // base condition
	}
	
	int element = st.top();      // stores top element in call stack activation records
	st.pop();
	reverse(st);               // recursive call for smaller stack
	insertAtBottom(st, element);
}


int main(){
	stack<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	
	reverse(st);
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
}
