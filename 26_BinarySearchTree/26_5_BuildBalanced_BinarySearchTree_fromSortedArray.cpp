// Build Balanced Binary tree from Sorted array of elements.

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

node* buildBST_fromSA(int arr[], int start, int end){   // start indicate index of start of array, end is index of end of array
	if(start > end){
		return NULL;
	}
	int mid = (start+end)/2;                       // Compute mid index
	node* root = new node(arr[mid]);               // create a node for mid element as root
	root->left = buildBST_fromSA(arr, start, mid-1);   // split the array from start to mid-1 and mid+1 to end and compute lst and rst for mid recursively
	root->right = buildBST_fromSA(arr, mid+1, end);
	return root;	                               // return the root node 
}

void printPreorder(node* root){
	if(root == NULL){
		return;
	}
	cout << root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}

int main(){
	int sorted_arr[]= {10,20,30,40,50};
	node* root = buildBST_fromSA(sorted_arr,0,4);
	printPreorder(root);
	cout << endl;
}
