// Build Binary Search Tree from Preorder------ O(n)
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

node* Build_BST_from_preorder(int preorder[], int *po_idx, int key, int min, int max, int n){
	if(*po_idx >= n){
		return NULL;
	}
	node* root = NULL;
	if(key > min and key < max){
		root = new node(key);
		*po_idx = *po_idx + 1;
	
	    if(*po_idx < n){
	    	root->left = Build_BST_from_preorder(preorder, po_idx, preorder[*po_idx], min,key, n);
		}
		if(*po_idx < n){
	    	root->right = Build_BST_from_preorder(preorder, po_idx, preorder[*po_idx], key, max, n);
		}
	}
	return root;
}

void printPreorder(node* root){
	if(root == NULL){
		return;
	}
	cout << root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}

int main(){
	int preorder[] = {10,2,1,13,11};
	int n = 5;
	int po_idx = 0;
	node* root = Build_BST_from_preorder(preorder, &po_idx, preorder[0], INT_MIN, INT_MAX, n);
	
	printPreorder(root);
}


