#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char opStack[MAX];
int top = -1;

void push(char ch) { opStack[++top] = ch; }
char pop() { return opStack[top--]; }
char peek() { return opStack[top]; }
int isEmpty() { return top == -1; }

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int isVariable(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void infixToPostfix(const char* infix, char* postfix) {
    int i, j = 0;
    char ch;
    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if (isVariable(ch)) postfix[j++] = ch;
        else if (ch == '(') push(ch);
        else if (ch == ')') {
            while (!isEmpty() && peek() != '(') postfix[j++] = pop();
            pop();
        } else if (isOperator(ch)) {
            while (!isEmpty() && ((precedence(peek()) > precedence(ch)) || 
                   (precedence(peek()) == precedence(ch) && ch != '^')))
                postfix[j++] = pop();
            push(ch);
        }
    }
    while (!isEmpty()) postfix[j++] = pop();
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter the infix expression with variables (e.g. a+b*c): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

