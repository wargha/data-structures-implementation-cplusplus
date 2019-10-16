
#include "deque.h"
#include <cstring>
using namespace custom;
using std::string;
template <class T>
deque<T>::deque()
{
    this->iFront = 0;
    this->iBack = -1;
    this->numCapacity = 0;
    this->buffer = NULL;
}

template <class T>
deque<T>::deque(int capacity)
{
    if (capacity < 0)
        throw "Error: deque sizes must be greater than or equal to 0.";
    this->iFront = 0;
    this->iBack = -1;
    this->numCapacity = capacity;
    this->buffer = new T[capacity];
    for (int i = 0; i < numCapacity; i++)
    {
        this->buffer[i] = T();
    }
}

template <class T>
deque<T>::deque(const deque<T> &rhs)
{
    numCapacity = rhs.iBack - rhs.iFront + 1;
    buffer = new T[numCapacity];

    iFront = 0;
    iBack = numCapacity - 1;

    int f = rhs.iFront;
    int cap = rhs.numCapacity;

    for (int i = 0; i < numCapacity; i++) { 
        int z = (f % cap + cap) % cap;
        buffer[i] = rhs.buffer[z];
        f++;
    }
}

template <class T>
deque<T>::~deque()
{
}

template <class T>
int deque<T>::size()
{
    return iBack - iFront + 1;
}
template <class T>
int deque<T>::capacity()
{
    return this->numCapacity;
}
template <class T>
bool deque<T>::empty()
{

    return this->size() == 0;
}
template <class T>
void deque<T>::clear()
{
    this->iBack = -1;
    this->iFront = 0;
}

template <class T>
void deque<T>::push_back(T t)
{
    if (size() == capacity())
        resize(capacity() * 2);
    iBack++;
    buffer[iBackNormalize()] = t;
}

template <class T>
void deque<T>::push_front(T t)
{
    if (size() == capacity())
    {
  if (capacity() == 0) resize(1);
    else  resize(capacity() * 2);
       
    }
  
    iFront--;
    buffer[iFrontNormalize()] = t;
}

template <class T>
void deque<T>::pop_front()
{
    if (empty())
        throw "Error: Can not pop an empty deque.";
    iFront++;
}

template <class T>
void deque<T>::pop_back()
{
    if (empty())
        throw "Error: Can not pop an empty deque.";
    iBack--;
}

template <class T>
T &deque<T>::front()
{
    if (!this->empty())
        return buffer[iFrontNormalize()];

    throw "Error: deque is empty.";
}

template <class T>
T &deque<T>::back()
{
    if (!this->empty())
        return buffer[iBackNormalize()];

    throw "Error: deque is empty.";
}

template <class T>
int deque<T>::iFrontNormalize()
{
    return iNormalize(iFront);
}

template <class T>
int deque<T>::iBackNormalize()
{
    return iNormalize(iBack);
}

template <class T>
int deque<T>::iNormalize(int i)
{
    if (numCapacity == 0)
        throw "Error: Uninitialized deque.";

    return (i % numCapacity + numCapacity) % numCapacity;
}

template <class T>
void deque<T>::resize(int newCapacity)
{
    if (numCapacity < 0)
    {
        this->clear();
    }

    else if (newCapacity == 0)
    {
        this->buffer = 0;
        this->clear();
        this->numCapacity = newCapacity;
    }
    if (newCapacity > 0)
    {
        T *newBuffer = new T[newCapacity];
        int numElements = (newCapacity < size()) ? newCapacity : size();
        if (buffer != NULL)
        {
            for (int i = 0; i < numElements; i++, iFront++)
                newBuffer[i] = buffer[iFrontNormalize()];
        }

        delete[] buffer;
        buffer = newBuffer;
        this->numCapacity = newCapacity;
        iFront = 0;
        iBack = numElements - 1;
    }
}

template <class T>
deque<T> &deque<T>::operator=(const deque<T> &rhs)
{
    numCapacity = rhs.size();
    buffer = new T[numCapacity];

    iFront = 0;
    iBack = numCapacity - 1;

    int f = rhs.iFront;
    int cap = rhs.numCapacity;

    for (int i = 0; i < numCapacity; i++) { 
        int z = (f % cap + cap) % cap;
        buffer[i] = rhs.buffer[z];
        f++;
    }

    return *this;

}
