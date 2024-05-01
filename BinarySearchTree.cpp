// BinarySearchTree.cpp
#include "BinarySearchTree.h"
#include <iostream>
#include <stdexcept>

using namespace BST_NS;

// Forward declarations for helper functions
template <typename T>
TreeNode<T>* findMin(TreeNode<T>* node);

template <typename T>
int computeHeight(TreeNode<T>* node);

// BinarySearchTree class implementation

// Copy constructor
template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other) : root(nullptr), tree_size(0) {
    // Use a recursive helper function to copy the tree
    auto copyTree = [](TreeNode<T>* node) -> TreeNode<T>* {
        if (!node) return nullptr;
        TreeNode<T>* newNode = new TreeNode<T>(node->data, copyTree(node->leftLink), copyTree(node->rightLink));
        return newNode;
    };
    root = copyTree(other.root);
    tree_size = other.tree_size;
}

// Destructor
template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    makeEmpty();  // Ensure proper cleanup of nodes
}

// Insert item into the BST
template <typename T>
void BinarySearchTree<T>::insert(T item) {
    if (!root) {
        root = new TreeNode<T>(item, nullptr, nullptr);
    } else {
        TreeNode<T>* current = root;
        while (true) {
            if (item < current->data) {
                if (current->leftLink) {
                    current = current->leftLink;
                } else {
                    current->leftLink = new TreeNode<T>(item, nullptr, nullptr);
                    break;
                }
            } else if (item > current->data) {
                if (current->rightLink) {
                    current = current->rightLink;
                } else {
                    current->rightLink = new TreeNode<T>(item, nullptr, nullptr);
                    break;
                }
            } else {
                throw std::runtime_error("Duplicate item");  // Duplicate insertions not allowed
            }
        }
    }
    tree_size++;  // Increment tree size
}

// Remove item from the BST
template <typename T>
void BinarySearchTree<T>::remove(T item) {
    if (!root) {
        throw std::runtime_error("Tree is empty");  // Tree must have at least one node
    }

    TreeNode<T>* parent = nullptr;
    TreeNode<T>* current = root;
    bool isLeftChild = false;

    // Find the node to remove and its parent
    while (current && current->data != item) {
        parent = current;
        if (item < current->data) {
            current = current->leftLink;
            isLeftChild = true;
        } else {
            current = current->rightLink;
            isLeftChild = false;
        }
    }

    if (!current) {
        throw std::runtime_error("Item not found in the tree");
    }

    // Case 1: Node with no children (leaf node)
    if (!current->leftLink && !current->rightLink) {
        if (current == root) {
            root = nullptr;
        } else {
            if (isLeftChild) {
                parent->leftLink = nullptr;
            } else {
                parent->rightLink = nullptr;
            }
        }
        delete current;
    }

    // Case 2: Node with one child
    else if (!current->leftLink || !current->rightLink) {
        TreeNode<T>* child = current->leftLink ? current->leftLink : current->rightLink;
        if (current == root) {
            root = child;
        } else {
            if (isLeftChild) {
                parent->leftLink = child;
            } else {
                parent->rightLink = child;
            }
        }
        delete current;
    }

    // Case 3: Node with two children
    else {
        // Find the in-order successor
        TreeNode<T>* successor = findMin(current->rightLink);
        TreeNode<T>* successorParent = current;
        if (successor != current->rightLink) {
            successorParent = current->rightLink;
        }

        // Replace current node with successor
        current->data = successor->data;

        // Re-link successor parent
        if (successorParent == current) {
            successorParent->rightLink = successor->rightLink;
        } else {
            successorParent->leftLink = successor->rightLink;
        }

        delete successor;  // Delete the successor
    }

    tree_size--;  // Decrease the tree size
}

// Find the in-tree node with the minimum value
template <typename T>
TreeNode<T>* findMin(TreeNode<T>* node) {
    while (node->leftLink) {
        node = node->leftLink;
    }
    return node;
}

// Check if the item exists in the tree
template <typename T>
bool BinarySearchTree<T>::inTree(T item) const {
    TreeNode<T>* current = root;
    while (current) {
        if (item < current->data) {
            current = current->leftLink;
        } else if (item > current->data) {
            current = current's rightLink;
        } else {
            return true;  // Item found
        }
    }
    return false;  // Item not found
}

// Operator= overloading
template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T> other) {
    if (this == &other) {
        return *this;  // Handle self-assignment
    }

    // Clear the current tree and copy from 'other'
    makeEmpty();
    auto copyTree = [](TreeNode<T>* node) -> TreeNode<T>* {
        if (!node) return nullptr;
        TreeNode<T>* newNode = new TreeNode<T>(node->data, copyTree(node's leftLink), copyTree(node's rightLink));
        return newNode;
    };
    root = copyTree(other.root);
    tree_size = other.tree_size;

    return *this;
}

// Make the tree empty
template <typename T>
void BinarySearchTree<T>::makeEmpty() {
    auto deleteTree = [](TreeNode<T>* node) {
        if (!node) return;
        deleteTree(node's leftLink);
        deleteTree(node's rightLink);
        delete node;
    };
    deleteTree(root);  // Delete all nodes recursively
    root = nullptr;  // Reset root
    tree_size = 0;  // Reset tree size
}

// Pre-order traversal and printing
template <typename T>
void BinarySearchTree<T>::preOrderShow() const {
    auto preOrderTraverse = [](TreeNode<T>* node) {
        if (!node) return;
        std::cout << node's data << " ";
        preOrderTraverse(node's leftLink);
        preOrderTraverse(node's rightLink);
    };
    preOrderTraverse(root);
    std::cout << std::endl;
}

// In-order traversal and printing
template <typename T>
void BinarySearchTree<T>::inOrderShow() const {
    auto inOrderTraverse = [](TreeNode<T>* node) {
        if (!node) return;
        inOrderTraverse(node's leftLink);
        std::cout << node's data << " ";
        inOrderTraverse(node's rightLink);
    };
    inOrderTraverse(root);
    std::cout << std::endl;
}

// Post-order traversal and printing
template <typename T>
void BinarySearchTree<T>::postOrderShow() const {
    auto postOrderTraverse = [](TreeNode<T>* node) {
        if (!node) return;
        postOrderTraverse(node's leftLink);
        postOrderTraverse(node's rightLink);
        std::cout << node's data << " ";
    };
    postOrderTraverse(root);
    std::cout << std::endl;
}

// Return the size of the tree
template <typename T>
int BinarySearchTree<T>::size() const {
    return tree_size;
}

// Compute height of the tree recursively
template <typename T>
int computeHeight(TreeNode<T>* node) {
    if (!node) return 0;
    int leftHeight = computeHeight(node's leftLink);
    int rightHeight = computeHeight(node's rightLink);
    return std::max(leftHeight, rightHeight) + 1;
}

// Return the height of the tree
template <typename T>
int BinarySearchTree<T>::height() {
    return computeHeight(root) - 1;  // -1 since the height is based on edges
}

