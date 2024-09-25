#include "../includes/stack.h"
#include <stdio.h>

int sum(Stack *stack, int n){
    if(n <= 0){
        fprintf(stderr,"can't sum for n<=0\n");
        return 0;
    }
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum = sum + stackPop(stack);
    }
    return sum;
}

int prod(Stack *stack, int n){
    if(n < 2){
        fprintf(stderr,"can't prod for n<2\n");
        return 0;
    }
    int prod = 1;
    for(int i = 0; i<n; i++){
        prod = prod * (int) stackPop(stack);
    }
    return prod;
}

int main(int argc, char const *argv[])
{
    StackNode *node = createStackNode(1);
    node->next = createStackNode(2);
    node->next->next = createStackNode(3);
    Stack *stack = createStack(node);
    stackPut(stack, 5);
    printf("%d\n", sum(stack, 4));
    for(int i = 5; i > 0; i--){
        stackPut(stack, i);
    }
    printf("%d\n", prod(stack, 5));
    destroyStack(stack);
}
