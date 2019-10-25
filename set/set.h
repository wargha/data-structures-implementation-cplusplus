#ifndef set_h
#define set_h
#ifdef UNIT_TESTING
#include <iostream>
int main(int argc, const char *argv[]);
#endif
namespace custom
{
template <class T>
class set
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
    int findIndex(T t);

public:
    //constructors
    set();
    set(int numElements);
    set(const set<T> &);

    //destructor
    ~set();

    //assigner

    set assign(set rhs);

    //getters

    int size();
    int capacity();
    bool empty();
    void clear();
    void insert(T t);

    //mutators
    T access(int index);
    class iterator;
    iterator begin();
    iterator end();
    iterator erase(iterator & it);
    iterator find(T t);

    //accessor
    set<T> &operator=(const set<T> &);
    set<T> operator||(const set<T> &rhs);
    set<T> operator&&(const set<T> &rhs);
    set<T> operator-(const set<T> &rhs);
};
// template <class T>
template <class T>
class set<T>::iterator
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
#include "set.cpp"
#endif
