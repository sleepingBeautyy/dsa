#include <stdio.h>
#define SIZE 100

struct Stack {
 int s[SIZE];
 int top;
}st;

void push(int value) {
   if (st.top==SIZE-1) {
     printf("Stack Overflow!\n");
     } else {
       st.top++;
       st.s[st.top] = value;
        printf("%d Pushed to the stack.\n", value);
    }
}

int pop() {
     if (st.top==-1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
    int item = st.s[st.top];
    st.top--;
    return item;
    }
}


void display() {
    if (st.top==-1) {
    printf("Stack is empty.\n");
} else {
    printf("Elements in the stack: ");
    for (int i = 0; i <= st.top; i++) {
     printf("%d ", st.s[i]);
    }
    printf("\n");
    }
}

int main() {
  st.top=-1;
     push(10);
    push(20);
    push(30);
    display();
    pop();
    pop();

    display();

    return 0;
}
