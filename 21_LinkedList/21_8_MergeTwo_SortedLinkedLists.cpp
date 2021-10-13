// Merge two sorted Linked Lists.
//Ex : ll1 = 10->20->30->40,  ll2 = 2->19->23->38->45 , Result = 2->10->19->20->23->30->38->40->45
// We shall do it it iterative and recursive ways

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

// Function to iteratively merge two sorted linked lists
node* mergeIterative(node* &head1, node* &head2){
	node* p1 = head1;  // p1 points 1st sorted LL
	node* p2 = head2;  // p2 points to 2nd sorted LL
	node* dummyNode = new node(-1);   
	node*p3 = dummyNode;   // p3 is used to link the smallest valued node from two LLs as we traverse
	
	while(p1!=NULL && p2!=NULL){
		if(p1->data < p2->data){
			p3->next = p1;
			p1= p1->next;
		}
		else{
			p3->next = p2;
			p2= p2->next;
		}
		p3 = p3->next;
	} 
	
	if(p1!= NULL){
		p3->next = p1;
		p1 = p1->next;
		p3 = p3->next;
	}
	
		if(p2!= NULL){
		p3->next = p2;
		p2 = p2->next;
		p3 = p3->next;
	}
	return dummyNode->next;
}

// Function to merge two sorted LL using recursive function
node* mergeRecursive(node* &head1, node* &head2){
	if(head2==NULL){
		return head1;
	}
	if(head1 == NULL){
		return head2;
	}
	
	node* result;
	if(head1->data < head2->data){
		result = head1;
		result->next = mergeRecursive(head1->next, head2);
	}
	else{
		result = head2;
		result->next = mergeRecursive(head1, head2->next);
	}
	return result;
}

int main(){
	node* head1 = NULL;
	node* head2 = NULL;
	int arr1[]={10, 20, 30, 40};
	for(int i=0; i<(sizeof(arr1)/sizeof(arr1[0]));i++){
		insertAtTail(head1, arr1[i]);
	}
	
	int arr2[]={2,19,23,38,45};
	for(int i=0; i<(sizeof(arr2)/sizeof(arr2[0]));i++){
		insertAtTail(head2, arr2[i]);
	}
	display(head1);
	display(head2);

//	node* newhead2 = mergeRecursive(head1, head2);   // comment one of recursive or iterative. Dont run both since we are changing heads in both cases
//	display(newhead2);
	node* newhead1 = mergeIterative(head1, head2);
	display(newhead1);
	
}
