#include "bst.h"
#include <iostream>

using namespace std;

Node::Node(int k) {
    key = k;
    left = right = nullptr;
}

BST::BST() {
    root = nullptr;
}

Node* BST::insertRec(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insertRec(root->left, key);
    else if (key > root->key)
        root->right = insertRec(root->right, key);

    return root;
}

void BST::insert(int key) {
    root = insertRec(root, key);
}

Node* BST::deleteRec(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->key)
        root->left = deleteRec(root->left, key);
    else if (key > root->key)
        root->right = deleteRec(root->right, key);
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteRec(root->right, temp->key);
    }
    return root;
}

Node* BST::minValueNode(Node* node) {
    Node* current = node;

    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

void BST::remove(int key) {
    root = deleteRec(root, key);
}

bool BST::search(int key) {
    Node* current = root;
    while (current != nullptr) {
        if (current->key == key)
            return true;
        else if (current->key < key)
            current = current->right;
        else
            current = current->left;
    }
    return false;
}

void inorderHelper(Node* root) {
    if (root != nullptr) {
        inorderHelper(root->left);
        cout << root->key << " ";
        inorderHelper(root->right);
    }
}

void BST::inorderTraversal() {
    inorderHelper(root);
    cout << endl;
}

int heightHelper(Node* node) {
    if (node == nullptr) return -1;
    int leftHeight = heightHelper(node->left);
    int rightHeight = heightHelper(node->right);
    return 1 + max(leftHeight, rightHeight);
}

int BST::height() {
    return heightHelper(root);
}

int maxElementHelper(Node* node) {
    if (node->right == nullptr) return node->key;
    return maxElementHelper(node->right);
}

int BST::maxElement() {
    if (root == nullptr) return -1;
    return maxElementHelper(root);
}

int countNodesHelper(Node* node) {
    if (node == nullptr) return 0;
    return 1 + countNodesHelper(node->left) + countNodesHelper(node->right);
}

int BST::countNodes() {
    return countNodesHelper(root);
}

bool isBalancedHelper(Node* node) {
    if (node == nullptr) return true;
    int leftHeight = heightHelper(node->left);
    int rightHeight = heightHelper(node->right);
    return abs(leftHeight - rightHeight) <= 1 && isBalancedHelper(node->left) && isBalancedHelper(node->right);
}

bool BST::isBalanced() {
    return isBalancedHelper(root);
}

Node* lowestCommonAncestorHelper(Node* root, int key1, int key2) {
    if (root == nullptr) return nullptr;
    if (root->key == key1 || root->key == key2) return root;

    Node* leftLCA = lowestCommonAncestorHelper(root->left, key1, key2);
    Node* rightLCA = lowestCommonAncestorHelper(root->right, key1, key2);

    if (leftLCA && rightLCA) return root;

    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int BST::lowestCommonAncestor(int key1, int key2) {
    Node* lca = lowestCommonAncestorHelper(root, key1, key2);
    if (lca == nullptr) return -1;
    return lca->key;
}

// Function to find the lowest value in the BST
int minValueHelper(Node* node) {
    if (node->left == nullptr) return node->key;
    return minValueHelper(node->left);
}

int BST::minValue() {
    if (root == nullptr) return -1;
    return minValueHelper(root);
}

// Function to find the sum of all elements in the BST
int sumHelper(Node* node) {
    if (node == nullptr) return 0;
    return node->key + sumHelper(node->left) + sumHelper(node->right);
}

int BST::sum() {
    return sumHelper(root);
}

// Function to check if the BST is a valid binary search tree
bool isValidBSTHelper(Node* node, int min, int max) {
    if (node == nullptr) return true;
    if (node->key < min || node->key > max) return false;
    return isValidBSTHelper(node->left, min, node->key - 1) && isValidBSTHelper(node->right, node->key + 1, max);
}

bool BST::isValidBST() {
    return isValidBSTHelper(root, INT_MIN, INT_MAX);
}


void preorderHelper(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preorderHelper(root->left);
        preorderHelper(root->right);
    }
}

void BST::preorderTraversal() {
    preorderHelper(root);
    cout << endl;
}

void postorderHelper(Node* root) {
    if (root != nullptr) {
        postorderHelper(root->left);
        postorderHelper(root->right);
        cout << root->key << " ";
    }
}

void BST::postorderTraversal() {
    postorderHelper(root);
    cout << endl;
}