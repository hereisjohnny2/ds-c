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

void tree_order_walk(TreeNode *curr, List *path, TREE_ORDER order) {
  if (!curr)
    return;

  if (order == TREE_PRE)
    list_push(path, curr->value);

  tree_order_walk(curr->left, path, order);

  if (order == TREE_IN)
    list_push(path, curr->value);

  tree_order_walk(curr->right, path, order);

  if (order == TREE_POS)
    list_push(path, curr->value);
}

void tree_order(Tree *tree, List *path, TREE_ORDER order) {
  if (!tree) {
    return;
  }

  tree_order_walk(tree->head, path, order);
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

bool breadth_first_search(Tree *tree, int value) {
  if (!tree || !tree->head)
    return false;

  Queue *q = queue_new();
  enqueue(q, tree->head->value);

  return breadth_first_search_walk(tree->head, value, q);
}

bool tree_compare_walk(TreeNode *a, TreeNode *b) {
  // Structural Check
  if (!a && !b)
    return true;

  // Structural Check
  if (!a || !b)
    return false;

  // Value Check
  if (a->value != b->value)
    return false;

  return tree_compare_walk(a->left, b->left) &&
         tree_compare_walk(a->right, b->right);
}

bool tree_compare(Tree *a, Tree *b) {
  if (!a && !b)
    return true;

  if (!a || !b)
    return false;
  return tree_compare_walk(a->head, b->head);
}

bool bst_find_walk(TreeNode *node, int needle) {
  if (!node)
    return false;

  if (node->value == needle)
    return true;

  if (node->value < needle)
    return bst_find_walk(node->right, needle);

  return bst_find_walk(node->left, needle);
}

bool bst_find(Tree *tree, int needle) {
  if (!tree || !tree->head)
    return false;

  return bst_find_walk(tree->head, needle);
}

void bst_insert_walk(TreeNode *node, int value) {
  if (!node) {
    node = tree_node_new(value);
    return;
  }

  if (node->value < value) {
    if (!node->right) {
      node->right = tree_node_new(value);
    } else {
      bst_insert_walk(node->right, value);
    }
  } else {
    if (!node->left) {
      node->left = tree_node_new(value);
    } else {
      bst_insert_walk(node->left, value);
    }
  }
}

void bst_insert(Tree *tree, int value) {
  if (!tree->head) {
    tree->head = tree_node_new(value);
    return;
  }

  bst_insert_walk(tree->head, value);
}

void tree_free(Tree *tree) { free(tree); }

void tree_node_free(TreeNode *node) { free(node); }
