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

node* buildTree(int postorder[],int inorder[], int start, int end){
	static int idx = end;
	int curr = postorder[idx];
	if(start > end){
		return NULL;
	}
	node* root = new node(curr);
	idx--;                          // idx is a pointer to the end of postorder. It decrements after a node is created in Btree
	if(start == end){
		return root;
	}
	
	int pos = search(inorder, start, end, curr);
	root->right = buildTree(postorder, inorder, pos+1, end);
	root->left = buildTree(postorder, inorder, start, pos-1);
	
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
	int postorder[]= {4,2,5,3,1};
	int inorder[]= {4,2,1,5,3};
	
	int start = 0;
	int end = (sizeof(postorder)/sizeof(postorder[0])) - 1;
	node* root = buildTree(postorder, inorder, start, end);  // 0,4 indicate start and end index pointers of inorder. These are useful during recursion to know where to split the LsubT, RsubT
	inordr(root);  // to check if the tree which is created is correct
}
