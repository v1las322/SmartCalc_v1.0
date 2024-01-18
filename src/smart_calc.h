#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_MAX_SIZE 255

typedef struct stack_stand {
  double value[STACK_MAX_SIZE];
  int top;
} stack;

int error_input(const char* input_label);
void init_stack(stack* stack);
int is_empty(stack* stack);
void push(stack* stack, double value);
double pop(stack* stack);
int is_operand(char value);
int priority(char operand);
int is_letter(char c);
void in_rpn(const char* input_label, char* rpn_label);
double calc_rpn(char* rpn);
