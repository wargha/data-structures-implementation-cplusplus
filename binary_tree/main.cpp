

#include <iostream> // for CIN and COUT
#include <string>   // for STRING
#include <cassert>  // for ASSERT
#include "bnode.h"  // your BinaryNode class should be in bnode.h
using namespace std;

void assertTrue(bool isTrue, int lineNumber);


/**********************************************************************
 * MAIN
 * This is just a simple menu to launch a collection of tests
 ***********************************************************************/
int countTests = 0;
int totalTests = 100;

int main()
{
    string testName;

    // Test1: a bool Stack with defeault constructor
    testName = "Default Constructor";
    cout << "Start Test: " << testName << endl;
    BNode<bool> tree;
    assertTrue(sizeBTree(&tree) == 1, __LINE__);
    assertTrue(tree.pLeft == NULL, __LINE__);
    assertTrue(tree.pRight == NULL, __LINE__);
    assertTrue(tree.pParent == NULL, __LINE__);
    assertTrue(tree.data == NULL, __LINE__); // 0 = NULL
    testName = "Non Default Constructor";
    cout << "Start Test: " << testName << endl;
    // Test2: double Stack with non-default constructor
    BNode<double> *pTree = new BNode<double>(3.14159);
    assertTrue(sizeBTree(pTree) == 1, __LINE__);
    assertTrue(pTree->data != NULL, __LINE__);
    assertTrue(pTree->data == 3.14159, __LINE__);
    assertTrue(pTree->pLeft == NULL, __LINE__);
    assertTrue(pTree->pRight == NULL, __LINE__);
    assertTrue(pTree->pParent == NULL, __LINE__);
    BNode<string> *pStringTree = new BNode<string>("Testing a string...");
    assertTrue(sizeBTree(pStringTree) == 1, __LINE__);
    delete pTree;

    testName = "Add";
    cout << "Start Test: " << testName << endl;
    BNode<int> *pAdd = new BNode<int>(1);
    addLeft(pAdd, 2);
    assertTrue(pAdd->pLeft->data == 2, __LINE__);
    addLeft(pAdd, 3);
    assertTrue(pAdd->pLeft->data == 3, __LINE__);
    addRight(pAdd, 3);
    addLeft(pAdd->pRight, 4);
    assertTrue(pAdd->pRight->pLeft->data == 4, __LINE__);
    assertTrue(pAdd->pRight->data == 3, __LINE__);
    addRight(pAdd, new BNode<int>(1));
    assertTrue(pAdd->pRight->data == 1, __LINE__);

    testName = "Delete";
    cout << "Start Test: " << testName << endl;
    deleteBTree(pAdd);
    assertTrue(true, __LINE__); // only gets here if the tree was deleted with no errors

    testName = "display";
    cout << "Start Test: " << testName << endl;

    return 0;
}

void assertTrue(bool isTrue, int lineNumber)
{
    if (isTrue)
    {
        cout << "\t Testing line " << lineNumber << " ... passed" << endl;
        countTests++;
    }

    else
        cout << " \t Error on line " << lineNumber << endl;
    return;
}

void testDisplay()
{
#ifdef TEST3
    try
    {
        // create
        BNode<string> *pTree = NULL;

        // prompt for seven words
        string word;
        cout << "Enter seven words\n";
        cout << "\tRoot node:         ";
        cin >> word;
        pTree = new BNode<string>(word);

        cout << "\tLeft child:        ";
        cin >> word;
        addLeft(pTree, new BNode<string>(word));

        cout << "\tRight child:       ";
        cin >> word;
        addRight(pTree, new BNode<string>(word));

        cout << "\tLeft-Left child:   ";
        cin >> word;
        addLeft(pTree->pLeft, new BNode<string>(word));

        cout << "\tLeft-Right child:  ";
        cin >> word;
        addRight(pTree->pLeft, new BNode<string>(word));

        cout << "\tRight-Left child:  ";
        cin >> word;
        addLeft(pTree->pRight, new BNode<string>(word));

        cout << "\tRight-Right child: ";
        cin >> word;
        addRight(pTree->pRight, new BNode<string>(word));

        // display the results
        cout << "Completed tree: { " << pTree << "}\n";

        // delete the tree
        deleteBTree(pTree);
    }
    catch (const char *error)
    {
        cout << error << endl;
    }
#endif // TEST3
}

void testMerge()
{
#ifdef TEST4
    try
    {
        // create the middle tree
        BNode<char> *pMiddle = new BNode<char>('m');
        addLeft(pMiddle, 'l');
        addRight(pMiddle, 'n');
        cout << "Middle tree: { " << pMiddle << "}"
             << " size = " << sizeBTree(pMiddle) << endl;

        // create lower tree
        BNode<char> *pLower = new BNode<char>('b');
        addLeft(pLower, 'a');
        addRight(pLower, 'c');
        cout << "Lower tree: { " << pLower << "}"
             << " size = " << sizeBTree(pLower) << endl;

        // create upper tree
        BNode<char> *pUpper = new BNode<char>('y');
        addLeft(pUpper, 'x');
        addRight(pUpper, 'z');
        cout << "Upper tree: { " << pUpper << "}"
             << " size = " << sizeBTree(pUpper) << endl;

        // add Lower to the left of Middle, and Upper to the right of Middle
        addLeft(pMiddle->pLeft, pLower);
        addRight(pMiddle->pRight, pUpper);
        cout << "Merged tree: { " << pMiddle << "}"
             << " size = " << sizeBTree(pMiddle) << endl;

        // copy the tree
        BNode<char> *pCopy = copyBTree(pMiddle);

        // delete the tree
        deleteBTree(pMiddle);
        assert(pMiddle == NULL);

        // display the copied tree
        cout << "Copied tree: { " << pCopy << "}"
             << " size = " << sizeBTree(pCopy) << endl;
        deleteBTree(pCopy);
        assert(pCopy == NULL);
    }
    catch (const char *error)
    {
        cout << error << endl;
    }
#endif // TEST4
}
