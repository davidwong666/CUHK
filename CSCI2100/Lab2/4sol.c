/*
I, Wong Kwok Kam, am submitting the assignment for
an individual project.
I declare that the assignment here submitted is original except for
source material explicitly acknowledged, the piece of work, or a part
of the piece of work has not been submitted for more than one purpose
(i.e. to satisfy the requirements in two different courses) without
declaration. I also acknowledge that I am aware of University policy
and regulations on honesty in academic work, and of the disciplinary
guidelines and procedures applicable to breaches of such policy and
regulations, as contained in the University website
http://www.cuhk.edu.hk/policy/academichonesty/.
It is also understood that assignments without a properly signed
declaration by the student concerned will not be graded by the
teacher(s).
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF -1

// data structure of the stack, which is implemented by an array "arr"
struct stack {
    int capacity;
    int size;
    int* arr;
};

typedef struct stack* StackADT;

// Description: Create a stack with the capacity xxx
// Usage: StackADT yourStack = CreateStack(capacity)
StackADT CreateStack(int capacity) {
    StackADT s = (StackADT) malloc(sizeof(struct stack));
    s->arr = (int*) malloc(capacity * sizeof(int));
    s->capacity = capacity;
    s->size = 0;
    return s;
}

// Description: Return 1 if the stack is empty, and 0 otherwise
// Usage: int result = IsEmpty(yourStack);
int IsEmpty(StackADT s) {
    return s->size == 0;
}

// Description: Return 1 if the stack is full, and 0 otherwise
// Usage: int result = IsFull(yourStack);
int IsFull(StackADT s) {
    return s->size == s->capacity;
}

// Description: Push a value into the stack
// Usage: Push(yourStack, value);
// Tips: If it is full, do nothing.
void Push(StackADT s, int value) {
    // write your code here
    if(!IsFull(s)){
        s->arr[s->size] = value;
        s->size++;
    }
}

// Description: Pop a value from the stack
// Usage: Pop(yourStack);
// Tips: If it is empty, do nothing.
void Pop(StackADT s) {
    // write your code here
    if(!IsEmpty(s)){
        s->size--;
    }
}

// Description: Obtain the top value from the stack
// Usage: int topValue = Top(yourStack);
// Tips: Your should check if it is empty. If empty, you should return INF.
int Top(StackADT s) {
    // write your code here
    if(IsEmpty(s)){
        return INF;
    }
    else{
        return s->arr[s->size-1];
    }
}

// Description: Calulate the number of unblocked buildings that a new item can see
// Usage: int numOfBuildings = DoSomething(yourStack, newValue);
// Tips: Implement it with the stack. 
// Tips: You may push every item into the stack. 
// Tips: Before you push a new item into the stack, you may do something in order to maintain certain property of this stack.
// Tips: This property should help a new item calculate the number of unblocked buildings it can see.
int DoSomething(StackADT s, int value) {
    // write your code here
    int caseA = 1;
    int blockingheight, count = 0;
    static int maxheight, prevpos = 0;
    // base case for the first building
    if(IsEmpty(s)){
        maxheight = value;
        prevpos = 1;
        Push(s, value);
        return 0;
    }
    StackADT temp = CreateStack(s->capacity);
    if(value > maxheight){
        maxheight = value;
        Push(s, value);
        prevpos = s->size;
        count = 0;
        return s->size-1;
    }
    else if(value == maxheight){
        count = 0;
        int pos = prevpos; // create pos for return
        Push(s, value);
        prevpos = s->size; // update prevpos
        return s->size - pos;
    }
    //for value < maxheight
    else{
        while(!IsEmpty(s)){
            if(caseA == 1){
                if(value > Top(s)){
                    blockingheight = value;
                    count++;
                    Push(temp, Top(s));
                    Pop(s);
                }
                // if value <= Top(s)
                else{
                    blockingheight = Top(s);
                    caseA = 2;
                    count++;
                    Push(temp, Top(s));
                    Pop(s);
                }
            }
            // if not caseA == 1
            else{
                if(Top(s) <= blockingheight){
                    if(blockingheight == maxheight) break;
                    Push(temp, Top(s));
                    Pop(s);
                }
                // if Top(s) > blockingheight
                else{
                    blockingheight = Top(s); //update the blocking height
                    if(blockingheight == maxheight) {count++; break;}
                    count++;
                    Push(temp, Top(s));
                    Pop(s);
                }
            }
        }
    }
    while(!IsEmpty(temp)){
        Push(s, Top(temp));
        Pop(temp);
    }
    Push(s, value);
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    StackADT s = CreateStack(n);

    int value;
    for(int i=0; i<n; i++) {
        scanf("%d", &value);
        printf("%d\n", DoSomething(s, value));
    }
}