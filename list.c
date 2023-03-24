#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* local =(List*) malloc (sizeof(List));
  local -> head = NULL;
  local -> tail = NULL;
  local -> current = NULL;
  
  return local;
}

void * firstList(List * list) {
  list -> current = list -> head;
  
  return NULL; //list -> current -> data;
}

void * nextList(List * list) {
  list -> current = list -> current -> next;
  
  return list -> head -> data;
}

void * lastList(List * list) {
  list -> current = list -> tail;
  
  return list -> tail -> data;
}

void * prevList(List * list) {
  list -> current = list -> current -> prev;
  
  return NULL; //list -> current -> data;
}

void pushFront(List * list, void * data) {
  Node* nuevoNodo = createNode(&data);
  if(list -> head == NULL){
    list -> head = nuevoNodo;
  }
  else{
    nuevoNodo -> next = list -> head;
    list -> head = nuevoNodo;
  }
  list -> current = nuevoNodo;
  list -> tail = list -> current;
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}