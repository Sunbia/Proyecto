#ifndef LISTADT_HPP
#define LISTADT_HPP
typedef unsigned int index_t;
template <class T>
class ListADT
{
public:
    virtual bool empty() = 0;
    virtual unsigned int size() = 0;
    virtual T get_tail() = 0;
    virtual T get_head() = 0;
    virtual T get(index_t) = 0;
    virtual bool contains(T) = 0;
    virtual void addBeforeHead(T) = 0;
    virtual void addAfterTail(T) = 0;
    virtual void add(T, index_t) = 0;
    virtual void remove(T) = 0;
    virtual void removeHead() = 0;
    virtual void removeTail() = 0;
    virtual void display() = 0;
};
#endif