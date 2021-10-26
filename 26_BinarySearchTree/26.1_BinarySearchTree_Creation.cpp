// Binary Search Tree Creation
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

node* Insert_BST(node* root, int val){
	if(root == NULL){
		return new node(val);
	}
	if(val < root->data){
		root->left = Insert_BST(root->left, val);
	}
	if(val > root->data){
		root->right = Insert_BST(root->right, val);
	}
	return root;
}

void inorder(node* root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout << root->data<<" ";
	inorder(root->right);
}

int main(){
	node* root = new node(5);
	Insert_BST(root, 1);
	Insert_BST(root, 3);
	Insert_BST(root, 7);
	Insert_BST(root, 2);
	Insert_BST(root, 9);
	Insert_BST(root, 6);
	
	inorder(root);
}
