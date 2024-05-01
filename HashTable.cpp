/* *
2 * HashTable.cpp
3 * Brendan Scharmann #825291656
5 * 2024 - 04 - 30
6 */

#include "HashTable.h"
#include <stdexcept>   
#include "LinkedList.h"

namespace HashTableNS {

    HashTable::HashTable() {
        for (int i = 0; i < SIZE; i++) {
            hashArray[i] = nullptr;
        }
    }

    HashTable::~HashTable() {
        for (int i = 0; i < SIZE; i++) {
            Node<string>* current = hashArray[i];
            while (current != nullptr) {
                Node<string>* next = current->getLink();
                delete current;
                current = next;
            }
        }
    }

    int HashTable::computeHash(string s) {
        int hash = 0;
        for (char c : s) {
            hash = (hash * 31 + c) % SIZE; // Simple hash function
        }
        return hash;
    }

    bool HashTable::containsString(string target) const {
        int index = computeHash(target);
        Node<string>* current = hashArray[index];
        while (current != nullptr) {
            if (current->getData() == target) {
                return true;
            }
            current = current->getLink();
        }
        return false;
    }

    void HashTable::put(string s) {
        int index = computeHash(s);
        if (!containsString(s)) {
            LinkedListNS::headInsert(hashArray[index], s);
        }
    }

} // namespace HashTableNS
