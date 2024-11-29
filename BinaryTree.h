#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

// BinaryTree class template
template <typename T>
class BinaryTree {
private:
    struct TreeNode {
        T value;
        TreeNode* left;
        TreeNode* right;

        TreeNode(T val) : value(val), left(nullptr), right(nullptr) {}; // Constructor
    };

    TreeNode* root; // Pointer to the root of the tree

    // insertNode function template
    void insertNode(TreeNode*& node, T value)
    {
        if (!node) {
            node = new TreeNode(value);
        } else if (value < node->value) {
            insertNode(node->left, value);
        } else {
            insertNode(node->right, value);
        }
    }

    // destroySubTree function template
    void destroySubTree(TreeNode* node)
    {
        if (node) {
            destroySubTree(node->left);
            destroySubTree(node->right);
            delete node;
        }
    }

    // displayInOrder function template
    void displayInOrder(TreeNode* node) const
    {
        if (node) {
            displayInOrder(node->left);
            std::cout << node->value << std::endl;
            displayInOrder(node->right);
        }
    }
    
    // searchNode function template
    bool searchNode(TreeNode* node, T value) const{
        if(!node) return false;
        if (value == node->value) return true;
        else if (value < node->value) return searchNode(node->left, value);
        else return searchNode(node->right, value);
    }
public:
    BinaryTree() : root(nullptr) {};    // Constructor
    ~BinaryTree() { destroySubTree(root); }; // Destructor
    
    void insertNode(T value) { insertNode(root, value); };
    void displayInOrder() const { displayInOrder(root); };
    bool searchNode(T value) const { return searchNode(root, value); };
};

#endif