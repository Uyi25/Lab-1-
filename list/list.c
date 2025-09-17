// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* mylist = (list_t *) malloc(sizeof(list_t)); 
  mylist->head = NULL;
  return mylist;   
}


void list_free(list_t *l) {
  if (!l) return;
  node_t *curr = l->head;
  while (curr != NULL) {
    node_t *temp = curr;
    curr = curr->next;
    free(temp);
  }
  free(l);
}


void list_print(list_t *l) {
  if (!l || !l->head) {
    printf("NULL\n");
    return;
  }
  node_t *curr = l->head;
  while (curr != NULL) {
    printf("%d->", curr->value);
    curr = curr->next;
  }
  printf("NULL\n");
}


char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 10024);
  char tbuf[20];

	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) {
  int count = 0;
  node_t *curr = l->head;
  while (curr != NULL) {
    count++;
    curr = curr->next;
  }
  return count;
}


void list_add_to_back(list_t *l, elem value) {
  node_t *newNode = getNode(value);
  if (l->head == NULL) {
    l->head = newNode;
    return;
  }
  node_t *curr = l->head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = newNode;
}

void list_add_to_front(list_t *l, elem value) {
     node_t *cur_node = (node_t *) getNode(value);

     /* Insert to front */
     node_t *head = l->head;  // get head of list

     cur_node->next = head;
     l->head = cur_node;
}

node_t * getNode(elem value) {
  node_t *mynode;

  mynode = (node_t *) malloc(sizeof(node_t));
  mynode->value = value;
  mynode->next = NULL;

  return mynode;
}

// 1-based indexing version

void list_add_at_index(list_t *l, elem value, int index) {
  if (index <= 1 || !l->head) { 
    list_add_to_front(l, value);
    return;
  }
  node_t *curr = l->head;
  for (int i = 1; curr && i < index - 1; i++) curr = curr->next;

  if (!curr || !curr->next) { // index >= length+1
    list_add_to_back(l, value);
    return;
  }

  node_t *n = getNode(value);
  n->next = curr->next;
  curr->next = n;
}

elem list_remove_at_index(list_t *l, int index) {
  if (!l->head) return -1;
  if (index <= 1) return list_remove_from_front(l);

  node_t *curr = l->head;
  for (int i = 1; curr && curr->next && i < index - 1; i++) curr = curr->next;

  if (!curr || !curr->next) return list_remove_from_back(l);

  node_t *tmp = curr->next;
  elem val = tmp->value;
  curr->next = tmp->next;
  free(tmp);
  return val;
}



elem list_remove_from_back(list_t *l) {
  if (l->head == NULL) return -1;
  node_t *curr = l->head;
  if (curr->next == NULL) {
    elem val = curr->value;
    free(curr);
    l->head = NULL;
    return val;
  }
  while (curr->next->next != NULL) {
    curr = curr->next;
  }
  elem val = curr->next->value;
  free(curr->next);
  curr->next = NULL;
  return val;
}

elem list_remove_from_front(list_t *l) {
  if (l->head == NULL) return -1;
  node_t *temp = l->head;
  elem val = temp->value;
  l->head = temp->next;
  free(temp);
  return val;
}

elem list_remove_at_index(list_t *l, int index) {
  if (l->head == NULL) return -1;
  if (index <= 1) return list_remove_from_front(l);

  node_t *curr = l->head;
  int pos = 1;
  while (curr->next != NULL && pos < index - 1) {
    curr = curr->next;
    pos++;
  }
  if (curr->next == NULL) {
    return list_remove_from_back(l);
  }
  node_t *temp = curr->next;
  elem val = temp->value;
  curr->next = temp->next;
  free(temp);
  return val;
}


bool list_is_in(list_t *l, elem value) { return false; }
elem list_get_elem_at(list_t *l, int index) { return -1; }
int list_get_index_of(list_t *l, elem value) { return -1; }

