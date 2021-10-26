// Search and Delete a node in a binary search tree
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

node* insertInBST(node* root, int val){
	if(root == NULL){                                     // after traversing to correct position, inplace of null create new node and attach it to BST
		return new node(val);
	}
	if(val< root->data){                                   // Recursively traverse in LST if val< root->data until the correct position is found (that is NULL) 
		root->left = insertInBST(root->left, val);
	}
	if(val > root->data){                                 // Recursively traverse in RST if val > root->data until the correct position is found (that is NULL)
		root->right = insertInBST(root->right, val);
	}
	return root;
}

node* searchInBST(node* root, int key){   // Searching in BST
	if(root == NULL){
		return NULL;
	}
	if(key == root->data){
		return root;
	}
	if(key < root->data){
		searchInBST(root->left, key);     // search in LST if key < root->data
	}
	if(key > root->data){
		searchInBST(root->right, key);   // search in RST if key > root->data
	}

}

node* inorderSuccessor(node* root){
	node* curr = root;
	while(curr && curr->left != NULL){
		curr = curr->left;
	}
	return curr;
}

node* deleteInBST(node* root, int key){
	if(key < root->data){
		root->left = deleteInBST(root->left, key);
	}
	else if(key > root->data){
		root->right = deleteInBST(root->right, key);
	}
	// Case - 1 & 2 --------- if To be deleted node key has only one sub tree(either left or right) or when it is a leaf node
	else{       // if key == root->data
		if(root->left == NULL){    // if lst is null for node 'key', return rst root
			node* temp = root->right;
			free(root);     // free or remove the node key
			return temp; 
		}
		else if(root->right == NULL){    // if rst is null for node 'key', return lst root
			node* temp = root->left;
			free(root);
			return temp;
		}
	
	    // Case -3. When the to be deleted node key has two children lst and rst
	    node* temp = inorderSuccessor(root->right);
	    root->data = temp->data;
	    root->right = deleteInBST(root->right, temp->data);
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
	insertInBST(root, 1);
	insertInBST(root, 3);
	insertInBST(root, 7);
	insertInBST(root, 2);
	insertInBST(root, 9);
	insertInBST(root, 6);
	
	inorder(root);
	
	cout << endl;
	if(searchInBST(root, 7)== NULL){
		cout << "Node doesn't exist"<<endl;
	}
	else{
		cout << "Node Exist"<<endl;
	}
	
	root = deleteInBST(root, 9);
	inorder(root);
}
