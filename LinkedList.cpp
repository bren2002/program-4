/* *
2 * LinkedList.cpp
3 * Brendan Scharmann #825291656
5 * 2024 - 04 - 30
6 */

#include "LinkedList.h"
#include <stdexcept>

namespace LinkedListNS {

    // Insert at the head
    template<class T>
    void headInsert(Node<T>*& head, const T& theData) {
        head = new Node<T>(theData, head);
    }

    // Insert after a specific node
    template<class T>
    void insert(Node<T>* afterMe, const T& theData) {
        if (afterMe == nullptr) {
            throw std::invalid_argument("Cannot insert after a null node");
        }
        Node<T>* newNode = new Node<T>(theData, afterMe->getLink());
        afterMe->setLink(newNode);
    }

    // Delete the node after the specified node
    template<class T>
    void deleteNode(Node<T>* before) {
        if (before == nullptr || before->getLink() == nullptr) {
            throw std::invalid_argument("No node to delete");
        }
        Node<T>* toDelete = before->getLink();
        before->setLink(toDelete->getLink());
        delete toDelete;
    }

    // Delete the first node
    template<class T>
    void deleteFirstNode(Node<T>*& head) {
        if (head == nullptr) {
            throw std::invalid_argument("No node to delete");
        }
        Node<T>* toDelete = head;
        head = head->getLink();
        delete toDelete;
    }

    // Search for a specific item
    template<class T>
    Node<T>* search(Node<T>* head, const T& target) {
        while (head != nullptr) {
            if (head->getData() == target) {
                return head;
            }
            head = head->getLink();
        }
        return nullptr;
    }

} // namespace LinkedListNS

