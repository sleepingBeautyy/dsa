#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100

struct Stack
{
    int top;
    int items[SIZE];
};

struct Stack stack;

void initialize()
{
    stack.top = -1;
}

int isEmpty()
{
    return stack.top == -1;
}

int isFull()
{
    return stack.top == SIZE - 1;
}

void push(int value)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    stack.items[++stack.top] = value;
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack.items[stack.top--];
}

int getOperandValue(char c)
{
    switch (c)
    {
    case 'A':
        return 5;
    case 'B':
        return 3;
    case 'C':
        return 2;
    default:
        printf("Unknown operand: %c\n", c);
        return -1;
    }
}

int evaluatePrefix(char *expression)
{
    initialize();

    int i;
    int operand1, operand2;
    int result;

    for (i = strlen(expression) - 1; i >= 0; i--)
    {
        if (isdigit(expression[i]))
        {
            push(expression[i] - '0');
        }
        else if (isalpha(expression[i]))
        {
            int value = getOperandValue(expression[i]);
            if (value != -1)
            {
                push(value);
            }
            else
            {
                return -1;
            }
        }
        else
        {
            operand1 = pop();
            operand2 = pop();

            if (operand1 == -1 || operand2 == -1)
            {
                return -1;
            }

            switch (expression[i])
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '%':
                result = operand1 % operand2;
                break;
            default:
                printf("Invalid operator\n");
                return -1;
            }

            push(result);
        }
    }

    return pop();
}

int main()
{
    char expression[100];

    printf("Enter a prefix expression: ");
    scanf("%s", expression);

    int result = evaluatePrefix(expression);

    if (result != -1)
    {
        printf("Result: %d\n", result);
    }
    else
    {
        printf("Error in expression evaluation.\n");
    }

    return 0;
}
