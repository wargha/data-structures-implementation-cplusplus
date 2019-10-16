
#include "stack.h"
#include <cstring>
using namespace custom;
using std::string;
template <class T>
stack<T>::stack()
{
    this->numCapacity = 0;
    this->numElements = 0;
    this->buffer = NULL;
}
template <class T>
stack<T>::stack(int numElements)
{
    if (numElements <= 0)
        throw "Error: stack sizes must be greater than 0.";

    this->numElements = numElements;
    this->numCapacity = numElements;
    this->buffer = new T[numElements];
    for (int i = 0; i < numElements; i++)
    {
        this->buffer[i] = T();
    }
}

template <class T>
stack<T>::stack(const stack<T> &v)
{
    *this = v;
}

template <class T>
stack<T>::stack(int numElements, T t)
{
    if (numElements <= 0)
        throw "Error: stack sizes must be greater than 0.";

    this->numElements = numElements;
    this->numCapacity = numElements;
    this->buffer = new T[numElements];
    for (int i = 0; i < numElements; i++)
    {
        this->buffer[i] = t;
    }
}

template <class T>
stack<T>::~stack()
{
}
// template <class T>
// stack<T>::assign(stack rhs)
// {
// }

template <class T>
int stack<T>::size()
{
    return this->numElements;
}
template <class T>
int stack<T>::capacity()
{
    return this->numCapacity;
}
template <class T>
bool stack<T>::empty()
{
    return (numElements == 0);
}
template <class T>
void stack<T>::clear()
{
    this->numElements = 0;
}

template <class T>
void stack<T>::push(T t)
{
    if (numElements == numCapacity)
        resize(numCapacity == 0 ? 1 : numCapacity * 2);
    buffer[numElements++] = t;
}


template <class T>
void stack<T>::pop()
{
    if (!this->empty()) --numElements;
}

template <class T>
T & stack<T>::top()
{   if (!this->empty()) return buffer[numElements  - 1];
    
    throw "Error: asking for top of empty stack.";
}

template <class T>
void stack<T>::resize(int numCapacity)
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
stack<T> &stack<T>::operator=(const stack<T> &v)
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

