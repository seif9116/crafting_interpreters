#include "doublyLinked.h"

DoublyLinkedList* initList(){
    DoublyLinkedList* list = malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}
void freeNode(DoublyLinkedNode* node){
    free(node->data);
    free(node);
}

void freeList(DoublyLinkedList* list){
    DoublyLinkedNode* curr = list->head;
    DoublyLinkedNode* nextNode;

    while(curr!= NULL){
        nextNode = curr->next;
        freeNode(curr);
        curr = nextNode;
    }
    free(list);

}

DoublyLinkedNode* findDoubly(DoublyLinkedList* list, const char* s1){
    DoublyLinkedNode* curr = list->head;
    while (curr != NULL){
        if (strcmp(curr->data, s1)==0){
            return curr; 
        } else {
            curr = curr->next;
        }
    }
    fprintf(stderr, "Error no string in list");
    exit(1);
}
DoublyLinkedNode* initNode(const char* s1){
    DoublyLinkedNode* newNode = malloc(sizeof(DoublyLinkedNode));
    if (newNode == NULL){
        fprintf(stderr, "Error alloc memory");
        exit(2);
    }
    newNode->data = malloc(strlen(s1)+1);
    if (newNode->data == NULL){
        fprintf(stderr, "Error alloc memory");
        exit(2);
    }
    strcpy(newNode->data, s1);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAfter(DoublyLinkedList* list, const char* s1, const char* s2){
    DoublyLinkedNode* node = findDoubly(list, s1);
    DoublyLinkedNode* newNode = initNode(s2);
    newNode->prev = node; 
    if (node->next == NULL){
        list->tail = newNode;
    } else {
        newNode->next = node->next;
        node->next->prev = newNode;
    }
    node->next = newNode;
}

void insertBefore(DoublyLinkedList* list, const char* s1, const char* s2){
    DoublyLinkedNode* node = findDoubly(list, s1);
    DoublyLinkedNode* newNode = initNode(s2);
    if (node->prev == NULL){
        list->head = newNode;
    } else {
        newNode->prev = node->prev;
        node->prev->next = newNode;
    }
    node->prev = newNode;
    newNode->next = node;
}
void insertBeginning(DoublyLinkedList* list, const char* s1){
    if (list->head == NULL){
        DoublyLinkedNode* newNode = initNode(s1);
        list->head = newNode;
        list->tail = newNode;
    } else {
        insertBefore(list, list->head->data, s1);
    }
}

void insertEnd(DoublyLinkedList* list, const char* s1){
    if (list->tail==NULL){
        insertBeginning(list, s1);
    } else {
        insertAfter(list, list->tail->data, s1);
    }
}


void deleteDoubly(char* s, DoublyLinkedList* list){
    DoublyLinkedNode* node = findDoubly(list, s);
    if (node->prev == NULL){
        list->head = node->next;
        if (list->head != NULL){
            list->head->prev = NULL;
        }
    } else {
        node->prev->next = node->next;
    }

    if (node->next==NULL){
        list->tail = node->prev;

    } else {
        node->next->prev = node->prev;
    }
    freeNode(node);
}
