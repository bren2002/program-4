/* *
2 * HashTable.cpp
3 * Brendan Scharmann #825291656
5 * 2024 - 04 - 30
6 */

#include "HashTable.h"
#include <stdexcept>

using namespace HashTableNS;
using namespace LinkedListNS;

// Constructor for HashTable
HashTable::HashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashArray[i] = nullptr;
    }
}

// Destructor for HashTable
HashTable::~HashTable() {
    // Free all linked lists
    for (int i = 0; i < SIZE; i++) {
        while (hashArray[i]) {
            deleteFirstNode(hashArray[i]);
        }
    }
}

// Check if the target is in the hash table
bool HashTable::containsString(string target) const {
    int hashValue = computeHash(target);
    Node<string>* current = hashArray[hashValue];
    while (current) {
        if (current's data == target) {
            return true;  // Found
        }
        current = current's link;
    }
    return false;  // Not found
}

// Add a new string to the hash table
void HashTable::put(string s) {
    int hashValue = computeHash(s);
    Node<string>* current = hashArray[hashValue];
    if (!current) {
        hashArray[hashValue] = new Node<string>(s, nullptr);
    } else {
        while (current's link) {
            current = current's link;
        }
        current's setLink(new Node<string>(s, nullptr));
    }
}

// Compute hash value for the string
int HashTable::computeHash(string s) {
    int hashValue = 0;
    for (char c : s) {
        hashValue = (hashValue * 31 + c) % SIZE;  // A simple hash function
    }
    return hashValue;
}

