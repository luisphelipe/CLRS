#include "../../00_c-unity/unity.h"
#include "queue.h"

void setUp(void) {
  // this is executed before each test
  // set stuff up here
}

void tearDown(void) {
  // this is executed after each test
  // clean stuff up here
}

void test_queue_init(void) {
  // Arrange
  // Act
  QUEUE *Q = QUEUE_INIT();

  // Assert
  int expected_value[4] = {0, 0, 0, 0};
  TEST_ASSERT_EQUAL_INT_ARRAY(expected_value, Q->data, 4);
  TEST_ASSERT_EQUAL_INT(0, Q->head);
  TEST_ASSERT_EQUAL_INT(-1, Q->tail);
  TEST_ASSERT_EQUAL_INT(0, Q->size);
  //   STACK_FREE(S);
}

void test_queue_print(void) {
  // Arrange
  QUEUE *Q = QUEUE_INIT();
  int length = 4;
  char target[5 * length + 3];

  // Act
  const char *result = _QUEUE_PRINT(target, Q, length, 1);

  // Assert
  char *expected = "|  0 |  0 |  0 |  0 |";
  TEST_ASSERT_EQUAL_STRING(expected, result);
  //   STACK_FREE(S);
}

void test_queue_enqueue(void) {
  // Arrange
  QUEUE *Q = QUEUE_INIT();

  // Act
  ENQUEUE(Q, 10);
  ENQUEUE(Q, 30);
  ENQUEUE(Q, 20);

  // Assert
  int expected_value[4] = {10, 30, 20, 0};

  TEST_ASSERT_EQUAL_INT_ARRAY(expected_value, Q->data, 4);
  TEST_ASSERT_EQUAL_INT(0, Q->head);
  TEST_ASSERT_EQUAL_INT(2, Q->tail);
  TEST_ASSERT_EQUAL_INT(3, Q->size);
  //   STACK_FREE(S);
}

void test_queue_dequeue(void) {
  QUEUE *Q = QUEUE_INIT();

  ENQUEUE(Q, 10);
  ENQUEUE(Q, 20);

  // test initial state
  int first_expected_value[4] = {10, 20, 0, 0};
  TEST_ASSERT_EQUAL_INT_ARRAY(first_expected_value, Q->data, 4);
  TEST_ASSERT_EQUAL_INT(0, Q->head);
  TEST_ASSERT_EQUAL_INT(1, Q->tail);
  TEST_ASSERT_EQUAL_INT(2, Q->size);

  // test dequeue
  DEQUEUE(Q);
  int second_expected_value[4] = {0, 20, 0, 0};
  TEST_ASSERT_EQUAL_INT_ARRAY(second_expected_value, Q->data, 4);
  TEST_ASSERT_EQUAL_INT(1, Q->head);
  TEST_ASSERT_EQUAL_INT(1, Q->tail);
  TEST_ASSERT_EQUAL_INT(1, Q->size);

  // test new queue
  ENQUEUE(Q, 99);
  int third_expected_value[4] = {0, 20, 99, 0};
  TEST_ASSERT_EQUAL_INT_ARRAY(third_expected_value, Q->data, 4);
  TEST_ASSERT_EQUAL_INT(1, Q->head);
  TEST_ASSERT_EQUAL_INT(2, Q->tail);
  TEST_ASSERT_EQUAL_INT(2, Q->size);
}

void test_queue_wrap_around(void) {
  QUEUE *Q = QUEUE_INIT();

  // queue 999 itens
  // size 999, head 0, tail 998
  for (int i = 0; i < 999; i++) {
    ENQUEUE(Q, i);
  }

  TEST_ASSERT_EQUAL_INT(999, Q->size);
  TEST_ASSERT_EQUAL_INT(0, Q->head);
  TEST_ASSERT_EQUAL_INT(998, Q->tail);

  // queue
  // size 1000, head 0, tail 999
  ENQUEUE(Q, 1000);

  TEST_ASSERT_EQUAL_INT(1000, Q->size);
  TEST_ASSERT_EQUAL_INT(0, Q->head);
  TEST_ASSERT_EQUAL_INT(999, Q->tail);

  // dequeue
  // size 999, head 1, tail 999
  int head_value = DEQUEUE(Q);

  TEST_ASSERT_EQUAL_INT(0, head_value);
  TEST_ASSERT_EQUAL_INT(999, Q->size);
  TEST_ASSERT_EQUAL_INT(1, Q->head);
  TEST_ASSERT_EQUAL_INT(999, Q->tail);

  // queue
  // size 1000, head 1, tail 0
  ENQUEUE(Q, 1001);

  TEST_ASSERT_EQUAL_INT(1000, Q->size);
  TEST_ASSERT_EQUAL_INT(1, Q->head);
  TEST_ASSERT_EQUAL_INT(0, Q->tail);

  // and some more
  DEQUEUE(Q);
  DEQUEUE(Q);
  head_value = DEQUEUE(Q);
  ENQUEUE(Q, 1002);

  TEST_ASSERT_EQUAL_INT(3, head_value);
  TEST_ASSERT_EQUAL_INT(998, Q->size);
  TEST_ASSERT_EQUAL_INT(4, Q->head);
  TEST_ASSERT_EQUAL_INT(1, Q->tail);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_queue_init);
  RUN_TEST(test_queue_print);
  RUN_TEST(test_queue_enqueue);
  RUN_TEST(test_queue_dequeue);
  RUN_TEST(test_queue_wrap_around);

  return UNITY_END();
}