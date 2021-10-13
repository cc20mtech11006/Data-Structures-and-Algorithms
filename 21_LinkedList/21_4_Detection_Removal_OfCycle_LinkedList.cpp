// Detect and remove cycle from linked list

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

// Detect Cycle in linked list
bool detectCycle(node* &head){
	node* fast = head;
	node* slow = head;
	
	while(fast!=NULL && fast->next!=NULL){
		fast= fast->next->next;
		slow = slow->next;
		if(fast==slow){   // if their is a cycle fast and slow meet at some point otherwise fast becomes null if no cycle exist
			return true;
		}
	}
	return false;
}

// Make cycle in Linked list  at a given position
void makeCycle(node* &head, int pos){
	node* temp = head;
	node* cylceStartNode;
	int count =1;
	while(temp->next!=NULL){
		if(count==pos){
			cylceStartNode = temp;    // set a pointer cycleStartNode to given position
		}
		temp = temp->next;
		count++;
	}
	temp->next = cylceStartNode;     // last node rejoins cycle CycleStartNode to form cycle
}

void removeCycle(node* &head){
	node* slow = head;
	node* fast = head;
	
	do{
		slow  = slow->next;
		fast = fast->next->next;
	}while(slow!=fast);
	
	fast = head;           // assigning fast to head
	while(slow->next!= fast->next){  // slow, fast continues until slow next = fast next. In that case, slow will be the last node in LL.
	slow = slow->next;
	fast = fast->next;
	}
	slow->next = NULL;  // breaking the cycle by assigning NUll to next part
}


int main(){
	node* head = NULL;
	insertAtTail(head,10);     // 10
	insertAtTail(head,20);     // 10->20
	insertAtTail(head,30);     // 10->20->30
	insertAtTail(head,40);     // 10->20->30->40
	insertAtTail(head,50);     // 10->20->30->40->50
	insertAtTail(head,60);     //// 10->20->30->40->50->60
	display(head);
	cout << detectCycle(head) <<endl; 
	cout <<"-------- Making Cycle--------"<<endl;
	makeCycle(head,3);
	cout << detectCycle(head)<<endl;   
	removeCycle(head);
	cout << detectCycle(head)<<endl;
	
}
