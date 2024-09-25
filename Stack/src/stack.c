#include "../includes/stack.h"
#include <stdio.h>


StackNode *createStackNode(void *val){
    StackNode* node = (StackNode*) malloc(sizeof(StackNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void destroyStackNode(StackNode *node, bool recursiveDestroy){
    if(node == NULL){
        fprintf(stderr, "Can't destroy NULL node");
        return;
    } 
    if(recursiveDestroy && node->next){
        destroyStackNode(node->next, true);
    }
    free(node);
}

Stack *createStack(StackNode *head){
    if(head == NULL){
        fprintf(stderr,"Stack head can't be null\n");
        return NULL;
    }
    Stack* stack =  (Stack*)malloc(sizeof(Stack));
    int length = 1;
    StackNode *node = head;
    while (node->next)
    {
        length++;
        node = node->next; 
    }
    stack->head = head;
    stack->length = length;
    return stack;
}

Stack *createStackVal(void *value){
    StackNode *node = createStackNode(value);
    return createStack(node);
}

void *stackPop(Stack *stack)
{
    if(stackIsEmpty(stack)){
        fprintf(stderr, "Can't pop empty stack\n");
        exit(1);
    }
    StackNode* node = stack->head->next;
    void *val = stack->head->val;
    destroyStackNode(stack->head, false);
    if(node == NULL){
        stack->head = NULL;
        stack->length = 0;
        return val;
    }
    stack->head = node;
    stack->length--;
    return val;
}

void *stackPeek(Stack *stack){
    if(stackIsEmpty(stack)){
        fprintf(stderr,"Stack is empty\n");
        return 0;
    }
    return stack->head->val;
}

void stackPut(Stack *stack, void *value){
    StackNode *node = createStackNode(value);
    if(!stackIsEmpty(stack)){
        node->next = stack->head;
    }
    stack->head = node;
    stack->length++;
}

void destroyStack(Stack *stack)
{
    if(stack == NULL){
        fprintf(stderr, "Can't destroy null stack\n");
        return;
    }
    if(!stackIsEmpty(stack)){
        destroyStackNode(stack->head, true);
        stack->length = 0;
    }
    free(stack);
}

bool stackIsEmpty(Stack *stack)
{
    if((stack->head == NULL && stack->length != 0) || stack->length < 0){
        fprintf(stderr, "Crtitical stack memory error, exiting\n");
        exit(1);
    }
    return (stack->length == 0);
}
