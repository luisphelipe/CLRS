#ifndef _H_TESTE
#define _H_TESTE

// STACK "CLASS"
extern const int STACK_SIZE;

typedef struct {
  //   int data[STACK_SIZE];  // BUILD FAILS
  int data[1000];
  int top;
} stack;

stack *STACK_INIT();
void STACK_PRINT(stack *S, int length);

stack *_STACK_PUSH(stack *S, int val, int debug);
stack *STACK_PUSH(stack *S, int val);

int _STACK_POP(stack *S, int debug);
int STACK_POP(stack *S);

void STACK_FREE(stack *S);

void run_stack_tests(void);

#endif
