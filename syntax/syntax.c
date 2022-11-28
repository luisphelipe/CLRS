// referece: https://learnxinyminutes.com/docs/c/

#define SIZE 5

#include <stdio.h>
#include <stdlib.h>

enum days { SUN = 1, MON, TUE, WED, THU, FRI, SAT };

void example_output();
void example_input();
void example_variables();
void example_arrays();
void print_array(int *arr, int size);
void example_strings();

void syntax(void) {
  example_output();
  example_input();
  example_variables();
  example_arrays();
  example_strings();
}

void example_output() {
  printf("Hello World! %d\n", SIZE);
  printf("%d %d %d\n", SUN, MON, TUE);
}

void example_input() {
  int input;
  printf("What is your age? ");
  scanf("%d", &input);
  printf("input=%d\n", input);
}

void example_variables() {
  int intv = 4;
  short shortv = 2;
  char charv = 'c';
  long longv = 4;
  long long longlongv = 8;

  printf("sizes in byte of each type\nint=%d short=%d char=%c long=%ld long "
         "long=%lld\n",
         intv, shortv, charv, longv, longlongv);
}

void example_arrays() {
  int arr1[SIZE] = {0};
  print_array(arr1, SIZE);

  int arr2[SIZE] = {1, 2, 4, 3};
  print_array(arr2, SIZE);

  int arr3[] = {0};
  print_array(arr3, 1);
}

void print_array(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void example_strings() {
  char string[] = "this is a string!";
  printf("%s\n", string);
}
