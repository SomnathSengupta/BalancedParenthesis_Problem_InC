#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct Stack{
    int top; 
    char arr[max];
}stack;
int isFull(stack st) {
    if (st.top == max -1) // Stack is Full
        return 1;
    return 0;
}
int isEmpty(stack st) {
    if (st.top == -1) // Stack is empty
        return 1;
    return 0;
}
int push(stack* st, char num) {
    if (isFull(*st)) // Overflow condition
        return -1;
    else {
        st -> top++;
        st -> arr[st -> top] = num;
        return 0;
    }
}
int pop(stack* st) {
    if (isEmpty(*st)) // Underflow Condition
        return -1;
    else {
        char x = st -> arr[st -> top];
        st -> top--;
        return 0;
    }
}
void parenthesisChecker(char *str) {
    stack st;
    st.top = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            push(&st,str[i]);
        }
        if (str[i] == ')') {
            if (pop(&st) == -1) {
                printf("Unbalanced");
               return;
            }
        }
    }
    int c = isEmpty(st);
    if (c == 1) {
        printf("Balanced");
    }
    else {
        printf("Unbalanced ");
    }
}
int main()
{
    char str[20];
    printf("Enter one expression: ");
    gets(str);
    parenthesisChecker(str);
    return 0;
}