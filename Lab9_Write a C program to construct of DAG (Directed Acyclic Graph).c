#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EXPR_LENGTH 100

// Structure for a node in the DAG
typedef struct Node {
    char data[10];
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(char data[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to display the DAG
void display(Node* root, int space) {
    if (root == NULL)
        return;
    space += 5;
    display(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%s\n", root->data);
    display(root->left, space);
}

// Function to build DAG from expression
Node* buildDAG(char expression[], int start, int end) {
    // Base case: If the expression contains only one operand
    if (start == end) {
        char operand[2];
        operand[0] = expression[start];
        operand[1] = '\0';
        return createNode(operand);
    }

    // Find the position of the operator with the lowest precedence
    int minPrecedence = 9999;
    int minIndex = -1;
    int parenthesesCount = 0;

    for (int i = start; i <= end; i++) {
        if (expression[i] == '(')
            parenthesesCount++;
        else if (expression[i] == ')')
            parenthesesCount--;
        else if (parenthesesCount == 0 &&
                 (expression[i] == '+' || expression[i] == '-' ||
                  expression[i] == '*' || expression[i] == '/')) {
            int precedence;
            if (expression[i] == '+' || expression[i] == '-')
                precedence = 1;
            else
                precedence = 2;
            if (precedence <= minPrecedence) {
                minPrecedence = precedence;
                minIndex = i;
            }
        }
    }

    // If operator is not found (expression is enclosed within parentheses)
    if (minIndex == -1) {
        if (expression[start] == '(' && expression[end] == ')')
            return buildDAG(expression, start + 1, end - 1);
    }

    // Create a node for the operator
    Node* root = createNode("");
    root->data[0] = expression[minIndex];
    root->data[1] = '\0';

    // Recursively build left and right subtrees
    root->left = buildDAG(expression, start, minIndex - 1);
    root->right = buildDAG(expression, minIndex + 1, end);

    return root;
}

int main() {
    char expression[MAX_EXPR_LENGTH];
    printf("Enter an expression: ");
    fgets(expression, MAX_EXPR_LENGTH, stdin);
    expression[strcspn(expression, "\n")] = 0; // Removing trailing newline character

    int length = strlen(expression);
    Node* root = buildDAG(expression, 0, length - 1);

    printf("Directed Acyclic Graph (DAG) for the expression:\n");
    display(root, 0);

    return 0;
}
