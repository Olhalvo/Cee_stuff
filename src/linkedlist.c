#include "../includes/linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

Node* createNode(void* data)
{
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
}

void destroyNode(Node* node){
    free(node);
}

LinkedList* createLinkedList(Node* tail)
{
    LinkedList* list = malloc(sizeof(LinkedList));
    Node** temp = &tail;
    int len = 1;
    while((*temp)->next != NULL)
    {
        len++;
        temp = &((*temp)->next);
    }
    list->tail = tail;
    list->head = *temp;
    list->len = len;
    return list;
}

LinkedList* createLinkedListVal(void* val)
{
    LinkedList* list = malloc(sizeof(LinkedList));
    list->tail = createNode(val);
    list->head = list->tail;
    list->len = 1;
    return list;
}

void destroyLinkedList(LinkedList* list) {
    Node* temp = list->tail;
    while (temp->next != NULL)
    {
        Node* last = temp;
        temp = temp->next;
        destroyNode(last);
    }
    destroyNode(temp);
    free(list);
}

void linkedListAdd(LinkedList* list, void* value)
{
    list->head->next = createNode(value);
    list->head = list->head->next;
    list->len++;
}

void addAll(LinkedList* list, Node* tail)
{
    int addLen = 1;
    list->head->next = tail;
    Node** temp = &tail;
    while ((*temp)->next != NULL)
    {
        addLen++;
        temp = &((*temp)->next);
    }
    list->head = *(temp);
    list->len+= addLen;
}

void addAtTail(LinkedList *list, Node *node)
{
    int addLen = 1;
    Node** temp = &node;
    while ((*temp)->next != NULL)
    {
        addLen++;
        temp = &((*temp)->next);
    }
    (*temp)->next = list->tail;
    list->tail = node;
    list->len = addLen + list->len;
}

void addValueAtTail(LinkedList *list, void *val)
{
    Node *temp = createNode(val);
    temp->next = list->tail;
    list->tail = temp;
    list->len++;
}

void addValueAtIndex(LinkedList *list, void *val, int index)
{   	
    if(index == 0){
        addValueAtTail(list, val);
        return;
    }
    Node **node = linkedListGetAsNode(list, index-1);
    Node *add = createNode(val);
    add->next = (*node)->next;
    (*node)->next = add;
    list->len++;    
}

void addAtIndex(LinkedList *list, Node *node, int index)
{   
    if(index == 0){
        addAtTail(list, node);
        return;
    }
    int addLen = 1;
    Node** nodeAtIndex = linkedListGetAsNode(list, index-1);
    Node** temp = &node;
    while((*temp)->next != NULL){
        addLen++;
        temp = &((*temp)->next);
    }
    (*temp)->next = (*nodeAtIndex)->next;
    (*nodeAtIndex)->next = node;
    list->len += addLen;
}

void removeLinkedList(LinkedList *list, int index)
{
    if(index == list->len-1){
        popLinkedList(list);
        return;
    }
    Node** previous = linkedListGetAsNode(list, index-1);
    Node* node = (*previous)->next;
    (*previous)->next = node->next;
    destroyNode(node);
    list->len--;   
}

void popLinkedList(LinkedList *list)
{
    destroyNode(list->head);
    list->len--;
    Node** prev = linkedListGetAsNode(list, list->len-1);
    list->head = *prev;
    list->head->next = NULL;
}

void *linkedListGet(LinkedList *list, int index)
{
    if(index >= list->len)
    {
        fprintf(stderr,"List index out of bounds: %d\n", index);
        destroyLinkedList(list);
        exit(-1);
    }
    Node* temp = list->tail;
    for(int i = 0; i < index; i++)
    {
        temp = temp->next;
        if(temp==NULL){
            fprintf(stderr, "List index iterates through NULL node, index: %d", index);
            exit(-1);
        }
    }
    return temp->data;
}

Node** linkedListGetAsNode(LinkedList* list, int index)
{
    if(index == 0){
        return &(list->tail);
    }
    if(index >= list->len){
        fprintf(stderr,"List index out of bounds: %d\n", index);
        destroyLinkedList(list);
        exit(-1);
    }
    Node** temp = &(list->tail);
    for(int i = 0; i < index; i++){
        temp = &((*temp)->next);
        if(*temp==NULL){
            fprintf(stderr, "List index iterates through NULL node, index: %d", index);
            exit(-1);
        }
    }
    return temp;
}

void** getAsArray(LinkedList* list)
{
    void** arr = (void**) malloc(sizeof(void*) * list->len); 
    
    if(list->len == 1)
    {
        arr[0] = list->tail->data;
        return arr;
    }
    
    int index = 0;
    Node* temp = list->tail;
    
    while(temp->next != NULL)
    {
        arr[index] = temp->data;
        temp = temp->next;
        index++;
    }
    
    arr[index] = temp->data;
    
    return arr;
}

