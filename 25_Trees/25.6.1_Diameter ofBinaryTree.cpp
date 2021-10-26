// Calculate diameter of Binary Tree
// Diameter of BT is the longest distance between two leaf nodes. It may or may not include root node
/*   Example:             Diameter = 7  ------- since longest distance between two leaf nodes (9,8,4,2,5,6,7) ---- doesn't include root
              1
            /   
          2      
        /  \ 
       4    5  
     /       \
    8         6
  /            \
9               7

*/

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

// Method -1 ----------- O(n^2)
int DiameterOfBinaryTree(node* root){    
	if(root == NULL){
		return 0;
	}
	int lst_height = HeightOfBinaryTree(root->left);
	int rst_height = HeightOfBinaryTree(root->right);
	int curr_diameter = lst_height + rst_height + 1;
	
	int lst_diameter = DiameterOfBinaryTree(root->left);
	int rst_diameter = DiameterOfBinaryTree(root->right);
	
	return max(curr_diameter, max(lst_diameter, rst_diameter));
}

// Method-2 ----------------- Optimised O(n)
int OptimisedDiameterOfBinaryTree(node*root, int* height){
	if(root == NULL){
		*height =0;
		return 0;
	}
	int lst_height =0, rst_height =0;
	
	int lst_diameter = OptimisedDiameterOfBinaryTree(root->left, &lst_height);
	int rst_diameter = OptimisedDiameterOfBinaryTree(root->right, &rst_height);
	
	int curr_diameter = lst_height + rst_height + 1;
	*height = max(lst_height, rst_height) +1;

	return max(curr_diameter, max(lst_diameter, rst_diameter));
}   
	

int main(){
	node* root = new node(1);
	root->left = new node(2);

	
	root->left->left = new node(4);
	root->left->left->left = new node(8);
	root->left->left->left->left = new node(9);
	root->left->right = new node(5);
	root->left->right->right = new node(6);
	root->left->right->right->left = new node(7);
	
/*   Binary tree formed from above code
              1
            /   
          2      
        /  \ 
       4    5  
     /       \
    8         6
  /            \
9               7
    
*/
	int diameter = DiameterOfBinaryTree(root);
	cout << "Diameter of given Binary Tree = "<< diameter <<endl;
	
	int height =0;
	int optimized_diameter = OptimisedDiameterOfBinaryTree(root, &height);
	cout << "Optimized method diameter = "<< optimized_diameter;
	return 0;
}
