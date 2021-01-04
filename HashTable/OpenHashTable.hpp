#ifndef OPENHASHTABLE_HPP
#define OPENHASHTABLE_HPP
// ────────────────────────────────────────────────────────────────────────────────

#include "HashTable.hpp"
#include "..\List\DLinkedList.hpp"
#include <cstdlib>
#include <iostream>
#define defaultMAX 10
using std::cout;
using std::endl;
// ────────────────────────────────────────────────────────────────────────────────

template <class Key, class Value>
class OpenHashTable : public HashTable<Key, Value>
{

private:
    unsigned int maxLength;
    unsigned int numElements;
    ListADT<Bucket<Key, Value>> *table[defaultMAX];
    int hash(Key);

public:
    OpenHashTable();
    OpenHashTable(unsigned int);
    ~OpenHashTable();
    bool empty();
    int size();
    Value find(Key);
    void insert(Key, Value);
    void remove(Key);
    void display();
    bool contains(Key);
};

template <typename Key, typename Value>
OpenHashTable<Key, Value>::OpenHashTable()
{
    numElements = 0;
    maxLength = defaultMAX;
    for (size_t i = 0; i < maxLength; i++)
    {
        table[i] = nullptr;
    }
}

template <typename Key, typename Value>
OpenHashTable<Key, Value>::OpenHashTable(unsigned int length)
{
    numElements = 0;
    maxLength = length;
    for (size_t i = 0; i < maxLength; i++)
    {
        table[i] = nullptr;
    }
}

template <typename Key, typename Value>
OpenHashTable<Key, Value>::~OpenHashTable()
{
    delete[] table;
}

template <typename Key, typename Value>
int OpenHashTable<Key, Value>::hash(Key key)
{
    return (int)(key % maxLength);
}

template <typename Key, typename Value>
bool OpenHashTable<Key, Value>::empty()
{
    return numElements == 0;
}

template <typename Key, typename Value>
int OpenHashTable<Key, Value>::size()
{
    return numElements;
}

template <typename Key, typename Value>
Value OpenHashTable<Key, Value>::find(Key key)
{
    int index = hash(key);
    Value returnvalue;
    for (size_t i = 0; i < this->table[index]->getsize(); i++)
    {
        if (table[index]->get(i).key == key)
        {
            returnvalue = table[index]->get(i).value;
            break;
        }
    }
    return returnvalue;
}

template <typename Key, typename Value>
void OpenHashTable<Key, Value>::insert(Key key, Value value)
{
    int index = hash(key);
    if (table[index] == nullptr)
    {
        table[index] = new DLinkedList<Bucket<Key, Value>>();
        Bucket<Key, Value> newdata;
        newdata.key = key;
        newdata.value = value;
        table[index]->addAfterTail(newdata);
        numElements++;
    }
    else
    {
        Bucket<Key, Value> newdata;
        newdata.key = key;
        newdata.value = value;
        table[index]->addAfterTail(newdata);
        numElements++;
    }
}

template <typename Key, typename Value>
void OpenHashTable<Key, Value>::remove(Key key)
{
    int index = hash(key);
    for (size_t i = 0; i < table[index]->getsize(); i++)
    {
        if (table[index]->get(i).key == key)
        {
            table[index]->remove(table[index]->get(i));
        }
    }
}

template <typename Key, typename Value>
void OpenHashTable<Key, Value>::display()
{
    
    for (size_t i = 0; i < maxLength; i++)
    {
        size_t j = 0;
        while (table[i] != nullptr && j < table[i]->getsize())
        {
            cout << table[i]->get(j);
            j++;
        }
        cout << endl;
    }
}
template <typename Key, typename Value>
bool OpenHashTable<Key, Value>::contains(Key key)
{
    int index = hash(key);
    if (table[index] == nullptr)
    {
        return false;
    }

    for (size_t i = 0; i < this->table[index]->getsize(); i++)
    {
        if (table[index]->get(i).key == key)
        {
            return true;
        }
    }

    return false;
}

#endif