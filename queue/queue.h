#ifndef queue_h
#define queue_h
#ifdef UNIT_TESTING
#include <iostream>
int main(int argc, const char *argv[]);
#endif
namespace custom
{
template <class T>
class queue
{
#ifdef UNIT_TESTING
    friend int ::main(int argc, const char *argv[]);
#endif
private:
    T *buffer;
    int numCapacity;
    int numPop;
    int numPush;
    void resize(int numCapacity);

public:
    //constructors
    queue();
    queue(const queue<T> &);

    //destructor
    ~queue();


    //getters

    int size();
    int capacity();
    bool empty();
    void clear();

    //mutators

    void push(T t);
    void pop();
    T & front();
    T & back();
    int iHead();
    int iTail();

    //accessor
    queue<T> &operator=(const queue<T> &);
};

} // namespace custom
#include "queue.cpp"
#endif
