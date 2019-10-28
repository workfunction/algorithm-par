CC ?= gcc
CFLAGS ?= -std=gnu99 -g

SRC_LIST := list.c list.h
SRC_TREE := tree.c tree.h

EXEC := test_list test_tree

all: $(EXEC)

test_list: test_list.c $(SRC_LIST)
	$(CC) $(CFLAGS) $^

test_tree: test_tree.c $(SRC_LIST) $(SRC_TREE)
	$(CC) $(CFLAGS) $^