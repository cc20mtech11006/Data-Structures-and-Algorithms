// Building all possible types of Binary search trees using [1,2.------,n] numbers.
// Here we use Catalan number to solve the problem

// Catalan Number
// C(n) = sigma(C(i) * C(i-1)) ---------- for i = 1 to n  
// Direct formula of C(n) = (1/(n+1) * (2nCn))

#include<iostream>
#include<vector>
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

// Function to build all possible BSTs with given numbers from 1 to n
vector<node*> build_All_BSTs(int start, int end){       // Start indicate first number, end indicate last number
	vector<node*> rootNodes_ofTrees;
	if(start > end){                         
		rootNodes_ofTrees.push_back(NULL);
		return rootNodes_ofTrees;
	}
	
	for(int rootNodeVal = start; rootNodeVal <= end; rootNodeVal++){
		vector<node*> lst_RootNodes = build_All_BSTs(start, rootNodeVal-1);   // stores root nodes of all possible BST's constructed for numbers start to currentRootVal-1. Since all these numbers are less than current root value, they must go into Left sub tree of our current BST
		vector<node*> rst_RootNodes = build_All_BSTs(rootNodeVal+1, end);    // stores root nodes of all possible BST's constructed for numbers currentRootVal-1 to end. Since all these numbers are greater than current root value, they must go into right sub tree of our current BST
		
		for(int j =0; j < lst_RootNodes.size();j++){
			node* left = lst_RootNodes[j];                // pick 1 left sub tree root node and call it left
			for(int k=0; k < rst_RootNodes.size(); k++){
				node* right = rst_RootNodes[k];           // pick 1 right sub tree root node and call it right
				
				node* curr_root = new node(rootNodeVal);    // Create current root node
				curr_root->left = left;                     // Attach left sub tree root node to current root node on left
				curr_root->right = right;                   // attach right sub tree root node to current root node on right
				rootNodes_ofTrees.push_back(curr_root);     // Insert current root node into result vector
			}
		}
	} 
	return rootNodes_ofTrees;
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
	vector<node*> rootNodes_AllBSTs;
	rootNodes_AllBSTs = build_All_BSTs(1,3);
	for(int i=0; i < rootNodes_AllBSTs.size(); i++){
		cout << i+1 << " : ";
		printPreorder(rootNodes_AllBSTs[i]);
		cout << endl;
	}
	return 0;
}
