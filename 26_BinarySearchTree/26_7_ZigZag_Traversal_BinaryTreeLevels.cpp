// Zig zag traversal in level order of binary tree
	/*   Let Binary tree 
              1
            /   \
          2      3
        /  \    /  \
       4    5  6    7
      / \     / \          Output : 1  3 2  4 5 6 7  11 10 9 8  (Printing node values in zig zag manner- Left to right in one level, right to left in next level)
     8   9   10  11
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

void ZigZag_BT(Node* root){
	if(root == NULL){          // if tree is empty then return
		return;
	}
	stack<Node*> curr_level;    // stack to store current level elements
	stack<Node*> next_level;    // stack to store left and right children of current level elements
	
	bool leftToRight = true;
	curr_level.push(root);
	
	while(!curr_level.empty()){
		Node* temp = curr_level.top();
		curr_level.pop();
		
		if(temp){
			cout << temp->data <<" ";
			
			if(leftToRight){
				if(temp->left){
					next_level.push(temp->left);
				}
				if(temp->right){
					next_level.push(temp->right);
				}
			}
			
			if(!leftToRight){
				if(temp->right){
					next_level.push(temp->right);
				}
				if(temp->right){
					next_level.push(temp->left);
				}
			}
			
			if(curr_level.empty()){
				leftToRight = !leftToRight;
				swap(curr_level, next_level);
			}
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
	root->right->right = new Node(7);
	root->left->left->left = new Node(8);
	root->left->left->right = new Node(9);
	root->right->left->left = new Node(10);
	root->right->left->right = new Node(11);	
	
	/*   Binary tree formed from above code
              1
            /   \
          2      3
        /  \    /  \
       4    5  6    7
      / \     / \
     8   9   10  11
*/
	
	ZigZag_BT(root);
}
