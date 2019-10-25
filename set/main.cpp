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
 * the percentage of asserts found in this test code that
 * your data structure code passed.
 */
#define UNIT_TESTING
//Do not change the next line without instructor approval.
//To do so is cheating and, when found, will result in consequences.
int asserts_existing = 394;

#include <cstring>
#include "set.h"
#include "unit_testing.h"

using namespace custom;

/*
 * While set can be implemented either sorted
 * or not sorted, for this class, you are
 * required to implement the sorted design.
 */

int main(int argc, const char* argv[])
{
    
    /*
     * Testing default constructor
     */
    startTestSet("Default Constructor");
    set <int> defaultset;
    assertTrue(defaultset.numCapacity == 0, __LINE__);
    assertTrue(defaultset.numElements == 0, __LINE__);
    assertTrue(defaultset.buffer == NULL, __LINE__);
    
    /*
     * Testing sized set constructor
     */
    startTestSet("Sized Constructor");
    try{
        set<int> badSizeset(-3);
        assertTrue(false, __LINE__);
    } catch(const char* exceptionMessage)
    {
        assertTrue(strcmp(exceptionMessage,"Error: set sizes must be greater than or equal to 0.") == 0, __LINE__);
    }
    
    set <int> sizedset(4);
    assertTrue(sizedset.numCapacity == 4, __LINE__);
    assertTrue(sizedset.numElements == 0, __LINE__);
    assertTrue(sizedset.buffer != NULL, __LINE__);
    
    /*
     * Testing Size
     */
    startTestSet("Size");
    set <int> sizeTestset;
    
    sizeTestset.numCapacity = 8;
    sizeTestset.numElements = 4;
    assertTrue(sizeTestset.size() == 4, __LINE__);
    
    /*
     * Resetting for further use
     */
    sizeTestset.numCapacity = 8;
    sizeTestset.numElements = 8;
    sizeTestset.buffer = new int[sizeTestset.numCapacity];
    for (int i = 0; i < sizeTestset.numCapacity; i++)
    {
        sizeTestset.buffer[i]=i*i+1;
    }
    //buffer: [1,2,5,10,17,26,50,65]
    /*
     * Testing Clear
     */
    startTestSet("Clear");
    sizeTestset.clear();
    assertTrue(sizeTestset.numCapacity == 8, __LINE__);
    assertTrue(sizeTestset.numElements == 0, __LINE__);
    assertTrue(sizeTestset.buffer != NULL, __LINE__);
    
    /*
     * Testing Empty
     */
    startTestSet("Empty");
    sizeTestset.numElements = 3;
    assertTrue(!sizeTestset.empty(), __LINE__);
    
    sizeTestset.numElements = 0;
    
    assertTrue(sizeTestset.empty(), __LINE__);
    
    /*
     * Testing insert with no resizing
     */
    startTestSet("Insert First Element No Resize");
    set <int> insertset;
    insertset.buffer = new int[5];
    insertset.numCapacity = 5;
    insertset.numElements = 0;
    
    int * tempBuffer = insertset.buffer;
    insertset.insert(3);
    assertTrue(tempBuffer == insertset.buffer, __LINE__);
    assertTrue(insertset.numCapacity == 5, __LINE__);
    assertTrue(insertset.numElements == 1, __LINE__);
    assertTrue(insertset.buffer[0] == 3, __LINE__);
    
    //make sure inserting a duplicate makes no changes to the end result.
    startTestSet("Insert Duplicate Element");
    insertset.insert(3);
    assertTrue(insertset.numCapacity == 5, __LINE__);
    assertTrue(insertset.numElements == 1, __LINE__);
    assertTrue(insertset.buffer[0] == 3, __LINE__);
    
    startTestSet("Insert Second Element No Resize");
    insertset.insert(7);
    assertTrue(insertset.numCapacity == 5, __LINE__);
    assertTrue(insertset.numElements == 2, __LINE__);
    assertTrue(insertset.buffer[0] == 3, __LINE__);
    assertTrue(insertset.buffer[1] == 7, __LINE__);
    
    startTestSet("Insert Third Element No Resize");
    insertset.insert(-5);
    assertTrue(insertset.numCapacity == 5, __LINE__);
    assertTrue(insertset.numElements == 3, __LINE__);
    assertTrue(insertset.buffer[0] == -5, __LINE__);
    assertTrue(insertset.buffer[1] == 3, __LINE__);
    assertTrue(insertset.buffer[2] == 7, __LINE__);
    
    /*
     * Testing resize
     */
    startTestSet("Negative Resize");
    set<int> emptyResizeset;
    emptyResizeset.resize(-1);
    assertTrue(emptyResizeset.numCapacity == 0, __LINE__);
    assertTrue(emptyResizeset.numElements == 0, __LINE__);
    assertTrue(emptyResizeset.buffer == NULL, __LINE__);
    
    startTestSet("Default Set Resize");
    emptyResizeset.resize(7);
    assertTrue(emptyResizeset.numCapacity == 7, __LINE__);
    assertTrue(emptyResizeset.numElements == 0, __LINE__);
    assertTrue(emptyResizeset.buffer != NULL, __LINE__);
    
    startTestSet("Resize");
    set <int> resizeSet;
    resizeSet.buffer = new int[5];
    resizeSet.numCapacity = 5;
    resizeSet.numElements = 5;
    resizeSet.buffer[0] = 7;
    resizeSet.buffer[1] = 12;
    resizeSet.buffer[2] = 10;
    resizeSet.buffer[3] = 9;
    resizeSet.buffer[4] = 8;
    //buffer: [7,12,10,9,8]
    
    int *theBuffer = resizeSet.buffer;
    resizeSet.resize(10);
    //buffer: [7,12,10,9,8,_,_,_,_,_]
    assertTrue(theBuffer != resizeSet.buffer, __LINE__);
    assertTrue(resizeSet.numCapacity == 10, __LINE__);
    assertTrue(resizeSet.numElements == 5, __LINE__);
    assertTrue(resizeSet.buffer[0] == 7, __LINE__);
    assertTrue(resizeSet.buffer[1] == 12, __LINE__);
    assertTrue(resizeSet.buffer[2] == 10, __LINE__);
    assertTrue(resizeSet.buffer[3] == 9, __LINE__);
    assertTrue(resizeSet.buffer[4] == 8, __LINE__);
    
    theBuffer = resizeSet.buffer;
    resizeSet.resize(2);
    //buffer: [7,12,10,9,8,_,_,_,_,_]
    assertTrue(theBuffer != resizeSet.buffer, __LINE__);
    assertTrue(resizeSet.numCapacity == 2, __LINE__);
    assertTrue(resizeSet.numElements == 2, __LINE__);
    assertTrue(resizeSet.buffer[0] == 7, __LINE__);
    assertTrue(resizeSet.buffer[1] == 12, __LINE__);
    
    theBuffer = resizeSet.buffer;
    resizeSet.resize(0);
    assertTrue(resizeSet.numCapacity == 0, __LINE__);
    assertTrue(resizeSet.numElements == 0, __LINE__);
    assertTrue(resizeSet.buffer == NULL, __LINE__);
    
    
    /*
     * Testing insert with resize
     */
    startTestSet("Insert First Element with Resize");
    set<int> insertResizeSet;
    insertResizeSet.buffer = NULL;
    insertResizeSet.numCapacity = 0;
    insertResizeSet.numElements = 0;
    
    insertResizeSet.insert(21);
    assertTrue(insertResizeSet.buffer != NULL, __LINE__);
    assertTrue(insertResizeSet.numCapacity == 1, __LINE__);
    assertTrue(insertResizeSet.numElements == 1, __LINE__);
    assertTrue(insertResizeSet.buffer[0] == 21, __LINE__);
    
    startTestSet("Insert Second Element with Resize");
    int* oldBuffer = insertResizeSet.buffer;
    insertResizeSet.insert(7);
    assertTrue(insertResizeSet.buffer != NULL, __LINE__);
    assertTrue(insertResizeSet.buffer != oldBuffer, __LINE__);
    assertTrue(insertResizeSet.numCapacity == 2, __LINE__);
    assertTrue(insertResizeSet.numElements == 2, __LINE__);
    assertTrue(insertResizeSet.buffer[0] == 7, __LINE__);
    assertTrue(insertResizeSet.buffer[1] == 21, __LINE__);
    
    //testing insert something that already exits
    startTestSet("Insert Duplicate Element");
    oldBuffer = insertResizeSet.buffer;
    insertResizeSet.insert(7);
    assertTrue(insertResizeSet.buffer != NULL, __LINE__);
    assertTrue(insertResizeSet.buffer == oldBuffer, __LINE__);
    assertTrue(insertResizeSet.numCapacity == 2, __LINE__);
    assertTrue(insertResizeSet.numElements == 2, __LINE__);
    assertTrue(insertResizeSet.buffer[0] == 7, __LINE__);
    assertTrue(insertResizeSet.buffer[1] == 21, __LINE__);
    
    //testing resize on insert yet again
    startTestSet("Insert Third Element with Resize");
    oldBuffer = insertResizeSet.buffer;
    insertResizeSet.insert(100);
    assertTrue(insertResizeSet.buffer != NULL, __LINE__);
    assertTrue(insertResizeSet.buffer != oldBuffer, __LINE__);
    assertTrue(insertResizeSet.numCapacity == 4, __LINE__);
    assertTrue(insertResizeSet.numElements == 3, __LINE__);
    assertTrue(insertResizeSet.buffer[0] == 7, __LINE__);
    assertTrue(insertResizeSet.buffer[1] == 21, __LINE__);
    assertTrue(insertResizeSet.buffer[2] == 100, __LINE__);
    
    
    //testing no-resize on insert
    startTestSet("Insert Fourth Element with Resize");
    oldBuffer = insertResizeSet.buffer;
    insertResizeSet.insert(50);
    assertTrue(insertResizeSet.buffer != NULL, __LINE__);
    assertTrue(insertResizeSet.buffer == oldBuffer, __LINE__);
    assertTrue(insertResizeSet.numCapacity == 4, __LINE__);
    assertTrue(insertResizeSet.numElements == 4, __LINE__);
    assertTrue(insertResizeSet.buffer[0] == 7, __LINE__);
    assertTrue(insertResizeSet.buffer[1] == 21, __LINE__);
    assertTrue(insertResizeSet.buffer[2] == 50, __LINE__);
    assertTrue(insertResizeSet.buffer[3] == 100, __LINE__);
    
    /*
     * Testing FindIndex
     */
    startTestSet("Find Index");
    set<int> findIndexSet;
    //testing find with empty set
    findIndexSet.numElements = 0;
    findIndexSet.numCapacity = 0;
    findIndexSet.buffer = NULL;
    assertTrue(findIndexSet.findIndex(35) == 0, __LINE__);
    
    //resetting
    findIndexSet.numElements = 3;
    findIndexSet.numCapacity = 4;
    findIndexSet.buffer = new int[4];
    findIndexSet.buffer[0] = 2;
    findIndexSet.buffer[1] = 4;
    findIndexSet.buffer[2] = 8;
    //buffer - [2,4,8]
    //Testing happy paths
    assertTrue(findIndexSet.findIndex(8) == 2, __LINE__);
    assertTrue(findIndexSet.findIndex(2) == 0, __LINE__);
    assertTrue(findIndexSet.findIndex(4) == 1, __LINE__);
    //Testing not found. Indicates where the element should be inserted when not found.
    assertTrue(findIndexSet.findIndex(5) == 2, __LINE__);
    assertTrue(findIndexSet.findIndex(27) == 3, __LINE__);
    assertTrue(findIndexSet.findIndex(0) == 0, __LINE__);
    assertTrue(findIndexSet.findIndex(-100) == 0, __LINE__);
    
    
    /*
     * Testing Raw Iterators
     */
    startTestSet("Raw Iterator");
    set<int>::iterator nullIt = set<int>::iterator();
    assertTrue(nullIt.ptr == NULL, __LINE__);
    int someInt = 3;
    int *someIntPtr = &someInt;
    set<int>::iterator intPtr = set<int>::iterator(&someInt);
    assertTrue(intPtr.ptr == someIntPtr, __LINE__);
    
    /*
     * Testing Iterator Assignment Operator
     */
    startTestSet("Iterator Assignment");
    set<int>::iterator iteratorToAssign;
    iteratorToAssign.ptr = someIntPtr;
    set<int>::iterator assignedToIterator;
    assignedToIterator = iteratorToAssign;
    assertTrue(assignedToIterator.ptr == someIntPtr, __LINE__);
    
    /*
     * Testing Iterator Comparison Operators
     */
    
    //reset
    int someOtherInt = 4;
    int* someOtherIntPtr = &someOtherInt;
    assignedToIterator.ptr = someOtherIntPtr;
    startTestSet("Iterator == Operator");
    set<int>::iterator duplicateValueIterator;
    duplicateValueIterator.ptr = someIntPtr;
    
    
    assertTrue(iteratorToAssign == duplicateValueIterator, __LINE__);
    assertTrue(!(assignedToIterator == iteratorToAssign), __LINE__);
    
    startTestSet("Iterator != Operator");
    assertTrue(iteratorToAssign != assignedToIterator, __LINE__);
    assertTrue(!(iteratorToAssign != duplicateValueIterator), __LINE__);
    /*
     * Testing Dereference Operator
     */
    startTestSet("Iterator * Operator");
    assertTrue(*assignedToIterator == 4, __LINE__);
    /*
     * Testing iterator incrementor
     */
    startTestSet("Iterator Pre and Post-Increment");
    nullIt.ptr = NULL;
    assertTrue((nullIt++).ptr == NULL, __LINE__);
    assertTrue((++nullIt).ptr == NULL, __LINE__);
    
    set<int> incrementTesterSet;
    incrementTesterSet.buffer = new int[3];
    //setting to the beginning of buffer
    set<int>::iterator fakeBeginIt = set<int>::iterator();
    fakeBeginIt.ptr = incrementTesterSet.buffer;
    
    assertTrue((fakeBeginIt++).ptr == incrementTesterSet.buffer, __LINE__);
    //reset
    fakeBeginIt.ptr = incrementTesterSet.buffer;
    assertTrue((++fakeBeginIt).ptr == incrementTesterSet.buffer+1, __LINE__);
    
    startTestSet("Iterator Pre and Post-Decrement Operator");
    incrementTesterSet.buffer = new int[8];
    incrementTesterSet.numCapacity = 8;
    incrementTesterSet.numElements = 5;
    incrementTesterSet.buffer[0] = 6;
    incrementTesterSet.buffer[1] = 4;
    incrementTesterSet.buffer[2] = -3;
    incrementTesterSet.buffer[3] = 2;
    incrementTesterSet.buffer[4] = 0;
    //buffer: [6,4,-3,2,0]
    //setting to the end of buffer
    set<int>::iterator fakeEndIt = set<int>::iterator();
    fakeEndIt.ptr = incrementTesterSet.buffer+incrementTesterSet.numElements;
    assertTrue((fakeEndIt--).ptr == incrementTesterSet.buffer+incrementTesterSet.numElements, __LINE__);
    //reset
    fakeEndIt.ptr = incrementTesterSet.buffer+incrementTesterSet.numElements;
    assertTrue((--fakeEndIt).ptr == incrementTesterSet.buffer+incrementTesterSet.numElements - 1, __LINE__);
    
    /*
     * Testing union operator
     */
    startTestSet("Empty Set Union");
    set<int>shortSet;
    shortSet.numCapacity = 0;
    shortSet.numElements = 0;
    shortSet.buffer = NULL;
    
    set<int>longSet;
    longSet.numCapacity = 0;
    longSet.numElements = 0;
    longSet.buffer = NULL;
    
    //testing union empty sets is empty set
    assertTrue((shortSet || longSet).numCapacity == 0, __LINE__);
    assertTrue((shortSet || longSet).numElements == 0, __LINE__);
    assertTrue((shortSet || longSet).buffer == NULL, __LINE__);
    
    startTestSet("Filled Set Union");

    //testing union empty set with filled buffer set
    longSet.buffer = new int[10];
    longSet.numCapacity = 10;
    longSet.numElements = 10;

    longSet.buffer[0] = 3;
    longSet.buffer[1] = 4;
    longSet.buffer[2] = 5;
    longSet.buffer[3] = 6;
    longSet.buffer[4] = 7;
    longSet.buffer[5] = 8;
    longSet.buffer[6] = 9;
    longSet.buffer[7] = 10;
    longSet.buffer[8] = 11;
    longSet.buffer[9] = 12;

    assertTrue((shortSet || longSet).buffer != NULL, __LINE__);
    assertTrue((shortSet || longSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).buffer != longSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).numCapacity == 10, __LINE__);
    assertTrue((shortSet || longSet).numElements == 10, __LINE__);
    assertTrue((shortSet || longSet).buffer != NULL, __LINE__);
    assertTrue((shortSet || longSet).buffer != longSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).buffer[0] == 3, __LINE__);
    assertTrue((shortSet || longSet).buffer[1] == 4, __LINE__);
    assertTrue((shortSet || longSet).buffer[2] == 5, __LINE__);
    assertTrue((shortSet || longSet).buffer[3] == 6, __LINE__);
    assertTrue((shortSet || longSet).buffer[4] == 7, __LINE__);
    assertTrue((shortSet || longSet).buffer[5] == 8, __LINE__);
    assertTrue((shortSet || longSet).buffer[6] == 9, __LINE__);
    assertTrue((shortSet || longSet).buffer[7] == 10, __LINE__);
    assertTrue((shortSet || longSet).buffer[8] == 11, __LINE__);
    assertTrue((shortSet || longSet).buffer[9] == 12, __LINE__);
    
    //testing union empty set with partially filled buffer set
    //reset longSet
    longSet.numElements = 3;
    assertTrue((shortSet || longSet).buffer != NULL, __LINE__);
    assertTrue((shortSet || longSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).buffer != longSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).numCapacity == 3, __LINE__);
    assertTrue((shortSet || longSet).numElements == 3, __LINE__);
    assertTrue((shortSet || longSet).buffer != NULL, __LINE__);
    assertTrue((shortSet || longSet).buffer != longSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).buffer[0] == 3, __LINE__);
    assertTrue((shortSet || longSet).buffer[1] == 4, __LINE__);
    assertTrue((shortSet || longSet).buffer[2] == 5, __LINE__);
    
    //testing union partially filled buffer set with full buffer
    //reset longSet
    longSet.numElements = 3;
    //reset shortSet
    shortSet.buffer = new int[5];
    shortSet.numCapacity = 5;
    shortSet.numElements = 5;
    shortSet.buffer[0] = 5;
    shortSet.buffer[1] = 6;
    shortSet.buffer[2] = 7;
    shortSet.buffer[3] = 8;
    shortSet.buffer[4] = 9;
    
    assertTrue((shortSet || longSet).buffer != NULL, __LINE__);
    assertTrue((shortSet || longSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).buffer != longSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).numCapacity == 7, __LINE__);
    assertTrue((shortSet || longSet).numElements == 7, __LINE__);
    assertTrue((shortSet || longSet).buffer != NULL, __LINE__);
    assertTrue((shortSet || longSet).buffer != longSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).buffer[0] == 3, __LINE__);
    assertTrue((shortSet || longSet).buffer[1] == 4, __LINE__);
    assertTrue((shortSet || longSet).buffer[2] == 5, __LINE__);
    assertTrue((shortSet || longSet).buffer[3] == 6, __LINE__);
    assertTrue((shortSet || longSet).buffer[4] == 7, __LINE__);
    assertTrue((shortSet || longSet).buffer[5] == 8, __LINE__);
    assertTrue((shortSet || longSet).buffer[6] == 9, __LINE__);
    
    //testing union two full sets -- no elements in common
    //resetting longSet
    longSet.numElements = 10;
    shortSet.buffer = new int[6];
    shortSet.numCapacity = 6;
    shortSet.numElements = 6;
    shortSet.buffer[0] = -6;
    shortSet.buffer[1] = -5;
    shortSet.buffer[2] = -4;
    shortSet.buffer[3] = -3;
    shortSet.buffer[4] = -2;
    shortSet.buffer[5] = -1;
    assertTrue((shortSet || longSet).buffer != NULL, __LINE__);
    assertTrue((shortSet || longSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).buffer != longSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).numCapacity == 16, __LINE__);
    assertTrue((shortSet || longSet).numElements == 16, __LINE__);
    assertTrue((shortSet || longSet).buffer != NULL, __LINE__);
    assertTrue((shortSet || longSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).buffer != longSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).buffer[0] == -6, __LINE__);
    assertTrue((shortSet || longSet).buffer[1] == -5, __LINE__);
    assertTrue((shortSet || longSet).buffer[2] == -4, __LINE__);
    assertTrue((shortSet || longSet).buffer[3] == -3, __LINE__);
    assertTrue((shortSet || longSet).buffer[4] == -2, __LINE__);
    assertTrue((shortSet || longSet).buffer[5] == -1, __LINE__);
    assertTrue((shortSet || longSet).buffer[6] == 3, __LINE__);
    assertTrue((shortSet || longSet).buffer[7] == 4, __LINE__);
    assertTrue((shortSet || longSet).buffer[8] == 5, __LINE__);
    assertTrue((shortSet || longSet).buffer[9] == 6, __LINE__);
    assertTrue((shortSet || longSet).buffer[10] == 7, __LINE__);
    assertTrue((shortSet || longSet).buffer[11] == 8, __LINE__);
    assertTrue((shortSet || longSet).buffer[12] == 9, __LINE__);
    assertTrue((shortSet || longSet).buffer[13] == 10, __LINE__);
    assertTrue((shortSet || longSet).buffer[14] == 11, __LINE__);
    assertTrue((shortSet || longSet).buffer[15] == 12, __LINE__);
    
    //testing union two full sets all of short found in long
    //resetting short set
    shortSet.buffer[0] = 5;
    shortSet.buffer[1] = 7;
    shortSet.buffer[2] = 8;
    shortSet.buffer[3] = 9;
    shortSet.buffer[4] = 10;
    shortSet.buffer[5] = 11;
    
    assertTrue((shortSet || longSet).buffer != NULL, __LINE__);
    assertTrue((shortSet || longSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).buffer != longSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).numCapacity == 10, __LINE__);
    assertTrue((shortSet || longSet).numElements == 10, __LINE__);
    assertTrue((shortSet || longSet).buffer != NULL, __LINE__);
    assertTrue((shortSet || longSet).buffer != longSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((shortSet || longSet).buffer[0] == 3, __LINE__);
    assertTrue((shortSet || longSet).buffer[1] == 4, __LINE__);
    assertTrue((shortSet || longSet).buffer[2] == 5, __LINE__);
    assertTrue((shortSet || longSet).buffer[3] == 6, __LINE__);
    assertTrue((shortSet || longSet).buffer[4] == 7, __LINE__);
    assertTrue((shortSet || longSet).buffer[5] == 8, __LINE__);
    assertTrue((shortSet || longSet).buffer[6] == 9, __LINE__);
    assertTrue((shortSet || longSet).buffer[7] == 10, __LINE__);
    assertTrue((shortSet || longSet).buffer[8] == 11, __LINE__);
    assertTrue((shortSet || longSet).buffer[9] == 12, __LINE__);
    
    //testing union with itself
    assertTrue((longSet || longSet).buffer != NULL, __LINE__);
    assertTrue((longSet || longSet).buffer != longSet.buffer, __LINE__);
    assertTrue((longSet || longSet).numCapacity == 10, __LINE__);
    assertTrue((longSet || longSet).numElements == 10, __LINE__);
    assertTrue((longSet || longSet).buffer != NULL, __LINE__);
    assertTrue((longSet || longSet).buffer != longSet.buffer, __LINE__);
    assertTrue((longSet || longSet).buffer[0] == 3, __LINE__);
    assertTrue((longSet || longSet).buffer[1] == 4, __LINE__);
    assertTrue((longSet || longSet).buffer[2] == 5, __LINE__);
    assertTrue((longSet || longSet).buffer[3] == 6, __LINE__);
    assertTrue((longSet || longSet).buffer[4] == 7, __LINE__);
    assertTrue((longSet || longSet).buffer[5] == 8, __LINE__);
    assertTrue((longSet || longSet).buffer[6] == 9, __LINE__);
    assertTrue((longSet || longSet).buffer[7] == 10, __LINE__);
    assertTrue((longSet || longSet).buffer[8] == 11, __LINE__);
    assertTrue((longSet || longSet).buffer[9] == 12, __LINE__);
    
    /*
     * Testing Union of Partially Filled Sets
     */
    startTestSet("Partially Filled Set Union");
    set<int>partialSet;
    partialSet.buffer = new int[10];
    partialSet.numElements = 5;
    partialSet.numCapacity = 10;
    partialSet.buffer[0] = -4;
    partialSet.buffer[1] = 1;
    partialSet.buffer[2] = 3;
    partialSet.buffer[3] = 37;
    partialSet.buffer[4] = 1829;
    
    set<int>otherPartialSet;
    otherPartialSet.buffer = new int[15];
    otherPartialSet.numElements = 4;
    otherPartialSet.numCapacity = 15;
    otherPartialSet.buffer[0] = 1;
    otherPartialSet.buffer[1] = 37;
    otherPartialSet.buffer[2] = 78;
    otherPartialSet.buffer[3] = 789;
    
    
    assertTrue((partialSet || otherPartialSet).buffer != NULL, __LINE__);
    assertTrue((partialSet || otherPartialSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((partialSet || otherPartialSet).buffer != longSet.buffer, __LINE__);
    assertTrue((partialSet || otherPartialSet).numElements == 7, __LINE__);
    assertTrue((partialSet || otherPartialSet).numCapacity == 7, __LINE__);
    assertTrue((partialSet || otherPartialSet).buffer[0] == -4, __LINE__);
    assertTrue((partialSet || otherPartialSet).buffer[1] == 1, __LINE__);
    
    
    
    

    /*
     * Testing Intersection
     */
    startTestSet("Intersection");
    //resetting shortSet
    shortSet.buffer = NULL;
    shortSet.numCapacity = 0;
    shortSet.numElements = 0;
    
    //resetting longSet
    longSet.buffer = NULL;
    longSet.numCapacity = 0;
    longSet.numElements = 0;
    //testing intersection of empty sets
    
    assertTrue((shortSet && longSet).numCapacity == 0, __LINE__);
    assertTrue((shortSet && longSet).numElements == 0, __LINE__);
    assertTrue((shortSet && longSet).buffer == NULL, __LINE__);
    
    //resetting longSet
    longSet.buffer = new int[10];
    longSet.numCapacity = 10;
    longSet.numElements = 10;
    longSet.buffer[0] = 3;
    longSet.buffer[1] = 4;
    longSet.buffer[2] = 5;
    longSet.buffer[3] = 6;
    longSet.buffer[4] = 7;
    longSet.buffer[5] = 8;
    longSet.buffer[6] = 9;
    longSet.buffer[7] = 10;
    longSet.buffer[8] = 11;
    longSet.buffer[9] = 12;
    
    //testing intersection of empty set and non-empty set
    // assertTrue((shortSet && longSet).buffer == NULL,__LINE__);
    assertTrue((shortSet && longSet).buffer == shortSet.buffer,__LINE__);
    assertTrue((shortSet && longSet).buffer != longSet.buffer,__LINE__);
    assertTrue((shortSet && longSet).numCapacity == 0, __LINE__);
    assertTrue((shortSet && longSet).numElements == 0, __LINE__);
    assertTrue((shortSet && longSet).buffer == NULL, __LINE__);
    
    //resetting shortSet
    shortSet.buffer = new int[6];
    shortSet.numCapacity = 6;
    shortSet.numElements = 6;
    shortSet.buffer[0] = -6;
    shortSet.buffer[1] = -5;
    shortSet.buffer[2] = -4;
    shortSet.buffer[3] = -3;
    shortSet.buffer[4] = -2;
    shortSet.buffer[5] = -1;
    
    //testing intersection nothing in common
    assertTrue((shortSet && longSet).numCapacity == 0, __LINE__);
    assertTrue((shortSet && longSet).numElements == 0, __LINE__);
    assertTrue((shortSet && longSet).buffer == NULL, __LINE__);
    
    
    //resetting shortSet
    shortSet.buffer[0] = 5;
    shortSet.buffer[1] = 7;
    shortSet.buffer[2] = 8;
    shortSet.buffer[3] = 9;
    shortSet.buffer[4] = 10;
    shortSet.buffer[5] = 11;
    
    //testing intersection all short set in common
    assertTrue((shortSet && longSet).buffer != NULL,__LINE__);
    assertTrue((shortSet && longSet).buffer != shortSet.buffer,__LINE__);
    assertTrue((shortSet && longSet).buffer != longSet.buffer,__LINE__);
    assertTrue((shortSet && longSet).numCapacity == 6, __LINE__);
    assertTrue((shortSet && longSet).numElements == 6, __LINE__);
    assertTrue((shortSet && longSet).buffer != NULL, __LINE__);
    assertTrue((shortSet && longSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((shortSet && longSet).buffer != longSet.buffer, __LINE__);
    assertTrue((shortSet && longSet).buffer[0] == 5, __LINE__);
    assertTrue((shortSet && longSet).buffer[1] == 7, __LINE__);
    assertTrue((shortSet && longSet).buffer[2] == 8, __LINE__);
    assertTrue((shortSet && longSet).buffer[3] == 9, __LINE__);
    assertTrue((shortSet && longSet).buffer[4] == 10, __LINE__);
    assertTrue((shortSet && longSet).buffer[5] == 11, __LINE__);
    
    //resetting shortSet
    shortSet.buffer[3] = 70;
    shortSet.buffer[4] = 121;
    shortSet.buffer[5] = 1273;
    
    
    //testing intersection some elements in common
    assertTrue((shortSet && longSet).buffer != NULL,__LINE__);
    assertTrue((shortSet && longSet).buffer != shortSet.buffer,__LINE__);
    assertTrue((shortSet && longSet).buffer != longSet.buffer,__LINE__);
    assertTrue((shortSet && longSet).numCapacity == 3, __LINE__);
    assertTrue((shortSet && longSet).numElements == 3, __LINE__);
    assertTrue((shortSet && longSet).buffer != NULL, __LINE__);
    assertTrue((shortSet && longSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((shortSet && longSet).buffer != longSet.buffer, __LINE__);
    assertTrue((shortSet && longSet).buffer[0] == 5, __LINE__);
    assertTrue((shortSet && longSet).buffer[1] == 7, __LINE__);
    
    /*
     * Testing Difference
     */
    startTestSet("Difference");
    //resetting shortSet
    shortSet.numCapacity = 0;
    shortSet.numElements = 0;
    shortSet.buffer = NULL;
    //resetting longSet
    longSet.numCapacity = 0;
    longSet.numElements = 0;
    longSet.buffer = NULL;
    
    //testing difference empty sets both directions
    
    assertTrue((shortSet - longSet).numCapacity == 0, __LINE__);
    assertTrue((shortSet - longSet).numElements == 0, __LINE__);
    assertTrue((shortSet - longSet).buffer == NULL, __LINE__);
    assertTrue((longSet - shortSet).numCapacity == 0, __LINE__);
    assertTrue((longSet - shortSet).numElements == 0, __LINE__);
    assertTrue((longSet - shortSet).buffer == NULL, __LINE__);
    
    //resetting longSet
    longSet.buffer = new int[10];
    longSet.numCapacity = 10;
    longSet.numElements = 10;
    longSet.buffer[0] = 3;
    longSet.buffer[1] = 4;
    longSet.buffer[2] = 5;
    longSet.buffer[3] = 6;
    longSet.buffer[4] = 7;
    longSet.buffer[5] = 8;
    longSet.buffer[6] = 9;
    longSet.buffer[7] = 10;
    longSet.buffer[8] = 11;
    longSet.buffer[9] = 12;
    
    //testing one set empty difference both ways
    
    assertTrue((shortSet - longSet).numCapacity == 0, __LINE__);
    assertTrue((shortSet - longSet).numElements == 0, __LINE__);
    assertTrue((shortSet - longSet).buffer == NULL, __LINE__);
    
    assertTrue((longSet - shortSet).buffer != NULL,__LINE__);
    assertTrue((longSet - shortSet).buffer != shortSet.buffer,__LINE__);
    assertTrue((longSet - shortSet).buffer != longSet.buffer,__LINE__);
    assertTrue((longSet - shortSet).numCapacity == 10, __LINE__);
    assertTrue((longSet - shortSet).numElements == 10, __LINE__);
    assertTrue((longSet - shortSet).buffer != NULL, __LINE__);
    assertTrue((longSet - shortSet).buffer != longSet.buffer, __LINE__);
    assertTrue((longSet - shortSet).buffer[0] == 3, __LINE__);
    assertTrue((longSet - shortSet).buffer[1] == 4, __LINE__);
    assertTrue((longSet - shortSet).buffer[2] == 5, __LINE__);
    assertTrue((longSet - shortSet).buffer[3] == 6, __LINE__);
    assertTrue((longSet - shortSet).buffer[4] == 7, __LINE__);
    assertTrue((longSet - shortSet).buffer[5] == 8, __LINE__);
    assertTrue((longSet - shortSet).buffer[6] == 9, __LINE__);
    assertTrue((longSet - shortSet).buffer[7] == 10, __LINE__);
    assertTrue((longSet - shortSet).buffer[8] == 11, __LINE__);
    assertTrue((longSet - shortSet).buffer[9] == 12, __LINE__);
    
    //testing difference for sets with same elements
    
    assertTrue((shortSet - shortSet).numCapacity == 0, __LINE__);
    assertTrue((shortSet - shortSet).numElements == 0, __LINE__);
    assertTrue((shortSet - shortSet).buffer == NULL, __LINE__);
    
    //resetting shortSet
    shortSet.numCapacity = 6;
    shortSet.numElements = 6;
    shortSet.buffer = new int[6];
    shortSet.buffer[0] = -6;
    shortSet.buffer[1] = -5;
    shortSet.buffer[2] = -4;
    shortSet.buffer[3] = -3;
    shortSet.buffer[4] = -2;
    shortSet.buffer[5] = -1;
    
    //testing difference nothing in common both ways
    //longSet [3,4,5,6,7,8,9,10,11,12]
    assertTrue((shortSet - longSet).numCapacity == 6, __LINE__);
    assertTrue((shortSet - longSet).numElements == 6, __LINE__);
    assertTrue((shortSet - longSet).buffer != NULL, __LINE__);
    assertTrue((shortSet - longSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((shortSet - longSet).buffer != longSet.buffer, __LINE__);
    assertTrue((shortSet - longSet).buffer[0] == -6, __LINE__);
    assertTrue((shortSet - longSet).buffer[1] == -5, __LINE__);
    assertTrue((shortSet - longSet).buffer[2] == -4, __LINE__);
    assertTrue((shortSet - longSet).buffer[3] == -3, __LINE__);
    assertTrue((shortSet - longSet).buffer[4] == -2, __LINE__);
    assertTrue((shortSet - longSet).buffer[5] == -1, __LINE__);
    
    assertTrue((longSet - shortSet).numCapacity == 10, __LINE__);
    assertTrue((longSet - shortSet).numElements == 10, __LINE__);
    assertTrue((longSet - shortSet).buffer != NULL, __LINE__);
    assertTrue((longSet - shortSet).buffer != longSet.buffer, __LINE__);
    assertTrue((longSet - shortSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((longSet - shortSet).buffer[0] == 3, __LINE__);
    assertTrue((longSet - shortSet).buffer[1] == 4, __LINE__);
    assertTrue((longSet - shortSet).buffer[2] == 5, __LINE__);
    assertTrue((longSet - shortSet).buffer[3] == 6, __LINE__);
    assertTrue((longSet - shortSet).buffer[4] == 7, __LINE__);
    assertTrue((longSet - shortSet).buffer[5] == 8, __LINE__);
    assertTrue((longSet - shortSet).buffer[6] == 9, __LINE__);
    assertTrue((longSet - shortSet).buffer[7] == 10, __LINE__);
    assertTrue((longSet - shortSet).buffer[8] == 11, __LINE__);
    assertTrue((longSet - shortSet).buffer[9] == 12, __LINE__);
    
    //resetting shortSet
    shortSet.buffer[0] = -21;
    shortSet.buffer[1] = -13;
    shortSet.buffer[2] = 0;
    shortSet.buffer[3] = 1;
    shortSet.buffer[4] = 5;
    shortSet.buffer[5] = 11;
    
    //testing some elements in common both ways
    //longSet [3,4,5,6,7,8,9,10,11,12]
    assertTrue((shortSet - longSet).numCapacity == 4, __LINE__);
    assertTrue((shortSet - longSet).numElements == 4, __LINE__);
    assertTrue((shortSet - longSet).buffer != NULL, __LINE__);
    assertTrue((shortSet - longSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((shortSet - longSet).buffer != longSet.buffer, __LINE__);
    assertTrue((shortSet - longSet).buffer[0] == -21, __LINE__);
    assertTrue((shortSet - longSet).buffer[1] == -13, __LINE__);
    assertTrue((shortSet - longSet).buffer[2] == 0, __LINE__);
    assertTrue((shortSet - longSet).buffer[3] == 1, __LINE__);
    
    assertTrue((longSet - shortSet).numCapacity == 8, __LINE__);
    assertTrue((longSet - shortSet).numElements == 8, __LINE__);
    assertTrue((longSet - shortSet).buffer != NULL, __LINE__);
    assertTrue((longSet - shortSet).buffer != longSet.buffer, __LINE__);
    assertTrue((longSet - shortSet).buffer != shortSet.buffer, __LINE__);
    assertTrue((longSet - shortSet).buffer[0] == 3, __LINE__);
    assertTrue((longSet - shortSet).buffer[1] == 4, __LINE__);
    assertTrue((longSet - shortSet).buffer[2] == 6, __LINE__);
    assertTrue((longSet - shortSet).buffer[3] == 7, __LINE__);
    assertTrue((longSet - shortSet).buffer[4] == 8, __LINE__);
    assertTrue((longSet - shortSet).buffer[5] == 9, __LINE__);
    assertTrue((longSet - shortSet).buffer[6] == 10, __LINE__);
    assertTrue((longSet - shortSet).buffer[7] == 12, __LINE__);
    
    /*
     * Testing Find
     */
    startTestSet("Find");
    set<int>findSet;
    findSet.numCapacity = 0;
    findSet.numElements = 0;
    findSet.buffer = NULL;
    
    set<int>::iterator foundIt;
    foundIt = findSet.find(3);
    assertTrue(foundIt.ptr == NULL, __LINE__);
    
    //resetting
    findSet.numCapacity = 5;
    findSet.numElements = 4;
    findSet.buffer = new int[5];
    findSet.buffer[0] = -231;
    findSet.buffer[1] = 0;
    findSet.buffer[2] = 13;
    findSet.buffer[3] = 857;
    
    //testing happy path
    foundIt = findSet.find(-231);
    assertTrue(foundIt.ptr == findSet.buffer, __LINE__);
    
    foundIt = findSet.find(857);
    assertTrue(foundIt.ptr == findSet.buffer+3, __LINE__);
    
    //testing non-existant
    
    foundIt = findSet.find(23);
    assertTrue(foundIt.ptr == NULL, __LINE__);
    
    /*
     * Testing Erase
     */
    startTestSet("Erase");
    set <int> eraseSet;
    eraseSet.buffer = new int[6];
    eraseSet.numCapacity = 6;
    eraseSet.numElements = 5;
    eraseSet.buffer[0] = -500;
    eraseSet.buffer[1] = 0;
    eraseSet.buffer[2] = 7;
    eraseSet.buffer[3] = 13;
    eraseSet.buffer[4] = 23;
    
    eraseSet.erase(nullIt);
    assertTrue(eraseSet.numCapacity == 6, __LINE__);
    assertTrue(eraseSet.numElements == 5, __LINE__);
    assertTrue(eraseSet.buffer[0] == -500, __LINE__);
    assertTrue(eraseSet.buffer[1] == 0, __LINE__);
    assertTrue(eraseSet.buffer[2] == 7, __LINE__);
    assertTrue(eraseSet.buffer[3] == 13, __LINE__);
    assertTrue(eraseSet.buffer[4] == 23, __LINE__);
    
    
    set<int>::iterator eraseLastIter = set<int>::iterator(eraseSet.buffer+4);
    eraseSet.erase(eraseLastIter);
    assertTrue(eraseSet.numCapacity == 6, __LINE__);
    assertTrue(eraseSet.numElements == 4, __LINE__);
    assertTrue(eraseSet.buffer[0] == -500, __LINE__);
    assertTrue(eraseSet.buffer[1] == 0, __LINE__);
    assertTrue(eraseSet.buffer[2] == 7, __LINE__);
    assertTrue(eraseSet.buffer[3] == 13, __LINE__);
    
    set<int>::iterator eraseMidIter = set<int>::iterator(eraseSet.buffer+2);
    eraseSet.erase(eraseMidIter);
    assertTrue(eraseSet.numCapacity == 6, __LINE__);
    assertTrue(eraseSet.numElements == 3, __LINE__);
    assertTrue(eraseSet.buffer[0] == -500, __LINE__);
    assertTrue(eraseSet.buffer[1] == 0, __LINE__);
    assertTrue(eraseSet.buffer[2] == 13, __LINE__);
    
    set<int>::iterator eraseFirstIter = set<int>::iterator(eraseSet.buffer);
    eraseSet.erase(eraseFirstIter);
    assertTrue(eraseSet.numCapacity == 6, __LINE__);
    assertTrue(eraseSet.numElements == 2, __LINE__);
    assertTrue(eraseSet.buffer[0] == 0, __LINE__);
    assertTrue(eraseSet.buffer[1] == 13, __LINE__);
    
    
    /*
     * Testing = operator and copy constructor
     */
    startTestSet("Set = Operator");
    set <int> setToCopy;
    setToCopy.numCapacity = 8;
    setToCopy.numElements = 8;
    setToCopy.buffer = new int[setToCopy.numCapacity];
    for (int i = 0; i < setToCopy.numCapacity; i++)
    {
        setToCopy.buffer[i]=i*i+1;
    }
    set <int> setAssignedCopy;
    setAssignedCopy = setToCopy;
    assertTrue(setAssignedCopy.numCapacity == 8, __LINE__);
    assertTrue(setAssignedCopy.numElements == 8, __LINE__);
    assertTrue(setAssignedCopy.buffer != setToCopy.buffer, __LINE__);
    assertTrue(setAssignedCopy.buffer[0] == 1, __LINE__);
    assertTrue(setAssignedCopy.buffer[1] == 2, __LINE__);
    assertTrue(setAssignedCopy.buffer[2] == 5, __LINE__);
    assertTrue(setAssignedCopy.buffer[3] == 10, __LINE__);
    assertTrue(setAssignedCopy.buffer[4] == 17, __LINE__);
    assertTrue(setAssignedCopy.buffer[5] == 26, __LINE__);
    assertTrue(setAssignedCopy.buffer[6] == 37, __LINE__);
    assertTrue(setAssignedCopy.buffer[7] == 50, __LINE__);
    
    startTestSet("(Full) Copy Constructor");
    set <int> setCopy(setToCopy);
    assertTrue(setCopy.numCapacity == 8, __LINE__);
    assertTrue(setCopy.numElements == 8, __LINE__);
    assertTrue(setCopy.buffer != setToCopy.buffer, __LINE__);
    assertTrue(setCopy.numCapacity == 8, __LINE__);
    assertTrue(setCopy.buffer[0] == 1, __LINE__);
    assertTrue(setCopy.buffer[1] == 2, __LINE__);
    assertTrue(setCopy.buffer[2] == 5, __LINE__);
    assertTrue(setCopy.buffer[3] == 10, __LINE__);
    assertTrue(setCopy.buffer[4] == 17, __LINE__);
    assertTrue(setCopy.buffer[5] == 26, __LINE__);
    assertTrue(setCopy.buffer[6] == 37, __LINE__);
    assertTrue(setCopy.buffer[7] == 50, __LINE__);
    
    /*
     * Resetting to not full set
     */
    startTestSet("(Not full) = Operator");
    setToCopy.numElements = 3;
    
    set <int> notFullsetAssignedCopy;
    notFullsetAssignedCopy = setToCopy;
    assertTrue(notFullsetAssignedCopy.numCapacity == 3, __LINE__);
    assertTrue(notFullsetAssignedCopy.numElements == 3, __LINE__);
    assertTrue(notFullsetAssignedCopy.buffer != setToCopy.buffer, __LINE__);
    assertTrue(notFullsetAssignedCopy.buffer[0] == 1, __LINE__);
    assertTrue(notFullsetAssignedCopy.buffer[1] == 2, __LINE__);
    assertTrue(notFullsetAssignedCopy.buffer[2] == 5, __LINE__);
    
    startTestSet("(Not Full) Copy Constructor");
    set <int> notFullSetCopy(setToCopy);
    assertTrue(notFullSetCopy.numCapacity == 3, __LINE__);
    assertTrue(notFullSetCopy.numElements == 3, __LINE__);
    assertTrue(notFullSetCopy.buffer != setToCopy.buffer, __LINE__);
    assertTrue(notFullSetCopy.buffer[0] == 1, __LINE__);
    assertTrue(notFullSetCopy.buffer[1] == 2, __LINE__);
    assertTrue(notFullSetCopy.buffer[2] == 5, __LINE__);
    
    
    
    /*
     * Testing insert for Non-Integer set Behavior (Just to Make Sure set Works For Other Types)
     */
    startTestSet("Can Hold Strings");
    set <std::string> stringset;
    stringset.insert("Hello");
    stringset.insert("It's me");
    stringset.insert("Are you wondering");
    assertTrue(stringset.numCapacity == 4, __LINE__);
    assertTrue(stringset.buffer[0] == "Are you wondering", __LINE__);
    assertTrue(stringset.buffer[1] == "Hello", __LINE__);
    assertTrue(stringset.buffer[2] == "It's me", __LINE__);
    
    
    
    generateTestingReport();
    
    return 0;
}
