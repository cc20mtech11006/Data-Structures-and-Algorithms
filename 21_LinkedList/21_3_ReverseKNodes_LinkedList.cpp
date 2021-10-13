// Reverse k nodes in linkedlist ------------- O(n)
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

// Function to reverse k nodes in linked list
node* reversek(node* &head, int k){
	node* prevptr = NULL;
	node* currptr = head;
	node* nextptr;
	
	int count = 0;
	while(currptr!=NULL && count<k){
		nextptr = currptr->next;
		currptr->next = prevptr; // reversing link
		
		prevptr = currptr;  // incrementing pointers
		currptr = nextptr;  // at last these two point to next set of k nodes
		count++;
	}
	if(nextptr!=NULL){
		head->next = reversek(nextptr, k);   //
	}
	return prevptr;
}

int main(){
	node* head = NULL;
	insertAtTail(head,10);     // 10
	insertAtTail(head,20);     // 10->20
	insertAtTail(head,30);     // 10->20->30
	insertAtTail(head,40);     // 10->20->30->40
	insertAtTail(head,50);
	insertAtTail(head,60);
	display(head);    
	node* newhead = reversek(head,2);  // here k=2, we can take any value to reverse k nodes
	display(newhead);

}













