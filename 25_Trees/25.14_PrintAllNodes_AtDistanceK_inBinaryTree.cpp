// Find all the nodes in Binary tree that are at distance k from a given target node
/*   Let Binary tree  
              1
            /   \
          2      3
           \     / \
            5   8  7               // NodesAtDistanceK(BT, 2, 3) ------- Output =  6 9 8 7      (Here target node = 2, distance k = 3)
			/ 
		   4 
		   / \
		   6  9
*/
// Case-1 Start from target node 2 and search for nodes in its lst and rst with distance k-1
// Case-2 Find ancestor of target and search for target in its sub trees. If target is found in lst, then explore the nodes in ancestors rst with distance k-1. If target is found in rst, then explore the nodes in ancestors lst with distance k-1.

#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;
	
	node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};
// Case -1. Traversing from target node to get the nodes with dist k in its lst and rst.
void printNodesInSubTree(node* root, int k){    // function to print nodes at distance k starting from current node using only its lst and rst
	if(root == NULL || k<0){
		return;
	}
	if(k==0){
		cout << root->data<< " ";
		return;
	}
	printNodesInSubTree(root->left, k-1);
	printNodesInSubTree(root->right, k-1);
}

// Case -2 Finding ancestor of target node. if target lies in lst of target, search for nodes with dist k-d in ancestors rst. if target lies in rst of ancestor, search for nodes with dist k-d in ancestors lst, where d id distance between target and ancestor
int printNodesAtDistK(node* root, node* target, int k){
	if(root == NULL){
		return -1;
	}
	if(root == target){
		printNodesInSubTree(root, k);
		return 0;
	}
	
	int ld = printNodesAtDistK(root->left, target,k);
	if(ld != -1){
		if(ld+1 == k){
			cout << root->data<<" ";
		}
		else{
			printNodesInSubTree(root->right, k-ld-2);
		}
		return ld+1;
	}
	
	int rd = printNodesAtDistK(root->right,target, k);
	if(rd != -1){
		if(rd+1 == k){
			cout << root->data<<" ";
		}
		else{
			printNodesInSubTree(root->left, k-rd-2);
		}
		return rd+1;
	}
	return -1;
}

int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->right = new node(5);
	root->right->left = new node(8);
	root->right->right = new node(7);
	root->left->right->left = new node(4);
	root->left->right->left->left = new node(6);
	root->left->right->left->right = new node(9);
/*   Binary tree from above code
              1
            /   \
          2      3
           \     / \
            5   8  7               // NodesAtDistanceK(BT, 2, 3) ------- Output =  6 9 8 7      (Here target node = 2, distance k = 3)
			/ 
		   4 
		   / \
		   6  9
*/
    node* target = root->left;   
    int k = 3;
	printNodesAtDistK(root, target, k);
	return 0;
}
