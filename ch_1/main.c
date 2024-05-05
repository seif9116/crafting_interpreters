#include "doublyLinked.h"

int main(){
    DoublyLinkedList* list = initList();
    insertEnd(list, "hello");
    assert(strcmp(list->head->data, "hello")==0);
    assert(strcmp(list->tail->data, "hello")==0);
    insertBeginning(list, "world");
    assert(strcmp(list->head->data, "world")==0);
    assert(strcmp(list->tail->data, "hello")==0);
    assert(strcmp(list->head->next->data, "hello")==0);
    deleteDoubly("world", list);
    assert(strcmp(list->head->data, "hello")==0);
    assert(strcmp(list->tail->data, "hello")==0);
    insertEnd(list, "world");
    assert(strcmp(list->head->data,"hello")==0);
    assert(strcmp(list->tail->data, "world")==0);
    free(list);
}
