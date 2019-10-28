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
    while (node != NULL && *(int*)(node->value) != *(int*)value) {
        node = node->next;
    }
    return node;
}

void remove_node(LIST* list, void *value) {

}

NODE* visit_node(LIST* list, int index) {
    NODE* curr = list->head;
    while (index--) {
        curr = curr->next;
    }
    return curr;
}

void merge_sort(NODE* head, int front, int end) {

}

void sort_list(LIST* list) {
    merge_sort(list->head, 0, list->size-1);
}

void print_list (LIST* list) {
    NODE* curr = list->head;
    while (curr != NULL){
        printf("%d  ", *(int*)(curr->value));
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