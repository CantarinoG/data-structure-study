#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list> //Doubly linked list
#include <utility>
#include <iostream>

using namespace std;

class HashTable
{
private:
    vector<list<pair<int, string>>> table;
    int size; // Number of buckets
    int hashFunction(int key);

public:
    HashTable(int size);
    void debug();
    void insert(int key, string &value); // C++ note: Receives a reference to that string rather than copying it.
    int search(int key, string &value);  // Search for a value by key. Value is changed via reference. Returns 1 or 0 whether a value with that key was found or not.
    int remove(int key);                 // Returns 1 or 0 whether the value was found and removed or not.
};

#endif