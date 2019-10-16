/*
 * main.cpp
 *
 *  Created by Lee Barney on 09/18/18.
 *  Copyright (c) 2018 Lee Barney
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this softwaref and associated documentation files (the "Software"),
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
int asserts_existing = 145;

#include <iostream>
#include "queue.h"
#include "unit_testing.h"

using namespace custom;



int main(int argc, const char* argv[]) {
    
    /*
     * Testing default constructor
     */
    startTestSet("Default Constructor");
    queue <int> defaultQueue;
    assertTrue(defaultQueue.numCapacity == 0, __LINE__);
    assertTrue(defaultQueue.numPush == 0, __LINE__);
    assertTrue(defaultQueue.numPop == 0, __LINE__);
    assertTrue(defaultQueue.buffer == NULL, __LINE__);
    
    
    
    /*
     * Testing Size
     */
    startTestSet("Size");
    queue <int> sizeTestQueue;
    
    sizeTestQueue.numCapacity = 8;
    sizeTestQueue.numPush = 4;
    sizeTestQueue.numPop = 0;
    assertTrue(sizeTestQueue.size() == 4, __LINE__);
    
    sizeTestQueue.numPop = 4;
    assertTrue(sizeTestQueue.size() == 0, __LINE__);
    
    sizeTestQueue.numPop = 2;
    assertTrue(sizeTestQueue.size() == 2, __LINE__);
    
    
    sizeTestQueue.numPush = 32;
    sizeTestQueue.numPop = 29;
    assertTrue(sizeTestQueue.size() == 3, __LINE__);
    
    /*
     * Testing Capacity
     */
    startTestSet("Capacity");
    assertTrue(sizeTestQueue.capacity() == 8, __LINE__);
    sizeTestQueue.numCapacity = 0;
    assertTrue(sizeTestQueue.capacity() == 0, __LINE__);
    
    /*
     * Resetting for further use
     */
    sizeTestQueue.numCapacity = 8;
    sizeTestQueue.numPush = 8;
    sizeTestQueue.numPop = 0;
    sizeTestQueue.buffer = new int[sizeTestQueue.numCapacity];
    for (int i = 0; i < sizeTestQueue.numCapacity; i++) {
        sizeTestQueue.buffer[i]=i*i+1;
    }
    /*
     * Testing Clear
     */
    startTestSet("Clear");
    sizeTestQueue.clear();
    assertTrue(sizeTestQueue.numCapacity == 8, __LINE__);
    assertTrue(sizeTestQueue.numPush == 0, __LINE__);
    assertTrue(sizeTestQueue.numPop == 0, __LINE__);
    assertTrue(sizeTestQueue.buffer != NULL, __LINE__);
    
    /*
     * Testing Empty
     */
    startTestSet("Empty");
    sizeTestQueue.numPush = 3;
    sizeTestQueue.numPop = 2;
    assertTrue(!sizeTestQueue.empty(), __LINE__);
    
    sizeTestQueue.numPop = 3;
    
    assertTrue(sizeTestQueue.empty(), __LINE__);
    
    /*
     * Testing resize
     */
    startTestSet("Negative Resize");
    queue<int> emptyResizeQueue;
    emptyResizeQueue.resize(-1);
    assertTrue(emptyResizeQueue.numCapacity == 0, __LINE__);
    assertTrue(emptyResizeQueue.numPush == 0, __LINE__);
    assertTrue(emptyResizeQueue.numPop == 0, __LINE__);
    assertTrue(emptyResizeQueue.buffer == NULL, __LINE__);
    
    startTestSet("Default Queue Resize");
    emptyResizeQueue.resize(7);
    assertTrue(emptyResizeQueue.numCapacity == 7, __LINE__);
    assertTrue(emptyResizeQueue.numPush == 0, __LINE__);
    assertTrue(emptyResizeQueue.numPop == 0, __LINE__);
    assertTrue(emptyResizeQueue.buffer != NULL, __LINE__);
    
    startTestSet("Resize Test");
    queue <int> resizeQueue;
    resizeQueue.buffer = new int[5];
    resizeQueue.numCapacity = 5;
    resizeQueue.numPush = 5;
    resizeQueue.numPop = 0;
    resizeQueue.buffer[0] = 7;
    resizeQueue.buffer[1] = 12;
    resizeQueue.buffer[2] = 10;
    resizeQueue.buffer[3] = 9;
    resizeQueue.buffer[4] = 8;
    
    int *theBuffer = resizeQueue.buffer;
    resizeQueue.resize(10);
    assertTrue(theBuffer != resizeQueue.buffer, __LINE__);
    assertTrue(resizeQueue.numCapacity == 10, __LINE__);
    assertTrue(resizeQueue.numPush == 5, __LINE__);
    assertTrue(resizeQueue.numPop == 0, __LINE__);
    assertTrue(resizeQueue.buffer[0] == 7, __LINE__);
    assertTrue(resizeQueue.buffer[1] == 12, __LINE__);
    assertTrue(resizeQueue.buffer[2] == 10, __LINE__);
    assertTrue(resizeQueue.buffer[3] == 9, __LINE__);
    assertTrue(resizeQueue.buffer[4] == 8, __LINE__);
    
    theBuffer = resizeQueue.buffer;
    //reset
    delete [] resizeQueue.buffer;
    resizeQueue.buffer = new int[5];
    theBuffer = resizeQueue.buffer;
    resizeQueue.numCapacity = 5;
    resizeQueue.numPush = 18;
    resizeQueue.numPop = 13;
    resizeQueue.buffer[0] = 7;
    resizeQueue.buffer[1] = 12;
    resizeQueue.buffer[2] = 10;
    resizeQueue.buffer[3] = 9;
    resizeQueue.buffer[4] = 8;
    
    resizeQueue.resize(10);
    assertTrue(theBuffer != resizeQueue.buffer, __LINE__);
    assertTrue(resizeQueue.numCapacity == 10, __LINE__);
    assertTrue(resizeQueue.numPush == 5, __LINE__);
    assertTrue(resizeQueue.numPop == 0, __LINE__);
    assertTrue(resizeQueue.buffer[0] == 9, __LINE__);
    assertTrue(resizeQueue.buffer[1] == 8, __LINE__);
    assertTrue(resizeQueue.buffer[2] == 7, __LINE__);
    assertTrue(resizeQueue.buffer[3] == 12, __LINE__);
    assertTrue(resizeQueue.buffer[4] == 10, __LINE__);
    
    
    
    theBuffer = resizeQueue.buffer;
    resizeQueue.resize(2);
    assertTrue(theBuffer != resizeQueue.buffer, __LINE__);
    assertTrue(resizeQueue.numCapacity == 2, __LINE__);
    assertTrue(resizeQueue.numPush == 2, __LINE__);
    assertTrue(resizeQueue.numPop == 0, __LINE__);
    assertTrue(resizeQueue.buffer[0] == 9, __LINE__);
    assertTrue(resizeQueue.buffer[1] == 8, __LINE__);
    
    theBuffer = resizeQueue.buffer;
    resizeQueue.resize(0);
    assertTrue(resizeQueue.numCapacity == 0, __LINE__);
    assertTrue(resizeQueue.numPush == 0, __LINE__);
    assertTrue(resizeQueue.numPop == 0, __LINE__);
    assertTrue(resizeQueue.buffer == NULL, __LINE__);
    
    /*
     * Testing iHead and iTail
     */
    startTestSet("iHead and iTail");
    queue <int> headTailQueue;
    headTailQueue.buffer = new int[8];
    headTailQueue.numCapacity = 8;
    headTailQueue.numPush = 0;
    headTailQueue.numPop = 0;
    assertTrue(headTailQueue.iHead() == 0, __LINE__);
    assertTrue(headTailQueue.iTail() == -1, __LINE__);
    
    
    headTailQueue.numPush = 1;
    headTailQueue.numPop = 0;
    assertTrue(headTailQueue.iHead() == 0, __LINE__);
    assertTrue(headTailQueue.iTail() == 0, __LINE__);
    
    
    headTailQueue.numPush = 2;
    headTailQueue.numPop = 0;
    assertTrue(headTailQueue.iHead() == 0, __LINE__);
    assertTrue(headTailQueue.iTail() == 1, __LINE__);
    
    
    headTailQueue.numPush = 2;
    headTailQueue.numPop = 1;
    assertTrue(headTailQueue.iHead() == 1, __LINE__);
    assertTrue(headTailQueue.iTail() == 1, __LINE__);
    
    
    headTailQueue.numPush = 2;
    headTailQueue.numPop = 2;
    assertTrue(headTailQueue.iHead() == 2, __LINE__);
    assertTrue(headTailQueue.iTail() == 1, __LINE__);
    
    
    headTailQueue.numPush = 21;
    headTailQueue.numPop = 17;
    assertTrue(headTailQueue.iHead() == 1, __LINE__);
    assertTrue(headTailQueue.iTail() == 4, __LINE__);
    
    
    /*
     * Testing push with resizing
     */
    startTestSet("Push with Resize First Element");
    queue <int> pushResizeQueue;
    pushResizeQueue.push(1);
    assertTrue(pushResizeQueue.numCapacity == 1, __LINE__);
    assertTrue(pushResizeQueue.numPush == 1, __LINE__);
    assertTrue(pushResizeQueue.numPop == 0, __LINE__);
    assertTrue(pushResizeQueue.buffer[0] == 1, __LINE__);
    
    startTestSet("Push with Resize Second Element");
    pushResizeQueue.push(5);
    assertTrue(pushResizeQueue.numCapacity == 2, __LINE__);
    assertTrue(pushResizeQueue.numPush == 2, __LINE__);
    assertTrue(pushResizeQueue.numPop == 0, __LINE__);
    assertTrue(pushResizeQueue.buffer[0] == 1, __LINE__);
    assertTrue(pushResizeQueue.buffer[1] == 5, __LINE__);
    
    startTestSet("Push with Resize Third Element");
    pushResizeQueue.push(10);
    assertTrue(pushResizeQueue.numCapacity == 4, __LINE__);
    assertTrue(pushResizeQueue.numPush == 3, __LINE__);
    assertTrue(pushResizeQueue.numPop == 0, __LINE__);
    assertTrue(pushResizeQueue.buffer[0] == 1, __LINE__);
    assertTrue(pushResizeQueue.buffer[1] == 5, __LINE__);
    assertTrue(pushResizeQueue.buffer[2] == 10, __LINE__);
    
    startTestSet("Push with Resize Fourth Element");
    pushResizeQueue.push(11);
    assertTrue(pushResizeQueue.numCapacity == 4, __LINE__);
    assertTrue(pushResizeQueue.numPush == 4, __LINE__);
    assertTrue(pushResizeQueue.numPop == 0, __LINE__);
    assertTrue(pushResizeQueue.buffer[0] == 1, __LINE__);
    assertTrue(pushResizeQueue.buffer[1] == 5, __LINE__);
    assertTrue(pushResizeQueue.buffer[2] == 10, __LINE__);
    assertTrue(pushResizeQueue.buffer[3] == 11, __LINE__);
    
    startTestSet("Push with Resize Fifth Element");
    pushResizeQueue.push(13);
    assertTrue(pushResizeQueue.numCapacity == 8, __LINE__);
    assertTrue(pushResizeQueue.numPush == 5, __LINE__);
    assertTrue(pushResizeQueue.numPop == 0, __LINE__);
    assertTrue(pushResizeQueue.buffer[0] == 1, __LINE__);
    assertTrue(pushResizeQueue.buffer[1] == 5, __LINE__);
    assertTrue(pushResizeQueue.buffer[2] == 10, __LINE__);
    assertTrue(pushResizeQueue.buffer[3] == 11, __LINE__);
    assertTrue(pushResizeQueue.buffer[4] == 13, __LINE__);
    
    /*
     * Testing Pop
     */
    // startTestSet("Pop");
    // queue<int>popQueue;
    // popQueue.numPop = 0;
    // popQueue.pop();
    // assertTrue(popQueue.numPop == 1, __LINE__);

    startTestSet("Pop");
    queue<int>popQueue;
    popQueue.numPop = 0;
    popQueue.pop();
    assertTrue(popQueue.numPop == 0, __LINE__);
    
    popQueue.numPop = 10000;
    popQueue.pop();
    assertTrue(popQueue.numPop == 10001, __LINE__);
    
    
    /*
     * Testing = operator and copy constructor
     */
    startTestSet("(Full)= Operator");
    queue <int> queueToCopy;
    queueToCopy.numCapacity = 8;
    queueToCopy.numPush = 8;
    queueToCopy.numPop = 0;
    queueToCopy.buffer = new int[queueToCopy.numCapacity];
    for (int i = 0; i < queueToCopy.numCapacity; i++) {
        queueToCopy.buffer[i]=i*i+1;
    }
    queue <int> queueAssignedCopy;
    queueAssignedCopy = queueToCopy;
    assertTrue(queueAssignedCopy.numCapacity == 8, __LINE__);
    assertTrue(queueAssignedCopy.numPush == 8, __LINE__);
    assertTrue(queueAssignedCopy.numPop == 0, __LINE__);
    assertTrue(queueAssignedCopy.buffer != queueToCopy.buffer, __LINE__);
    assertTrue(queueAssignedCopy.buffer[0] == 1, __LINE__);
    assertTrue(queueAssignedCopy.buffer[1] == 2, __LINE__);
    assertTrue(queueAssignedCopy.buffer[2] == 5, __LINE__);
    assertTrue(queueAssignedCopy.buffer[3] == 10, __LINE__);
    assertTrue(queueAssignedCopy.buffer[4] == 17, __LINE__);
    assertTrue(queueAssignedCopy.buffer[5] == 26, __LINE__);
    assertTrue(queueAssignedCopy.buffer[6] == 37, __LINE__);
    assertTrue(queueAssignedCopy.buffer[7] == 50, __LINE__);
    
    startTestSet("(Full) Copy Constructor");
    queue <int> queueCopy(queueToCopy);
    assertTrue(queueCopy.numCapacity == 8, __LINE__);
    assertTrue(queueCopy.numPush == 8, __LINE__);
    assertTrue(queueCopy.numPop == 0, __LINE__);
    assertTrue(queueCopy.buffer != queueToCopy.buffer, __LINE__);
    assertTrue(queueCopy.numCapacity == 8, __LINE__);
    assertTrue(queueCopy.buffer[0] == 1, __LINE__);
    assertTrue(queueCopy.buffer[1] == 2, __LINE__);
    assertTrue(queueCopy.buffer[2] == 5, __LINE__);
    assertTrue(queueCopy.buffer[3] == 10, __LINE__);
    assertTrue(queueCopy.buffer[4] == 17, __LINE__);
    assertTrue(queueCopy.buffer[5] == 26, __LINE__);
    assertTrue(queueCopy.buffer[6] == 37, __LINE__);
    assertTrue(queueCopy.buffer[7] == 50, __LINE__);
    
    /*
     * Resetting to not full queue
     */
    startTestSet("(Not Full) = Operator");
    queueToCopy.numPop = 5;
    
    queue <int> notFullQueueAssignedCopy;
    notFullQueueAssignedCopy = queueToCopy;
    assertTrue(notFullQueueAssignedCopy.numCapacity == 3, __LINE__);
    assertTrue(notFullQueueAssignedCopy.numPush == 3, __LINE__);
    assertTrue(notFullQueueAssignedCopy.numPop == 0, __LINE__);
    assertTrue(notFullQueueAssignedCopy.buffer != queueToCopy.buffer, __LINE__);
    assertTrue(notFullQueueAssignedCopy.buffer[0] == 26, __LINE__);
    assertTrue(notFullQueueAssignedCopy.buffer[1] == 37, __LINE__);
    assertTrue(notFullQueueAssignedCopy.buffer[2] == 50, __LINE__);
    
    startTestSet("(Not Full) Copy Constructor");
    queue <int> notFullQueueCopy(queueToCopy);
    assertTrue(notFullQueueCopy.numCapacity == 3, __LINE__);
    assertTrue(notFullQueueCopy.numPush == 3, __LINE__);
    assertTrue(notFullQueueCopy.numPop == 0, __LINE__);
    assertTrue(notFullQueueCopy.buffer != queueToCopy.buffer, __LINE__);
    assertTrue(notFullQueueCopy.buffer[0] == 26, __LINE__);
    assertTrue(notFullQueueCopy.buffer[1] == 37, __LINE__);
    assertTrue(notFullQueueCopy.buffer[2] == 50, __LINE__);
    
    
    /*
     * Testing back
     */
    startTestSet("Back");
    queue<int> frontBackQueue;
    frontBackQueue.numPush = 0;
    frontBackQueue.numPop = 0;
    frontBackQueue.numCapacity = 16;
    try{
        int& theBackRef = frontBackQueue.back();
        assertTrue(false, __LINE__);
    } catch(const char* message){
        assertTrue(strcmp(message, "Error: asking for back of empty queue.") == 0, __LINE__);
    }
    //simulating use
    frontBackQueue.buffer = new int[16];
    for (int i = 0; i < 16; i++) {
        frontBackQueue.buffer[i] = 2*i;
    }
    frontBackQueue.numPush = 8;
    frontBackQueue.numPop = 4;
    assertTrue(frontBackQueue.back() == 14, __LINE__);
    frontBackQueue.back() = 15;
    assertTrue(frontBackQueue.buffer[7] == 15, __LINE__);
    
    
    //reset queue
    frontBackQueue.buffer = new int[16];
    for (int i = 0; i < 16; i++) {
        frontBackQueue.buffer[i] = 2*i;
    }
    frontBackQueue.numPush = 0;
    frontBackQueue.numPop = 0;
    frontBackQueue.numCapacity = 16;
    /*
     * Testing front
     */
    startTestSet("Front");
    try{
        int& theFrontRef = frontBackQueue.front();
        assertTrue(false, __LINE__);
    } catch(const char* message){
        assertTrue(strcmp(message, "Error: asking for front of empty queue.") == 0, __LINE__);
    }
    
    frontBackQueue.numPush = 8;
    frontBackQueue.numPop = 4;
    
    assertTrue(frontBackQueue.front() == 8, __LINE__);
    frontBackQueue.front() = 9;
    assertTrue(frontBackQueue.buffer[4] == 9, __LINE__);
    
    /*
     * Testing push for Non-Integer Queue Behavior (Just to Make Sure queue Works For Other Types)
     */
    startTestSet("Can Hold Strings");
    queue <std::string> stringQueue;
    
    stringQueue.push("Hello");
    stringQueue.push("It's me");
    stringQueue.push("I was wondering");
    assertTrue(stringQueue.numCapacity == 4, __LINE__);
    assertTrue(stringQueue.buffer[0] == "Hello", __LINE__);
    assertTrue(stringQueue.buffer[1] == "It's me", __LINE__);
    assertTrue(stringQueue.buffer[2] == "I was wondering", __LINE__);
    
    generateTestingReport();
    return 0;
}
