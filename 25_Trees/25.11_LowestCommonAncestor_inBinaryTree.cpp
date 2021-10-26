// Program to find Lowest common ancestor(LCA) of any two nodes in binary tree
/*   Let Binary tree 
              1
            /   \
          2      3
        /  \    /  \
       4    5  6    7  
	  /       /
	8        9               LCA(9,7) ------    Output: 3. (3 is the lowest common ancestor of 9,7)
*/

#include<iostream>
#include<vector>
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

bool getPath(node*root, int key, vector<int> &path){
	if(root == NULL){
		return false;
	}
	path.push_back(root->data);
	if(root->data == key){
		return true;
	}
	if(getPath(root->left, key, path) || getPath(root->right, key, path)){
		return true;
	}
	path.pop_back();  // if path doesn't exist from root
	return false;
}

// Method -1 ----------- O(n^2) --- not optimised
int LCA(node* root, int n1, int n2){   
	vector<int> path1, path2;
	
	if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
		return -1;
	}
	
	int i;
	for(i=0;i<path1.size()&&path2.size(); i++){   // finding point of divergence of paths
		if(path1[i]!=path2[i]){
			break;
		}
	}	
	return path1[i-1];   // since i++ is executed in for loop we have to subtract by 1 to get our LCA
}

//Method - 2 ------- Optimised ------ O(n) // Both n1 and n2 must be present in binary tree for this method to work
node* LCA_optimised(node* root, int n1, int n2){
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
	
	cout << "Method-1 LCA = "<< LCA(root, 9,7)<< endl;
	node* lca = LCA_optimised(root, 9,7);
	if(lca== NULL){
		cout << "LCA doesn't exist" << endl;
	}
	else{
		cout << "Optimised method LCA = "<< lca->data<<endl;
	}
	return 0;
}
