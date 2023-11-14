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
LinkedList* createLinkedListVal(void* val);
void destroyLinkedList(LinkedList* list);
void linkedListAdd(LinkedList* list, void* value);
void addAll(LinkedList* list, Node* tail);
void addAtIndex(LinkedList * list, Node* node, int index);
void addAtTail(LinkedList* list, Node* node);
void addValueAtTail(LinkedList* list, void* val);
void addValueAtIndex(LinkedList * list, void* val, int index);
void removeLinkedList(LinkedList* list, int index);
void popLinkedList(LinkedList* list);
void* linkedListGet(LinkedList* list, int index);
Node** linkedListGetAsNode(LinkedList* list, int index);
void** getAsArray(LinkedList* list);







#endif