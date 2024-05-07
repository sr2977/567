#include "bst.h"
#include <iostream>

using namespace std;

int main() {
    BST bst;

    // Insert some elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Perform various operations on the BST
    cout << "Inorder traversal: ";
    bst.inorderTraversal();

    cout << "Preorder traversal: ";
    bst.preorderTraversal();

    cout << "Postorder traversal: ";
    bst.postorderTraversal();

    cout << "Height of the BST: " << bst.height() << endl;

    cout << "Maximum element in the BST: " << bst.maxElement() << endl;

    cout << "Number of nodes in the BST: " << bst.countNodes() << endl;

    cout << "Sum of all elements in the BST: " << bst.sum() << endl;

    cout << "Is the BST balanced? " << (bst.isBalanced() ? "Yes" : "No") << endl;

    cout << "Lowest common ancestor of 20 and 40: " << bst.lowestCommonAncestor(20, 40) << endl;

    cout << "Minimum value in the BST: " << bst.minValue() << endl;

    cout << "Is the BST a valid binary search tree? " << (bst.isValidBST() ? "Yes" : "No") << endl;

    // Remove an element from the BST
    bst.remove(30);

    cout << "Inorder traversal after removing 30: ";
    bst.inorderTraversal();

    return 0;
}
