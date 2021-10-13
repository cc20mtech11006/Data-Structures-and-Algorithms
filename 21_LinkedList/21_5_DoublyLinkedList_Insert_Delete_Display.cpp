// Doubly Linked List, Insert, Delete, Display elements

#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
	node* prev;
	
	node(int val){
		data= val;
		next = NULL;
		prev = NULL;
	}
};

// Inserting an element at head of linked list
void insertAtHead(node* &head, int val){
	node* n = new node(val);
	n->next= head;
	if(head!=NULL){
		head-> prev= n;
	}
	head = n;
}

// Inserting element at tail of linked list
void insertAtTail(node* &head, int val){
	node* n = new node(val);
	if(head==NULL){       // If linked list is empty
		insertAtHead(head, val);
		return;
	}
	node* temp = head;
	while(temp->next!= NULL){
		temp = temp->next;
	}
	temp->next = n;
	n->prev= temp;
}

//Function to display linked list
void display(node* & head){
	node* temp = head;
	while(temp->next!=NULL){
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL"<<endl;
}

void deletionAtHead(node* &head){
	node* todelete= head;
	if(head==NULL){
		return;
	}
	head = head->next;
	head->prev = NULL;
	
	delete todelete;
	
}

// Function to delete node at given position in linked list
void deletion(node* &head, int pos){
	if(pos==1){
		deletionAtHead(head);
		return;
	}
	node* temp = head;
	int count =1;
	while(temp->next!=NULL && count <pos){         //Traversing until position
		temp = temp->next;
		count++;
	}
	temp->prev->next = temp->next;  // previous node of temp points points to next node of temp
	if(temp->next!=NULL){
		temp->next->prev = temp->prev;  // if next node of temp is not null, node next prev link must point to previous node of temp
	}
	delete temp;
}


int main(){
	node* head = NULL;
	insertAtHead(head,10);
	insertAtTail(head,20);
	insertAtTail(head,30);
	insertAtTail(head,40);
	insertAtTail(head,50);
	insertAtTail(head,60);
	insertAtTail(head,70);
	display(head);
	deletion(head, 4);
	display(head);
	deletionAtHead(head);
	display(head);
}






















































