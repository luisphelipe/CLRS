#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

const int QUEUE_SIZE = 1000;

QUEUE *QUEUE_INIT() {
  QUEUE *Q = malloc(sizeof *Q);

  Q->data = (int *)malloc(sizeof(int) * QUEUE_SIZE);
  Q->head = 0;
  Q->tail = -1;
  Q->size = 0;

  for (int i = 0; i < QUEUE_SIZE; i++) {
    Q->data[i] = 0;
  }

  return Q;
}

char *_QUEUE_PRINT(char *result, QUEUE *Q, int length, int silent) {
  char *target = result;

  for (int i = 0; i < length; i++) {
    int index = Q->head + i;
    if (index >= QUEUE_SIZE) {
      index = index % QUEUE_SIZE;
    }

    int val = Q->data[index];
    if (index == Q->tail) {
      target += sprintf(target, "|[%2d]", val);
    } else {
      target += sprintf(target, "| %2d ", val);
    }
  }

  target += sprintf(target, "|");

  if (!silent) {
    printf("queue= %s\n", result);
  }

  return result;
};

void QUEUE_PRINT(QUEUE *Q, int length) {
  char target[5 * length + 3];
  _QUEUE_PRINT(target, Q, length, 0);
}

QUEUE *ENQUEUE(QUEUE *Q, int val) {
  // verify overflow
  if (Q->size + 1 > QUEUE_SIZE) {
    // TODO: throw error
    return Q;
  }

  // calculate element index (end of list)
  int index = Q->tail + 1;

  // set tail to start of list if reached the end
  if (index >= QUEUE_SIZE) {
    index %= QUEUE_SIZE;
  }

  // add element to index and update queue attributes
  Q->data[index] = val;
  Q->tail = index;
  Q->size += 1;

  return Q;
}

int DEQUEUE(QUEUE *Q) {
  if (Q->size == 0) {
    return 0;
  }

  int value = Q->data[Q->head];
  Q->data[Q->head] = 0;

  int new_head = Q->head + 1;
  if (new_head >= QUEUE_SIZE) {
    new_head %= QUEUE_SIZE;
  }

  Q->head = new_head;
  Q->size -= 1;

  return value;
};

void QUEUE_FREE(QUEUE *Q);
