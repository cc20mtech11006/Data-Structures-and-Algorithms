// Binary tree construction using preorder and inorder
// Given Preoeder arraya and inorder array. Using these 2 arrays we have construct binary tree

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

int search(int inorder[], int start, int end, int curr){
	for(int i= start; i <=end;i++){
		if(inorder[i]==curr){
			return i;
		}
	}
	return -1;
}

node* buildTree(int preorder[], int inorder[], int start, int end){  // start, end indicate indexe pointers for starting element and last element in current inorder array. 
 	static int idx = 0;
 	if(start > end){
 		return NULL;                 // Happens when their is no right sub tree to build tree
	 }
 	int curr = preorder[idx];        // Current element which we are seeing in preorder
 	node* root = new node(curr);     // Creating a node in our tree with value curr.
 	idx++;                           // idx is a pointer to the start of postorder. It increaments after a node is created in Btree
 	
 	if(start == end){
 		return root;                 // happens when their is only 1 node in right or left sub tree
	 }
 	
 	// Now we have to find the position of curr in inorder array and recursive bulid tree for left sub tree and right sub tree
 	int pos = search(inorder, start, end, curr);
 	root->left = buildTree(preorder, inorder, start, pos-1);
 	root->right = buildTree(preorder, inorder, pos+1, end);
 	
 	return root;
}

void inordr(node* root){
		if(root == NULL){
			return;
		}
		inordr(root->left);
		cout << root->data <<" ";
		inordr(root->right);
	}

int main(){
	int preorder[]= {1,2,4,3,5};
	int inorder[]= {4,2,1,5,3};
	int start = 0;
	int end = (sizeof(preorder)/sizeof(preorder[0])) - 1;
	node* root = buildTree(preorder, inorder, start, end);  // 0,4 indicate start and end index pointers of inorder. These are useful during recursion to know where to split the LsubT, RsubT
	inordr(root);  // To check if the tree which is created is correct
}
