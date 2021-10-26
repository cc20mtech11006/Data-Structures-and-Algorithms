// Find Minimum distance between two nodes in binary tree.
// We find lowest common anestor. Then find distance between lca and node1. Add it to distance between lca and node2.
/*   Let Binary tree 
              1
            /   \
          2      3
        /  \    /  \
       4    5  6    7  
	  /       /
	8        9               findDist(5,3) ------    Output: 3. (2+1 =3 =====> dist(5,1)+dist(3,1) since 1 is lca)
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

node* LCA_optimised(node* root, int n1, int n2){   // Function to find lca
	if(root == NULL){
		return NULL;
	}
	if((root->data == n1 || root->data == n2)){
		return root;
	}
	
	node* lst_lca = LCA_optimised(root->left, n1,n2);
	node* rst_lca = LCA_optimised(root->right, n1, n2);
	
	if(lst_lca && rst_lca){
		return root;
	}
	if(lst_lca != NULL){
		return lst_lca;
	}
	else{
		return rst_lca;
	}
}

int findDist(node*root, int k, int dist){   
	if(root == NULL){
		return -1;
	}
	if(root->data == k){
		return dist;
	}
	int left = findDist(root->left, k, dist+1);
	int right = findDist(root->right, k, dist+1);
	if(left != -1){
		return left;
	}
	else if(right != -1){
		return right;
	}	
}

int distBtwnNodes(node*root, int n1, int n2){
	node* lca = LCA_optimised(root, n1,n2);
	int d1 = findDist(lca, n1,0);
	int d2 = findDist(lca, n2,0);  // 0 indicates current level of binary tree
	
	return d1+d2;
}

int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right= new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	root->left->left->left = new node(8);
	root->right->left->left = new node(9);
	/*  Binary tree  from above code
              1
            /   \
          2      3
        /  \    /  \
       4    5  6    7  
	  /       /
	8        9               
*/	
	node* lca = LCA_optimised(root, 5,3);
	if(lca== NULL){
		cout << "LCA doesn't exist" << endl;
	}
	else{
		cout << "Optimised method LCA = "<< lca->data<<endl;
	}
	
	cout << " Distance between 5, 7 is : "<<distBtwnNodes(root, 5,3)<<endl;
	return 0;
}
