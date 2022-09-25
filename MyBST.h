#ifndef __MYBST_H__
#define __MYBST_H__

#include "BST.h"

class MyBST : public BST
{
	BST::BST;
    public:
        MyBST();
        vector<Rotation> transform(MyBST target);
    private:
        Node* rotateRight(Node* Q);
        Node* rotateLeft(Node* P);
};

int findKeyHeight(Node* ptr, int key_weight, int height);
int getHeight(Node* ptr);
Node* search(int weight, vector<Rotation> order);
vector<Rotation> rotate(Node* ptr, Node* target);

Node* myRotateRight(Node* Q);
Node* myRotateLeft(Node* P);

#endif /* __MYBST_H__*/