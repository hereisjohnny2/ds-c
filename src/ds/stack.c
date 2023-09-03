#include "stack.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct myNode {
  int value;
  struct myNode *next;
} Node;

typedef struct myStack {
  Node *head;
  size_t len;
} Stack;

int stack_len(Stack *stack) {
  if (stack == NULL)
    return 0;
  return stack->len;
}

Stack *stack_new() {
  Stack *s = malloc(sizeof(Stack));
  s->len = 0;
  return s;
}

bool stack_push(Stack *stack, int value) {
  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL)
    return false;

  new_node->value = value;
  new_node->next = stack->head;

  stack->head = new_node;

  stack->len++;

  return true;
}

int stack_peek(Stack *stack) {
  if (stack->len == 0)
    return STACK_EMPTY;
  return stack->head->value;
}

int stack_pop(Stack *stack) {
  if (stack->len == 0)
    return STACK_EMPTY;

  Node *nextHead = stack->head;
  int value = nextHead->value;
  stack->head = nextHead->next;

  free(nextHead);

  stack->len--;

  return value;
}

void stack_free(Stack *stack) { free(stack); }
