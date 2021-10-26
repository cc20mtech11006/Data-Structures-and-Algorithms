// Flatten a Binary tree. Make all nodes to form a line 
// We store root->right in temp, First we flatten left sub tree, attach it to root->right. Then using temp attach right sub tree to flattened left sub tree. 
// Again do that same with temp as root.
/*   Let Binary tree  
              1
            /   \
          2      3
           \      \
            5      7  
*/
/* flattened Binary tree
              1
               \
                2
                 \
                  5
                   \
				    3
                     \
				      7
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

void flatten(node* root){
	if(root==NULL || (root->left==NULL && root->right==NULL)){    // if root is null or we dont have lst or rst then return since its already flat
		return;
	}
	if(root->left!=NULL){
		flatten(root->left);	       // First flatten lst
	
		node* temp = root->right;      // store rst first node in a variable temp
		root->right = root->left;     // make flattened lst as a rst to root node
		root->left = NULL;           // make lst of root as null. Now lst is flattened and transfered to right
	
    	node* t = root->right;      // Traverse new right sub tree until we reach end, that is where the flattened lst ends.
	    while(t->right!=NULL){
		    t = t->right;
	    }
	    t->right = temp;           // Attach initial rst which is stored in temp to the tail end of flattened lst that is transfered to right
	}
	flatten(root->right);         // Now flatten the rst.  (We cannot write t->right here because in next iteration, root->left will be null)
}

void inorder(node* root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout << root->data<<" ";
	inorder(root->right);
}

int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right= new node(3);
	root->left->right = new node(5);
	root->right->right = new node(7);

	flatten(root);
	inorder(root);
	return 0;
}




