// odd Nodes before even nodes in Linked list
// Ex : 10->20->30->40->50->60->null   ------------   Output : 10->30->50->20->40->60->null (all odd position nodes must come before even position nodes)

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

// Function to put all odd position nodes before even position nodes
void oddBeforeEven(node* head){
	node* odd = head;     // A pointer that traverses and links all odd position nodes
	node* even = head->next;   // A pointer that traverses and links all even position nodes
	node* evenstart = head->next;    // Intializing a pointer to store first even node in LL
	while(odd->next!=NULL && even->next!=NULL){
		odd->next = even->next;  // 1st node address part overrided with 3rd node address  (1-3 link formed), later (3-5 linked formed)
		odd = odd->next;         // odd points to 3rd node
		even->next = odd->next;  // 2nd node address part overrided with 4th node address (2-4 link formed), later (4-6 link formed)
		even = even->next;      // even become 4th node address.    Similarly all odd nodes become linked and all even nodes become linked
	}
	odd->next = evenstart;  // last odd node linked to first even node
	
	if(odd->next==NULL){
		even->next = NULL;  // if LL ends with odd node, then make even node point to null.(Since this becomes end node of updated oddBeforeEven Linked list)
	}	
}

int main(){
	node* head = NULL;
	insertAtHead(head, 10);
	insertAtTail(head, 20);
	insertAtTail(head, 30);
	insertAtTail(head, 40);
	insertAtTail(head, 50);
	insertAtTail(head, 60);
	insertAtTail(head, 70);
	display(head);
	
	oddBeforeEven(head);
	display(head);
}

