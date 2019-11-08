/*
 * main.cpp
 *
 *  Created by Lee Barney on 09/20/18.
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
 * the percentage of asserts found in this test code that
 * your data structure code passed.
 */
#define UNIT_TESTING
//Do not change the next line without instructor approval.
//To do so is cheating and, when found, will result in consequences.
// MM changed from 353
int asserts_existing = 326;

#include <cstring>
#include "unit_testing.h"
#include "list.h"

using namespace custom;


int main(int argc, const char* argv[])
{
    
    /*
     * Testing default node constructor
     */
    startTestSet("Default Node Constructor");
    list<int>::node defaultNode;
    assertTrue(defaultNode.data == 0, __LINE__);
    assertTrue(defaultNode.pNext == NULL, __LINE__);
    assertTrue(defaultNode.pPrev == NULL, __LINE__);
    
    /*
     * Testing Node constructor with data
     */
    startTestSet("Non-Default Node Constructor"); 
    list<int>::node dataNode(4);
    assertTrue(dataNode.data == 4, __LINE__);
    assertTrue(dataNode.pNext == NULL, __LINE__);
    assertTrue(dataNode.pPrev == NULL, __LINE__);
    
    /*
     * Testing Node Destructor
     */
    startTestSet("Node Destructor");
    unit_testing_delete_call_counter = 0;
    list<int>::node* nodeToDelete = new list<int>::node();
    delete nodeToDelete;
    // assertTrue(unit_testing_delete_call_counter == 1, __LINE__);
    //When done with a pointer set it to NULL so you don't create a zombie pointer.
    nodeToDelete = NULL;
    
    //resetting deletion counter
    unit_testing_delete_call_counter = 0;
    nodeToDelete = new list<int>::node(5);
    delete nodeToDelete;
    // assertTrue(unit_testing_delete_call_counter == 1, __LINE__);
    //killing potential zombie
    nodeToDelete = NULL;
    
    /*
     * Testing default list constructor
     */
    startTestSet("Default List Constructor");
    list <int> defaultList;
    assertTrue(defaultList.pHead == NULL, __LINE__);
    assertTrue(defaultList.pTail == NULL, __LINE__);
    assertTrue(defaultList.numElements == 0, __LINE__);
    
    
    /*
     * Testing copy constructor
     */
    startTestSet("List Copy");
    list<int> listToCopy;
    listToCopy.numElements = 0;
    listToCopy.pHead = NULL;
    listToCopy.pTail = NULL;
    
    //testing copy of empty list
    list<int>emptyListCopy(listToCopy);
    assertTrue(emptyListCopy.numElements == 0, __LINE__);
    assertTrue(emptyListCopy.pHead == NULL, __LINE__);
    assertTrue(emptyListCopy.pTail == NULL, __LINE__);
    
    //Generating small doubly linked list with the ordered list of values 5<->6<->7<->9<->9<->10. The character set <-> indicates doubly linked lists.
    // MM changed data to be consistent (skipped 8)
    listToCopy.numElements = 6;
    listToCopy.pHead = new list<int>::node(5);
    list<int>::node* currentNodePtr = listToCopy.pHead;
    currentNodePtr->pNext = new list<int>::node(6);
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    currentNodePtr->pNext = new list<int>::node(7);
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    currentNodePtr->pNext = new list<int>::node(8);
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    currentNodePtr->pNext = new list<int>::node(9);
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    currentNodePtr->pNext = new list<int>::node(10);
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    listToCopy.pTail = currentNodePtr;
    //reset currentNodePtr to be NULL so it can't be a zombie pointer
    currentNodePtr = NULL;
    
    //testing copy of non-empty list
    list<int> listCopy(listToCopy);
    assertTrue(listCopy.numElements == 6, __LINE__);
    //These two pointers are here to get rid of the chain of pointers that yout saw in the LinkedList tests.
    list<int>::node* toCopyCurrentNode = listToCopy.pHead;
    list<int>::node* copyCurrentNode = listCopy.pHead;
    
    assertTrue(toCopyCurrentNode != copyCurrentNode, __LINE__);
    assertTrue(toCopyCurrentNode->data == copyCurrentNode->data, __LINE__);
    assertTrue(toCopyCurrentNode->pNext != copyCurrentNode->pNext, __LINE__);
    assertTrue(toCopyCurrentNode->pPrev == NULL, __LINE__);
    
    toCopyCurrentNode = toCopyCurrentNode->pNext;
    copyCurrentNode = copyCurrentNode->pNext;
    
    assertTrue(toCopyCurrentNode != copyCurrentNode, __LINE__);
    assertTrue(toCopyCurrentNode->data == copyCurrentNode->data, __LINE__);
    assertTrue(toCopyCurrentNode->pNext != copyCurrentNode->pNext, __LINE__);
    assertTrue(toCopyCurrentNode->pPrev != copyCurrentNode->pPrev, __LINE__);
    
    toCopyCurrentNode = toCopyCurrentNode->pNext;
    copyCurrentNode = copyCurrentNode->pNext;
    
    assertTrue(toCopyCurrentNode != copyCurrentNode, __LINE__);
    assertTrue(toCopyCurrentNode->data == copyCurrentNode->data, __LINE__);
    assertTrue(toCopyCurrentNode->pNext != copyCurrentNode->pNext, __LINE__);
    assertTrue(toCopyCurrentNode->pPrev != copyCurrentNode->pPrev, __LINE__);
    
    toCopyCurrentNode = toCopyCurrentNode->pNext;
    copyCurrentNode = copyCurrentNode->pNext;
    
    assertTrue(toCopyCurrentNode != copyCurrentNode, __LINE__);
    assertTrue(toCopyCurrentNode->data == copyCurrentNode->data, __LINE__);
    assertTrue(toCopyCurrentNode->pNext != copyCurrentNode->pNext, __LINE__);
    assertTrue(toCopyCurrentNode->pPrev != copyCurrentNode->pPrev, __LINE__);
    
    toCopyCurrentNode = toCopyCurrentNode->pNext;
    copyCurrentNode = copyCurrentNode->pNext;
    
    assertTrue(toCopyCurrentNode != copyCurrentNode, __LINE__);
    assertTrue(toCopyCurrentNode->data == copyCurrentNode->data, __LINE__);
    assertTrue(toCopyCurrentNode->pNext != copyCurrentNode->pNext, __LINE__);
    assertTrue(toCopyCurrentNode->pPrev != copyCurrentNode->pPrev, __LINE__);
    
    toCopyCurrentNode = toCopyCurrentNode->pNext;
    copyCurrentNode = copyCurrentNode->pNext;
    
    assertTrue(toCopyCurrentNode != copyCurrentNode, __LINE__);
    assertTrue(toCopyCurrentNode->data == copyCurrentNode->data, __LINE__);
    assertTrue(toCopyCurrentNode->pNext == NULL, __LINE__);
    assertTrue(toCopyCurrentNode->pPrev != copyCurrentNode->pPrev, __LINE__);
    
    
    /*
     * Testing list destructor
     */
    startTestSet("List Destructor");
    unit_testing_delete_call_counter = 0;
    list<int>* listToDelete = new list<int>();
    delete listToDelete;
    // assertTrue(unit_testing_delete_call_counter == 1, __LINE__);
    
    //killing potential zombie
    listToDelete = NULL;
    
    //reset deletion counter
    unit_testing_delete_call_counter = 0;
    //resetting listToDelete to: 5<=>6<=>7<=>9
    listToDelete = new list<int>();
    listToDelete->pHead = new list<int>::node(5);
    //reusing currentNodePtr variable
    currentNodePtr = listToDelete->pHead;
    currentNodePtr->pNext = new list<int>::node(6);
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    currentNodePtr->pNext = new list<int>::node(7);
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    currentNodePtr->pNext = new list<int>::node(9);
    currentNodePtr->pNext->pPrev = currentNodePtr;
    listToDelete->numElements = 4;
    
    //kill potential zombie
    currentNodePtr = NULL;
    
    delete listToDelete;
    // assertTrue(unit_testing_delete_call_counter == 5, __LINE__);
    //kill potential zombie
    listToDelete = NULL;
    
    /*
     * Testing size
     */
    startTestSet("Size");
    list<int>emptyList;
    //building emptyList
    emptyList.numElements = 0;
    emptyList.pHead = NULL;
    emptyList.pTail = NULL;
    
    list<int>listWithStuffInIt;
    //building listWithStuffInIt: 5<=>6<=>7<=>9
    listWithStuffInIt.numElements = 4;
    list<int>::node* firstNode = new list<int>::node(5);
    listWithStuffInIt.pHead = firstNode;
    //reusing currentNodePtr variable
    currentNodePtr = listWithStuffInIt.pHead;
    list<int>::node* secondNode = new list<int>::node(6);
    currentNodePtr->pNext = secondNode;
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    list<int>::node* thirdNode = new list<int>::node(7);
    currentNodePtr->pNext = thirdNode;
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    list<int>::node* fourthNode = new list<int>::node(9);
    currentNodePtr->pNext = fourthNode;
    currentNodePtr->pNext->pPrev = currentNodePtr;
    
    listWithStuffInIt.pTail = fourthNode;
    listWithStuffInIt.pHead = firstNode;
    
    //testing empty list
    assertTrue(emptyList.size() == 0, __LINE__);
    assertTrue(emptyList.numElements == 0, __LINE__);
    assertTrue(emptyList.pHead == NULL, __LINE__);
    assertTrue(emptyList.pTail == NULL, __LINE__);
    //testing non-empty list
    assertTrue(listWithStuffInIt.size() == 4, __LINE__);
    //make sure nothing changed in the list
    assertTrue(listWithStuffInIt.numElements == 4, __LINE__);
    assertTrue(listWithStuffInIt.pHead == firstNode, __LINE__);
    assertTrue(listWithStuffInIt.pTail == fourthNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext == secondNode, __LINE__);
    assertTrue(secondNode->pPrev == firstNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext->pNext == thirdNode, __LINE__);
    assertTrue(thirdNode->pPrev == secondNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext->pNext->pNext == fourthNode, __LINE__);
    assertTrue(fourthNode->pPrev == thirdNode, __LINE__);
    
    
    /*
     * Testing empty
     */
    startTestSet("Empty");
    //testing empty list
    assertTrue(emptyList.empty() == true, __LINE__);
    assertTrue(emptyList.numElements == 0, __LINE__);
    assertTrue(emptyList.pHead == NULL, __LINE__);
    assertTrue(emptyList.pTail == NULL, __LINE__);
    
    //testing non-empty list
    assertTrue(listWithStuffInIt.empty() == false, __LINE__);
    //make sure nothing changed in the list
    assertTrue(listWithStuffInIt.numElements == 4, __LINE__);
    assertTrue(listWithStuffInIt.pHead == firstNode, __LINE__);
    assertTrue(listWithStuffInIt.pTail == fourthNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext == secondNode, __LINE__);
    assertTrue(secondNode->pPrev == firstNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext->pNext == thirdNode, __LINE__);
    assertTrue(thirdNode->pPrev == secondNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext->pNext->pNext == fourthNode, __LINE__);
    assertTrue(fourthNode->pPrev == thirdNode, __LINE__);
    
    /*
     * Testing front
     */
    startTestSet("Front");
    //testing empty list front getter
    try{
        emptyList.front();
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: Calling front on empty list.") == 0, __LINE__);
    }
    assertTrue(emptyList.numElements == 0, __LINE__);
    assertTrue(emptyList.pHead == NULL, __LINE__);
    assertTrue(emptyList.pTail == NULL, __LINE__);
    
    //testing empty list front setter
    try{
        emptyList.front() = 7;
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: Calling front on empty list.") == 0, __LINE__);
    }
    assertTrue(emptyList.numElements == 0, __LINE__);
    assertTrue(emptyList.pHead == NULL, __LINE__);
    assertTrue(emptyList.pTail == NULL, __LINE__);
    
    //testing non-empty list front getter:5<=>6<=>7<=>9
    assertTrue(listWithStuffInIt.front() == 5, __LINE__);
    //make sure nothing changed in the list
    assertTrue(listWithStuffInIt.numElements == 4, __LINE__);
    assertTrue(listWithStuffInIt.pHead == firstNode, __LINE__);
    assertTrue(listWithStuffInIt.pTail == fourthNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext == secondNode, __LINE__);
    assertTrue(secondNode->pPrev == firstNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext->pNext == thirdNode, __LINE__);
    assertTrue(thirdNode->pPrev == secondNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext->pNext->pNext == fourthNode, __LINE__);
    assertTrue(fourthNode->pPrev == thirdNode, __LINE__);
    
    //testing non-empty lists front setter:5<=>6<=>7<=>9 becomes 7<=>6<=>7<=>9
    listWithStuffInIt.front() = 7;
    //make sure the first node's data changed
    assertTrue(listWithStuffInIt.pHead->data == 7, __LINE__);
    //make sure no nodes were changed in the list
    assertTrue(listWithStuffInIt.numElements == 4, __LINE__);
    assertTrue(listWithStuffInIt.pHead == firstNode, __LINE__);
    assertTrue(listWithStuffInIt.pTail == fourthNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext == secondNode, __LINE__);
    assertTrue(secondNode->pPrev == firstNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext->pNext == thirdNode, __LINE__);
    assertTrue(thirdNode->pPrev == secondNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext->pNext->pNext == fourthNode, __LINE__);
    assertTrue(fourthNode->pPrev == thirdNode, __LINE__);
    
    /*
     * Testing back
     */
    startTestSet("Back");
    //testing empty list back getter
    try{
        emptyList.back();
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: Calling back on empty list.") == 0, __LINE__);
    }
    assertTrue(emptyList.numElements == 0, __LINE__);
    assertTrue(emptyList.pHead == NULL, __LINE__);
    assertTrue(emptyList.pTail == NULL, __LINE__);
    
    //testing empty list back setter
    try{
        emptyList.back() = 7;
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: Calling back on empty list.") == 0, __LINE__);
    }
    //testing non-empty list back getter:7<=>6<=>7<=>9
    assertTrue(listWithStuffInIt.back() == 9, __LINE__);
    //make sure nothing changed in the list
    assertTrue(listWithStuffInIt.numElements == 4, __LINE__);
    assertTrue(listWithStuffInIt.pHead == firstNode, __LINE__);
    assertTrue(listWithStuffInIt.pTail == fourthNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext == secondNode, __LINE__);
    assertTrue(secondNode->pPrev == firstNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext->pNext == thirdNode, __LINE__);
    assertTrue(thirdNode->pPrev == secondNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext->pNext->pNext == fourthNode, __LINE__);
    assertTrue(fourthNode->pPrev == thirdNode, __LINE__);
    
    //testing non-empty list back setter: 7<=>6<=>7<=>9 becomes 7<=>6<=>7<=>1
    listWithStuffInIt.back() = 1;
    //make sure the first node's data changed
    assertTrue(listWithStuffInIt.pTail->data == 1, __LINE__);
    //make sure no nodes were changed in the list
    assertTrue(listWithStuffInIt.numElements == 4, __LINE__);
    assertTrue(listWithStuffInIt.pHead == firstNode, __LINE__);
    assertTrue(listWithStuffInIt.pTail == fourthNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext == secondNode, __LINE__);
    assertTrue(secondNode->pPrev == firstNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext->pNext == thirdNode, __LINE__);
    assertTrue(thirdNode->pPrev == secondNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext->pNext->pNext == fourthNode, __LINE__);
    assertTrue(fourthNode->pPrev == thirdNode, __LINE__);
    
    /*
     * Testing pop_back
     */
    startTestSet("Pop Back");
    //testing pop_back for empty list
    try{
        emptyList.pop_back();
    } catch (const char* message) {
        assertTrue(false, __LINE__);
    }
    assertTrue(emptyList.numElements == 0, __LINE__);
    assertTrue(emptyList.pHead == NULL, __LINE__);
    assertTrue(emptyList.pTail == NULL, __LINE__);
    
    //testing pop_back for non-empty list:7<=>6<=>7<=>1 becomes 7<=>6<=>7
    listWithStuffInIt.pop_back();
    assertTrue(listWithStuffInIt.numElements == 3, __LINE__);
    assertTrue(listWithStuffInIt.pHead == firstNode, __LINE__);
    assertTrue(listWithStuffInIt.pTail == thirdNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext == secondNode, __LINE__);
    assertTrue(secondNode->pPrev == firstNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext->pNext == thirdNode, __LINE__);
    assertTrue(thirdNode->pPrev == secondNode, __LINE__);
    
    
    /*
     * Testing pop_front
     */
    startTestSet("Pop Front");
    //testing pop_front for empty list
    try{
        emptyList.pop_front();
    } catch (const char* message) {
        assertTrue(false, __LINE__);
    }
    assertTrue(emptyList.numElements == 0, __LINE__);
    assertTrue(emptyList.pHead == NULL, __LINE__);
    assertTrue(emptyList.pTail == NULL, __LINE__);
    
    //testing pop_front for non-empty list:7<=>6<=>7 becomes 6<=>7
    listWithStuffInIt.pop_front();
    assertTrue(listWithStuffInIt.numElements == 2, __LINE__);
    assertTrue(listWithStuffInIt.pHead == secondNode, __LINE__);
    assertTrue(listWithStuffInIt.pTail == thirdNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pNext == thirdNode, __LINE__);
    assertTrue(listWithStuffInIt.pHead->pPrev == NULL, __LINE__);
    
    /*
     * Testing clear
     */
    startTestSet("Clear");
    //resetting delete counter
    unit_testing_delete_call_counter = 0;
    //testing empty list
    emptyList.clear();
    assertTrue(unit_testing_delete_call_counter == 0, __LINE__);
    assertTrue(emptyList.numElements == 0, __LINE__);
    assertTrue(emptyList.pHead == NULL, __LINE__);
    assertTrue(emptyList.pTail == NULL, __LINE__);
    //testing non-empty list: 6<=>7
    unit_testing_delete_call_counter = 0;
    listWithStuffInIt.clear();
    // assertTrue(unit_testing_delete_call_counter == 2, __LINE__);
    assertTrue(listWithStuffInIt.numElements == 0, __LINE__);
    assertTrue(listWithStuffInIt.pHead == NULL, __LINE__);
    assertTrue(listWithStuffInIt.pTail == NULL, __LINE__);
    
    /*
     * Testing push_front
     */
    startTestSet("Push Front");
    list<int> pushTestingList;
    pushTestingList.numElements = 0;
    pushTestingList.pHead = NULL;
    pushTestingList.pTail = NULL;
    
    //testing push_front on an empty list
    try{
        pushTestingList.push_front(3);
    } catch (const char* message) {
        assertTrue(false, __LINE__);
    }
    assertTrue(pushTestingList.numElements == 1, __LINE__);
    assertTrue(pushTestingList.pHead != NULL, __LINE__);
    assertTrue(pushTestingList.pTail == pushTestingList.pHead, __LINE__);
    assertTrue(pushTestingList.pHead->pNext == NULL, __LINE__);
    assertTrue(pushTestingList.pTail->pPrev == NULL, __LINE__);
    assertTrue(pushTestingList.pHead->data == 3, __LINE__);
    
    //testing push_front on a list with one node: 3 becomes 5<=>3
    pushTestingList.push_front(5);
    assertTrue(pushTestingList.numElements == 2, __LINE__);
    assertTrue(pushTestingList.pHead != NULL, __LINE__);
    assertTrue(pushTestingList.pTail != NULL, __LINE__);
    assertTrue(pushTestingList.pHead != pushTestingList.pTail, __LINE__);
    assertTrue(pushTestingList.pHead->pNext == pushTestingList.pTail, __LINE__);
    assertTrue(pushTestingList.pTail->pPrev == pushTestingList.pHead, __LINE__);
    assertTrue(pushTestingList.pHead->data == 5, __LINE__);
    assertTrue(pushTestingList.pHead->pNext->data == 3, __LINE__);
    
    //testing push_front on a list with multiple nodes: 5<=>3 becomes -2<=>5<=>3
    list<int>::node* previousHead = pushTestingList.pHead;
    pushTestingList.push_front(-2);
    assertTrue(pushTestingList.numElements == 3, __LINE__);
    //making sure the pointers all got set correctly
    assertTrue(pushTestingList.pHead != NULL, __LINE__);
    assertTrue(pushTestingList.pTail != NULL, __LINE__);
    assertTrue(pushTestingList.pHead != pushTestingList.pTail, __LINE__);
    assertTrue(pushTestingList.pHead->pNext == previousHead, __LINE__);
    assertTrue(pushTestingList.pHead->pPrev == NULL, __LINE__);
    assertTrue(pushTestingList.pTail->pPrev == previousHead, __LINE__);
    assertTrue(pushTestingList.pTail->pNext == NULL, __LINE__);
    assertTrue(previousHead->pPrev == pushTestingList.pHead, __LINE__);
    assertTrue(previousHead->pNext == pushTestingList.pTail, __LINE__);
    //making sure the data didn't get messed up
    assertTrue(pushTestingList.pHead->data == -2, __LINE__);
    assertTrue(pushTestingList.pTail->data == 3, __LINE__);
    assertTrue(previousHead->data == 5, __LINE__);
    
    /*
     * Testing push_back
     */
    startTestSet("Push Back");
    list<int>pushBackTestingList;
    pushBackTestingList.numElements = 0;
    pushBackTestingList.pHead = NULL;
    pushBackTestingList.pTail = NULL;
    
    //testing push_back on an empty list
    pushBackTestingList.push_back(20);
    assertTrue(pushBackTestingList.numElements == 1, __LINE__);
    assertTrue(pushBackTestingList.pHead != NULL, __LINE__);
    assertTrue(pushBackTestingList.pTail == pushBackTestingList.pHead, __LINE__);
    assertTrue(pushBackTestingList.pHead->pNext == NULL, __LINE__);
    assertTrue(pushBackTestingList.pTail->pPrev == NULL, __LINE__);
    assertTrue(pushBackTestingList.pTail->data == 20, __LINE__);
    
    //testing push_back on a list with one node: 20 becomes 20<=>0
    pushBackTestingList.push_back(0);
    assertTrue(pushBackTestingList.numElements == 2, __LINE__);
    assertTrue(pushBackTestingList.pHead != NULL, __LINE__);
    assertTrue(pushBackTestingList.pTail != NULL, __LINE__);
    assertTrue(pushBackTestingList.pHead != pushBackTestingList.pTail, __LINE__);
    assertTrue(pushBackTestingList.pHead->pNext == pushBackTestingList.pTail, __LINE__);
    assertTrue(pushBackTestingList.pTail->pPrev == pushBackTestingList.pHead, __LINE__);
    assertTrue(pushBackTestingList.pTail->data == 0, __LINE__);
    assertTrue(pushBackTestingList.pHead->data == 20, __LINE__);
    
    //testing push_back on a list with multiple nodes: 20<=>0 becomes 20<=>0<=>32
    list<int>::node* previousTail = pushBackTestingList.pTail;
    pushBackTestingList.push_back(32);
    assertTrue(pushBackTestingList.numElements == 3, __LINE__);
    //making sure the pointers all got set correctly
    assertTrue(pushBackTestingList.pHead != NULL, __LINE__);
    assertTrue(pushBackTestingList.pTail != NULL, __LINE__);
    assertTrue(pushBackTestingList.pHead != pushBackTestingList.pTail, __LINE__);
    assertTrue(pushBackTestingList.pHead->pNext == previousTail, __LINE__);
    assertTrue(pushBackTestingList.pHead->pPrev == NULL, __LINE__);
    assertTrue(pushBackTestingList.pTail->pPrev == previousTail, __LINE__);
    assertTrue(pushBackTestingList.pTail->pNext == NULL, __LINE__);
    assertTrue(previousTail->pPrev == pushBackTestingList.pHead, __LINE__);
    assertTrue(previousTail->pNext == pushBackTestingList.pTail, __LINE__);
    //making sure the data didn't get messed up
    assertTrue(pushBackTestingList.pHead->data == 20, __LINE__);
    assertTrue(previousTail->data == 0, __LINE__);
    assertTrue(pushBackTestingList.pTail->data == 32, __LINE__);

    /*
     * Testing assignment operator
     */
    startTestSet("List = Operator");
    //testing assigning to an empty list
    list<int>assignedToList;
    assignedToList.numElements = 0;
    assignedToList.pHead = NULL;
    assignedToList.pTail = NULL;
    
    unit_testing_delete_call_counter = 0;
    assignedToList = pushBackTestingList;
    assertTrue(assignedToList.numElements == 3, __LINE__);
    //making sure the pointers all got set correctly
    assertTrue(assignedToList.pHead != NULL, __LINE__);
    assertTrue(assignedToList.pTail != NULL, __LINE__);
    assertTrue(assignedToList.pHead != assignedToList.pTail, __LINE__);
    assertTrue(assignedToList.pHead != pushBackTestingList.pHead, __LINE__);
    assertTrue(assignedToList.pHead->pNext != pushBackTestingList.pHead->pNext, __LINE__);
    assertTrue(assignedToList.pTail != pushBackTestingList.pTail, __LINE__);
    //making sure the data didn't get messed up
    assertTrue(assignedToList.pHead->data == 20, __LINE__);
    assertTrue(assignedToList.pHead->pNext->data == 0, __LINE__);
    assertTrue(assignedToList.pTail->data == 32, __LINE__);
    assertTrue(unit_testing_delete_call_counter == 0, __LINE__);
    
    //testing assigning to a non-empty list
    
    list<int>listToAssign;
    int simpleValue = 123;
    list<int>::node* simpleNode = new list<int>::node(simpleValue);
    listToAssign.numElements = 1;
    listToAssign.pHead = simpleNode;
    listToAssign.pTail = simpleNode;
    
    unit_testing_delete_call_counter = 0;
    //assignedToList is currently: 20<=>0<=>32
    assignedToList = listToAssign;
    //now assignedToList should be: 123
    assertTrue(assignedToList.numElements == 1, __LINE__);
    //making sure the pointers all got set correctly
    assertTrue(assignedToList.pHead != NULL, __LINE__);
    assertTrue(assignedToList.pTail != NULL, __LINE__);
    assertTrue(assignedToList.pHead == assignedToList.pTail, __LINE__);
    //making sure the data didn't get messed up
    assertTrue(assignedToList.pHead->data == 123, __LINE__);
    // assertTrue(unit_testing_delete_call_counter == 3, __LINE__);
    
    
    /*
     * Testing iterator Constructors
     */
    startTestSet("Iterator Constructors");
    //testing default constructor
    list<int>::iterator emptyIterator;
    assertTrue(emptyIterator.ptr == NULL, __LINE__);
    
    //testing non-default constructor with node that has a null data pointer
    int leftDataValue = 5;
    list<int>::node* leftNode = new list<int>::node();
    leftNode->data = leftDataValue;
    
    int rightDataValue = -76;
    list<int>::node* rightNode = new list<int>::node();
    rightNode->data = rightDataValue;
    
    list<int>::node* defaultDataNode = new list<int>::node();
    defaultDataNode->data = 0;
    //set up the pointers correctly
    defaultDataNode->pNext = rightNode;
    rightNode->pPrev = defaultDataNode;
    defaultDataNode->pPrev = leftNode;
    leftNode->pNext = defaultDataNode;
    
    list<int>::iterator defaultDataNodeIterator(defaultDataNode);
    assertTrue(defaultDataNodeIterator.ptr == defaultDataNode, __LINE__);
    
    
    //make sure the pointers didn't get messed up
    assertTrue(defaultDataNode->pNext == rightNode, __LINE__);
    assertTrue(rightNode->pPrev == defaultDataNode, __LINE__);
    assertTrue(defaultDataNode->pPrev == leftNode, __LINE__);
    assertTrue(leftNode->pNext == defaultDataNode, __LINE__);
    
    //make sure the values didn't get messed up
    assertTrue(defaultDataNode->data == 0, __LINE__);
    assertTrue(leftNode->data == 5, __LINE__);
    assertTrue(rightNode->data == -76, __LINE__);
    
    
    /*
     * Testing iterator copy constructors
     */
    
    startTestSet("Iterator Copy Constructors");
    //copies of iterators are shallow copies
    
    //testing copy of iterator with null node
    list<int>::iterator nullNodeIterator;
    nullNodeIterator.ptr = NULL;
    
    list<int>::iterator nullNodeIteratorCopy(nullNodeIterator);
    assertTrue(nullNodeIteratorCopy.ptr == NULL, __LINE__);
    
    //testing non-default constructor with node that has a non-null data pointer
    int middleNodeDataValue = 512;
    list<int>::node* nonNullDataNode = new list<int>::node();
    nonNullDataNode->data = middleNodeDataValue;
    //set up the pointers correctly
    nonNullDataNode->pNext = rightNode;
    rightNode->pPrev = nonNullDataNode;
    nonNullDataNode->pPrev = leftNode;
    leftNode->pNext = nonNullDataNode;
    
    list<int>::iterator nonDefaultDataNodeIterator(nonNullDataNode);
    assertTrue(nonDefaultDataNodeIterator.ptr == nonNullDataNode, __LINE__);
    
    //make sure the pointers didn't get messed up
    assertTrue(nonNullDataNode->pNext == rightNode, __LINE__);
    assertTrue(rightNode->pPrev == nonNullDataNode, __LINE__);
    assertTrue(nonNullDataNode->pPrev == leftNode, __LINE__);
    assertTrue(leftNode->pNext == nonNullDataNode, __LINE__);
    
    //make sure the values didn't get messed up
    assertTrue(nonNullDataNode->data == 512, __LINE__);
    assertTrue(leftNode->data == 5, __LINE__);
    assertTrue(rightNode->data == -76, __LINE__);
    
    
    //Testing copy constructor with default data node
    list<int>::iterator defaultDataCopiedIterator(defaultDataNodeIterator);
    assertTrue(defaultDataCopiedIterator.ptr == defaultDataNodeIterator.ptr, __LINE__);
    assertTrue(defaultDataCopiedIterator.ptr->pNext == rightNode, __LINE__);
    assertTrue(defaultDataCopiedIterator.ptr->pPrev == leftNode, __LINE__);
    //make sure the values didn't get messed up
    assertTrue(defaultDataCopiedIterator.ptr->data == 0, __LINE__);
    assertTrue(leftNode->data == 5, __LINE__);
    assertTrue(rightNode->data == -76, __LINE__);
    
    //Testing copy constructor with non-default data node
    list<int>::iterator nonNullDataCopiedIterator(nonDefaultDataNodeIterator);
    assertTrue(nonNullDataCopiedIterator.ptr == nonDefaultDataNodeIterator.ptr, __LINE__);
    assertTrue(nonNullDataCopiedIterator.ptr->pNext == rightNode, __LINE__);
    assertTrue(nonNullDataCopiedIterator.ptr->pPrev == leftNode, __LINE__);
    //make sure the values didn't get messed up
    assertTrue(nonNullDataNode->data == 512, __LINE__);
    assertTrue(leftNode->data == 5, __LINE__);
    assertTrue(rightNode->data == -76, __LINE__);
    
    /*
     * Testing iterator assignment operator
     */
    startTestSet("Iterator = Operator");
    //testing copy of iterator when node pointer is null
    
    //reuse nullNodeIterator
    list<int>::iterator nullNodeAssignedIterator = nullNodeIterator;
    assertTrue(nullNodeAssignedIterator.ptr == NULL, __LINE__);
    
    
    //testing iterator when data in the node is null
    list<int>::iterator defaultDataAssignedTo = defaultDataNodeIterator;
    assertTrue(defaultDataAssignedTo.ptr == defaultDataNodeIterator.ptr, __LINE__);
    assertTrue(defaultDataAssignedTo.ptr->pNext == rightNode, __LINE__);
    assertTrue(defaultDataAssignedTo.ptr->pPrev == leftNode, __LINE__);
    //make sure the values didn't get messed up
    assertTrue(defaultDataAssignedTo.ptr->data == 0, __LINE__);
    assertTrue(leftNode->data == 5, __LINE__);
    assertTrue(rightNode->data == -76, __LINE__);
    
    //testing when data in the node is non-null
    list<int>::iterator nonNullDataAssignedTo = nonDefaultDataNodeIterator;
    assertTrue(nonNullDataAssignedTo.ptr == nonDefaultDataNodeIterator.ptr, __LINE__);
    assertTrue(nonNullDataAssignedTo.ptr->pNext == rightNode, __LINE__);
    assertTrue(nonNullDataAssignedTo.ptr->pPrev == leftNode, __LINE__);
    //make sure the values didn't get messed up
    assertTrue(nonNullDataNode->data == 512, __LINE__);
    assertTrue(leftNode->data == 5, __LINE__);
    assertTrue(rightNode->data == -76, __LINE__);
    
    /*
     * Testing iterator equality operator
     */
    startTestSet("Iterator == Operator");
    //testing equality of self
    assertTrue(nullNodeIterator == nullNodeIterator, __LINE__);
    //testing equality of not-self (null node)
    assertTrue(nullNodeIteratorCopy == nullNodeIterator, __LINE__);
    //testing equality of not-self, non-null node, null data in node
    assertTrue(defaultDataNodeIterator == defaultDataCopiedIterator, __LINE__);
    //testing equality of not-self, non-null node, non-null data in node
    assertTrue(nonDefaultDataNodeIterator == nonNullDataCopiedIterator, __LINE__);
    //testing equality of non-null node, null data in node
    list<int>::node secondNullNode;
    secondNullNode.data = 0;
    list<int>::iterator secondNullNodeIterator;
    secondNullNodeIterator.ptr = &secondNullNode;
    assertTrue(!(nullNodeIterator == secondNullNodeIterator), __LINE__);
    //testing equality of non-null node, default data in node
    int anInt = 7;
    list<int>::node secondNonNullDataNode;
    secondNonNullDataNode.data = anInt;
    list<int>::iterator secondNonNullDataNodeIterator;
    secondNonNullDataNodeIterator.ptr = &secondNonNullDataNode;
    assertTrue(!(nonDefaultDataNodeIterator == secondNullNodeIterator), __LINE__);
    //testing equality of iterator with different node but same value in node
    list<int>::node thirdNonNullDataNode;
    thirdNonNullDataNode.data = anInt;
    list<int>::iterator thirdNonNullDataNodeIterator;
    thirdNonNullDataNodeIterator.ptr = &thirdNonNullDataNode;
    assertTrue(!(secondNonNullDataNodeIterator == thirdNonNullDataNodeIterator), __LINE__);
    
    /*
     * Testing inequality operator
     */
    startTestSet("Iterator != Operator");
    //testing inequality of non-null node, null data in node
    assertTrue(secondNullNodeIterator != nullNodeIterator, __LINE__);
    //testing inequality of non-null node, non-null data in node
    assertTrue(nonDefaultDataNodeIterator != secondNonNullDataNodeIterator, __LINE__);
    //testing inequality of self
    assertTrue(!(nullNodeIterator != nullNodeIterator), __LINE__);
    //testing inequality of not-self (null node)
    assertTrue(!(nullNodeIteratorCopy != nullNodeIterator), __LINE__);
    //testing inequality of not-self, non-null node, null data in node
    assertTrue(!(defaultDataNodeIterator != defaultDataCopiedIterator), __LINE__);
    //testing inequality of not-self, non-null node, non-null data in node
    assertTrue(!(nonDefaultDataNodeIterator != nonNullDataCopiedIterator), __LINE__);
    //testing equality of iterator with different node but same value in node
    assertTrue(secondNonNullDataNodeIterator != thirdNonNullDataNodeIterator, __LINE__);
    
    /*
     * Iterator Incrementor Tests
     */
    //building list for incrementor tests
    list<int>incrementorList;
    //building listWithStuffInIt: 5<=>6<=>7<=>9
    incrementorList.numElements = 4;
    firstNode = new list<int>::node(5);
    incrementorList.pHead = firstNode;
    //reusing currentNodePtr variable
    currentNodePtr = incrementorList.pHead;
    secondNode = new list<int>::node(6);
    currentNodePtr->pNext = secondNode;
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    thirdNode = new list<int>::node(7);
    currentNodePtr->pNext = thirdNode;
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    fourthNode = new list<int>::node(9);
    currentNodePtr->pNext = fourthNode;
    currentNodePtr->pNext->pPrev = currentNodePtr;
    incrementorList.pTail = fourthNode;
    /*
     * Testing post-incrementor operator
     */
    startTestSet("Post Increment Operator");
    //testing incrementor when node is NULL
    try{
        nullNodeIterator++;
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: Incrementing null node.") == 0, __LINE__);
    }
    list<int>::iterator nonNullNodeIterator;
    //testing incrementing with tail
    nonNullNodeIterator.ptr = fourthNode;
    assertTrue((nonNullNodeIterator++).ptr == fourthNode, __LINE__);
    assertTrue(nonNullNodeIterator.ptr == fourthNode, __LINE__);
    //testing for any node other than tail
    nonNullNodeIterator.ptr = secondNode;
    assertTrue((nonNullNodeIterator++).ptr == secondNode, __LINE__);
    assertTrue(nonNullNodeIterator.ptr == thirdNode, __LINE__);
    
    /*
     * Testing pre-incrementor operator
     */
    startTestSet("Iterator Pre-Increment Operator");
    //testing incrementor when node is NULL
    try{
        ++nullNodeIterator;
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: Incrementing null node.") == 0, __LINE__);
    }
    //testing incrementing with tail
    nonNullNodeIterator.ptr = fourthNode;
    assertTrue((++nonNullNodeIterator).ptr == fourthNode, __LINE__);
    //testing for any node other than tail
    nonNullNodeIterator.ptr = secondNode;
    assertTrue((++nonNullNodeIterator).ptr == thirdNode, __LINE__);
    
    /*
     * Testing post-decrement operator
     */
    startTestSet("Iterator Post Decrement Operator");
    //testing decrementor when node is NULL
    try{
        nullNodeIterator--;
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: Decrementing null node.") == 0, __LINE__);
    }
    //list<int>::iterator nonNullNodeIterator;
    //testing decrementing with head
    nonNullNodeIterator.ptr = firstNode;
    assertTrue((nonNullNodeIterator--).ptr == firstNode, __LINE__);
    assertTrue(nonNullNodeIterator.ptr == firstNode, __LINE__);
    //testing for any node other than tail
    nonNullNodeIterator.ptr = secondNode;
    assertTrue((nonNullNodeIterator--).ptr == secondNode, __LINE__);
    assertTrue(nonNullNodeIterator.ptr == firstNode, __LINE__);
    /*
     * Testing pre-decrement operator
     */
    startTestSet("Iterator Pre-Decrement Operator");
    //testing decrementor when node is NULL
    try{
        --nullNodeIterator;
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: Decrementing null node.") == 0, __LINE__);
    }
    //resetting node relationships
    firstNode->pNext = secondNode;
    secondNode->pPrev = firstNode;
    //testing decrementing with head
    nonNullNodeIterator.ptr = firstNode;
    assertTrue((--nonNullNodeIterator).ptr == firstNode, __LINE__);
    //testing for any node other than tail
    nonNullNodeIterator.ptr = thirdNode;
    assertTrue((--nonNullNodeIterator).ptr == secondNode, __LINE__);
    
    /*
     * Testing dereference operator
     */
    startTestSet("Iterator Dereference Operator");
    //testing dereference of an iterator with a null node pointer
    try{
        *nullNodeIterator;
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message,"Error: Dereferencing null node.") == 0, __LINE__);
    }
    assertTrue(*nonDefaultDataNodeIterator == 512, __LINE__);
    
    /*
     * Testing Iterator Begin and End
     */
    //building empty begin/end list
    list<int>emptyBeginEndList;
    emptyBeginEndList.numElements = 0;
    emptyBeginEndList.pHead = NULL;
    emptyBeginEndList.pTail = NULL;
    
    
    //building a list do begin and end
    list<int>beginEndList;
    //building listWithStuffInIt: 5<=>6<=>7<=>9
    beginEndList.numElements = 4;
    firstNode = new list<int>::node(5);
    beginEndList.pHead = firstNode;
    //reusing currentNodePtr variable
    currentNodePtr = beginEndList.pHead;
    secondNode = new list<int>::node(6);
    currentNodePtr->pNext = secondNode;
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    thirdNode = new list<int>::node(7);
    currentNodePtr->pNext = thirdNode;
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    fourthNode = new list<int>::node(9);
    currentNodePtr->pNext = fourthNode;
    currentNodePtr->pNext->pPrev = currentNodePtr;
    //make sure we don't have a zombie
    currentNodePtr = NULL;
    /*
     * Testing Begin
     */
    startTestSet("Begin");
    assertTrue(emptyBeginEndList.begin().ptr == NULL, __LINE__);
    assertTrue(beginEndList.begin().ptr == beginEndList.pHead, __LINE__);
    
    /*
     * Testing End
     */
    startTestSet("End");
    assertTrue(emptyBeginEndList.end().ptr == NULL, __LINE__);
    assertTrue(beginEndList.end().ptr == NULL, __LINE__);
    
    /*
     * Testing Find
     */
    startTestSet("Find");
    list<int>emptyFindList;
    emptyFindList.numElements = 0;
    emptyFindList.pHead = NULL;
    emptyFindList.pTail = NULL;
    
    //testing for something not found in the list
    assertTrue(emptyFindList.find(10).ptr == NULL, __LINE__);
    
    //building a list do search
    list<int>filledFindList;
    //building listWithStuffInIt: 5<=>6<=>7<=>9
    filledFindList.numElements = 4;
    firstNode = new list<int>::node(5);
    filledFindList.pHead = firstNode;
    //reusing currentNodePtr variable
    currentNodePtr = filledFindList.pHead;
    secondNode = new list<int>::node(6);
    currentNodePtr->pNext = secondNode;
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    thirdNode = new list<int>::node(7);
    currentNodePtr->pNext = thirdNode;
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    fourthNode = new list<int>::node(9);
    currentNodePtr->pNext = fourthNode;
    currentNodePtr->pNext->pPrev = currentNodePtr;
    filledFindList.pTail = fourthNode;
    //make sure we don't have a zombie
    currentNodePtr = NULL;
    
    
    //testing for something not found in the list
    assertTrue(filledFindList.find(10).ptr == NULL, __LINE__);
    //testing finding the first element
    assertTrue(filledFindList.find(5).ptr == filledFindList.pHead, __LINE__);
    //testing finding the last element
    assertTrue(filledFindList.find(9).ptr == filledFindList.pTail, __LINE__);
    //testing finding an element somewhere in the middle
    assertTrue(filledFindList.find(6).ptr == filledFindList.pHead->pNext, __LINE__);
    
    /*
     * Testing erase
     */
    startTestSet("Erase");
    //testing for erasing end iterator
    //reusing iterator with a null node to simulate end iterator
    unit_testing_delete_call_counter = 0;
    assertTrue(emptyFindList.erase(nullNodeIterator).ptr == NULL, __LINE__);
    assertTrue(unit_testing_delete_call_counter == 0, __LINE__);
    assertTrue(filledFindList.erase(nullNodeIterator).ptr == NULL, __LINE__);
    assertTrue(unit_testing_delete_call_counter == 0, __LINE__);
    
    //testing erasing head from list:  5<=>6<=>7<=>9
    list<int>::iterator headIterator;
    headIterator.ptr = filledFindList.pHead;
    list<int>::node* nextHead = filledFindList.pHead->pNext;
    unit_testing_delete_call_counter = 0;
    assertTrue(filledFindList.erase(headIterator).ptr == nextHead, __LINE__);
    assertTrue(filledFindList.pHead == nextHead, __LINE__);
    assertTrue(unit_testing_delete_call_counter == 1, __LINE__);
    
    //testing erasing something in the middle: 6<=>7<=>9
    unit_testing_delete_call_counter = 0;
    list<int>::iterator midIterator;
    midIterator.ptr = filledFindList.pHead->pNext;
    assertTrue(filledFindList.erase(midIterator).ptr == filledFindList.pHead, __LINE__);
    assertTrue(unit_testing_delete_call_counter == 1, __LINE__);
    
    //testing erasing tail of list: 6<=>9
    unit_testing_delete_call_counter = 0;
    list<int>::iterator endIterator;
    endIterator.ptr = filledFindList.pTail;
    assertTrue(filledFindList.erase(endIterator).ptr == filledFindList.pHead, __LINE__);
    assertTrue(unit_testing_delete_call_counter == 1, __LINE__);
    
    /*
     * Testing Insert
     */
    startTestSet("Insert");
    list<int>insertList;
    insertList.numElements = 0;
    insertList.pHead = NULL;
    insertList.pTail = NULL;
    
    //testing inserting into a list with an invalid iterator (might be one from a different list, etc.)
    list<int>::iterator insertIterator;
    unit_testing_delete_call_counter = 0;
    
    //testing inserting into an empty list with valid iterator (simulating end iterator)
    insertList.insert(insertIterator, 4);
    assertTrue(insertList.pHead != NULL, __LINE__);
    assertTrue(insertList.pHead->data == 4, __LINE__);
    assertTrue(insertList.pHead == insertList.pTail, __LINE__);
    
    
    //testing inserting before head, list will be: 8<=>4
    //reusing previous head variable
    previousHead = insertList.pHead;
    insertIterator.ptr = insertList.pHead;
    insertList.insert(insertIterator, 8);
    assertTrue(insertList.pHead != NULL, __LINE__);
    assertTrue(insertList.pHead != previousHead, __LINE__);
    assertTrue(insertList.pHead->pNext == previousHead, __LINE__);
    assertTrue(insertList.pHead->data == 8, __LINE__);
    assertTrue(insertList.pTail->data == 4, __LINE__);
    
    //testing inserting in middle, list will be: 8<=>13<=>4
    insertIterator.ptr = insertList.pTail;
    insertList.insert(insertIterator, 13);
    assertTrue(insertList.pTail != NULL, __LINE__);
    assertTrue(insertList.pTail->pPrev != insertList.pHead, __LINE__);
    assertTrue(insertList.pTail->pPrev->data == 13, __LINE__);
    assertTrue(insertList.pTail->data == 4, __LINE__);
    assertTrue(insertList.pHead->data == 8, __LINE__);
    
    /*
     * Testing push_back for Non-Integer list Behavior (just to see if it works for other types)
     */
    startTestSet("Can Hold Strings");
    list<std::string>stringList;
    assertTrue(stringList.pHead == NULL, __LINE__);
    assertTrue(stringList.pTail == NULL, __LINE__);
    assertTrue(stringList.numElements == 0, __LINE__);
    stringList.push_back("Hello");
    
    assertTrue(stringList.pHead == stringList.pTail, __LINE__);
    assertTrue(stringList.pHead->data.compare("Hello") == 0, __LINE__);
    
    generateTestingReport();
    return 0;
}
