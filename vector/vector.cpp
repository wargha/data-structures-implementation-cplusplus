
#include "vector.h"
#include <cstring>

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

template<class T>
T & vector<T>::operator[](int index) { 
    if (index >= 0 && index < numElements)
    return buffer[index];
    throw "Error: indices must be greater than zero and less than size().";
}
template<class T>
vector<T> & vector<T>::operator=(const vector<T> & v) { 
    delete[] buffer;
    if (v.numCapacity > v.numElements) { 
        numCapacity = v.numElements;
    } else {  numCapacity = v.numCapacity;}
    numElements = v.numElements;
    buffer = new T[numElements];
    for (int i = 0; i < numElements; i++) { 
        buffer[i] = v.buffer[i];
    }
    return *this;
}
template<class T>
vector<T>::iterator::iterator(){
    this->ptr = NULL;
}

template<class T>
vector<T>::iterator::iterator(T * p){
   this->ptr = p;
}
// iterator vector::end(){return;}
}