// Linked List implementation of stack

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

void push(node* &top, int val){
	node* ptr = new node(val);
	ptr->next = top;
	top = ptr;	
}

void pop(node* &top){
	if(top == NULL){
		cout << "Stack underflow "<<endl;
		return;
	}
	cout << top->data << " popped"<< endl;
	top = top->next;
	
}

void Top(node* &top){
	if(top == NULL){
		cout << "Stack underflow "<<endl;
		return;
	}
	cout << "Top Element = "<< top->data << endl;
}

void empty(node* &top){
	if(top == NULL){
		cout << "Stack empty "<<endl;
	}
	else{
		cout << "Stack not empty "<< endl;
	}
}

void display(node* &top){
	node* temp = top;
	while(temp!= NULL){
		cout << temp->data << " <- ";
		temp = temp ->next;
	}cout << "NULL"<<endl;
	return;
}

int main(){
	node* st = NULL;
	push(st,2);
	push(st,3);
	push(st,4);
	push(st,5);
	display(st);
	pop(st);
	pop(st);
	display(st);
	Top(st);
	empty(st);
	pop(st);
	pop(st);
	empty(st);
}

