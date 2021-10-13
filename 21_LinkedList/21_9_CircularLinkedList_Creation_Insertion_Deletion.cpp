// Circular Linked Lists - Creation, Insertion, Deletion
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

// Insert at Head of Circular Linked list
void insertAtHead(node* &head, int val){
	node* n = new node(val);
	node* temp = head;
	
	if(head==NULL){    // if LL is empty, we are creating first node in LL
		head = n;
		n->next = n;
		return;
	}
	
	while(temp->next!=head){  // traversing whole LL
		temp = temp->next;
	}
	temp->next = n;    // Changing last node next to n
	n->next = head;
	head = n;
}

// Insert at Tail function in Circular linked list
void insertAtTail(node* &head, int val){
	if(head == NULL){   // If LL is empty then insert new node at head
		insertAtHead(head, val);
		return;
	}
	node* n = new node(val);   //creating new node n that has to be attached at tail of LL
	node* temp = head;
	while(temp->next!=head){  // traversing whole LL
		temp = temp->next;
	}
	temp->next = n;    // inserting node n  at the end of LL
	n->next = head;   // last node n points to head
}

// Display Linked List
void display(node* &head){
	node* temp = head;
	do{
		cout << temp->data << "->";
		temp = temp->next;
	}while(temp!=head);     // don't forget semicolon
	cout << "head"<< endl;
}

//  Delete at Head in Linked list
void deleteAtHead(node* &head){
	node* temp = head;
	while(temp->next!=head){
		temp = temp->next;
	}
	node* todelete = head;
	temp->next = head->next;
	head = head->next;
	
	delete todelete;
}

// delete a node in circular LL
void deletion(node* &head, int pos){
	if(pos==1){
		deleteAtHead(head);
		return;
	}
	node* temp = head;
	int count =1;
	while(count < pos-1){  // upto the node which is before the node to be deleted
		temp = temp->next;
		count++;
	}
	node* todelete = temp->next;
	temp->next = temp->next->next;  // Previous node must be linked to (to be deleted node's) next node
	delete todelete;
}

int main(){
	node* head = NULL;
	insertAtHead(head, 10);
	insertAtTail(head, 20);
	insertAtTail(head, 30);
	insertAtTail(head, 40);
	insertAtTail(head, 50);
	insertAtTail(head, 60);
	insertAtHead(head, 5);
	display(head);
	
	deletion(head, 3); // delete at position 3
	display(head);
	deleteAtHead(head);
	display(head);

}
