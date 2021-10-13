// Reversing Linked list - Iterative way and recursive way ------ O(n),
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

// Insert element at tail in Linked list
void insertAtTail(node* &head, int val){
	node* n = new node(val);
	if(head==NULL){      // if linked list is empty
		head = n;
		return;
	}
	node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = n;
}

// Display linked list
void display(node* &head){
	node* temp = head;
	while(temp!=NULL){
		cout << temp->data <<"->";
		temp = temp->next;
	}
	cout << "NULL"<<endl;
}

// Function to reverse a linked list using iterative method
node* reverseIterative(node* &head){
	node* prevptr = NULL;   // We assign 3 pointers
	node* currptr = head;
	node* nextptr;
	
	while(currptr!= NULL){   // iteratively increment 3 pointers to next position untill NULL
		nextptr = currptr->next;  // storing next address to current node in nextptr
		currptr->next = prevptr;  // Reversing the link
		
		prevptr = currptr;  // incrementing pointers
		currptr = nextptr;
	}
	return prevptr;  // new head becomes prevptr
}

node* reverseRecursive(node* &head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	node* newhead = reverseRecursive(head->next); // calling by reference in func. So reccur traverses entire list and assigns newhead to lastnode.
	head->next->next = head;
	head->next = NULL;
	
	return newhead;

}

int main(){
	node* head = NULL;
	insertAtTail(head,10);     // 10
	insertAtTail(head,20);     // 10->20
	insertAtTail(head,30);     // 10->20->30
	insertAtTail(head,40);     // 10->20->30->40
	display(head);             // 10->20->30->40
	node* newhead1 = reverseIterative(head);
	display(newhead1);         //40->30->20->10->NULL
	node* newhead2 = reverseRecursive(newhead1);
	display(newhead2);         //10->20->30->40->NULL
}



















