#include "../includes/stack.h"

StackNode *createStackNode(void *val)
{
    StackNode* node = (StackNode*) malloc(sizeof(StackNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void destroyStackNode(StackNode *node, bool recursiveDestroy){
    if(recursiveDestroy && node->next){
        destroyStackNode(node->next, true);
    }
    free(node);
}

Stack *createStackVal(void *value)
{
    return NULL;
}
