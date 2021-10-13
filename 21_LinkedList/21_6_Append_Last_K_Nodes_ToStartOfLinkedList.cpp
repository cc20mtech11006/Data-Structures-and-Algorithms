// Append last k nodes of linked list to starting of linked list
// Ex ll = 10->20->30->40->50->60->70->NULL, k= 3 -------- Output : 50->60->70->10->20->30->40->NULL

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

// length of linked list
int length(node* &head){
	int l=0;
	node* temp = head;
	while(temp!=NULL){
		temp = temp->next;
		++l;
	}
	return l;
}

// Appending last k nodes to front of linked list
node* appendKToFront(node* &head, int k){
	int l = length(head);  // finding length of linked list
	node* temp = head;
	node* tail;   // A pointer to point the tail of original LL
	node* newtail;
	node* newhead;
	
	int count =1;
	while(temp->next!= NULL){
		if(count == l-k){
			newtail = temp;   // last node of new LL is pointed by newtail
		}
		if(count == l-k+1){
			newhead = temp;   //  Starting node of new LL is pointed by newhead
		}
		temp = temp->next;
		count++;
	} 
	tail = temp;   // last node of original LL is pointed by tail
	
	// Changing links in LL
	newtail->next = NULL;
	tail->next = head;
	
	return newhead;
}

int main(){
	node* head = NULL;
	int arr[]={10, 20, 30, 40, 50, 60 , 70};
	for(int i=0; i<(sizeof(arr)/sizeof(arr[0]));i++){
		insertAtTail(head, arr[i]);
	}
	display(head);
	int k=3;
	cout <<endl<< "Appending last "<< k << " nodes to front"<<endl;
	node* newhead = appendKToFront(head, k);
	display(newhead);
}
