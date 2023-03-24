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
  if(list -> head == NULL){
    return NULL;
  }
  list -> current = list -> head;
  
  return list -> current -> data;
}

void * nextList(List * list) {
  if(list -> current == NULL){
    return NULL;
  }
  if(list -> current ->next == NULL){
    return NULL;
  }
  list -> current = list -> current -> next;
  
  return list -> current -> data;
}

void * lastList(List * list) {
  if(list -> current == NULL){
    return NULL;
  }
  if(list -> tail ==NULL){
    return NULL;
  }
  list -> current = list -> tail;
  
  return list -> tail -> data;
}

void * prevList(List * list) {
  if(list -> current == NULL){
    return NULL;
  }
  if(list -> current ->prev == NULL){
    return NULL;
  }
  list -> current = list -> current -> prev;
  
  return list -> current -> data;
}

void pushFront(List * list, void * data) {
  Node* nuevoNodo = createNode(data);
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
  Node* nuevoNodo = createNode(data);
  if(list -> current == NULL){
    return;
  }
  //Node *nodoTemp = list -> current -> next;
  else{
    list -> current -> next -> prev = nuevoNodo;
  }
  list -> current -> next = nuevoNodo;
  if (list->tail == list->current) {
    list->tail = nuevoNodo;
    
  }
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
  Node *aux = list -> head;
  aux -> next = list -> current -> next;
  while( aux -> next != list -> current)
    aux = aux->next;
  
  return list -> current -> data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}