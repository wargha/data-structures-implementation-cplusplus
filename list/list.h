#ifndef LIST_H
#define LIST_H

#define NULL 0

#ifdef UNIT_TESTING
int main(int argc, const char *argv[]);
#endif

namespace custom
{
template <class T>
class list
{
public:
    class node;
    class iterator;

#ifdef UNIT_TESTING
    friend int ::main(int argc, const char *argv[]);
#endif

    list();
    list(const list &rhs);
    ~list();
    list<T> &operator=(const list &rhs);
    int size() const;
    bool empty() const;
    void clear();

    void push_front(const T &t);
    void push_back(const T &t);
    void pop_front();
    void pop_back();

    T &front();
    T &back();

    iterator find(const T &t);
    void insert(iterator &it, const T &t);
    void insertAt(node *pNode, const T &t, bool after = false);
    iterator erase(iterator &it);
    iterator begin();
    iterator end();

private:
    node *pHead;
    node *pTail;
    int numElements;
};

template <class T>
class list<T>::node
{
public:
#ifdef UNIT_TESTING
    friend int ::main(int argc, const char *argv[]);
#endif

    friend list;

    node();
    node(T t);
    ~node();
    T data;
    node *pPrev;
    node *pNext;
};

template <class T>
class list<T>::iterator
{
public:
#ifdef UNIT_TESTING
    friend int ::main(int argc, const char *argv[]);
#endif
    friend list;

    iterator();
    iterator(T *p);
    iterator(const iterator &rhs);
    iterator(node *&ptr);
    iterator& operator=(const iterator &rhs);
    bool operator!=(const iterator &rhs) const;
    bool operator==(const iterator &rhs) const;
    T& operator*();
    iterator& operator++();
    iterator operator++(int postfix);
    iterator& operator--();
    iterator operator--(int postfix);

private:
    node *ptr;
};
} // namespace custom

#include "list.cpp"
#endif