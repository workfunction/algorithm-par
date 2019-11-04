#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    LIST* list = init_list();
    int input[100];
    for (int i = 0; i < 100; i++) {
        input[i] = rand()%100;
        list->insert_head(list, &input[i]);
    }
    list->print_list(list);
    list->remove_head(list);
    printf("\n\n");
    list->print_list(list);
    printf("\n\n");
    int i = 5;
    printf("%d", GET_INT(list->find_node(list, &i)->value));
    printf("\n\n");
    i = 200;
    printf("%d", list->find_node(list, &i));
    printf("\n\n");
    list->sort_list(list, 0);
    list->print_list(list);
    printf("\n\n");
}