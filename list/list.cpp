#include "list.h"

using namespace custom;

/************
 * LIST
 * ************/

template <class T>
list<T>::list()
{
    pHead = NULL;
    pTail = NULL;
    numElements = 0;
}

template <class T>
list<T>::list(const list<T> &rhs)
{
    pHead = NULL;
    pTail = NULL;
    numElements = 0;
    *this = rhs;
}

template <class T>
list<T>::~list()
{
    clear();
}

template <class T>
list<T> &list<T>::operator=(const list &rhs)
{
    clear();
    for (node *p = rhs.pHead; p; p = p->pNext)
    {
        push_back(p->data);
    }
    return *this;
}

template <class T>
int list<T>::size() const
{
    return numElements;
}

template <class T>
bool list<T>::empty() const
{
    return numElements == 0;
}

template <class T>
void list<T>::clear()
{
    node *pCurrent = pHead;
    while (pCurrent)
    {
        node *pTarget = pCurrent;
        pCurrent = pCurrent->pNext;
        delete pTarget;
        numElements--;
    }
    pHead = NULL;
    pTail = NULL;
}

template <class T>
void list<T>::push_front(const T &t)
{
    insertAt(pHead, t, false);
}

template <class T>
void list<T>::push_back(const T &t)
{
    insertAt(pTail, t, true);
}

template <class T>
void list<T>::pop_front()
{
    if (pTail != NULL)
    {
        pHead = pHead->pNext;
        pHead->pPrev = NULL;
        numElements--;
    }
}

template <class T>
void list<T>::pop_back()
{
    if (pTail != NULL)
    {
        pTail = pTail->pPrev;
        pTail->pNext = NULL;
        numElements--;
    }
}

template <class T>
T &list<T>::front()
{
    if (!empty())
        return pHead->data;
    else
        throw "Error: Calling front on empty list.";
}

template <class T>
T &list<T>::back()
{
    if (!empty())
        return pTail->data;
    else
        throw "Error: Calling back on empty list.";
}

template <class T>
typename list<T>::iterator list<T>::find(const T &t)
{
    for (node *p = pHead; p; p = p->pNext)
    {
        if (p->data == t)
            return iterator(p);
    }

    return iterator();
}

template <class T>
void list<T>::insert(iterator &it, const T &t)
{
    insertAt(it.ptr, t, false);
}

template <class T>
void list<T>::insertAt(node *pCurrent, const T &element, bool after)
{
    node *pNew = new node(element);

    if (empty())
    {
        pHead = pNew;
        pTail = pNew;
        numElements++;
        return;
    }

    if (after == false)
    {
        if (pHead == pCurrent)
        {
            pHead = pNew;
        }

        pNew->pNext = pCurrent;
        pNew->pPrev = pCurrent->pPrev;
        pCurrent->pPrev = pNew;

        if (pNew->pPrev)
        {
            pNew->pPrev->pNext = pNew;
        }
    }
    else
    {
        if (pTail == pCurrent)
        {
            pTail = pNew;
        }

        pNew->pPrev = pCurrent;
        pNew->pNext = pCurrent->pNext;
        pCurrent->pNext = pNew;

        if (pNew->pNext)
        {
            pNew->pNext->pPrev = pNew;
        }
    }
   numElements++;
}

template <class T>
typename list<T>::iterator list<T>::erase(iterator &t)
{
    iterator tNew = iterator(t);
    if (!empty())
    {
        if (t.ptr == pHead)
        {
            t.ptr->pNext->pPrev = t.ptr->pPrev;
            pHead = t.ptr->pNext;
            ++tNew;
        }
        else if (t.ptr == pTail)
        {
            t.ptr->pPrev->pNext = t.ptr->pNext;
            --tNew;
        }
        else if (t.ptr == NULL)
        {
            return t.ptr;
        }

        else
        {
            t.ptr->pPrev->pNext = t.ptr->pNext;
            t.ptr->pNext->pPrev = t.ptr->pPrev;
            --tNew;
        }
    }
    else
    {
        return t.ptr;
    }

    delete t.ptr;
    numElements--;
    return tNew;
}

template <class T>
typename list<T>::iterator list<T>::begin()
{
    return iterator(pHead);
}

template <class T>
typename list<T>::iterator list<T>::end()
{
    return iterator(pTail);
}

/****************
 * NODE
 *****************/

template <class T>
list<T>::node::node()
{
    data = T();
    pPrev = NULL;
    pNext = NULL;
}

template <class T>
list<T>::node::node(T t)
{
    data = t;
    pNext = NULL;
    pPrev = NULL;
}

template <class T>
list<T>::node::~node()
{
    // delete pNext;
    // delete pPrev;
}

/**************** 
 * list::iterator implementation 
 ****************/

template <class T>
list<T>::iterator::iterator()
{
    ptr = NULL;
}

template <class T>
list<T>::iterator::iterator(T *p)
{
    ptr = p;
}

template <class T>
list<T>::iterator::iterator(const iterator &rhs)
{
    *this = rhs;
}

template <class T>
list<T>::iterator::iterator(node *&aNode)
{
    ptr = aNode;
}

template <class T>
typename list<T>::iterator &list<T>::iterator::operator=(const iterator &rhs)
{
    ptr = rhs.ptr;
    return *this;
}

template <class T>
bool list<T>::iterator::operator!=(const iterator &rhs) const
{
    return rhs.ptr != this->ptr;
}

template <class T>
bool list<T>::iterator::operator==(const iterator &rhs) const
{
    return rhs.ptr == this->ptr;
}

template <class T>
T &list<T>::iterator::operator*()
{
    if (!ptr == NULL)
        return ptr->data;

    throw "Error: Dereferencing null node.";
}

template <class T>
typename list<T>::iterator &list<T>::iterator::operator++()
{

    if (ptr == NULL)
        throw "Error: Incrementing null node.";

    if (ptr->pNext)
        ptr = ptr->pNext;

    return *this;
}

template <class T>
typename list<T>::iterator list<T>::iterator::operator++(int postfix)
{
    iterator tmp(*this);
    ++(*this);
    return tmp;
}

template <class T>
typename list<T>::iterator &list<T>::iterator::operator--()
{
    if (ptr == NULL)
        throw "Error: Decrementing null node.";

    if (ptr->pPrev)
        ptr = ptr->pPrev;

    return *this;
}

template <class T>
typename list<T>::iterator list<T>::iterator::operator--(int postfix)
{
    iterator tmp(*this);
    --(*this);
    return tmp;
}