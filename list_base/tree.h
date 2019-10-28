typedef struct tnode_t TREE_NODE;
typedef struct btree_t BTREE;

struct tnode_t
{
    char data;
    int key;
    TREE_NODE *left_child;
    TREE_NODE *right_child;
    TREE_NODE *parent;
};

struct btree_t
{
    TREE_NODE *root;
    void (*print_btree_post)(BTREE *tree);
    /*
    void (*insert_head)(BTREE* tree, int value);
    void (*insert_tail)(BTREE* tree, int value);
    NODE*(*remove_head)(BTREE* tree);
    NODE*(*find_node)  (BTREE* tree, int value);
    void (*remove_node)(BTREE* tree, int value);
    void (*sort_list)  (BTREE* tree);
    void (*print_list) (BTREE* tree);
    */
};

BTREE* init_btree(char* input, unsigned int size);