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
  
  nuevoNodo -> data = data;
  nuevoNodo -> prev = list -> current;
  nuevoNodo -> next = list -> current -> next;
  //Node *nodoTemp = list -> current -> next;
  if(list -> current -> next == NULL){
    return;
  }
    
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
  if(list-> current == NULL){
    return NULL;
  }
  if(list -> current -> next == NULL){
    return NULL;
  }
  Node *aux = list -> current;
  void *dato  = aux -> data;

  if (aux == list -> head){
    list -> head = aux -> next;
  }
  else{
    aux -> next -> prev = aux -> prev;
  }
  if(aux == list -> tail){
    list -> tail = aux -> prev;
  }
  else{
    aux -> next -> prev = aux -> prev;
  }
  
  list -> current = aux -> next;
  return dato;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}