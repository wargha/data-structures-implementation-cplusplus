
#include "queue.h"
#include <cstring>
using namespace custom;
using std::string;
template <class T>
queue<T>::queue()
{
    this->numCapacity = 0;
    this->numPop = 0;
    this->numPush = 0;
    this->buffer = NULL;
}

template <class T>
queue<T>::queue(const queue<T> &v)
{
    *this = v;
}

template <class T>
queue<T>::~queue()
{
}

template <class T>
int queue<T>::size()
{
    return numPush - numPop;
}
template <class T>
int queue<T>::capacity()
{
    return this->numCapacity;
}
template <class T>
bool queue<T>::empty()
{
    return (numPop == numPush);
}
template <class T>
void queue<T>::clear()
{
    this->numPop = 0;
    this->numPush = 0;
}

template <class T>
void queue<T>::push(T t)
{
    if (size() == capacity())
    {
        if (capacity() == 0)
            resize(1);
        else
            resize(numCapacity * 2);
    }
    numPush++;
    buffer[iTail()] = t;
}

template <class T>
void queue<T>::pop()
{
    if (!empty())
        this->numPop++;
}

template <class T>
T &queue<T>::front()
{
    if (!this->empty())
        return buffer[iHead()];

    throw "Error: asking for front of empty queue.";
}

template <class T>
T &queue<T>::back()
{
    if (!this->empty())
        return buffer[iTail()];

    throw "Error: asking for back of empty queue.";
}

template <class T>
int queue<T>::iHead()
{
    return numPop % numCapacity;
}

template <class T>
int queue<T>::iTail()
{
    return (numPush - 1) % numCapacity;
}

template <class T>
void queue<T>::resize(int numCapacity)
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
    if (numCapacity > 0)
    {
        T *newBuffer = new T[numCapacity];
        int numElements = (numCapacity < size()) ? numCapacity : size();
        for (int i = 0; i < numElements; i++, numPop++)
        {
            newBuffer[i] = buffer[iHead()];
        }

        delete[] buffer;
        buffer = newBuffer;
        this->numCapacity = numCapacity;
        numPop = 0;
        numPush = numElements;
    }
}

template <class T>
queue<T> &queue<T>::operator=(const queue<T> &rhs)
{
    numPush = rhs.numPush;
    numPop = rhs.numPop;
    numCapacity = rhs.numCapacity;
    
    if(numPop > 0)
    {
        numCapacity = numCapacity - numPop;
        numPush = numPush - numPop;

        buffer = new T[rhs.numCapacity];

        for (int i = 0; i < rhs.numCapacity; i++)
        {
            buffer[i] = rhs.buffer[i + numPop];
        }

        numPop = 0;
    }
    else
    { 
        buffer = new T[rhs.numCapacity];

        for (int i = 0; i < rhs.numCapacity; i++)
        {
            buffer[i] = rhs.buffer[i];
        }
    }
   return *this;
}
