#include "../c-unity/unity.h"
#include "stack.h"

void setUp(void) {
  printf("[test_stack] setup\n");
  // set stuff up here
}

void tearDown(void) {
  printf("[test_stack] teardown\n");
  // clean stuff up here
}

void test_stack_push(void) {
  // test stuff
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_stack_push);
  return UNITY_END();
}