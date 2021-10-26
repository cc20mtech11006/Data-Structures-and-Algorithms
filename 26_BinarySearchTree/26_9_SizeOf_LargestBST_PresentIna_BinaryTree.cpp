// Print size of largest Binary search tree present in a given Binary Tree
/*   Binary tree-1 formed from above code
              1
            /   \
          4      7
        /  \    /  
       3    5  8                   Output : 3  (since 3 4 5 is the largest BST in the given Binary tree)
*/

#include<iostream>
#include<climits>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

struct Info{ 
	int size;       // Number of nodes in current binary tree 
	int min;        // minimum value of all nodes in current BT
	int max;       // maximum value of all nodes in current BT
	int ans;       // Size of largest BST known until now is stored in this. This is final ans which is printed in main()
	bool isBST;   // a boolean variable which tells is the BT is a BST
};

Info largestBST_in_BT(Node* root){
	if(root == NULL){
		return { 0, INT_MAX, INT_MIN, 0, true};       // If tree is empty, return these values and it is a BST 
	}
	if(root->left == NULL && root->right == NULL){
		return { 1, root->data, root->data, 1, true};   // if tree has only one node, return these values and it is a BST
	}
	
	Info curr_root_info;
	Info lst_info = largestBST_in_BT(root->left);
	Info rst_info = largestBST_in_BT(root->right);
	
	curr_root_info.size = 1+ lst_info.size + rst_info.size;    // calculate size of current Binary Tree
	
	if(lst_info.isBST == true && rst_info.isBST == true && lst_info.max < root->data && rst_info.min > root->data){  // if these 4 conditions satisfy then current BT is BST
		curr_root_info.min = min(root->data, min(lst_info.min, rst_info.min));
		curr_root_info.max = max(root->data, max(lst_info.max, rst_info.max));
		curr_root_info.ans = curr_root_info.size;
		curr_root_info.isBST = true ;              // current Binary tree is a BST
		
		return curr_root_info;
	}
	
	// if 1 of 4 conditions is false then BT is not a BST. Update info for the current root
	curr_root_info.ans = max(lst_info.ans, rst_info.ans);
	curr_root_info.isBST = false;
	
	return curr_root_info;
}

int main(){
	Node* root = new Node(6);
	root->left = new Node(4);
	root->right = new Node(7);
	root->left->left = new Node(3);
	root->left->right = new Node(5);	 
/*   Binary tree formed from above code
              6
            /   \
          4      7
        /  \      
       3    5   
*/
	cout << " Largest BST size in BT = "<< largestBST_in_BT(root).ans << endl;
	return 0;
}
