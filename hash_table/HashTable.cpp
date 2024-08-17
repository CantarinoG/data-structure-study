#include "HashTable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size) : size(size)
{
    table.resize(size);
}

void HashTable::debug() const
{
    for (int i = 0; i < size; ++i)
    {
        cout << "Bucket " << i << ": ";
        for (const pair<int, string> &pair : table[i])
        {
            cout << "{" << pair.first << ": " << pair.second << "} ";
        }
        cout << endl;
    }
}

int HashTable::hashFunction(int key) const // Division method
{
    return key % size;
}

void HashTable::insert(int key, string &value)
{
    int index = hashFunction(key);
    // Iterate through the list to see if key already exists. If it does, update the value.
    for (pair<int, string> &pair : table[index])
    {
        if (pair.first == key)
        {
            pair.second = value;
            return;
        }
    }

    table[index].emplace_back(key, value); // The emplace_back method know to take two arguments instead of one based on the data type(pair).
}

int HashTable::search(int key, string &value) const
{
    int index = hashFunction(key);
    for (const pair<int, string> pair : table[index])
    {
        if (pair.first == key)
        {
            value = pair.second;
            return 1;
        }
    }
    return 0;
}

int HashTable::remove(int key)
{
    int index = hashFunction(key);
    auto &bucket = table[index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it)
    {
        if (it->first == key)
        {
            bucket.erase(it);
            return 1;
        }
    }
    return 0;
}