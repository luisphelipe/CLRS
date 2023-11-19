#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

const int STACK_SIZE = 1000;

stack *STACK_INIT() {
  stack *S = malloc(sizeof *S);
  for (int i = 0; i < STACK_SIZE; i++) {
    S->data[i] = 0;
  }
  S->top = -1;
  return S;
}

void STACK_FREE(stack *S) { free(S); }

stack *STACK_PUSH(stack *S, int val) {
  int new_top = S->top + 1;

  if (new_top < STACK_SIZE) {
    S->data[new_top] = val;
    S->top = new_top;
  } else {
    // TODO: throw "overflow" error
  }

  STACK_PRINT(S, 4);
  return S;
}

int STACK_POP(stack *S) {
  int new_top = S->top - 1;
  int value = 0;

  if (new_top >= -1) {
    value = S->data[S->top];
    S->top = new_top;
  } else {
    // TODO: throw "underflow" error
  }

  STACK_PRINT(S, 4);
  return value;
}

void STACK_PRINT(stack *S, int length) {
  int max = length ? length : S->top;
  //   printf("printing stack with top=%d\n", S->top);
  for (int i = 0; i < max; i++) {
    if (i == S->top) {
      printf("|[%2d]", S->data[i]);
    } else {
      printf("| %2d ", S->data[i]);
    }
  }
  printf("|\n");
}

// END OF STACK "CLASS"

void run_stack_tests(void) {
  printf("Hello Stacks!\n");

  stack *S = STACK_INIT();
  STACK_PRINT(S, 4);

  STACK_PUSH(S, 10);
  STACK_PUSH(S, 20);
  STACK_PUSH(S, 30);
  STACK_POP(S);
  STACK_PUSH(S, 40);
  STACK_POP(S);
  STACK_POP(S);
  STACK_PUSH(S, 50);

  STACK_FREE(S);
}
