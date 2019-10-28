#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    char i[] = "ABCDEFGHI";
    BTREE *tree = init_btree(i, 9);
    tree->print_btree_post(tree);
}