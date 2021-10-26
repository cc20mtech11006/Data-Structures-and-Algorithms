// Calculate height of Binary tree
// height calculation always starts from root to leaf

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

int HeightOfBinaryTree(node* root){
	if(root == NULL){
		return 0;
	}
	int lst_height = HeightOfBinaryTree(root->left);
	int rst_height = HeightOfBinaryTree(root->right);
	return max(lst_height, rst_height)+1;
}

int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	
	root->left->left = new node(4);
	root->left->left->left = new node(8);
	root->left->left->left->left = new node(9);
	root->left ->right = new node(5);
	
	root->right->left = new node(6);
	root->right->right = new node(7);
	
/*   Binary tree formed from above code
              1
            /   \
          2      3
        /  \    /  \
       4    5  6    7
     /
    8
  /
9

*/
	int height = HeightOfBinaryTree(root);
	cout << " Height of given Binary Tree = "<< height <<endl;
	return 0;
}
