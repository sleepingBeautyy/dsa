
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 90

char stack[MAX];
int top = -1;void push(char c) {
stack[++top] = c;
}
char pop() {
return stack[top--];
}
int precedence(char op) {
if (op == '+' || op == '-') return 1;
if (op == '*' || op == '/') return 2;
if (op == '^') return 3;
return 0;
}
void reverse(char* exp) {
int len = strlen(exp);
for (int i = 0; i < len / 2; i++) {
char temp = exp[i];
exp[i] = exp[len - i - 1];
exp[len - i - 1] = temp;
}
}
void infixToPrefix(char* infix, char* prefix) {
reverse(infix);
int i = 0, j = 0;
char c;
while ((c = infix[i++]) != '\0') {
if (isalnum(c))
prefix[j++] = c;
else if (c == ')')
push(c);
else if (c == '(') {
while (stack[top] != ')')
prefix[j++] = pop();
pop();
} else {
while (top != -1 && precedence(stack[top]) > precedence(c))
prefix[j++] = pop();
push(c);
}
}
while (top != -1)prefix[j++] = pop();
prefix[j] = '\0';
reverse(prefix);
}
int main() {

char infix[MAX], prefix[MAX];
printf("Enter infix expression: ");
scanf("%s", infix);
infixToPrefix(infix, prefix);
printf("Prefix expression: %s\n", prefix);

   return 0;
}