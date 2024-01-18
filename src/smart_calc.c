#include "smart_calc.h"

int error_input(const char* input_label) {
  int error = 1;
  int size = strlen(input_label);
  int count = 1;
  for (int i = 0; i < size; i++) {
    if (input_label[i] == '(') {
      count--;
    }
    if (input_label[i] == ')') {
      count++;
    }
  }
  if (count != 1) {
    error = 0;
  }
  return error;
}

void init_stack(stack* stack) { stack->top = -1; }

int is_empty(stack* stack) { return stack->top == -1; }

void push(stack* stack, double value) { stack->value[++stack->top] = value; }

double pop(stack* stack) { return stack->value[stack->top--]; }

int is_operand(char value) {
  return value == '+' || value == '-' || value == '*' || value == '/' ||
         value == '^' || value == '%';
}

int priority(char operand) {
  int result = 0;
  switch (operand) {
    case '+':
    case '-':
      result = 1;
      break;
    case '*':
    case '/':
    case '%':
      result = 2;
      break;
    case '^':
      result = 3;
      break;
    case 's':
    case 'c':
    case 't':
    case 'S':
    case 'C':
    case 'T':
    case 'l':
    case 'L':
    case 'Q':
      result = 4;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

int is_letter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void in_rpn(const char* input_label, char* rpn_label) {
  stack stack;
  init_stack(&stack);

  int input_size = strlen(input_label);
  int rpn_i = 0;
  int unar_minus = 0, unar_plus = 0;
  for (int i = 0; i < input_size; i++) {
    if (unar_minus) {
      rpn_label[rpn_i++] = '-';
      unar_minus = 0;
    }
    if (unar_plus) {
      unar_plus = 0;
    }
    if (isdigit(input_label[i])) {
      while (isdigit(input_label[i]) || input_label[i] == '.') {
        rpn_label[rpn_i++] = input_label[i++];
      }
      rpn_label[rpn_i++] = ' ';
      i--;
    } else if (input_label[i] == '(') {
      push(&stack, input_label[i]);
    } else if (input_label[i] == ')') {
      while (!is_empty(&stack) && stack.value[stack.top] != '(') {
        rpn_label[rpn_i++] = pop(&stack);
        rpn_label[rpn_i++] = ' ';
      }
      if (!is_empty(&stack) && stack.value[stack.top] == '(') {
        pop(&stack);
      }
    } else if (input_label[i] == '-' &&
               (i == 0 || is_operand(input_label[i - 1]) ||
                input_label[i - 1] == '(')) {
      unar_minus = 1;
      push(&stack, input_label[i]);
      push(&stack, '0');
      continue;
    } else if (input_label[i] == '+' &&
               (i == 0 || is_operand(input_label[i - 1]) ||
                input_label[i - 1] == '(')) {
      unar_plus = 1;
      continue;
    } else if (is_operand(input_label[i])) {
      while (!is_empty(&stack) &&
             priority(input_label[i]) <= priority(stack.value[stack.top]) &&
             stack.value[stack.top] != '(') {
        rpn_label[rpn_i++] = pop(&stack);
        rpn_label[rpn_i++] = ' ';
      }
      push(&stack, input_label[i]);
    } else if (is_letter(input_label[i])) {
      if ((i + 3 < input_size) &&
          (input_label[i] == 's' && input_label[i + 1] == 'i' &&
           input_label[i + 2] == 'n' && !is_letter(input_label[i + 3]))) {
        push(&stack, 's');
        i += 2;
      } else if ((i + 2 < input_size) &&
                 (input_label[i] == 'c' && input_label[i + 1] == 'o' &&
                  input_label[i + 2] == 's' &&
                  !is_letter(input_label[i + 3]))) {
        push(&stack, 'c');
        i += 2;
      } else if ((i + 2 < input_size) &&
                 (input_label[i] == 't' && input_label[i + 1] == 'a' &&
                  input_label[i + 2] == 'n' &&
                  !is_letter(input_label[i + 3]))) {
        push(&stack, 't');
        i += 2;
      } else if ((i + 3 < input_size) &&
                 (input_label[i] == 'a' && input_label[i + 1] == 's' &&
                  input_label[i + 2] == 'i' && input_label[i + 3] == 'n' &&
                  !is_letter(input_label[i + 4]))) {
        push(&stack, 'S');
        i += 3;
      } else if ((i + 3 < input_size) &&
                 (input_label[i] == 'a' && input_label[i + 1] == 'c' &&
                  input_label[i + 2] == 'o' && input_label[i + 3] == 's' &&
                  !is_letter(input_label[i + 4]))) {
        push(&stack, 'C');
        i += 3;
      } else if ((i + 3 < input_size) &&
                 (input_label[i] == 'a' && input_label[i + 1] == 't' &&
                  input_label[i + 2] == 'a' && input_label[i + 3] == 'n' &&
                  !is_letter(input_label[i + 4]))) {
        push(&stack, 'T');
        i += 3;
      } else if ((i + 1 < input_size) &&
                 (input_label[i] == 'l' && input_label[i + 1] == 'n' &&
                  !is_letter(input_label[i + 2]))) {
        push(&stack, 'l');
        i += 1;
      } else if ((i + 2 < input_size) &&
                 (input_label[i] == 'l' && input_label[i + 1] == 'o' &&
                  input_label[i + 2] == 'g' &&
                  !is_letter(input_label[i + 3]))) {
        push(&stack, 'L');
        i += 2;
      } else if ((i + 3 < input_size) &&
                 (input_label[i] == 's' && input_label[i + 1] == 'q' &&
                  input_label[i + 2] == 'r' && input_label[i + 3] == 't' &&
                  !is_letter(input_label[i + 4]))) {
        push(&stack, 'Q');
        i += 3;
      } else {
        while (!is_empty(&stack) &&
               priority(input_label[i]) <= priority(stack.value[stack.top])) {
          rpn_label[rpn_i++] = pop(&stack);
          rpn_label[rpn_i++] = ' ';
        }
        push(&stack, input_label[i]);
      }
    }
  }

  while (!is_empty(&stack)) {
    rpn_label[rpn_i++] = pop(&stack);
    rpn_label[rpn_i++] = ' ';
  }
  rpn_label[rpn_i] = '\0';
}

double calc_rpn(char* rpn) {
  stack stack;
  init_stack(&stack);

  char* token = strtok(rpn, " ");

  while (token) {
    if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
      double value = strtod(token, NULL);
      push(&stack, value);
    } else if (is_operand(token[0])) {
      double operand2 = pop(&stack);
      double operand1 = pop(&stack);
      double result = 0.0;

      switch (token[0]) {
        case '+':
          result = operand1 + operand2;
          break;
        case '-':
          if (strlen(token) > 1) {
            push(&stack, -operand2);
            continue;
          } else {
            result = operand1 - operand2;
          }
          break;
        case '*':
          result = operand1 * operand2;
          break;
        case '/':
          result = operand1 / operand2;
          break;
        case '^':
          result = pow(operand1, operand2);
          break;
        case '%':
          result = fmod(operand1, operand2);
          break;
      }
      push(&stack, result);
    } else if (is_letter(token[0])) {
      double operand = pop(&stack);
      double result = 0.0;

      switch (token[0]) {
        case 's':
          result = sin(operand);
          break;
        case 'c':
          result = cos(operand);
          break;
        case 't':
          result = tan(operand);
          break;
        case 'S':
          result = asin(operand);
          break;
        case 'C':
          result = acos(operand);
          break;
        case 'T':
          result = atan(operand);
          break;
        case 'l':
          result = log(operand);
          break;
        case 'L':
          result = log10(operand);
          break;
        case 'Q':
          result = sqrt(operand);
          break;
      }
      push(&stack, result);
    }
    token = strtok(NULL, " ");
  }
  return pop(&stack);
}