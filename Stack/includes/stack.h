#ifndef STACK_H
#define STACK_H
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct _StackNode
{
    void* val;
    struct _StackNode* next;
} StackNode;

StackNode* createStackNode(void* val);
void destroyStackNode(StackNode* node, bool recursiveDestroy);

typedef struct _Stack {
    int lenght;
    StackNode* head;
} Stack;

/**
 * @brief Creates stack and automatically calculates lenght from a given stack node
 * @author Olhalvo
 * @date 19/09/2024
 * @param StackNode* head Head of the given stack, IE. the first one to be popped when stackPop() is called on the given stack
 * @return Pointer to the created Stack structure
 */
Stack* createStack(StackNode* head);
/**
 * @brief Creates a stack node from the given value and creates a stack with it as head
 * @author Olhalvo
 * @date 19/09/2024
 * @param void* value - Value for the given stack head
 * @return Pointer to the created Stack structure
 */
Stack* createStackVal(void* value);
void* stackPop(Stack* stack);
void* stackPeek(Stack* stack);
void  stackPut(Stack* stack, void* value);
bool  stackIsEmpty(Stack* stack);
void destroyStack(Stack* stack);


#endif //STACK_H
