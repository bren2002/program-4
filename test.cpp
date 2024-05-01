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

void testLinkedList() {
    Node<int>* list = nullptr;

    // Test head insertion
    LinkedListNS::headInsert(list, 1);
    LinkedListNS::headInsert(list, 2);
    LinkedListNS::headInsert(list, 3);

    // Test insertion after a node
    LinkedListNS::insert(list, 4);

    // Test search
    Node<int>* found = LinkedListNS::search(list, 2);
    if (found != nullptr) {
        std::cout << "LinkedList Search found: " << found->getData() << std::endl;
    } else {
        std::cout << "LinkedList Search did not find the item" << std::endl;
    }

    // Test node deletion
    LinkedListNS::deleteFirstNode(list); // Deletes 3
    LinkedListNS::deleteNode(list); // Deletes 4

    // Display the remaining list
    Node<int>* current = list;
    std::cout << "LinkedList: ";
    while (current != nullptr) {
        std::cout << current->getData() << " ";
        current = current's getLink();
    }
    std::cout << std::endl;
}

void testHashTable() {
    HashTable table;

    // Test adding strings
    table.put("apple");
    table.put("banana");
    table.put("orange");

    // Test searching
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
}

void testBinarySearchTree() {
    BinarySearchTree<int> bst;

    // Test insertion
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

    // Test size
    std::cout << "BinarySearchTree Size: " << bst.size() << std::endl;

    // Test height
    std::cout << "BinarySearchTree Height: " << bst.height() << std::endl;

    // Test removal
    bst.remove(7);

    std::cout << "BinarySearchTree In-order after removal of 7: ";
    bst.inOrderShow();
    std::cout << std::endl;

    // Test searching in tree
    if (bst.inTree(6)) {
        std::cout << "BinarySearchTree found 6" << std::endl;
    } else {
        std::cout << "BinarySearchTree did not find 6" << std::endl;
    }

    if (bst.inTree(7)) {
        std::cout << "BinarySearchTree found 7" << std::endl;
    } else {
        std::cout << "BinarySearchTree did not find 7" << std::endl;
    }
}

int main() {
    std::cout << "Testing LinkedList" << std::endl;
    testLinkedList();
    
    std::cout << "\nTesting HashTable" << std::endl;
    testHashTable();
    
    std::cout << "\nTesting BinarySearchTree" << std::endl;
    testBinarySearchTree();
    
    return 0;
}


