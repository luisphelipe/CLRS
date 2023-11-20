// referece: https://learnxinyminutes.com/docs/c/

#define SIZE 5

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

enum days { SUN = 1, MON, TUE, WED, THU, FRI, SAT };

void example_output();
void example_input();
void example_variables();
void example_arrays();
void print_array(int *arr, int size);
void example_strings();
void example_shorthand_declaration();
void example_other();
void example_structs();
void example_pointers();
void example_function_pointers();

void syntax(void) {
  example_output();
  example_input();
  example_variables();
  example_arrays();
  example_strings();
  example_shorthand_declaration();
  example_other();
  example_pointers();
  example_structs();
  example_function_pointers();
}

void example_output() {
  printf("Hello World! %d\n", SIZE);
  printf("\a %d %d %d\n", SUN, MON, TUE);
  // Special characters:
  /*
  '\a'; // alert (bell) character
  '\n'; // newline character
  '\t'; // tab character (left justifies text)
  '\v'; // vertical tab
  '\f'; // new page (form feed)
  '\r'; // carriage return
  '\b'; // backspace character
  '\0'; // NULL character. Usually put at end of strings in C.
  //   hello\n\0. \0 used by convention to mark end of string.
  '\\'; // backslash
  '\?'; // question mark
  '\''; // single quote
  '\"'; // double quote
  '\xhh'; // hexadecimal number. Example: '\xb' = vertical tab character
  '\0oo'; // octal number. Example: '\013' = vertical tab character

  //print formatting:
  "%d";    // integer
  "%3d";   // integer with minimum of length 3 digits (right justifies text)
  "%s";    // string
  "%f";    // float
  "%ld";   // long
  "%3.2f"; // minimum 3 digits left and 2 digits right decimal float
  "%7.4s"; // (can do with strings too)
  "%c";    // char
  "%p";    // pointer. NOTE: need to (void *)-cast the pointer, before passing
           //                it as an argument to `printf`.
  "%x";    // hexadecimal
  "%o";    // octal
  "%%";    // prints %
  */
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

void example_shorthand_declaration() {
  int l = 1, ll = 2;
  int a, b, c;
  a = b = c = 99;
  printf("l=%d ll=%d\n", l, ll);
  printf("a=%d b=%d c=%d\n", a, b, c);
}

void example_other() {
  int thernary = (1 > 2) ? 10 : 20;
  printf("thernary=%d\n", thernary);
  bool test = false;
  printf("bool is %s\n", test ? "true" : "false");
  const char *my_str = "this is my very own string literal\0";
  printf("it's good practice to declare strings as const: %s\n", my_str);
}

void example_pointers() { printf("TODO: EXAMPLE POINTERS\n"); }

void example_structs() {
  typedef struct {
    int width;
    int height;
  } rect;

  rect test = {1, 2};
  printf("width=%d height=%d\n", test.width, test.height);

  test.width = 10;
  test.height = 20;
  printf("width=%d height=%d\n", test.width, test.height);
}

void example_function_pointers() {
  printf("TODO: EXAMPLE FUNCTION POINTERS\n");
}
