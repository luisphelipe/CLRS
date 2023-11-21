#include "../00_c-unity/unity.h"
// #include "stack.h"

void setUp(void) {
  // this is executed before each test
  // set stuff up here
}

void tearDown(void) {
  // this is executed after each test
  // clean stuff up here
}

void test_something(void) {
  // write some assertions...
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_something);

  return UNITY_END();
}