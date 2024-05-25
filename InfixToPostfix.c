#include <stdio.h>
#include <string.h>

int SP(char symbol) {
    switch(symbol) {
        case '+':
        case '-': return 2;
        case '*':
        case '/': 
        case '%': return 4;
        case '^':
        case '$': return 5;
        case '(': return 0;
        case '#': return -1;
        default: return 8;
    }
}

int IP(char symbol) {
    switch(symbol) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': 
        case '%': return 3;
        case '^':
        case '$': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7;
    }
}

void infix_postfix(char infix[], char postfix[]) {
    int top, j, i;
    char s[21], symbol; 
    top = -1;
    s[++top] = '#'; 
    j = 0;
    for(i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        while(SP(s[top]) > IP(symbol)) {
            postfix[j] = s[top--];
            j++;
        }
        if(SP(s[top]) != IP(symbol))
            s[++top] = symbol;
        else
            top--;
    }
    while(s[top] != '#') {
        postfix[j++] = s[top--];
    }
    postfix[j] = '\0';
}

int main() {
    char infix[20], postfix[20];
    
    printf("\nEnter a valid infix expression: ");
    scanf("%19s", infix);
    
    infix_postfix(infix, postfix);
    
    printf("\nThe infix expression is: %s\n", infix);
    printf("The postfix expression is: %s\n", postfix);
    
    return 0;
}

