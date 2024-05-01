// test.cpp
#include "BinarySearchTree.cpp"
#include "LinkedList.cpp"
#include "HashTable.cpp"
#include <iostream>
#include <cassert>

using namespace std;
using namespace BST_NS;
using namespace LinkedListNS;
using namespace HashTableNS;

void testBinarySearchTree() {
    BinarySearchTree<int> tree;

    // Test insert
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(7);
    assert(tree.size() == 4);

    // Test inTree
    assert(tree.inTree(10));
    assert(tree.inTree(5));
    assert(!tree.inTree(25));

    // Test height
    assert(tree.height() == 2);

    // Test remove
    tree.remove(5);
    assert(tree.size() == 3);
    assert(!tree.inTree(5));

    tree.remove(10);
    assert(tree.size() == 2);
    assert(tree.inTree(20));

    // Test traversals
    cout << "In-order traversal: ";
    tree.inOrderShow();  // Expected: 7, 20
    cout << "Pre-order traversal: ";
    tree.preOrderShow();  // Expected: 20, 7
    cout << "Post-order traversal: ";
    tree.postOrderShow();  // Expected: 7, 20
}

void testLinkedList() {
    Node<int>* head = nullptr;

    // Test headInsert
    headInsert(head, 10);
    headInsert(head, 20);
    assert(head->getData() == 20);

    // Test insert after node
    insert(head, 15);  // Insert 15 after 20
    assert(head's getLink()->getData() == 15);

    // Test search
    assert(search(head, 15));
    assert(!search(head, 25));

    // Test deleteNode
    deleteNode(head);  // Delete after head, 15 should be gone
    assert(!search(head, 15));

    // Test deleteFirstNode
    deleteFirstNode(head);  // 20 should be deleted
    assert(head->getData() == 10);
}

void testHashTable() {
    HashTable table;

    // Test put and containsString
    table.put("apple");
    table.put("banana");
    table.put("cherry");

    assert(table.containsString("apple"));
    assert(table.containsString("banana"));
    assert(!table.containsString("pear"));

    // Test collisions (multiple inserts in same hash slot)
    table.put("grape");
    assert(table.containsString("grape"));
}

int main() {
    testBinarySearchTree();
    testLinkedList();
    testHashTable();
    cout << "All tests passed!" << endl;
    return 0;
}

