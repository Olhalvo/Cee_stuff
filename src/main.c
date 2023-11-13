#include <stdio.h>
#include "../includes/linkedlist.h"

int main(){
    LinkedList* list = createLinkedListVal(6);
    linkedListAdd(list, 7);
    linkedListAdd(list, 8);
    void** arr = getAsArray(list);
    for(int i = 0; i < list->len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    destroyLinkedList(list);
}
