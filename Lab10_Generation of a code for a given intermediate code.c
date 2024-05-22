#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_SIZE 100

// Stack structure
struct Stack {
    int top;
    char* items[MAX_EXPR_SIZE];
};

// Function to create a new stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to push an item to the stack
void push(struct Stack* stack, char* item) {
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char* pop(struct Stack* stack) {
    if (stack->top == -1)
        return NULL;
    return stack->items[stack->top--];
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert postfix expression to two-address assembly language code
void postfixToAssembly(char* postfixExpr) {
    struct Stack* stack = createStack();
    char* operand1, *operand2, *result;
    char assemblyCode[100];

    for (int i = 0; postfixExpr[i]; i++) {
        if (isalnum(postfixExpr[i])) {
            char temp[2];
            temp[0] = postfixExpr[i];
            temp[1] = '\0';
            push(stack, strdup(temp)); // Push operand onto stack
        } else if (isOperator(postfixExpr[i])) {
            operand2 = pop(stack);
            operand1 = pop(stack);

            // Generate assembly code
            sprintf(assemblyCode, "%c = %s %c %s", 'T', operand1, postfixExpr[i], operand2);
            printf("%s\n", assemblyCode);

            // Push result onto stack
            push(stack, strdup("T"));
        }
    }
}

int main() {
    char postfixExpr[MAX_EXPR_SIZE];

    // Input postfix expression
    printf("Enter postfix expression: ");
    fgets(postfixExpr, MAX_EXPR_SIZE, stdin);

    // Remove newline character from input
    postfixExpr[strcspn(postfixExpr, "\n")] = 0;

    printf("Assembly code:\n");
    postfixToAssembly(postfixExpr);

    return 0;
}
