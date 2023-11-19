#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

const int STACK_SIZE = 1000;

stack *INITIALIZE_STACK() {
  stack *S = malloc(sizeof *S);
  for (int i = 0; i < STACK_SIZE; i++) {
    S->data[i] = 0;
  }
  S->top = -1;
  return S;
}

stack *PUSH(stack *S, int val) {
  int new_top = S->top + 1;

  if (new_top < STACK_SIZE) {
    S->data[new_top] = val;
    S->top = new_top;
  } else {
    // TODO: throw "overflow" error
  }

  PRINT_STACK(S, 4);
  return S;
}

stack *POP(stack *S) {
  int new_top = S->top - 1;

  if (new_top >= -1) {
    S->top = new_top;
  } else {
    // TODO: throw "underflow" error
  }

  PRINT_STACK(S, 4);
  return S;
}

void PRINT_STACK(stack *S, int length) {
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

  stack *S = INITIALIZE_STACK();
  PRINT_STACK(S, 4);
  PUSH(S, 10);
  PUSH(S, 20);
  PUSH(S, 30);
  POP(S);
  PUSH(S, 40);
  POP(S);
  POP(S);
  PUSH(S, 50);
}
