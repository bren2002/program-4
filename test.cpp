/* *
2 * test.cpp
3 * Brendan Scharmann #825291656
5 * 2024 - 04 - 30
6 */

#include "LinkedList.cpp"
#include "HashTable.cpp"
#include "BinarySearchTree.cpp"
#include <iostream>

using LinkedListNS::Node;
using HashTableNS::HashTable;
using BST_NS::BinarySearchTree;

// Test function for LinkedList
void testLinkedList() {
    // Create a linked list
    Node<int>* list = nullptr;

    // Insert at the head
    LinkedListNS::headInsert(list, 1);
    LinkedListNS::headInsert(list, 2);
    LinkedListNS::headInsert(list, 3);

    // Insert after a specific node
    LinkedListNS::insert(list, 4);

    // Search for an item
    Node<int>* found = LinkedListNS::search(list, 2);
    if (found != nullptr) {
        std::cout << "LinkedList Search found: " << found->getData() << std::endl;
    } else {
        std::cout << "LinkedList Search did not find 2" << std::endl;
    }

    // Delete the first node
    LinkedListNS::deleteFirstNode(list); // This should delete 3

    // Delete a specific node
    LinkedListNS::deleteNode(list); // This should delete 4

    // Display the remaining linked list
    Node<int>* current = list;
    std::cout << "LinkedList Content: ";
    while (current != nullptr) {
        std::cout << current->getData() << " ";
        current = current->getLink();
    }
    std::cout << std::endl;
}

// Test function for HashTable
void testHashTable() {
    HashTable table;

    // Insert strings into the hash table
    table.put("apple");
    table.put("banana");
    table.put("orange");

    // Check if specific strings are in the hash table
    if (table.containsString("banana")) {
        std::cout << "HashTable found 'banana'" << std::endl;
    } else {
        std::cout << "HashTable did not find 'banana'" << std::endl;
    }

    if (table.containsString("grape")) {
        std::cout << "HashTable found 'grape'" << std::endl;
    } else {
        std::cout << "HashTable did not find 'grape'" << std::endl;
    }

    // Insert more strings
    table.put("grape");
    table.put("kiwi");

    // Display hash table content
    std::cout << "HashTable Content:" << std::endl;
    for (int i = 0; i < HashTableNS::SIZE; i++) {
        Node<std::string>* current = table.hashArray[i];
        while (current != nullptr) {
            std::cout << current->getData() << " ";
            current = current->getLink();
        }
    }
    std::cout << std::endl;
}

// Test function for Binary Search Tree
void testBinarySearchTree() {
    BinarySearchTree<int> bst;

    // Insert elements into the BST
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    // Test in-order traversal
    std::cout << "BinarySearchTree In-order: ";
    bst.inOrderShow();
    std::cout << std::endl;

    // Test pre-order traversal
    std::cout << "BinarySearchTree Pre-order: ";
    bst.preOrderShow();
    std::cout << std::endl;

    // Test post-order traversal
    std::cout << "BinarySearchTree Post-order: ";
    bst.postOrderShow();
    std::cout << std::endl;

    // Test size and height
    std::cout << "BinarySearchTree Size: " << bst.size() << std::endl;
    std::cout << "BinarySearchTree Height: " << bst.height() << std::endl;

    // Test removal and traversal
    bst.remove(7);
    std::cout << "BinarySearchTree In-order after removal of 7: ";
    bst.inOrderShow();
    std::cout << std::endl;

    // Test searching in the BST
    if (bst.inTree(6)) {
        std::cout << "BinarySearchTree found 6" << std::endl;
    } else {
        std::cout << "BinarySearchTree did not find 6" << std::endl;
    }

    if (bst.inTree(7)) {
        std::cout << "BinarySearchTree did not find 7" << std::endl;
    }
}

int main() {
    // Test LinkedList operations
    std::cout << "Testing LinkedList" << std::endl;
    testLinkedList();

    // Test HashTable operations
    std::cout << "\nTesting HashTable" << std::endl;
    testHashTable();

    // Test BinarySearchTree operations
    std::cout << "\nTesting BinarySearchTree" << std::endl;
    testBinarySearchTree();

    return 0;
}



