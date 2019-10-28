#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "tree.h"

TREE_NODE* new_node(char data, int key, TREE_NODE* l_child, TREE_NODE* r_child, TREE_NODE* parent) {
    TREE_NODE* node = (TREE_NODE*)malloc(sizeof(TREE_NODE));
    node->data = data;
    node->key = key;
    node->left_child = l_child;
    node->right_child = r_child;
    node->parent = parent;
    return node;
}

void _btree_post(TREE_NODE *curr) {
    if(curr) {
        _btree_post(curr->left_child);
        _btree_post(curr->right_child);
        printf("%c  ", curr->data);
    }
}

void print_btree_post(BTREE *tree) {
    _btree_post(tree->root);
}

BTREE* init_btree(char* input, unsigned int size){
    if (!size) {
        return NULL;
    }
    BTREE* tree = (BTREE*)malloc(sizeof(BTREE));
    TREE_NODE* root = new_node(input[0], 0, NULL, NULL, NULL);

    tree->root = root;
    tree->print_btree_post = &print_btree_post;

    printf("Add root '%c'\n", root->data);

    LIST* queue = init_list();
    TREE_NODE* curr = root;
    for (int i = 1; i < size; i++) {
        if (input[i] >= 65 && input[i] <= 90) {
            TREE_NODE* node = new_node(input[i], 0, NULL, NULL, curr);
            if (i%2) {
                curr->left_child = node;
                printf("Add l child '%c' of '%c'\n", node->data, curr->data);
            } else {
                curr->right_child = node;
                printf("Add r child '%c' of '%c'\n", node->data, curr->data);
            }
            queue->insert_tail(queue, node);
        }
        if (i%2 == 0) {
            curr = (TREE_NODE*)(queue->remove_head(queue)->value);
        }
    }
    return tree;
}