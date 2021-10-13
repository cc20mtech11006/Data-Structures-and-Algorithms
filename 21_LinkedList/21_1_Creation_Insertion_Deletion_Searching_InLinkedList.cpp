// Creating a linked list, inserting elements at tail, inserting elements at head, 
// search an element in linked list, display the linked list, deletion of node, deletion of node at head.

#include<iostream>
using namespace std;

// Creating class node that represents a node in linked list
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

// Insert element at head in linked list
void insertAtHead(node* &head,int val){
	node* n = new node(val);
	n->next = head;
	head = n;	
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

// Searching if an element exist or not in linked list
bool search(node* p, int key){
	node* temp = p;
	while(temp!=NULL){
		if(temp->data==key){
			return true;
		}
		temp = temp->next;
	}
	return false;
}

// Delete node at head in linked list
void deleteAtHead(node* &head){
	node* todelete = head;
	head = head->next;
	delete todelete;
}

// Deletion of node in linked list
void delete_node(node* &head, int key){
	if(head==NULL){
		return;
	}
	if(head->next==NULL){
		deleteAtHead(head);
		return;
	}
	node* temp = head;
		while(temp->next->data != key){
			temp = temp->next;
			if(temp->next == NULL){
				cout << "Element not found to delete"<< endl;
				return;
			}
		}
		node* todelete = temp->next;
		temp->next = temp->next->next;
		delete todelete;
	}


//----------------------------------------------------------------------------------
int main(){
	node* head = NULL;
	node** p = &head;
	insertAtTail(head,20);     // 20
	insertAtTail(head,30);     // 20->30
	insertAtHead(head,10);     // 10->20->30
	insertAtTail(head,40);     // 10->20->30->40
	display(head);             // 10->20->30->40
	
	delete_node(head, 30);     // 10->20->40
	delete_node(head, 50);     // Element not found to delete
	display(head);             // 10->20->40
	deleteAtHead(head);        // 20->40
	display(head);             // 20->40
	
	cout << search(*p,40)<< endl;   // 1
	cout << search(*p,50)<< endl;   // 0
}














