#ifndef bnode_H
#define bnode_H

#include <cassert>
#include <iostream>
using namespace std;

template <class T>
class BNode
{
public:
    T data;
    BNode *pLeft;
    BNode *pRight;
    BNode *pParent;

    BNode()
    {
        data = T();
        pLeft = NULL;
        pRight = NULL;
        pParent = NULL;
    }

    //Non-Default Constructor
    BNode(const T &value)
    {
        data = value;
        pLeft = NULL;
        pRight = NULL;
        pParent = NULL;
    }
};

template <class T>
int sizeBTree(BNode<T> *head)
{
    int size = 1;
    if (head->pLeft != NULL)
    {
        size += sizeBTree(head->pLeft);
    }
    if (head->pRight != NULL)
    {
        size += sizeBTree(head->pRight);
    }
    return size;
}

template <class T>
void deleteBTree(BNode<T> *&pNode)
{
    if (!pNode)
        return;

    deleteBTree(pNode->pLeft);
    deleteBTree(pNode->pRight);
    delete pNode;
    pNode = NULL;
}

template <class T>
BNode<T> *copyBTree(const BNode<T> *pSrc)
{
      if (pSrc == NULL)
    {
        return NULL;
    }
    
    BNode<T>* pDestination = new BNode<T>(pSrc->data);

    pDestination->pLeft = copyBTree(pSrc->pLeft);
    if (pDestination->pLeft != NULL)
    {
        pDestination->pLeft->pParent = pDestination;
    }

    pDestination->pRight = copyBTree(pSrc->pRight);
    if (pDestination->pRight != NULL)
    {
        pDestination->pRight->pParent = pDestination;
    }

    return pDestination;
}

template <class T>
void addLeft(BNode<T> *pNode, const T &data)
{
    addLeft(pNode, new BNode<T>(data));
}

template <class T>
void addLeft(BNode<T> *pNode, BNode<T> *pAdd)
{
    if (pNode)
    {
        pNode->pLeft = pAdd;
        if (pAdd)
            pAdd->pParent = pNode;
    }
}

template <class T>
void addRight(BNode<T> *pNode, const T &data)
{
    addRight(pNode, new BNode<T>(data));
}

template <class T>
void addRight(BNode<T> *pNode, BNode<T> *pAdd)
{
    if (pNode)
    {
        pNode->pRight = pAdd;
        if (pAdd)
            pAdd->pParent = pNode;
    }
}

template <class T>
ostream &operator<<(ostream &out, const BNode<T> *rhs)
{
  if (rhs) 
  { 
      out << rhs->pLeft << rhs->data << " " << rhs->pRight;
      return out;
  }
}

#endif // BNode_H