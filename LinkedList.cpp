/* *
2 * LinkedList.cpp
3 * Brendan Scharmann #825291656
5 * 2024 - 04 - 30
6 */

// LinkedList.cpp
#include "LinkedList.h"
#include <stdexcept>

using namespace LinkedListNS;

// Insert data at the head of the list
template<class T>
void headInsert(Node<T>*& head, const T& theData) {
    Node<T>* newNode = new Node<T>(theData, head);
    head = newNode;
}

// Insert data after the specified node
template<class T>
void insert(Node<T>* afterMe, const T& theData) {
    if (!afterMe) {
        throw std::runtime_error("Insert position is invalid.");
    }
    Node<T>* newNode = new Node<T>(theData, afterMe->getLink());
    afterMe->setLink(newNode);
}

// Delete the node in the list after the supplied node
template<class T>
void deleteNode(Node<T>* before) {
    if (!before || !before->getLink()) {
        throw std::runtime_error("Node to delete does not exist.");
    }
    Node<T>* toDelete = before->getLink();
    before->setLink(toDelete->getLink());
    delete toDelete;
}

// Delete the first node in the list
template<class T>
void deleteFirstNode(Node<T>*& head) {
    if (!head) {
        throw std::runtime_error("No nodes to delete.");
    }
    Node<T>* toDelete = head;
    head = head->getLink();
    delete toDelete;
}

// Search for a specific item in the list
template<class T>
Node<T>* search(Node<T>* head, const T& target) {
    Node<T>* current = head;
    while (current) {
        if (current->getData() == target) {
            return current;
        }
        current = current->getLink();
    }
    return nullptr;  // Not found
}


