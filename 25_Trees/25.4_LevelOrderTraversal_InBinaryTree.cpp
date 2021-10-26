// Level Order Traversal in Binary Tree
#include<iostream>
#include<queue>
using namespace std;


class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int val){   // Constructor
			data = val;
			left = NULL;
			right = NULL;
		}
};

void levelOrderTraversal(Node* root){
	queue<Node*> q;
	if(root == NULL){
		return;
	}
	q.push(root);         // Level 0 root is pushed
	q.push(NULL);         // After level 0 NULL is pushed into q. After every level we push null to indicate end of that level
	while(!q.empty()){
		Node* node = q.front();
		q.pop();
		if(node != NULL){     // if node not null, print node data and add left child and right child of that node into queue
			cout << node->data<<" ";
			if(node->left)
			     q.push(node->left);
			if(node->right)
				 q.push(node->right);
		}
		else if(!q.empty()){     // if node == null and q is not empty---that means we reached end of a level. 
			q.push(NULL);        // Previously we added left and right chidren of this level. Now we are adding null in queue after next level nodes or children are added
		    cout << endl;
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
	/*   Binary tree formed from above code
              1
            /   \
          2      3
        /  \    /  \
       4    5  6    7
*/
	
	levelOrderTraversal(root);
}

// queue:    1 null
//           null 2 3   ---------   pop 1 and add left and right children of 1 
//           2 3 null  ------------ pop starting null and add null at last to indicate end of level-1
//           3 null 4 5 ----------- pop 2 and add left and right children of 2
//           null 4 5 6 7 --------- pop 3 and add left and right children of 3
//           4 5 6 7 null --------- pop null and add null at last to indicate end of level-2
//           5 6 7 null ----------- pop 4 and their are no children
//           6 7 null -----------   pop 5 and their are no children
//           7 null -----------     pop 6 and their are no children
//           null -----------       pop null and q becomes empty. exit while loop and function complete.
