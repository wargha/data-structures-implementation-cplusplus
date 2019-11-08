#ifndef list_h
#define list_h
#ifdef UNIT_TESTING
#include <iostream>
int main(int argc, const char *argv[]);
#endif
namespace custom
{
template <typename T>
class node
{
#ifdef UNIT_TESTING
    friend int::main(int argc, const char *argv[]);
#endif

public:
    T data;
    node *pNext;
    node *pPrev;

    node()
    {
        data = 0;
        pNext = NULL;
        pPrev = NULL;
    }
    node(const T &value)
    {
        data = value;
        pNext = NULL;
        pPrev = NULL;
    }
};

//Copy Function
template <class T>
node<T> *copy(const node<T> *pSource) throw(const char *)
{
    if (pSource != NULL) 
    {
        node<T> *pDestination = new node<T>(pSource->data); 
        node<T> *nodeIter = pDestination;                   

        while (pSource->pNext)
        {
            pSource = pSource->pNext;                     
            nodeIter->pNext = new node<T>(pSource->data); 
            nodeIter->pNext->pPrev = nodeIter;            
            nodeIter = nodeIter->pNext;                   
        }

        return pDestination;
    }
    return 0;
}

//Insert Function
template <class T>
node<T> *insert(node<T> *&pNode, const T &t, bool after = false) throw(const char *)
{
    if (pNode == NULL)
    {
        throw "Error: inserting into NULL list.";
    }

    node<T> *pNew = new node<T>(t);

    if (!after)
    {
        pNew->pNext = pNode;

        if (pNode->pPrev != NULL)
        {
            pNode->pPrev->pNext = pNew;
            pNew->pPrev = pNode->pPrev;
        }

        pNode->pPrev = pNew;
    }
    else
    {
        pNew->pPrev = pNode;
        if (pNode->pNext != NULL)
        {
            pNode->pNext->pPrev = pNew;
            pNew->pNext = pNode->pNext;
        }
        pNode->pNext = pNew;
    }

    return pNew;
}

//Find Function
template <class T>
node<T> *find(node<T> *pHead, const T &t)
{
    if (pHead != NULL) 
    {
        while (pHead->pNext) 
        {
            if (t == pHead->data) 
            {
                return pHead; 
            }

            pHead = pHead->pNext; 
        }

        if (t == pHead->data) 
        {
            return pHead;
        }
    }
    return NULL;
}

//Clear Function
template <class T>
void clear(node<T> *&pHead) throw(const char *)
{
    node<T> *pDelete = new node<T>;

    if (!pHead)
    {
        throw "Error: freeing NULL list.";
        return;
    }
    
    while (pHead)
    {
        pDelete = pHead;
        pHead = pHead->pNext;
        delete[] pDelete;
    }  
}

//Remove Function
template <class T>
node<T> *remove(node<T> *&pRemove)
{
    if (pRemove == NULL)
    {
        return 0;
    }

    if (pRemove->pPrev)
    {
        pRemove->pPrev->pNext = pRemove->pNext;
    }

    //To detatch pointer to next node
    if (pRemove->pNext)
    {
        pRemove->pNext->pPrev = pRemove->pPrev;
    }

    //			create the node that we are going to return
    node<T> *pReturn;

    //
    if (pRemove->pPrev)
    {
        pReturn = pRemove->pPrev;
    }
    else
    {
        pReturn = pRemove->pNext;
    }

    delete[] pRemove; //finally delete after every pointer has been removed
    pRemove = NULL;

    return pReturn; //return the new node
}
} // namespace custom
#endif /* Node_h */
