#ifndef HASH_TABLE_T
#define HASH_TABLE_T
#include <iostream>
// ────────────────────────────────────────────────────────────────────────────────
template <typename Key, typename Value>
struct Bucket
{
    Key key;
    Value value;
    bool operator==(const Bucket<Key, Value> &ref)
    {
        return key == ref.key && value == ref.value;
    }
    bool operator!=(const Bucket<Key, Value> &ref)
    {
        return key != ref.key && value != ref.value;
    }
    friend std::ostream &operator<<(std::ostream &output, const Bucket<Key, Value> &ref)
    {
        output << ref.value;
        return output;
    }
};
// ────────────────────────────────────────────────────────────────────────────────

template <class Key, class Value>
class HashTable
{
public:
    virtual bool empty() = 0;
    virtual int size() = 0;
    virtual Value find(Key) = 0;
    virtual void insert(Key, Value) = 0;
    virtual void remove(Key) = 0;
    virtual void display() = 0;
};
#endif
