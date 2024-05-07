#ifndef BST_H
#define BST_H

#include <limits.h>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k);
};

class BST {
private:
    Node* root;

    Node* insertRec(Node* root, int key);
    Node* deleteRec(Node* root, int key);
    Node* minValueNode(Node* node);

public:
    BST();
    void insert(int key);
    void remove(int key);
    bool search(int key);
    void inorderTraversal();
    int countNodes();
    bool isBalanced();
    int height();
    int maxElement();   
    int lowestCommonAncestor(int key1, int key2);
    int minValue();
    int sum();
    bool isValidBST();
    void preorderTraversal();
    void postorderTraversal();
};

#endif
