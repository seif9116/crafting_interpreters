#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct DoublyLinkedNode {
    struct DoublyLinkedNode* next;
    struct DoublyLinkedNode* prev;
    char* data;
} DoublyLinkedNode;

typedef struct {
    DoublyLinkedNode* head;
    DoublyLinkedNode* tail;
} DoublyLinkedList;

void freeList(DoublyLinkedList* list);
DoublyLinkedList* initList();
DoublyLinkedNode* findDoubly(DoublyLinkedList* list, const char* s1);
DoublyLinkedNode* initNode(const char* s1);
void insertAfter(DoublyLinkedList* list, const char* s1, const char* s2);
void insertBefore(DoublyLinkedList* list, const char* s1, const char* s2);
void insertBeginning(DoublyLinkedList* list, const char* s1);
void insertEnd(DoublyLinkedList* list, const char* s1);
void deleteDoubly(char* s, DoublyLinkedList* list);
