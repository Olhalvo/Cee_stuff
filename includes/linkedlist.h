#ifndef LINKED_LIST_H
#define LINKED_LIST_H
typedef struct _LinkedNode 
{
    void* data;
    struct _LinkedNode* next;
} Node;

typedef struct _LinkedList
{
    Node* tail;
    Node* head;
    int len;
} LinkedList;

Node* createNode(void* data);
void destroyNode(Node* node);

LinkedList* createLinkedList(Node* tail);
void destroyLinkedList(LinkedList* list);
void addAll(LinkedList* list, Node* head);
void addAtIndex(LinkedList * list, Node* node, int index);
void removeLinkedList(LinkedList* list, int index);
void* linkedListGet(LinkedList* list, int index);
void** getAsArray(LinkedList* list);







#endif