namespace custom
{
template <class T>
class vector
{
public:
    T *buffer;
    int numElements;
    int numCapacity;

    //private resize
    void resize(int numCapacity);

public:
    //constructors
    vector();
    vector(int numElements);
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
    void access(int index);
    // iterator begin();
    // iterator end();
};
} // namespace custom