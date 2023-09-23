#include "tree.h"
#include "linked_list.h"
#include "queue.h"
#include <locale.h>
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
  if (!curr)
    return;

  if (order == TREE_PRE)
    list_push(path, curr->value);

  tree_order(curr->left, path, order);

  if (order == TREE_IN)
    list_push(path, curr->value);

  tree_order(curr->right, path, order);

  if (order == TREE_POS)
    list_push(path, curr->value);
}

bool breadth_first_search_walk(TreeNode *curr, int value, Queue *q) {
  if (!curr || queue_len(q) < 1) {
    return false;
  }

  if (value == dequeue(q)) {
    return true;
  }

  if (curr->left) {
    enqueue(q, curr->left->value);
  }

  if (curr->right) {
    enqueue(q, curr->right->value);
  }

  return breadth_first_search_walk(curr->left, value, q) ||
         breadth_first_search_walk(curr->right, value, q);
}

bool breadth_first_search(TreeNode *curr, int value) {
  if (!curr)
    return false;
  Queue *q = queue_new();
  enqueue(q, curr->value);

  return breadth_first_search_walk(curr, value, q);
}

bool tree_compare(TreeNode *a, TreeNode *b) {
  // Structural Check
  if (!a && !b)
    return true;

  // Structural Check
  if (!a || !b)
    return false;

  // Value Check
  if (a->value != b->value)
    return false;

  return tree_compare(a->left, b->left) && tree_compare(a->right, b->right);
}

void tree_free(Tree *tree) { free(tree); }

void tree_node_free(TreeNode *node) { free(node); }
