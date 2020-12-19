#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <cstdlib>
#include <iostream>
#include "ListADT.hpp"
using std::cout;
using std::endl;

template <class T>
struct node
{
    T data;
    node<T> *next;
};

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
    unsigned int size();
    T get_tail();
    T get_head();
    T get(index_t);
    bool contains(T);
    void addBeforeHead(T);
    void addAfterTail(T);
    void add(T, index_t);
    void remove(T);
    void removeHead();
    void removeTail();
    void display();
    node<T> *getTail();
    node<T> *getHead();
};

template <typename T>
LinkedList<T>::LinkedList()
{
    _head = NULL;
    _tail = NULL;
    _size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    node<T> *aux = _head;
    while (aux != NULL)
    {
        _head = _head->next;
        delete aux;
    }
}

template <typename T>
bool LinkedList<T>::empty()
{
    return (_head == NULL & _tail == NULL) == 0;
}

template <typename T>
unsigned int LinkedList<T>::size()
{
    return _size;
}

template <typename T>
T LinkedList<T>::get_tail()
{
    return _tail->data;
}

template <typename T>
T LinkedList<T>::get_head()
{
    return _head->data;
}

template <typename T>
T LinkedList<T>::get(index_t index)
{
    node<T> *aux = _head;
    int i = 0;
    while (aux != NULL)
    {
        if (i == index)
        {
            return aux->data;
        }
        aux = aux->next;
        i++;
    }

    return aux->data;
}

template <typename T>
bool LinkedList<T>::contains(T element)
{
    if (this->empty())
    {
        return false;
    }
    node<T> *aux = _head;
    while (aux != NULL)
    {
        if (aux->data == element)
        {
            return true;
        }
        aux = aux->next;
    }
    return false;
}

template <typename T>
void LinkedList<T>::addBeforeHead(T element)
{
    node<T> *aux = new node<T>;
    aux->next = _head;
    aux->data = element;
    if (this->empty())
    {
        _tail = aux;
        _head = aux;
        _size++;
    }
    else
    {
        _head = aux;
        _size++;
    }
}

template <typename T>
void LinkedList<T>::addAfterTail(T element)
{
    node<T> *aux = new node<T>;
    aux->next = NULL;
    aux->data = element;
    if (this->empty())
    {
        _tail = aux;
        _head = aux;
        _size++;
    }
    else
    {
        _tail->next = aux;
        _tail = aux;
        _size++;
    }
}

template <typename T>
void LinkedList<T>::add(T element, index_t index)
{
    node<T> *aux2 = new node<T>;
    aux2->data = element;
    if (this->empty())
    {
        _tail = aux2;
        _head = aux2;
        _size++;
    }
    else
    {
        node<T> *aux = _head;
        int i = 0;
        while (aux != NULL)
        {
            if (i == index - 1)
            {
                aux2->next = aux->next;
                aux->next = aux2;
                _size++;
            }
            aux = aux->next;
            i++;
        }
    }
}

template <typename T>
void LinkedList<T>::removeHead()
{
    node<T> *aux = this->_head;
    _head = _head->next;
    delete aux;
    _size--;
}

template <typename T>
void LinkedList<T>::removeTail()
{
    node<T> *aux = _head;
    for (size_t i = 0; i < _size; i++)
    {
        if (i == _size - 2) // (size -1) = ultimo elemento (tail)
        {
            _tail = aux;
            aux = aux->next;
            delete aux;
            break;
        }
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
        node<T> *actual = _head;
        node<T> *anterior;
        while (actual != NULL && actual->data != element)
        {
            anterior = actual;
            actual = actual->next;
        }
        anterior->next = actual->next;
        delete actual;
    }
}

template <typename T>
void LinkedList<T>::display()
{
    node<T> *aux = _head;
    while (aux != NULL)
    {
        if (aux == _tail)
        {
            cout << aux->data;
            break;
        }
        else
        {
            cout << aux->data << " --> ";
            aux = aux->next;
        }
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

#endif
