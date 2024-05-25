#include<stdio.h>
#include<string.h>

// Function to return stack precedence of an operator
int SP(char symbol) {
    switch(symbol) {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^':
        case '$': return 5;
        case '(': return 0;
        case '#': return -1;
        default: return 8;
    }
}

// Function to return input precedence of an operator
int IP(char symbol) {
    switch(symbol) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^':
        case '$': return 6;
        case '(':
            return 9;
        case ')':
            return 0;
        default: return 7;
    }
}

// Function to convert infix expression to postfix expression
void infix_postfix(char infix[], char postfix[]) {
    int top, j, i;
    char s[30], symbol;
    top = -1;
    s[++top] = '#'; // Initialize stack with '#'
    j = 0;
    for(i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        // Move operators from stack to output until precedence condition satisfies
        while(SP(s[top]) > IP(symbol)) {
            postfix[j] = s[top--];
            j++;
        }
        // Push the symbol onto the stack
        if(SP(s[top]) != IP(symbol))
            s[++top] = symbol;
        else
            top--;
    } 
    // Pop remaining operators from stack to output
    while(s[top] != '#') {
        postfix[j++] = s[top--];
    } 
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[20], postfix[20];
    printf("\nEnter a valid infix expression:\n");
    gets(infix); // Input infix expression
    infix_postfix(infix, postfix); // Convert infix to postfix
    printf("\nThe infix expression is:\n");
    printf("%s\n", infix); // Print infix expression
    printf("\nThe postfix expression is:\n");
    printf("%s\n", postfix); // Print postfix expression
    return 0;
}

