// Sum replacement Problem in Binary tree ------------ O(1)
// Replace evry root node with sum of its value plus it's Left sub tree sum plus its right sub tree sum
/*   Binary tree Example
              1
            /   \
          2      3
        /  \    
       4    5  

*/

/*   Binary tree formed after sum replacement
              15          // Root value + LST sum + RST sum = 1+11+3 = 15
            /   \
          11      3       // 2+4+5 = 11
        /  \   
       4    5  

*/

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int val){
			data =val;
			left = NULL;
			right = NULL;
		}
};

void sumReplacement(Node* root){
	if(root == NULL){
		return;
	}
	sumReplacement(root->left);
	sumReplacement(root->right);
	
	if(root->left != NULL){
		root->data = root->data + root->left->data;
	}
	if(root->right != NULL){
		root->data = root->data + root->right->data;
	}
}

void preorder(Node* root){
	if(root == NULL){
		return;
	}
	cout << root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right= new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
//	root->right->left = new Node(6);
//	root->right->right = new Node(7);
	
	preorder(root); 
	sumReplacement(root);
	cout << endl << "Preorder after sum replacement "<<endl;
	preorder(root);  // for checking result is sum replacement is done correctly or not.
	return 0;
}
