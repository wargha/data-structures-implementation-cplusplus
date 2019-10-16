#ifndef deque_h
#define deque_h
#ifdef UNIT_TESTING
#include <iostream>
int main(int argc, const char *argv[]);
#endif
namespace custom
{
template <class T>
class deque
{
#ifdef UNIT_TESTING
    friend int ::main(int argc, const char *argv[]);
#endif
private:
    T *buffer;
    int numCapacity;
    void resize(int numCapacity);
    int iFront;
    int iBack;

public:
    //constructors
    deque();
    deque(int capacity);
    deque(const deque<T> &);

    //destructor
    ~deque();


    //getters

    int size();
    int capacity();
    bool empty();
    void clear();

    //mutators

    void push_front(T t);
    void push_back(T t);
    void pop_front();
    void pop_back();
    T & front();
    T & back();

    int iFrontNormalize();
    int iBackNormalize();
    int iNormalize(int i);

    //accessor
    deque<T> &operator=(const deque<T> &);
};

} // namespace custom
#include "deque.cpp"
#endif
