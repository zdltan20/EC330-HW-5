
//Leanorine Lorenzana-Garcia BU-ID: U70358223
//Zachary Tan BU-ID: U71790150

//NOTE: We are unhappy with our original solution so please IGNORE it and
//we decided to submit late instead. Please ignore the original submission


/*
Sources:
https://www.tutorialspoint.com/cplusplus-program-to-search-for-an-element-in-a-binary-search-tree for search and parentnode
https://www.geeksforgeeks.org/sum-heights-individual-nodes-binary-tree/ for height
https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/ for traversing
references used for transform:
https://stackoverflow.com/questions/14027726/is-it-always-possible-to-turn-one-bst-into-another-using-tree-rotations
https://stackoverflow.com/questions/14027726/is-it-always-possible-to-turn-one-bst-into-another-using-tree-rotations
https://www.youtube.com/watch?v=YsLko6sSKh8
https://www.youtube.com/watch?v=4u--XDffIZM
*/

#include "MyBST.h"

/**
 * Computes how to transform this MyBST into the target MyBST using rotations.
 * Returns a vector of rotations indicating which rotations around which nodes
 * must be performed to transform this into the target.
 *
 * IMPORTANT: We want to transform T1 into T2 so the call should look like
 * rotations = t1.transform(t2)
 */
 
int findKeyHeight(Node* ptr, int key_weight, int height) {
	//finds height given a target and height of ptr already
	if(ptr == NULL) return 0; //null pointer or end of branch
	if(ptr->key == key_weight) return height; //found height
	int foundHeight = findKeyHeight(ptr->left, key_weight, height + 1);
	if(foundHeight > 0) {
		return foundHeight;
	} else { 
		foundHeight = findKeyHeight(ptr->right, key_weight, height + 1);
	} 
	return foundHeight;
 }
 
int getHeight(Node* ptr) {
	if(ptr == NULL) return 0;
	int leftHeight = getHeight(ptr->left);
	int rightHeight = getHeight(ptr->right);
	if(leftHeight >= rightHeight) return leftHeight + 1;
	return rightHeight + 1;
}
 /*
 Node* search(int weight, vector<Rotation> order) {
	Node* temp = this->root;
	while(true) {
		if(temp->key == weight) {
			return temp;
		} else if(temp->key < weight) {
			temp = temp->left;
			order.push_back(Rotation(temp->key, ZAG));
		} else {
			temp = temp->right;
			order.push_back(Rotation(temp->key, ZIG));
		}
	}
	return NULL;
 }*/
 
 vector<Rotation> rotate(Node* ptr, Node* target) {
	vector<Rotation> sequence;
	//int height = getHeight(target);
	if(target == NULL) return sequence;
	if(target->left == NULL && target->right == NULL) return sequence;
	while(ptr->key != target->key) {
		if(ptr->key < target->key) {
			sequence.push_back(Rotation(ptr->key, ZAG));
			ptr = myRotateLeft(ptr);
		} else {
			sequence.push_back(Rotation(ptr->key, ZIG));
			ptr = myRotateRight(ptr);
		}
	}
	vector<Rotation> ltemp = rotate(ptr->left, target->left);
	sequence.insert(sequence.end(), ltemp.begin(), ltemp.end());
	vector<Rotation> rtemp = rotate(ptr->left, target->right);
	sequence.insert(sequence.end(), rtemp.begin(), rtemp.end());
	return sequence;
 }

 
vector<Rotation> MyBST::transform(MyBST target) {
	vector<Rotation> sequence = rotate(this->root,target.root);
	
	
	
	
    return sequence;
    	
}

Node* myRotateRight(Node* Q) {
	Node* P = Q->left;
    Q->left = P->right;
    P->right = Q;
    return P;
}

Node* myRotateLeft(Node* P) {
	Node* Q = P->right;
    P->right = Q->left;
    Q->left = P;
    return Q;
}

// You can use the rotation functions below as a starting point, 
// or you can choose your own implementation strategy. 
Node* MyBST::rotateRight(Node* Q)
{
    Node* P = Q->left;
    Q->left = P->right;
    P->right = Q;
    return P;
}

Node* MyBST::rotateLeft(Node* P)
{
    Node* Q = P->right;
    P->right = Q->left;
    Q->left = P;
    return Q;
}
