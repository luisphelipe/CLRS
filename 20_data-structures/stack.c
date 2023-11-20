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

stack *_STACK_PUSH(stack *S, int val, int debug) {
  int new_top = S->top + 1;

  if (new_top < STACK_SIZE) {
    S->data[new_top] = val;
    S->top = new_top;
  } else {
    // TODO: throw "overflow" error
  }

  if (debug) {
    STACK_PRINT(S, 4);
  }

  return S;
}

stack *STACK_PUSH(stack *S, int val) { return _STACK_PUSH(S, val, 0); }

int _STACK_POP(stack *S, int debug) {
  int new_top = S->top - 1;
  int value = 0;

  if (new_top >= -1) {
    value = S->data[S->top];
    // S->data[S->top] = 0;
    S->top = new_top;
  } else {
    // TODO: throw "underflow" error
  }

  if (debug) {
    STACK_PRINT(S, 4);
  }

  return value;
}

int STACK_POP(stack *S) { return _STACK_POP(S, 0); }

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
  printf("Starting stack basic tests\n");

  stack *S = STACK_INIT();
  STACK_PRINT(S, 4);

  _STACK_PUSH(S, 10, 1);
  _STACK_PUSH(S, 20, 1);
  _STACK_PUSH(S, 30, 1);
  _STACK_POP(S, 1);
  _STACK_PUSH(S, 40, 1);
  _STACK_POP(S, 1);
  _STACK_POP(S, 1);
  _STACK_PUSH(S, 50, 1);

  STACK_FREE(S);
}
