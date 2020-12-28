#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <cstdlib>
#include <iostream>
#include "ListADT.hpp"
#include <string>
template <class T>
class LinkedList : public ListADT<T>
{
private:
    node<T> *_head;
    node<T> *_tail;
    index_t _size;

public:
    LinkedList();
    ~LinkedList();
    bool empty();
    unsigned int getsize();
    T getTailData();
    T getHeadData();
    T get(index_t);
    bool contains(T);
    void addBeforeHead(T);
    void addAfterTail(T);
    void add(T, index_t);
    void remove(T);
    void removeHead();
    void removeTail();

    node<T> *find(index_t);
    node<T> *find(T);
    node<T> *getTail();
    node<T> *getHead();
};
//
// ─── PROTECTED ──────────────────────────────────────────────────────────────────
//
template <typename T>
node<T> *LinkedList<T>::find(index_t index)
{
    node<T> *aux = _head;
    index_t i = 0;
    while (aux != nullptr)
    {
        if (i == index)
        {
            return aux;
        }
        aux = aux->next;
        i++;
    }
}

template <typename T>
node<T> *LinkedList<T>::find(T element)
{
    node<T> *aux = _head;
    while (aux != nullptr)
    {
        if (aux->data == element)
        {
            return aux;
        }
        aux = aux->next;
    }
}

template <typename T>
node<T> *LinkedList<T>::getTail()
{
    return _head;
}

template <typename T>
node<T> *LinkedList<T>::getHead()
{
    return _tail;
}

//
// ─── PUBLIC ─────────────────────────────────────────────────────────────────────
//

template <typename T>
LinkedList<T>::LinkedList()
{
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    node<T> *aux = _head;
    while (aux != nullptr)
    {
        _head = _head->next;
        delete aux;
    }
}

template <typename T>
bool LinkedList<T>::empty()
{
    return (_head == nullptr && _tail == nullptr);
}

template <typename T>
unsigned int LinkedList<T>::getsize()
{
    return _size;
}

template <typename T>
T LinkedList<T>::getTailData()
{
    return _tail->data;
}

template <typename T>
T LinkedList<T>::getHeadData()
{
    return _head->data;
}

template <typename T>
T LinkedList<T>::get(index_t index)
{
    node<T> *aux = _head;
    index_t i = 0;
    while (aux != nullptr && i < _size)
    {
        if (i == index)
        {
            return aux->data;
        }
        aux = aux->next;
        i++;
    }
}

template <typename T>
bool LinkedList<T>::contains(T element)
{
    if (this->empty())
    {
        return false;
    }
    node<T> *aux = _head;
    while (aux != nullptr)
    {
        if (aux->data == element)
        {
            return true;
        }
        aux = aux->next;
    }
}

template <typename T>
void LinkedList<T>::addBeforeHead(T element)
{
    node<T> *aux = new node<T>;
    aux->data = element;

    if (this->empty())
    {
        aux->next = nullptr;
        aux->prev = nullptr;
        _tail = aux;
        _head = aux;
        _size++;
    }
    else
    {
        aux->next = _head;
        aux->prev = nullptr;
        _head->prev = aux;
        _head = aux;
        _size++;
    }
}

template <typename T>
void LinkedList<T>::addAfterTail(T element)
{
    node<T> *aux = new node<T>;
    aux->data = element;
    if (this->empty())
    {
        aux->next = nullptr;
        aux->prev = nullptr;
        _tail = aux;
        _head = aux;
        _size++;
    }
    else
    {
        aux->prev = _tail;
        aux->next = nullptr;
        _tail->next = aux;
        _tail = aux;
        _size++;
    }
}

template <typename T>
void LinkedList<T>::add(T element, index_t index)
{
    if (this->empty())
    {
        addBeforeHead(element);
    }
    else
    {
        node<T> *target = get(index);
        node<T> *newNode = new node<T>();
        newNode->next = target;
        newNode->prev = target->prev;
        target->prev->next = newNode;
        target->prev = newNode;
        _size++;
    }
}

template <typename T>
void LinkedList<T>::removeHead()
{
    node<T> *aux = _head;
    _head = _head->next;
    delete aux;
    if (_head != nullptr)
    {
        _head->prev = nullptr;
    }
    _size--;
}

template <typename T>
void LinkedList<T>::removeTail()
{
    if (empty() == false)
    {
        node<T> *aux = _tail;
        _tail = _tail->prev;
        _tail->next = nullptr;
        delete aux;
    }
}
template <typename T>
void LinkedList<T>::remove(T element)
{
    if (this->empty())
    {
        return;
    }
    else if (this->_head->data == element)
    {
        this->removeHead();
    }
    else if (this->_tail->data == element)
    {
        this->removeTail();
    }
    else
    {
        node<T> *target = find(element);
        target->prev->next = target->next;
        target->next->prev = target->prev;
        delete target;
        _size--;
    }
}

#endif
