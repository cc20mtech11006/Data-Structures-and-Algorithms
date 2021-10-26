// Check if a given tree is BST or not
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

bool check_BST(node* root, node* min = NULL, node* max= NULL){  // min implies minimum limit of curr node, max implies maximum limit of current node
	if(root == NULL){
		return true;   // since an empty tree is bst
	}
	if(min!= NULL && root->data <= min->data){  // for curr node check if its value if less than mininum limit. if so return false
		return false;
	}
	if(max!=NULL && root->data >= max->data){  // for curr node check if its value is greater than maximum limit. if so return false
		return false;
	}                                         
	// if current node data lies between min limit and max limit it looks good, now check bst condition for the its lst and bst 
	
	bool leftValid = check_BST(root->left, min, root);
	bool rightValid = check_BST(root->right, root, max);
	return leftValid && rightValid;     // apart from current node, if its lst and rst are also valid, then return true.
}

int main(){
	node* root1 = new node(1);
	root1->left = new node(2);
	root1->right = new node(3);
	/*   1
	    / \
	   2   3
	*/   // 2 violates bst codition its >1
	if(check_BST(root1)==true){
		cout << "Valid BST"<< endl;
	}
	else{
		cout << "Invalid BST"<< endl;
	}
	
	node* root2 = new node(2);
	root2->left = new node(1);
	root2->right = new node(3);
	/*   2
	    / \
	   1   3
	*/   // its bst
	if(check_BST(root2)==true){
		cout << "Valid BST"<< endl;
	}
	else{
		cout << "Invalid BST"<< endl;
	}
}
