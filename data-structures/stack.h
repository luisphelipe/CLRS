#ifndef _H_TESTE
#define _H_TESTE

// STACK "CLASS"
extern const int STACK_SIZE;

typedef struct {
  //   int data[STACK_SIZE];  // BUILD FAILS
  int data[1000];
  int top;
} stack;

stack *INITIALIZE_STACK();
void PRINT_STACK(stack *S, int length);
stack *PUSH(stack *S, int val);
stack *POP(stack *S);

void run_stack_tests(void);

#endif
