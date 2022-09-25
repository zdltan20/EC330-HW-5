#include "node.h"

#include <iostream>
#include <cmath> //abs()
using namespace std;

/* 
https://www.tutorialspoint.com/cplusplus-program-to-search-for-an-element-in-a-binary-search-tree for search and parentnode
https://www.geeksforgeeks.org/sum-heights-individual-nodes-binary-tree/ for height
https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/ for traversing
references used for transform:
https://stackoverflow.com/questions/14027726/is-it-always-possible-to-turn-one-bst-into-another-using-tree-rotations
https://stackoverflow.com/questions/14027726/is-it-always-possible-to-turn-one-bst-into-another-using-tree-rotations
https://www.youtube.com/watch?v=YsLko6sSKh8
https://www.youtube.com/watch?v=4u--XDffIZM
*/

//function header declaration
int getWeight(node* root);

bool isWeightBalanced(node* root, int k) { 
	//if empty tree return true
	if(root == NULL) return true;
	
	//variable declaration
	bool isBalanced;
	
	//recurrsive call to check if any of the lower subtrees are weighted or not
	if(isWeightBalanced(root->left, k) && isWeightBalanced(root->right, k)) {
		isBalanced = true;
	} else {
		isBalanced = false;
	}
	
	//all lower subtrees are balanced and current subtree is balanced then true
	if(abs(getWeight(root->left) - getWeight(root->right)) <= k && isBalanced) {
		isBalanced = true;
	} else {
		isBalanced = false;
	}
	
	return isBalanced;
}

int getWeight(node* root) {
	//if pointer to NULL return nothing
	if(root == NULL) return 0;
	
	//get data for current pointer
	int weight = root->data;
	
	//recurssive call to left and right pointers
	weight += getWeight(root->left);
	weight += getWeight(root->right);
	
	return weight;
}