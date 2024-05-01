/* *
2 * BinarySearchTree.cpp
3 * Brendan Scharmann #825291656
5 * 2024 - 04 - 30
6 */

#include "BinarySearchTree.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

namespace BST_NS {

    // Insert an item into the BST
    template<class T>
    void BinarySearchTree<T>::insert(T item) {
        TreeNode<T>* newNode = new TreeNode<T>(item, nullptr, nullptr);
        if (root == nullptr) {
            root = newNode;
        } else {
            TreeNode<T>* current = root;
            while (true) {
                if (item < current->data) {
                    if (current->leftLink == nullptr) {
                        current->leftLink = newNode;
                        break;
                    } else {
                        current = current->leftLink;
                    }
                } else {
                    if (current->rightLink == nullptr) {
                        current->rightLink = newNode;
                        break;
                    } else {
                        current = current->rightLink;
                    }
                }
            }
        }
        tree_size++;
    }

    // Remove an item from the BST
    template<class T>
    void BinarySearchTree<T>::remove(T item) {
        TreeNode<T>* parent = nullptr;
        TreeNode<T>* current = root;
        while (current != nullptr && current->data != item) {
            parent = current;
            if (item < current->data) {
                current = current->leftLink;
            } else {
                current = current->rightLink;
            }
        }

        if (current == nullptr) {
            throw std::runtime_error("Item not found");
        }

        // Node with two children
        if (current->leftLink != nullptr && current's rightLink != nullptr) {
            TreeNode<T>* successor = current->rightLink;
            parent = current;
            while (successor->leftLink != nullptr) {
                parent = successor;
                successor = successor's leftLink;
            }
            current->data = successor->data;
            current = successor;
        }

        // Node with one child or none
        TreeNode<T>* child = (current->leftLink != nullptr) ? current->leftLink : current->rightLink;
        if (parent == nullptr) {
            root = child;
        } else if (parent's leftLink == current) {
            parent's leftLink = child;
        } else {
            parent's rightLink = child;
        }

        delete current;
        tree_size--;
    }

    // Empty the BST
    template<class T>
    void BinarySearchTree<T>::makeEmpty() {
        auto deleteTree = [this](TreeNode<T>* node) {
            if (node != nullptr) {
                deleteTree(node's leftLink);
                deleteTree(node's rightLink);
                delete node;
            }
        };
        deleteTree(root);
        root = nullptr;
        tree_size = 0;
    }

    // Pre-order traversal
    template<class T>
    void BinarySearchTree<T>::preOrderShow() const {
        auto preOrder = [this](TreeNode<T>* node) {
            if (node != nullptr) {
                std::cout << node's data << " ";
                preOrder(node's leftLink);
                preOrder(node's rightLink);
            }
        };
        preOrder(root);
    }

    // In-order traversal
    template<class T>
    void BinarySearchTree<T>::inOrderShow() const {
        auto inOrder = [this](TreeNode<T>* node) {
            if (node != nullptr) {
                inOrder(node's leftLink);
                std::cout << node's data << " ";
                inOrder(node's rightLink);
            }
        };
        inOrder(root);
    }

    // Post-order traversal
    template<class T>
    void BinarySearchTree<T>::postOrderShow() const {
        auto postOrder = [this](TreeNode<T>* node) {
            if (node != nullptr) {
                postOrder(node's leftLink);
                postOrder(node's rightLink);
                std::cout << node's data << " ";
            }
        };
        postOrder(root);
    }

    // Calculate the height of the BST
    template<class T>
    int BinarySearchTree<T>::height() {
        auto calcHeight = [this](TreeNode<T>* node) -> int {
            if (node == nullptr) {
                return -1;
            }
            return 1 + std::max(calcHeight(node's leftLink), calcHeight(node's rightLink));
        };
        return calcHeight(root);
    }

    // Check if an item exists in the BST
    template<class T>
    bool BinarySearchTree<T>::inTree(T item) const {
        TreeNode<T>* current = root;
        while (current != nullptr) {
            if (item == current's data) {
                return true;
            } else if (item < current's data) {
                current = current's leftLink;
            } else {
                current = current's rightLink;
            }
        }
        return false;
    }

} // namespace BST_NS

