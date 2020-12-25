#ifndef OPENHASHTABLE_HPP
#define OPENHASHTABLE_HPP
// ────────────────────────────────────────────────────────────────────────────────

#include "HashTable.hpp"
#include "..\List\LinkedList.hpp"
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
    try
    {
        if (table[index] == nullptr)
        {
            throw "La lista esta vacia";
        }
        else
        {
            for (size_t i = 0; i < this->table[index]->getsize(); i++)
            {
                if (table[index]->get(i).key == key)
                {
                    return table[index]->get(i).value;
                }
                else
                {
                    throw "No encontrado";
                }
            }
        }
    }
    catch (const char *emptylist)
    {
        cout << emptylist << endl;
    }
    catch (const char *notfinded)
    {
        cout << notfinded << endl;
    }
}

template <typename Key, typename Value>
void OpenHashTable<Key, Value>::insert(Key key, Value value)
{
    int index = hash(key);
    if (table[index] == nullptr)
    {
        table[index] = new LinkedList<Bucket<Key, Value>>();
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
        if (table[i] != nullptr)
        {
            while (j < table[i]->getsize())
            {
                if (j == table[i]->getsize() - 1)
                {
                    cout << table[i]->get(j);
                    j++;
                }
                else
                {
                    cout << table[i]->get(j) << "-->";
                    j++;
                }
            }
            cout << endl;
        }
    }
}

#endif