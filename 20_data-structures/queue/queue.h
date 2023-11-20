#ifndef _H_QUEUE
#define _H_QUEUE

extern const int QUEUE_SIZE;

typedef struct {
  int* data; // QUEUE SIZE
  int head; // 0
  int tail; // 0
  int size; // 0
} QUEUE;

QUEUE *QUEUE_INIT();

// this is the implementation that returns the string to allow for testing
char *_QUEUE_PRINT(char *target, QUEUE *Q, int length, int silent);
// and this is the commonly used for printing
void QUEUE_PRINT(QUEUE *Q, int length);

QUEUE *ENQUEUE(QUEUE *Q, int val);
int DEQUEUE(QUEUE *Q);

void QUEUE_FREE(QUEUE *Q);


#endif
