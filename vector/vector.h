#ifndef vector_h
#define vector_h
#ifdef UNIT_TESTING
#include <iostream>
int main(int argc, const char *argv[]);
#endif
namespace custom
{
template <class T>
class vector
{
#ifdef UNIT_TESTING
    friend int ::main(int argc, const char *argv[]);
#endif
private:
    T *buffer;
    int numElements;
    int numCapacity;
    //private resize
    void resize(int numCapacity);

public:
    //constructors
    vector();
    vector(int numElements);
    vector(const vector<T> &);
    vector(int numElements, T t);

    //destructor
    ~vector();

    //assigner

    vector assign(vector rhs);

    //getters

    int size();
    int capacity();
    bool empty();
    void clear();

    //mutators

    void push_back(T t);
    T access(int index);
    class iterator;
    iterator begin();
    iterator end();

    //accessor
    T &operator[](int index);
    vector<T> &operator=(const vector<T> &);
};
// template <class T>
template <class T>
class vector<T>::iterator
{
public:
#ifdef UNIT_TESTING
    friend int ::main(int argc, const char *argv[]);
#endif

    iterator();
    iterator(T *p);
    iterator(const iterator &rhs);
    iterator &operator=(const iterator &rhs);
    bool operator!=(const iterator &rhs) const;
    bool operator==(const iterator &rhs) const;
    T &operator*();
    iterator &operator++();
    iterator operator++(int postfix);
    iterator &operator--();
    iterator operator--(int postfix);

private:
    T *ptr;
};
} // namespace custom
#include "vector.cpp"
#endif
