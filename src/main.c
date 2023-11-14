#include <stdio.h>
#include "../includes/linkedlist.h"

int main(){
    LinkedList* list = createLinkedListVal(6);
    linkedListAdd(list, 7);
    linkedListAdd(list, 8);
    Node * node = createNode(9);
    node->next = createNode(10);
    node->next->next = createNode(11);
    addValueAtIndex(list, 5, 0);
    addAtIndex(list, node, 2);
    removeLinkedList(list, 1);
    popLinkedList(list);
    void** arr = getAsArray(list);
    printf("Array:[");
    for(int i = 0; i < list->len; i++){
        printf("%d,", arr[i]);
    }
    printf("]\n");
    destroyLinkedList(list);
}