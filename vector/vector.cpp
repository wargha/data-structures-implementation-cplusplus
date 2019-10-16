
#include "vector.h"
#include <cstring>
using namespace custom;
using std::string;
template <class T>
vector<T>::vector()
{
    this->numCapacity = 0;
    this->numElements = 0;
    this->buffer = NULL;
}
template <class T>
vector<T>::vector(int numElements)
{
    if (numElements <= 0)
        throw "Error: vector sizes must be greater than 0.";

    this->numElements = numElements;
    this->numCapacity = numElements;
    this->buffer = new T[numElements];
    for (int i = 0; i < numElements; i++)
    {
        this->buffer[i] = T();
    }
}

template <class T>
vector<T>::vector(const vector<T> &v)
{
    *this = v;
}

template <class T>
vector<T>::vector(int numElements, T t)
{
    if (numElements <= 0)
        throw "Error: vector sizes must be greater than 0.";

    this->numElements = numElements;
    this->numCapacity = numElements;
    this->buffer = new T[numElements];
    for (int i = 0; i < numElements; i++)
    {
        this->buffer[i] = t;
    }
}

template <class T>
vector<T>::~vector()
{
}
// template <class T>
// vector<T>::assign(vector rhs)
// {
// }

template <class T>
int vector<T>::size()
{
    return this->numElements;
}
template <class T>
int vector<T>::capacity()
{
    return this->numCapacity;
}
template <class T>
bool vector<T>::empty()
{
    return (numElements == 0);
}
template <class T>
void vector<T>::clear()
{
    this->numElements = 0;
}

template <class T>
void vector<T>::push_back(T t)
{
    if (numElements == numCapacity)
        resize(numCapacity == 0 ? 1 : numCapacity * 2);
    buffer[numElements++] = t;
}
template <class T>
T vector<T>::access(int index)
{
    return;
}

template <class T>
void vector<T>::resize(int numCapacity)
{
    if (numCapacity < 0)
    {
        this->clear();
    }

    else if (numCapacity == 0)
    {
        this->buffer = 0;
        this->clear();
        this->numCapacity = numCapacity;
    }
    else
    {
        T *newBuffer = new T[numCapacity];
        for (int i = 0; i < this->numElements && i < numCapacity; i++)
        {
            newBuffer[i] = buffer[i];
        }
        if (this->numElements > numCapacity)
        {
            this->numElements = numCapacity;
        }
        this->numCapacity = numCapacity;
        delete[] this->buffer;
        this->buffer = newBuffer;
    }
}

template <class T>
T &vector<T>::operator[](int index)
{
    if (index >= 0 && index < numElements)
        return buffer[index];
    throw "Error: indices must be greater than zero and less than size().";
}
template <class T>
vector<T> &vector<T>::operator=(const vector<T> &v)
{
    delete[] buffer;
    if (v.numCapacity > v.numElements)
    {
        numCapacity = v.numElements;
    }
    else
    {
        numCapacity = v.numCapacity;
    }
    numElements = v.numElements;
    buffer = new T[numElements];
    for (int i = 0; i < numElements; i++)
    {
        buffer[i] = v.buffer[i];
    }
    return *this;
}

template <class T>
typename vector<T>::iterator vector<T>::begin()
{
   return iterator(buffer);
}

template <class T>
typename vector<T>::iterator vector<T>::end()
{
   return iterator(buffer + numElements);
}

template <class T>
vector<T>::iterator::iterator()
{
    ptr = NULL;
}

template <class T>
vector<T>::iterator::iterator(T *p)
{
    ptr = p;
}

template <class T>
vector<T>::iterator::iterator(const iterator &rhs)
{
    *this = rhs;
}

template <class T>
typename vector<T>::iterator &vector<T>::iterator::operator=(const iterator &rhs)
{
    ptr = rhs.ptr;
    return *this;
}

template <class T>
bool vector<T>::iterator::operator!=(const iterator &rhs) const
{
    return rhs.ptr != this->ptr;
}

template <class T>
bool vector<T>::iterator::operator==(const iterator &rhs) const
{
    return rhs.ptr == this->ptr;
}

template <class T>
T &vector<T>::iterator::operator*()
{
    return *ptr;
}

template <class T>
typename vector<T>::iterator &vector<T>::iterator::operator++()
{
    if (ptr != NULL)
        ptr++;
    return *this;
}

template <class T>
typename vector<T>::iterator vector<T>::iterator::operator++(int postfix)
{
    iterator tmp(*this);
    if (ptr != NULL)
        ptr++;
    return tmp;
}

template <class T>
typename vector<T>::iterator &vector<T>::iterator::operator--()
{
    if (ptr != NULL)
        ptr--;
    return *this;
}

template <class T>
typename vector<T>::iterator vector<T>::iterator::operator--(int postfix)
{
    iterator tmp(*this);
    ptr--;
    return tmp;
}
