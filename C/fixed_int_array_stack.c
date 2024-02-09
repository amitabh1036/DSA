/* fixed_int_array_stack.c
  Fixed size array-based implementation of stack for integers.
*/

#include <stdio.h>

/* Set size of stack */
#define STACK_SIZE 10

/* Define the stack as fixed size array */
typedef struct {
  int top;
  int elements[STACK_SIZE];
} Stack;

/* Create the global stack */
Stack stack;

/* Define push routine for stack */
void push(int value)
{
  if (stack.top < STACK_SIZE) {
    stack.elements[stack.top] = value;
    printf("\nPushed element %d\n", stack.elements[stack.top]);
    stack.top++;
  } else {
    printf("\nError: Stack full\n");
    return;
  }
}

/* Define pop routine for stack */
int pop ()
{
  if (stack.top) {
    stack.top--;
    return stack.elements[stack.top];
  } else {
    printf("\nError: Stack empty\n");
    return -1;
  }
}

/* Print the stack elements */
void print()
{
  int index;

  if (!stack.top) {
    printf("\nEmpty Stack\n");
    return;
  }

  printf("\nPrinting Stack:\n\t");
  for (index = 0; index < stack.top; index++)
    printf("%d, ", stack.elements[index]);
  printf("\n");
}

/* Runs in a loop asking for push/pop/print operations */
int main()
{
  int option;
  int value;

  while (1) {
    printf("\nEnter option [1. Push, 2. Pop, 3. Print]: ");
    if (scanf("%d", &option) != 1) {
      printf("Illegal option; exiting...\n");
      return -1;
    }

    if (option == 1) {
      printf("Enter the value to push (except -1): ");
      if (scanf("%d", &value) != 1) {
        printf("Illegal value; exiting...\n");
        return -1;
      }

      push(value);
    } else if (option == 2) {
      value = pop();

      if (value != -1) {
        printf("\nPopped element: %d\n", value);
      }
    } else if (option == 3) {
      print();
    } else {
      printf("Incorrect option; exiting...\n");
      return 0;
    }
  }

  return 0;
}
