// Print Vertical order of Binary Tree
//                10
//              /    \
//             7      4
//           /   \   /  \
//          3   11 14   6  

//Output : 3   7   10 11 14     4    6  (verticalOrderFromLeft hdist = -2 (node 3), hdist = -1 (node 7), hdist =0 (node 10,11,14), hdist =1 (node 4), hdist = 2(node 6))

#include<iostream>
#include<map>
#include<vector>
using namespace std;

class node{
	public:
	int val;
	node* left;
	node* right;
	
	node(int data){
		val = data;
		left = NULL;
		right = NULL;
	}
};

void getVerticalOrder(node* root, int hdist, map<int, vector<int>> &m){
	if(root == NULL){
		return;
	}
	m[hdist].push_back(root->val);
	getVerticalOrder(root->left, hdist-1, m);
	getVerticalOrder(root->right, hdist+1, m);
}

int main(){ 
	node* root = new node(10);     // Creating BT
	root->left = new node(7);
	root->right = new node(4);
	root->left->left = new node(3);
	root->left->right = new node(11);
	root->right->left = new node(14);
	root->right->right = new node(6);
//                10
//              /    \
//             7      4
//           /   \   /  \
//          3   11 14   6  
	
	int hdist =0;
	map<int, vector<int>> m;
	getVerticalOrder(root, hdist, m);        // This function fills hashmap with appropriate node vlues based on horizontal distance
	
	int d =0;
	map<int, vector<int>> :: iterator it;           // Printing hashmap using iterator
	for(it = m.begin(); it!=m.end();it++){
		cout << "At Horizontal Diatance "<<d++<<" : ";
		for(int i=0; i<(*it).second.size(); i++){
			cout << ((*it).second)[i]<<" ";
		}
		cout << endl;
	}
}
