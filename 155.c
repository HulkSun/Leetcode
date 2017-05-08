/*
* Author: hulk
* Date: 2017-05-08 11:14:46
*/

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.*/
int min = INT_MAX;

typedef struct {
	int* val;
	int top;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    int* val = (int*)malloc(sizeof(int)*maxSize);
    MinStack* minStack = (MinStack*)malloc(sizeof(MinStack));
    minStack -> top = -1;
    minStack -> val = val;
    return minStack;
}

void minStackPush(MinStack* obj, int x) {
    if(x <= min)
    {
        obj -> val[++ (obj -> top)] = min;
        min = x;
    }
    obj -> val[++ (obj -> top)] = x;
}

void minStackPop(MinStack* obj) {
    if(obj -> val[obj -> top] == min)
    {
        min = obj -> val[--(obj -> top)];
    }
    obj -> top --;
}

int minStackTop(MinStack* obj) {
	return obj -> val[(obj -> top)];    
}

int minStackGetMin(MinStack* obj) {
    return min;
}

void minStackFree(MinStack* obj) {
    min = INT_MAX;
    free(obj -> val);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */