#include <stdio.h>
#include "../includes/linkedlist.h"

int main(){
    Node* first = createNode((void*) 5);
    Node* second = createNode((void*) 6);
    Node* third = createNode((void*) 7);
    first->next = second;
    second->next = third;
    LinkedList* list = createLinkedList(first);
    printf("list: %d, %d, %d \n", list->tail->data, list->tail->next->data, list->head->data);
    printf("node iteration: %d, %d; %d \n",first->data, first->next->data, first->next->next->data);
    printf("node referencing: %d, %d, %d \n", first->data, second->data, third->data);
    destroyLinkedList(list);
}
