// Print Left view elements in binary tree
	/*   Let Binary tree 
              1
            /   \
          2      3
        /  \    /  \
       4    5  6    7  
	  /       /
	8        9                   Output: 1 2 4 8. (In every level, we have to print left most element
*/
#include<iostream>
#include<queue>
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

void leftview(node* root){
	queue<node*> q;
	q.push(root);
	
	while(!q.empty()){		
		int n = q.size();
				
		for(int i=0;i<n;i++){            
			
			node* curr = q.front();
			q.pop();
			
			if(i == 0){       // this is the only line that differs from right view code
				cout << curr->data<<" ";
			}
			if(curr->left!=NULL){
				q.push(curr->left);
			}
			if(curr->right!= NULL){
				q.push(curr->right);
			}
		}	
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
	
	leftview(root);
	return 0;
}
