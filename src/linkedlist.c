#include "../includes/linkedlist.h"
#include <stdlib.h>

Node* createNode(void * data){
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
}

void destroyNode(Node* node){
    free(node);
}

LinkedList* createLinkedList(Node* tail){
    LinkedList* list = malloc(sizeof(LinkedList));
    Node* temp = tail;
    int len = 1;
    while(temp->next != NULL){
        len++;
        temp = temp->next;
    }
    Node* head = temp;
    list->tail = tail;
    list->head = head;
    list->len = len;
    return list;
}

void destroyLinkedList(LinkedList* list) {
    Node* temp = list->tail;
    while (temp->next != NULL){
        Node* last = temp;
        temp = temp->next;
        destroyNode(last);
    }
    destroyNode(temp);
    free(list);
}