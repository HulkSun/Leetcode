/*
* Author: hulk
* Date:2017-04-19 20:03:13
*/
/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue 
-- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. 
You may simulate a queue by using a list or deque (double-ended queue), 
as long as you use only standard operations of a queue.
You may assume that all operations are valid 
(for example, no pop or top operations will be called on an empty stack).*/

typedef struct {
	int top;
	int* queue;
    
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
    MyStack* mystack = (MyStack*)malloc(sizeof(MyStack));
    mystack -> top = -1;
    mystack -> queue = (int*)malloc(sizeof(int)*maxSize);
    return mystack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj-> queue[++(obj -> top)] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    return obj-> queue[(obj -> top)--] ;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj-> queue[(obj -> top)] ;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj -> top == -1) return true;
    else return false;
}

void myStackFree(MyStack* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * struct MyStack* obj = myStackCreate(maxSize);
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */