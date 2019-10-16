#ifndef stack_h
#define stack_h
#ifdef UNIT_TESTING
#include <iostream>
int main(int argc, const char *argv[]);
#endif
namespace custom
{
template <class T>
class stack
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
    stack();
    stack(int numElements);
    stack(const stack<T> &);
    stack(int numElements, T t);

    //destructor
    ~stack();

    //assigner

    stack assign(stack rhs);

    //getters

    int size();
    int capacity();
    bool empty();
    void clear();

    //mutators

    void push(T t);
    void pop();
    T & top();

    //accessor
    stack<T> &operator=(const stack<T> &);
};

} // namespace custom
#include "stack.cpp"
#endif
