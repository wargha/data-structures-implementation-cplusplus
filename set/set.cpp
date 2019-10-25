
#include "set.h"
#include <cstring>
using namespace custom;
using std::string;
template <class T>
set<T>::set()
{
    this->numCapacity = 0;
    this->numElements = 0;
    this->buffer = NULL;
}
template <class T>
set<T>::set(int capacity)
{
    if (capacity < 0)
    {
        throw "Error: set sizes must be greater than or equal to 0.";
    }
    else
    {
        this->numElements = 0;
        this->numCapacity = capacity;
        this->buffer = new T[this->numCapacity];
    }
}

template <class T>
set<T>::set(const set<T> &rhs)
{
    if (rhs.numElements > 0)
    {
        if (buffer != NULL)
        {
            delete[] buffer;
            buffer = NULL;
        }
        buffer = new T[rhs.numElements];

        for (int i = 0; i < rhs.numElements; i++)
        {
            buffer[i] = rhs.buffer[i];
        }
    }
    numElements = rhs.numElements;
    numCapacity = rhs.numElements;
}

template <class T>
set<T>::~set()
{
}

template <class T>
int set<T>::size()
{
    return this->numElements;
}

template <class T>
int set<T>::findIndex(T t)
{
    int iBegin = 0;
    int iEnd = numElements - 1;
    int iMiddle = 0;

    while (iBegin <= iEnd)
    {
        iMiddle = (iBegin + iEnd) / 2;

        if (buffer[iMiddle] == t)
            return iMiddle;
        if (t < buffer[iMiddle])
            iEnd = iMiddle - 1;
        else
            iBegin = iMiddle + 1;
    }
    return iBegin;
}

template <class T>
int set<T>::capacity()
{
    return this->numCapacity;
}
template <class T>
bool set<T>::empty()
{
    return (numElements == 0);
}

template <class T>
typename set<T>::iterator set<T>::erase(iterator &it)
{

    iterator empty;

    if (it != empty)
    {
        T t = *it;
        int iErase = findIndex(t);

        if (iErase != numElements && buffer[iErase] == t)
        {
            for (int i = iErase; i < numElements; i++)
                buffer[i] = buffer[i + 1];
        }
        numElements--;
    }
}

template <class T>
typename set<T>::iterator set<T>::find(T t)
{
    iterator it;
    int index = findIndex(t);
    if (index != numElements && buffer[index] == t)
        it = iterator(buffer + index);
    return it;
}

template <class T>
void set<T>::clear()
{
    this->numElements = 0;
}

template <class T>
void set<T>::insert(T t)
{
    int index = findIndex(t);
    if (index == numElements || buffer[index] != t)
    {
        if (numCapacity == numElements)
            resize(numCapacity == 0 ? 1 : numCapacity * 2);
        for (int i = numElements; i > index; i--)
            buffer[i] = buffer[i - 1];
        buffer[index] = t;
        numElements++;
    }
}

template <class T>
void set<T>::resize(int newCap)
{
    if (newCap == 0)
    {
        numCapacity = 0;
        numElements = 0;
        buffer = NULL;
    }

    if (newCap > 0)
    {
        T *newBuffer = new T[newCap];
        int items = (newCap < numElements) ? newCap : numElements;
        for (int i = 0; i < items; i++)
            newBuffer[i] = buffer[i];
        if (buffer != NULL)
            delete[] buffer;
        buffer = newBuffer;
        numCapacity = newCap;
        numElements = items;
    }
}

template <class T>
set<T> set<T>::operator&&(const set<T> &rhs)
{
    set<T> data;
    for (int i = 0; i < this->numElements; i++)
    {
        for (int j = 0; j < rhs.numElements; j++)
        {
            if (this->buffer[i] == rhs.buffer[j])
                data.insert(this->buffer[i]);
        }
    }
    if (data.numElements == 0)
        data.buffer = NULL;
    data.numCapacity = data.numElements;
    return data;
}
template <class T>
set<T> &set<T>::operator=(const set<T> &rhs)
{
    numElements = 0;
    if (rhs.numCapacity > numCapacity)
    {
        resize(rhs.numElements);
    }

    numElements = rhs.numElements;
    for (int i = 0; i < numElements; i++)
    {
        buffer[i] = rhs.buffer[i];
    }

    return *this;
}

template <class T>
set<T> set<T>::operator||(const set<T> &rhs)
{
    set<T> s;
    for (int i = 0; i < rhs.numElements; i++)
        s.insert(rhs.buffer[i]);

    for (int j = 0; j < this->numElements; j++)
        s.insert(this->buffer[j]);

    s.numCapacity = s.numElements;
    return s;
}

template <class T>
set<T> set<T>::operator-(const set<T> &rhs)
{
    int iLhs = 0;
    int iRhs = 0;
    set<T> result(numElements + rhs.numElements);

    while (iLhs < numElements || iRhs < rhs.numElements)
    {
        if (iLhs == numElements)
            break;

        else if (iRhs == rhs.numElements)
            result.buffer[result.numElements++] = buffer[iLhs++];

        else if (buffer[iLhs] < rhs.buffer[iRhs])
            result.buffer[result.numElements++] = buffer[iLhs++];

        else if (buffer[iLhs] > rhs.buffer[iRhs])
            iRhs++;

        else if (buffer[iLhs] == rhs.buffer[iRhs])
        {
            iRhs++;
            iLhs++;
        }
    }

    if (result.numElements == 0)
        result.buffer = NULL;
    result.numCapacity = result.numElements;
    return result;
}

template <class T>
typename set<T>::iterator set<T>::begin()
{
    return iterator(buffer);
}

template <class T>
typename set<T>::iterator set<T>::end()
{
    return iterator(buffer + numElements);
}

template <class T>
set<T>::iterator::iterator()
{
    ptr = NULL;
}

template <class T>
set<T>::iterator::iterator(T *p)
{
    ptr = p;
}

template <class T>
set<T>::iterator::iterator(const iterator &rhs)
{
    *this = rhs;
}

template <class T>
typename set<T>::iterator &set<T>::iterator::operator=(const iterator &rhs)
{
    ptr = rhs.ptr;
    return *this;
}

template <class T>
bool set<T>::iterator::operator!=(const iterator &rhs) const
{
    return rhs.ptr != this->ptr;
}

template <class T>
bool set<T>::iterator::operator==(const iterator &rhs) const
{
    return rhs.ptr == this->ptr;
}

template <class T>
T &set<T>::iterator::operator*()
{
    return *ptr;
}

template <class T>
typename set<T>::iterator &set<T>::iterator::operator++()
{
    if (ptr != NULL)
        ptr++;
    return *this;
}

template <class T>
typename set<T>::iterator set<T>::iterator::operator++(int postfix)
{
    iterator result = iterator(*this);
    if (ptr != NULL)
    {
        ++ptr;
    }
    return result;
}

template <class T>
typename set<T>::iterator &set<T>::iterator::operator--()
{
    if (ptr != NULL)
        ptr--;
    return *this;
}

template <class T>
typename set<T>::iterator set<T>::iterator::operator--(int postfix)
{
    // iterator tmp(*this);
    // ptr--;
    // return tmp;
    iterator result = iterator(*this);
    if (ptr != NULL)
    {
        ptr--;
    }
    return result;
}
