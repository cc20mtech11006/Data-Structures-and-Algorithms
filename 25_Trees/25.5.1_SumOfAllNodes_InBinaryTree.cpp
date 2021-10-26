// Print sum of all the node values in a given Binary tree
#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;
	
	node(int val){   //constructor
		data = val;
		left = NULL;
		right = NULL;
	}
};

int SumNodesInBinaryTree(node* root){
	if(root == NULL){
		return 0;
	}
	return SumNodesInBinaryTree(root->left) + SumNodesInBinaryTree(root->right) + root->data;  
}

int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	
	root->left->left = new node(4);
	root->left ->right = new node(5);
	
	root->right->left = new node(6);
	root->right->right = new node(7);
	
/*   Binary tree formed from above code
              1
            /   \
          2      3
        /  \    /  \
       4    5  6    7
*/
	int sum = SumNodesInBinaryTree(root);
	cout << " sum of all nodes in given Binary Tree = "<< sum <<endl;
	return 0;
}
