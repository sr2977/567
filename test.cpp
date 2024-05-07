#include <deepstate/DeepState.hpp>
#include "bst.h"
#include <vector>
#include <algorithm>

using namespace deepstate;

TEST(BSTTest, InsertionAndSearch) {
    BST bst;
    std::vector<int> keys = {10, 20, 30, 40, 20, 100, 32, 21, 343, 67};

    // Insertion Test
    for (int key : keys) {
        bst.insert(key);
        ASSERT_TRUE(bst.search(key));
    }
}

TEST(BSTTest, Removal) {
    BST bst;
    std::vector<int> keys = {10, 20, 30, 40, 20, 100, 32, 21, 343, 67};

    // Insert keys
    for (int key : keys) {
        bst.insert(key);
    }

    // Removal Test
    for (int key : keys) {
        bst.remove(key);
        ASSERT_FALSE(bst.search(key));
    }
}

TEST(BSTTest, Height) {
    BST bst;
    std::vector<int> keys = {10, 20, 30, 40, 20, 100, 32, 21, 343, 67};

    // Insert keys
    for (int key : keys) {
        bst.insert(key);
    }

    // Height Test
    int expectedHeight = 5; // Assuming a specific height
    ASSERT_EQ(bst.height(), expectedHeight) << bst.height();
}

TEST(BSTTest, MaxElement) {
    BST bst;
    std::vector<int> keys = {10, 20, 30, 40, 20, 100, 32, 21, 343, 67};

    // Insert keys
    for (int key : keys) {
        bst.insert(key);
    }

    // Maximum Element Test
    int expectedMax = 343;
    ASSERT_EQ(bst.maxElement(), expectedMax);
}

TEST(BSTTest, CountNodes) {
    BST bst;
    std::vector<int> keys = {10, 20, 30, 40, 20, 100, 32, 21, 343, 67};

    // Insert keys
    for (int key : keys) {
        bst.insert(key);
    }

    // Count Nodes Test
    int expectedCount = keys.size()-1; // Assuming no duplicates
    ASSERT_EQ(bst.countNodes(), expectedCount) << bst.countNodes();
}

TEST(BSTTest, IsBalanced) {
    BST bst;
    std::vector<int> keys = {10, 20, 30, 40, 20, 100, 32, 21, 343, 67};

    // Insert keys
    for (int key : keys) {
        bst.insert(key);
    }

    // Balanced Test
    ASSERT_FALSE(bst.isBalanced());
}

TEST(BSTTest, LowestCommonAncestor) {
    BST bst;
    std::vector<int> keys = {10, 20, 30, 40, 20, 100, 32, 21, 343, 67};

    // Insert keys
    for (int key : keys) {
        bst.insert(key);
    }

    // Lowest Common Ancestor Test
    int key1 = keys[0];
    int key2 = keys[1];
    ASSERT_EQ(bst.lowestCommonAncestor(key1, key2), 10) << bst.lowestCommonAncestor(key1, key2);
}

TEST(BSTTest, MinValue) {
    BST bst;
    std::vector<int> keys = {10, 20, 30, 40, 20, 100, 32, 21, 343, 67};

    // Insert keys
    for (int key : keys) {
        bst.insert(key);
    }

    // Minimum Value Test
    int expectedMin = *std::min_element(keys.begin(), keys.end());
    ASSERT_EQ(bst.minValue(), expectedMin);
}

TEST(BSTTest, IsValidBST) {
    BST bst;
    std::vector<int> keys = {10, 20, 30, 40, 20, 100, 32, 21, 343, 67};

    // Insert keys
    for (int key : keys) {
        bst.insert(key);
    }

    // Valid BST Test
    ASSERT_TRUE(bst.isValidBST());
}
