#include "../c-unity/unity.h"
#include "stack.h"

void setUp(void) {
  // this is executed before each test
  // set stuff up here
}

void tearDown(void) {
  // this is executed after each test
  // clean stuff up here
}

void test_stack_init(void) {
  stack *S = STACK_INIT();
  int expected_value[4] = {0, 0, 0};
  TEST_ASSERT_EQUAL_INT_ARRAY(expected_value, S->data, 3);
  STACK_FREE(S);
}

void test_stack_push(void) {
  stack *S = STACK_INIT();
  STACK_PUSH(S, 10);
  STACK_PUSH(S, 20);
  STACK_PUSH(S, 30);
  int expected_value[4] = {10, 20, 30};
  TEST_ASSERT_EQUAL_INT_ARRAY(expected_value, S->data, 3);
  STACK_FREE(S);
}

void test_stack_pop(void) {
  stack *S = STACK_INIT();
  STACK_PUSH(S, 10);
  STACK_PUSH(S, 20);
  STACK_PUSH(S, 30);
  STACK_POP(S);
  int expected_value[4] = {10, 20, 30};
  TEST_ASSERT_EQUAL_INT_ARRAY(expected_value, S->data, 3);
  STACK_FREE(S);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_stack_init);
  RUN_TEST(test_stack_push);
  RUN_TEST(test_stack_pop);

  return UNITY_END();
}