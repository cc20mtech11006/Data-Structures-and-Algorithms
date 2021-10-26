// Maximum path sum in a binary tree
/*   Let Binary tree  
              1
            /   \
          2      -3
           \     / \
            -5   8  7               // maxPathSum(root) ------- Output =  19      (since 6+4+9 = 19)
			/ 
		   4 
		   / \
		   6  9
*/
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

int maxPathSumUtil(node* root, int &ans){
	if(root == NULL){
		return 0;
	}
	int left = maxPathSumUtil(root->left, ans);
	int right = maxPathSumUtil(root->right, ans);
	
	int Node_CompletePathSum = max(max(root->data, root->data +left+ right), max(root->data + left, root->data +right));
	ans = max(ans, Node_CompletePathSum);     // Ans variable is updated to store maximum path sum result
	
	int Node_SinglePathSum = max(max(root->data +right, root->data+left), root->data);
	return Node_SinglePathSum;
}

int maxPathSum(node* root){
	int ans = INT_MIN;     // the final maximum path sum will be stored in this
	maxPathSumUtil(root, ans);  // a function that updates 'ans' for every node for every path
	return ans;
}

int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(-3);
	root->left->right = new node(-5);
	root->right->left = new node(8);
	root->right->right = new node(7);
	root->left->right->left = new node(4);
	root->left->right->left->left = new node(6);
	root->left->right->left->right = new node(9);
/*   Binary tree from above code
              1
            /   \
          2      -3
           \     / \
            -5   8  7               
			/ 
		   4 
		   / \
		   6  9
*/
	cout << maxPathSum(root);
	return 0;
}
