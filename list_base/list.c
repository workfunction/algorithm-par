#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void insert_head(LIST* list, void *value) {
    NODE *new = (NODE*)malloc(sizeof(NODE));
    new->value = value;
    new->next = list->head;
    list->size++;
    list->head = new;
}

void insert_tail(LIST* list, void *value) {
    if (list->head == NULL) {
        insert_head(list, value);
        return;
    }
    NODE *tail = list->head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    NODE *new = (NODE*)malloc(sizeof(NODE));
    new->value = value;
    new->next = NULL;
    list->size++;
    tail->next = new;
}

NODE* remove_head(LIST* list) {
    if (list->size == 0) {
        return NULL;
    }
    NODE *removed = list->head;
    list->head = list->head->next;
    list->size--;

    return removed;
}

NODE* find_node(LIST* list, void *value) {
    NODE *node = list->head;
    while (node != NULL && GET_INT(node->value) != GET_INT(value)) {
        node = node->next;
    }
    return node;
}

void remove_node(LIST* list, void *value) {

}

void split_list(NODE* source, NODE** front_ref, NODE** back_ref) {
    NODE* fast;
    NODE* slow;
    
    slow = source;
    fast = source->next;

    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    }

    *front_ref = source;
    *back_ref = slow->next;
    slow->next = NULL;
}

NODE* sort_merge(NODE* a, NODE* b) {
    NODE* result = NULL; 
  
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    if (GET_INT(a->value) <= GET_INT(b->value)) { 
        result = a; 
        result->next = sort_merge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = sort_merge(a, b->next); 
    } 
    return (result); 
}

void merge_sort(NODE** head_ref) {
    NODE* head = *head_ref;
    NODE* a;
    NODE* b;

    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    }

    split_list(head, &a, &b);

    merge_sort(&a);
    merge_sort(&b);

    *head_ref = sort_merge(a, b);
}

void sort_list(LIST* list, int method) {
    switch(method)
    {
    case 0:
        merge_sort(&(list->head));
        break;
    case 1:
        //merge_sort(&(list->head));
        break;
    default:
        break;
    }
    
}

void print_list (LIST* list) {
    NODE* curr = list->head;
    while (curr != NULL){
        printf("%d\t ", GET_INT(curr->value));
        curr = curr->next;
    }
}

LIST* init_list(void) {
    LIST *list = (LIST*)malloc(sizeof(LIST));
    list->head = NULL;
    list->size = 0;
    list->insert_head = &insert_head;
    list->insert_tail = &insert_tail;
    list->remove_head = &remove_head;
    list->find_node = &find_node;
    list->remove_node = &remove_node;
    list->sort_list = &sort_list;
    list->print_list = &print_list;
    return list;
}