// Check if two Binary Trees are identical. Same code is applicable for binary search trees as well
// root values must be same, lst, rst structure, all node values must be same
/*   Let Binary tree 1
              1
            /   \
          2      3
        /  \    /  
       4    5  6    
*/
/*   Let Binary tree 2
              1
            /   \
          2      3
        /  \    /                 Out put : True. Both are identical
       4    5  6    
*/

#include<iostream>
#include<stack>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};


bool areIdentical(Node* root1, Node* root2){
	if(root1== NULL && root2== NULL){       //  if both trees are empty, return true
		return true;
	}
	else if(root1 == NULL || root2 == NULL){   // if only 1 tree is empty, and other is not empty, return false
		return false;
	}
	else{
		bool condition1 = (root1->data == root2->data);         // Both root values must be equal
		bool condition2 = areIdentical(root1->left, root2->left);  // both trees lsts must be equal
		bool condition3 = areIdentical(root1->right, root2->right);  // both trees rsts must be equal
		
		if(condition1 && condition2 && condition3){  // if all conditions satisfy then only return true
			return true;
		}
		else{
			return false;   // if atleast 1 condition is false, then trees are not identical
		}
	}
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);		
/*   Binary tree-1 formed from above code
              1
            /   \
          2      3
        /  \    /  
       4    5  6   

*/
	Node* root1 = new Node(1);
	root1->left = new Node(2);
	root1->right = new Node(3);
	root1->left->left = new Node(4);
	root1->left->right = new Node(5);
	root1->right->left = new Node(6);		
/*   Binary tree-2 formed from above code
              1
            /   \
          2      3
        /  \    /  
       4    5   6  

*/	
	if(areIdentical(root, root1)){
		cout << "Two Binary Trees are Identical"<<endl;
	}
	else{
		cout << "Binary Trees are not identical" << endl;
	}
	return 0;
}
