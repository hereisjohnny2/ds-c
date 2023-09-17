#include "tree.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct myTreeNode {
  int value;
  struct myTreeNode *left;
  struct myTreeNode *right;
} TreeNode;

typedef struct myTree {
  TreeNode *head;
} Tree;

Tree *tree_new() {
  Tree *t = malloc(sizeof(Tree));
  t->head = NULL;
  return t;
}

TreeNode *tree_node_new(int value) {
  TreeNode *n = malloc(sizeof(TreeNode));
  n->value = value;
  n->right = NULL;
  n->left = NULL;
  return n;
}

bool tree_set_node(TreeNode *parent, TreeNode *child, int pos) {
  if (!parent || !child)
    return false;

  if (pos == 0) {
    parent->left = child;
  } else {
    parent->right = child;
  }

  return true;
}

void tree_order(TreeNode *curr, List *path, TREE_ORDER order) {
  if (!curr) {
    return;
  }

  if (order == TREE_PRE)
    list_push(path, curr->value);

  tree_order(curr->left, path, order);

  if (order == TREE_IN)
    list_push(path, curr->value);

  tree_order(curr->right, path, order);

  if (order == TREE_POS)
    list_push(path, curr->value);
}

void tree_free(Tree *tree) { free(tree); }

void tree_node_free(TreeNode *node) { free(node); }
