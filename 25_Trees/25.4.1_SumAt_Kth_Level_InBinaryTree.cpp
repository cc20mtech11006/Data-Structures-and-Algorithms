// Sum at Kth level of a binary tree.

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

int sumAtKthLevel(Node* root, int k){	
	if(root == NULL){
		return -1;
	}
	
	queue<Node*> q;
	q.push(root);         // Level 0 root is pushed
	q.push(NULL);         // After level 0 NULL is pushed into q. After every level we push null to indicate end of that level
	
	int level =0;
	int sum =0;
	
	while(!q.empty()){
		Node* node = q.front();
		q.pop();
		if(node != NULL){     // if node not null, if level = k do sum of nodes and add left child and right child of that node into queue
			if(level==k){
				sum += node->data;
			}
			if(node->left)
			     q.push(node->left);
			if(node->right)
				 q.push(node->right);
		}
		else if(!q.empty()){     // if node == null and q is not empty---that means we reached end of a level. 
			q.push(NULL);        // Previously we added left and right chidren of this level. Now we are adding null in queue after next level nodes or children are added
		    level++;
		}
	}
	return sum;
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
	int k = 2;     // k implies that level at which we want the sum of nodes in BT
	int sum = sumAtKthLevel(root, k);
	cout << "Sum at Level-"<< k << " = "<<sum;
}

// queue:    1 null
//             null 2 3   ---------   pop 1 and add left and right children of 1 
//                   2 3 null  ------------ pop null, qi snot empty so add null at rear of queue to indicate end of level-1   : Level = 1 traversal starts
//                     3 null 4 5 ----------- pop 2 and add left and right children of 2            : Level = 1
//                       null 4 5 6 7 --------- pop 3 and add left and right children of 3            : Level = 1
//                            4 5 6 7 null --------- pop null and add null at rear of queue to indicate end of level-2   : Level -2 traversal starts  sum = 0
//                              5 6 7 null ----------- pop 4 and their are no children        : Level -2  sum =4
//                                6 7 null -----------   pop 5 and their are no children        : Level -2  sum = 9
//                                  7 null -----------     pop 6 and their are no children        : Level -2 
//                                    null -----------     pop 7 and their are no children        : Level -2 
//                                         -----------       pop null and q becomes empty. exit while loop and function complete.
