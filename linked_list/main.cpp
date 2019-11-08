/*
 * main.cpp
 *
 *  Created by Lee Barney on 09/15/18.
 *  Copyright (c) 2018 Lee Barney
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation the
 *  rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

/* !!!!GRADING INSTRUCTIONS!!!!
 *
 * When you report your score for this test set, report
 * the percentage of assertTrues found in this test code that
 * your data structure code passed.
 */
#define UNIT_TESTING
//Do not change the next line without instructor approval.
//To do so is cheating and, when found, will result in consequences.
int asserts_existing = 84;

#include <cstring>
#include "unit_testing.h"
#include "linked_list.h"

using namespace custom;


int main(int argc, const char* argv[])
{
    
    /*
     * Testing default constructor
     */
    startTestSet("Default Constructor");
    node <int> defaultNode;
    assertTrue(defaultNode.data == 0, __LINE__);
    assertTrue(defaultNode.pNext == NULL, __LINE__);
    assertTrue(defaultNode.pPrev == NULL, __LINE__);
    
    /*
     * Testing constructor with data
     */
    startTestSet("Non-Default Constructor");
    node<int> dataNode(4);
    assertTrue(dataNode.data == 4, __LINE__);
    assertTrue(dataNode.pNext == NULL, __LINE__);
    assertTrue(dataNode.pPrev == NULL, __LINE__);
    
    /*
     *  Testing Copy Function
     */
    startTestSet("Copy");
    //The Copy function should produce a shallow copy.
    //That means the data doesn't get copied but the nodes do.
    
    //Generating small doubly linked list with the ordered list of values 5<->6<->7<->8<->9<->10. The character set <-> indicates doubly linked nodes.
    node<int>* theHead = new node<int>(5);
    node<int>* currentNodePtr = theHead;
    node<int>* aNode = new node<int>(6);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(7);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(8);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(9);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(10);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
   
    //Copying a null list of nodes.
    node<int>* whereToStartCopy = NULL;
    assertTrue(copy(whereToStartCopy) == NULL, __LINE__);
    
    //Copying an entire list of nodes.
    whereToStartCopy = theHead;
    node<int>* theCopyHead = copy(whereToStartCopy);
    //ensuring each node was copied and pNext pointers were duplicated correctly.
    assertTrue(theCopyHead != theHead, __LINE__);
    assertTrue(theCopyHead->pNext != theHead->pNext, __LINE__);
    assertTrue(theCopyHead->pNext->pNext != theHead->pNext->pNext, __LINE__);
    assertTrue(theCopyHead->pNext->pNext->pNext != theHead->pNext->pNext->pNext, __LINE__);
    assertTrue(theCopyHead->pNext->pNext->pNext->pNext != theHead->pNext->pNext->pNext->pNext, __LINE__);
    assertTrue(theCopyHead->pNext->pNext->pNext->pNext->pNext != theHead->pNext->pNext->pNext->pNext->pNext, __LINE__);
    assertTrue(theCopyHead->pNext->pNext->pNext->pNext->pNext->pNext == NULL, __LINE__);
    
    //ensuring the pPrev pointers were duplicated correctly.
    assertTrue(theCopyHead->pPrev == NULL, __LINE__);
    assertTrue(theCopyHead->pNext->pPrev == theCopyHead, __LINE__);
    assertTrue(theCopyHead->pNext->pNext->pPrev == theCopyHead->pNext, __LINE__);
    assertTrue(theCopyHead->pNext->pNext->pNext->pPrev == theCopyHead->pNext->pNext, __LINE__);
    assertTrue(theCopyHead->pNext->pNext->pNext->pNext->pPrev == theCopyHead->pNext->pNext->pNext, __LINE__);
    assertTrue(theCopyHead->pNext->pNext->pNext->pNext->pPrev == theCopyHead->pNext->pNext->pNext, __LINE__);
    assertTrue(theCopyHead->pNext->pNext->pNext->pNext->pNext->pPrev == theCopyHead->pNext->pNext->pNext->pNext, __LINE__);
    
    //ensuring the data pointers were set correctly
    assertTrue(theCopyHead->data == theHead->data, __LINE__);
    assertTrue(theCopyHead->pNext->data == theHead->pNext->data, __LINE__);
    assertTrue(theCopyHead->pNext->pNext->data == theHead->pNext->pNext->data, __LINE__);
    assertTrue(theCopyHead->pNext->pNext->pNext->data == theHead->pNext->pNext->pNext->data, __LINE__);
    assertTrue(theCopyHead->pNext->pNext->pNext->pNext->data == theHead->pNext->pNext->pNext->pNext->data, __LINE__);
    assertTrue(theCopyHead->pNext->pNext->pNext->pNext->pNext->data == theHead->pNext->pNext->pNext->pNext->pNext->data, __LINE__);
    

    //Copying a subset of nodes.
    whereToStartCopy = theHead->pNext->pNext;
    theCopyHead = copy(whereToStartCopy);
    assertTrue(theCopyHead->pPrev == NULL, __LINE__);
    assertTrue(whereToStartCopy->data == theCopyHead->data, __LINE__);
    assertTrue(whereToStartCopy->pNext->data == theCopyHead->pNext->data, __LINE__);
    assertTrue(whereToStartCopy->pNext->pNext->data == theCopyHead->pNext->pNext->data, __LINE__);
    assertTrue(whereToStartCopy->pNext->pNext->data == theCopyHead->pNext->pNext->data, __LINE__);
    assertTrue(whereToStartCopy->pNext->pNext->pNext->data == theCopyHead->pNext->pNext->pNext->data, __LINE__);
    assertTrue(whereToStartCopy->pNext->pNext->pNext->pNext == NULL, __LINE__);
    
    /*
     * Testing Insert
     */
    startTestSet("Insert");
    //Reuse the list of values 5<->6<->7<->9<->9<->10.
    //Testing inserting after a NULL node in the list.
    node<int>* nullNode = NULL;
    node<int>* createdNode = NULL;
    try{
        createdNode = insert(nullNode, 5);
        assertTrue(false, __LINE__);
    } catch(const char* message)
    {
        assertTrue(strcmp(message, "Error: inserting into NULL list.") == 0, __LINE__);
    }
    
    //Testing insertion before the head node.
    createdNode = insert(theHead, 3);
    //List of values is now 3<->5<->6<->7<->9<->9<->10.
    assertTrue(createdNode->data == 3, __LINE__);
    assertTrue(createdNode->pPrev == NULL, __LINE__);
    assertTrue(createdNode->pNext == theHead, __LINE__);
    assertTrue(theHead->pPrev == createdNode, __LINE__);
    
    //Testing insertion between two existing nodes after the first.
    //reset theHead pointer
    theHead = createdNode;//theHead now has value of 3
    node<int>* nodeToBeInsertedBefore = theHead->pNext;
    createdNode = insert(theHead, 4, true);
    //List of values is now 3<->4<->5<->6<->7<->9<->9<->10.
    assertTrue(createdNode->data == 4, __LINE__);
    assertTrue(createdNode->pPrev == theHead, __LINE__);
    assertTrue(createdNode->pNext == nodeToBeInsertedBefore, __LINE__);
    assertTrue(theHead->pNext == createdNode, __LINE__);
    
    //Testing insertion at the end of the list
    node<int>* lastNode = theHead->pNext->pNext->pNext->pNext->pNext->pNext->pNext;
    createdNode = insert(lastNode, 12, true);
    //List of values is now 3<->4<->5<->6<->7<->9<->9<->10<->12.
    assertTrue(createdNode->data == 12, __LINE__);
    assertTrue(createdNode->pPrev == lastNode, __LINE__);
    assertTrue(createdNode->pNext == NULL, __LINE__);
    assertTrue(lastNode->pNext == createdNode, __LINE__);
    
    //testing insertion between two existing nodes before the second.
    
    //reset lastNode
    lastNode = createdNode;
    node<int>* nodeToBeInsertedAfter = lastNode->pPrev;
    createdNode = insert(lastNode, 11);
    //List of values is now 3<->4<->5<->6<->7<->9<->9<->10<->11<->12.
    assertTrue(createdNode->data == 11, __LINE__);
    assertTrue(createdNode->pPrev == nodeToBeInsertedAfter, __LINE__);
    assertTrue(createdNode->pNext == lastNode, __LINE__);
    assertTrue(lastNode->pPrev == createdNode, __LINE__);
    
    /*
     * Testing Find
     */
    startTestSet("Find");
    //New list of values 5<->6<->7<->5.
    node<int>* findHead = new node<int>(5);
    currentNodePtr = findHead;
    aNode = new node<int>(6);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(7);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(5);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    
    
    //Testing searching NULL list
    node<int>* foundNode = find(nullNode, 5);
    assertTrue(foundNode == NULL, __LINE__);
    
    //Testing searching entire list without requested value
    foundNode = find(findHead,10);
    assertTrue(foundNode == NULL, __LINE__);
    
    //Testing searching sub-list without requested value
    foundNode = find(findHead->pNext,10);
    assertTrue(foundNode == NULL, __LINE__);
    
    //Testing searching full list with requested value
    foundNode = find(findHead,7);
    assertTrue(foundNode == findHead->pNext->pNext, __LINE__);
    
    //Testing searching partial list with requested value
    foundNode = find(findHead->pNext,7);
    assertTrue(foundNode == findHead->pNext->pNext, __LINE__);
    
    //Testing searching full list for first duplicate value
    foundNode = find(findHead,5);
    assertTrue(foundNode == findHead, __LINE__);
    
    
    //Testing searching sub list where sublist starts with last node
    foundNode = find(findHead->pNext->pNext->pNext,7);
    assertTrue(foundNode == NULL, __LINE__);
    
    /*
     * Testing clear
     */
    startTestSet("Clear");
    unit_testing_delete_call_counter = 0;
    //Testing freeing NULL list
    try{
        clear(nullNode);
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: freeing NULL list.") == 0, __LINE__);
        //this int variable is declared in the unit_testing_delete.h file. You should NEVER touch any code in that file.
        assertTrue(unit_testing_delete_call_counter == 0, __LINE__);
    }
    //Testing freeing list consisting of a single node.
    node<int>* singleNode = new node<int>(3);
    clear(singleNode);
    assertTrue(singleNode == NULL,__LINE__);//If you don't reset the pointer to the node passed in to your code in your code, you have a zombie pointer. Nasty things, zombie pointers.
    assertTrue(unit_testing_delete_call_counter == 1, __LINE__);
    
    
    //Resetting unit_testing_delete_call_counter
    unit_testing_delete_call_counter = 0;
    //Reusing findHead list with values 5<->6<->7<->5.
    //testing freeing a sublist
    clear(findHead->pNext->pNext);
    assertTrue(findHead->pNext->pNext == NULL, __LINE__);
    assertTrue(unit_testing_delete_call_counter == 2, __LINE__);
    
    //testing freeing an entire list
    //Resetting unit_testing_delete_call_counter
    unit_testing_delete_call_counter = 0;
    //theHead list is currently 3<->4<->5<->6<->7<->9<->9<->10<->11<->12
    clear(theHead);
    assertTrue(theHead == NULL, __LINE__);
    assertTrue(unit_testing_delete_call_counter == 10, __LINE__);
    
    /*
     * Testing Remove
     */
    startTestSet("Remove");
    //Resetting unit_testing_delete_call_counter
    unit_testing_delete_call_counter = 0;
    
    //Building list
    node<int>* removeHead = new node<int>(5);
    currentNodePtr = removeHead;
    aNode = new node<int>(6);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(7);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(5);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(13);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    
    //testing remove NULL node
    
    node<int>* nodeBefore = remove(nullNode);
    assertTrue(nodeBefore == NULL, __LINE__);
    assertTrue(unit_testing_delete_call_counter == 0, __LINE__);
    
    //testing remove malformed node
    node<int>* malformedNode = new node<int>(5);
    malformedNode->pNext = NULL;
    malformedNode->pPrev = NULL;
    nodeBefore = remove(malformedNode);
    assertTrue(malformedNode == NULL, __LINE__);
    assertTrue(nodeBefore == NULL, __LINE__);
    assertTrue(unit_testing_delete_call_counter == 1, __LINE__);
    
    
    //testing remove middle node
    //list is currently 5<->6<->7<->5<->13.
    unit_testing_delete_call_counter = 0;
    node<int>* nodeToRemove = removeHead->pNext->pNext;
    node<int>* nodeAfterToRemove = nodeToRemove->pNext;
    nodeBefore = remove(nodeToRemove);
    //list is now 5<->6<->5<->13.
    assertTrue(nodeToRemove == NULL, __LINE__);
    assertTrue(nodeBefore->pNext == nodeAfterToRemove, __LINE__);
    assertTrue(nodeAfterToRemove->pPrev == nodeBefore, __LINE__);
    assertTrue(unit_testing_delete_call_counter == 1, __LINE__);
    
    //testing removing headNode
    unit_testing_delete_call_counter = 0;
    nodeToRemove = removeHead;
    node<int>* secondNode = removeHead->pNext;
    node<int>* currentFirstNode = remove(removeHead);
    //list is now 6<->5<->13.
    assertTrue(currentFirstNode == secondNode, __LINE__);
    assertTrue(removeHead == NULL, __LINE__);
    assertTrue(unit_testing_delete_call_counter == 1, __LINE__);
    
    //testing removing lastNode
    //resetting removeHead
    unit_testing_delete_call_counter = 0;
    removeHead = currentFirstNode;
    nodeToRemove = removeHead->pNext->pNext;
    nodeBefore = remove(nodeToRemove);
    assertTrue(nodeBefore == removeHead->pNext, __LINE__);
    assertTrue(nodeToRemove == NULL, __LINE__);
    assertTrue(unit_testing_delete_call_counter == 1, __LINE__);
    
    /*
     * Testing insert for Non-Integer set Behavior (Just to Make Sure set Works For Other Types)
     */
    startTestSet("Can Hold Strings");
    node<std::string>* stringNode = new node<std::string>("Hello");
    std::string greeting = "Hello";
    
    assertTrue(stringNode->data.compare(greeting) == 0, __LINE__);
    assertTrue(stringNode->pNext == NULL, __LINE__);
    assertTrue(stringNode->pPrev == NULL, __LINE__);
    
    generateTestingReport();
    return 0;
}
