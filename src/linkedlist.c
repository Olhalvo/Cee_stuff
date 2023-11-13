#include "../includes/linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

Node* createNode(void* data)
{
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
}

void destroyNode(Node* node){free(node);}

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

void addAtIndex(LinkedList *list, Node *node, int index)
{
    //TODO Emotional Self Harm
}

void addAtTail(LinkedList *list, Node *node)
{
    //TODO Kill Myself metaforically
}

void addValueAtTail(LinkedList *list, void *node)
{
    //TODO BALLS AND SHIT
}

void addValueAtIndex(LinkedList *list, void *val, int index)
{
    //TODO I AM GOING INSANE
}

void removeLinkedList(LinkedList *list, int index)
{
    //TODO follow @well_thatssad on twitter :3
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

Node* linkedListGetAsNode(LinkedList* list, int index)
{
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
    return *temp;
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

