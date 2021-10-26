// Restore a Binary Search Tree.
// Given a binary search tree, where two nodes are swapped destorting the bst. We have to reswap the two nodes to make it a BST again.

#include<iostream>
#include<climits>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

void swap(int *a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void inorder(Node* root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout << root->data<<" ";
	inorder(root->right);
}

// Utility function to calculate pointers
void calcPointers(Node* root, Node** first, Node** mid, Node** last, Node** prev){
	if(root == NULL){
		return;
	}
	calcPointers(root->left, first, mid, last, prev);
	
	if(*prev && root->data < (*prev)->data){
		if(!*first){             // if its a first occurence of anomaly, first is initially null
			*first = *prev;      // We assign prev to first on first occurance of anomaly
			*mid = root;         // assigning mid to current node
		}
		else{
			*last = root;        // if its a second occurence of anomaly, first is not null, so it comes to else case and assign current node to last
		}
	}
	*prev = root;                // a pointer that stores the current node in this iteration. So that we can compare prev node and next iteration current node.
	calcPointers(root->right, first, mid, last, prev);
}
	
// Function to restore BST
void restoreBST(Node* root){
	Node *first, *mid, *last, *prev;         // Inorder of tree = [ 1, 9, 4, 6, 3, 13] ------ 9, 3 are swapped -------- Anomalies (9 > 4) and ( 6 > 3)
	first = NULL;   // first is used to represent First occurance of the previous node where the previous node > current node in inorder. In our case, it is 9.
	mid = NULL;     // mid is used to represent the First occurance of the current node where the previous node > current node in inorder. In our case, it is 4.
	last = NULL;    // last is used to represent the second occurance of the current node where the previous node > current node in inorder. In our case, it is 3.
	prev = NULL;    // a pointer that stores the previous node for every current node. So that we can compare prev node and current node. 
	
	calcPointers(root, &first, &mid, &last, &prev);
	
	// Case -1 ---- when the swapped nodes are not adjacent in inorder
	if(first && last){                             // first and last nodes will not be null in case-1. So swap first and last node values to correct BST
		swap(&(first->data), &(last->data));
	}
	// Case -2 ----- When the two swapped nodes are adjacent in inorder
	else if(first && mid){                        // last will be null in this case (Since swapped values are adjacent, we get 1 anomaly). So first and mid are swapped nodes. Now swap their values to correct BST
		swap(&(first->data) , &(mid->data));
	}	
}

int main(){
	Node* root = new Node(6);
	root->left = new Node(9);
	root->right = new Node(3);
	root->left->left = new Node(1);	
	root->left->right= new Node(4);
	root->right->right = new Node(13);
	/* Destorted BST formed from above code
	           6
	         /   \
	       9      3
	      / \      \
	     1   4     13             here 9 and 3 are swapped to destort bst  */
	     
	inorder(root);
	cout << endl;
	restoreBST(root);
	inorder(root);
}
