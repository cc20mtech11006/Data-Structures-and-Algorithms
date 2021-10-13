// Finding Intersection node value of two linked lists
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

// Making intersection between two linked lists at position 'pos' of 1st linked list
void intersect(node* &head1, node* &head2, int pos){
	node* temp1 = head1;
	pos--;
	while(pos>0){     // traversing 1st ll until pos
		temp1 = temp1->next;
		pos--;
	}
	node*temp2 = head2;
	while(temp2->next!=NULL){  // traversing to the end of 2nd ll
		temp2 = temp2->next;
	}
	temp2->next = temp1;	// last node of 2nd ll is attached to 1st ll 
}

// Finding intersection point of two linked lists
int intersection_value(node* &head1, node* &head2){   // we find intersection node value and return it
	int d=0;     // difference of lengths between two LLs
	node* ptr1;  // points longest linked list among two
	node* ptr2;  // points smallest linked list among two
	
	int l1= length(head1);
	int l2= length(head2);
	
	if(l1>l2){
		d = l1-l2;
		ptr1 = head1;
		ptr2= head2;
	}
	else{
		d = l2-l1;
		ptr1 = head2;
		ptr2 = head1;
	}
	
	while(d){     // we are traversing longest LL to d nodes so that we can start compareing equal number of nodes in both LLs.
		ptr1 = ptr1->next;
		d--;
	}
	
	while(ptr1!=NULL && ptr2!= NULL){
		if(ptr1==ptr2){                 // If both pointers points to same node implies intersection point
			return ptr1->data;
		}
		ptr1= ptr1->next;
		ptr2 = ptr2->next;
	}
	return -1;   // if their is no intersection
}

int main(){
	node* head1 = NULL;
	node* head2 = NULL;
	int arr1[]={10, 20, 30, 40, 50, 60 , 70};
	for(int i=0; i<(sizeof(arr1)/sizeof(arr1[0]));i++){
		insertAtTail(head1, arr1[i]);
	}
	
	int arr2[]={1,2};
	for(int i=0; i<(sizeof(arr2)/sizeof(arr2[0]));i++){
		insertAtTail(head2, arr2[i]);
	}
	
	intersect(head1,head2,3);  //intersect at 3rd position
	display(head1);
	display(head2);
	cout << "Value = "<< intersection_value(head1,head2);  // prints value at intersection node os two linked lists
}
