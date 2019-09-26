
#include "vector.h"

template <class T>
vector<T>::vector()
{
    this->numCapacity = 0;
    this->numElements = 0;
    this->buffer = 0;
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
template <class T>
vector<T> vector<T>::assign(vector rhs)
{
}

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
    return;
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
        this->numCapacity = 0;
    }
    else
    {
        T *newBuffer = new T[numCapacity];
        if (this->numCapacity > numCapacity)
        {
            for (int i = 0; i < this->numCapacity; i++)
            {
                newBuffer[i] = buffer[i];
            }
        }
        else
        {
            for (int i = 0; i < numElements; i++)
            {
                newBuffer[i] = buffer[i];
            }
        }

        delete[] this->buffer;
        this->buffer = newBuffer;
        this->numCapacity = numCapacity;
        //    this->numElements = numCapacity;
    }
}
// iterator vector::begin(){return;}
// iterator vector::end(){return;}
}