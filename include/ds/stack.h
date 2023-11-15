#ifndef STACK_C
#define STACK_C

#include <limits.h>
#include <stdbool.h>

#define STACK_EMPTY INT_MIN

typedef struct myNode Node;
typedef struct myStack Stack;

Stack *stack_new();
int stack_len(Stack *stack);
bool stack_push(Stack *stack, int value);
int stack_peek(Stack *stack);
int stack_pop(Stack *stack);
void stack_free(Stack *stack);

#endif // STACK_C
