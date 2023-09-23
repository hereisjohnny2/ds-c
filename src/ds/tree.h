#ifndef TREE_H
#define TREE_H

#include "linked_list.h"
#include <stdbool.h>

typedef enum {
  TREE_PRE,
  TREE_IN,
  TREE_POS,
} TREE_ORDER;
typedef struct myTreeNode TreeNode;
typedef struct myTree Tree;

Tree *tree_new();
TreeNode *tree_node_new(int value);
bool tree_set_node(TreeNode *parent, TreeNode *child, int pos);
void tree_order(TreeNode *curr, List *path, TREE_ORDER order);
bool breadth_first_search(TreeNode *curr, int value);
bool tree_compare(TreeNode *a, TreeNode *b);
void tree_free(Tree *tree);
void tree_node_free(TreeNode *node);

#endif // TREE_H
