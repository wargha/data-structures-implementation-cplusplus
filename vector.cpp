
#include "vector.h"
#include <iostream>
namespace custom
{
template <class T>
vector<T>::vector()
{
    numCapacity = 0;
    numElements = 0;
    buffer = 0;
}
template <class T>
vector<T>::vector(int numElements)
{
}
template <class T>
vector<T>::vector(int numElements, T t)
{
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
    return 1;
}
template <class T>
int vector<T>::capacity()
{
    return 1;
}
template <class T>
bool vector<T>::empty()
{
    return false;
}
template <class T>
void vector<T>::clear() { return; }

template <class T>
void vector<T>::push_back(T t)
{
    return;
}
template <class T>
void vector<T>::access(int index)
{
    return;
}

template <class T>
void vector<T>::resize(int numCapacity)
{
    return;
}
// iterator vector::begin(){return;}
// iterator vector::end(){return;}
} // namespace custom