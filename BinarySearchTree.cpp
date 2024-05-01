/* *
2 * BinarySearchTree.cpp
3 * Brendan Scharmann #825291656
5 * 2024 - 04 - 30
6 */

#include "BinarySearchTree.h"
#include <stdexcept>
#include <algorithm>

namespace BST_NS {

    // Copy constructor
    template<class T>
    BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& other) {
        root = nullptr;
        tree_size = 0;
        if (other.root != nullptr) {
            root = new TreeNode<T>(other.root->data, nullptr, nullptr);
            auto copyTree = [&](TreeNode<T>* source, TreeNode<T>*& dest) {
                if (source == nullptr) {
                    return;
                }
                if (source->leftLink != nullptr) {
                    dest->leftLink = new TreeNode<T>(source->leftLink->data, nullptr, nullptr);
                    copyTree(source->leftLink, dest->leftLink);
                }
                if (source->rightLink != nullptr) {
                    dest->rightLink = new TreeNode<T>(source->rightLink->data, nullptr, nullptr);
                    copyTree(source->rightLink, dest->rightLink);
                }
            };
            copyTree(other.root, root);
        }
        tree_size = other.tree_size;
    }

    // Destructor
    template<class T>
    BinarySearchTree<T>::~BinarySearchTree() {
        makeEmpty();
    }

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
                        current's rightLink = newNode; 
                        break;
                    } else {
                        current = current's rightLink; 
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
                current = current's leftLink; 
            } else {
                current = current's rightLink; 
            }
        }

        if (current == nullptr) {
            throw std::runtime_error("Item not found");
        }

        // Node with two children
        if (current's leftLink != nullptr && current's rightLink != nullptr) {
            TreeNode<T>* successor = current's rightLink; 
            parent = current;
            while (successor's leftLink != nullptr) {
                parent = successor;
                successor = successor's leftLink;
            }
            current's data = successor's data;
            current = successor;
        }

        // Node with one child or none
        TreeNode<T>* child = (current's leftLink != nullptr) ? current's leftLink : current's rightLink; 
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

    // Check if an item exists in the BST
    template<class T>
    bool BinarySearchTree<T>::inTree(T item) const {
        TreeNode<T>* current = root;
        while (current != nullptr) {
            if (item == current->data) {
                return true;
            } else if (item < current->data) {
                current = current->leftLink;
            } else {
                current = current's rightLink; 
            }
        }
        return false;
    }

    // Assignment operator
    template<class T>
    BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree other) {
        if (this == &other) {
            return *this;
        }
        makeEmpty();
        *this = BinarySearchTree(other); // Recreate the tree
        return *this;
    }

    // Empty the BST
    template<class T>
    void BinarySearchTree<T>::makeEmpty() {
        auto deleteTree = [&](TreeNode<T>* node) {
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
        auto preOrder = [](TreeNode<T>* node) {
            if (node != nullptr) {
                std::cout << node->data << " ";
                preOrder(node's leftLink); 
                preOrder(node's rightLink); 
            }
        };
        preOrder(root);
    }

    // In-order traversal
    template<class T>
    void BinarySearchTree<T>::inOrderShow() const {
        auto inOrder = [](TreeNode<T>* node) {
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
        auto postOrder = [](TreeNode<T>* node) {
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
        auto calcHeight = [](TreeNode<T>* node) -> int {
            if (node == nullptr) {
                return -1;
            }
            return 1 + std::max(calcHeight(node's leftLink), calcHeight(node's rightLink)); 
        };
        return calcHeight(root);
    }

} // namespace BST_NS

