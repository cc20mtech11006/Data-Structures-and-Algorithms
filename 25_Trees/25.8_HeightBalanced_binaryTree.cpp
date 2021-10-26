// Program to check if a binary tree is height balanced or not
// height balanced ==> (LST height - RST height)<=1. We check if this condition is true for every node in binary tree. If all nodes satisfy this condition then BT is balanced.
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

int Height(node* root){    // O(n)
	if(root == NULL){
		return 0;
	}
	int lst_height = Height(root->left);
	int rst_height = Height(root->right);
	return max(lst_height, rst_height)+1;
}

bool heightbalanced(node* root){     //   O(n^2) : For every node we are finding height seperately
	if(root == NULL){
		return true;
	}
	if(heightbalanced(root->left)==false){
		return false;
	}
	if(heightbalanced(root->right)==false){
		return false;
	}
	int lst_height = Height(root->left);
	int rst_height = Height(root->right);
	if(abs(lst_height-rst_height)<=1){
		return true;
	}
	else{
		return false;
	}
}

bool heightbalancedOptimised(node* root, int* height){     // ---------- O(n)
	if(root == NULL){
		return true;
	}
	int lst_height =0, rst_height =0;
	if(heightbalancedOptimised(root->left, &lst_height)==false){
		return false;
	}
	if(heightbalancedOptimised(root->right, &rst_height)==false){
		return false;
	}
	*height = max(lst_height, rst_height)+1;
	if(abs(lst_height - rst_height)<=1){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right= new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	/*   Binary tree formed from above code
              1
            /   \
          2      3
        /  \    /  \
       4    5  6    7  */
	
    cout << heightbalanced(root);
    cout << endl;
    
    node* root1 = new node(1);
	root1->left = new node(2);
	root1->left->left = new node(4);
	root1->left->right = new node(5);
		/*   Binary tree formed from above code
              1
            / 
          2     
        /  \   
       4    5           */
       
    cout << heightbalanced(root1);   
    cout << endl;
    
    int height = 0;
    cout << heightbalancedOptimised(root, &height);
    cout << endl;
    cout << heightbalancedOptimised(root1, &height);
	return 0;
}
