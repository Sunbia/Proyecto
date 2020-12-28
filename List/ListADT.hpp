#ifndef LISTADT_HPP
#define LISTADT_HPP
typedef unsigned int index_t;

template <class T>
struct node
{
    T data;
    node<T> *next;
    node<T> *prev;
};

template <class T>
class ListADT
{

public:
    virtual bool empty() = 0;
    virtual unsigned int getsize() = 0;
    virtual T getTailData() = 0;
    virtual T getHeadData() = 0;
    virtual T get(index_t) = 0;
    virtual bool contains(T) = 0;
    virtual void addBeforeHead(T) = 0;
    virtual void addAfterTail(T) = 0;
    virtual void add(T, index_t) = 0;
    virtual void remove(T) = 0;
    virtual void removeHead() = 0;
    virtual void removeTail() = 0;

    virtual node<T> *find(index_t) = 0;
    virtual node<T> *find(T) = 0;
    virtual node<T> *getTail() = 0;
    virtual node<T> *getHead() = 0;
};

#endif