#include<stdio.h> 
#include<stdlib.h>
#define MAX 4

int stack[MAX];
int top = -1;
int status = 0;

void push(int item) {
    if (top == (MAX - 1))
        printf("\n\nStack is Overflow");
    else {
        stack[++top] = item;
        status++;
    }
}

int pop() {
    int del;
    if (top == -1)
        printf("\n\nStack is Underflow");
    else {
        del = stack[top--];
        status--;
        printf("\nPopped element is %d", del);
    }
    return del;
}

void palindrome() {
    if (top == -1) {
        printf("\nStack is Empty");
        return;
    }

    int i = 0;
    int j = top;

    while (i < j) {
        if (stack[i] != stack[j]) {
            printf("\nStack contents are not Palindrome");
            return;
        }
        i++;
        j--;
    }

    printf("\nStack contents are Palindrome");
}

void display() {
    int i;
    printf("\nThe stack contents are:");
    if (top == -1)
        printf("\nStack is Empty");
    else {
        for (i = top; i >= 0; i--)
            printf("\n %d|", stack[i]);
        printf("\n");
    }
}

int main() {
    int ch, item;
    do {
        printf("\n\n----MAIN MENU----\n");
        printf("\n1. PUSH (Insert) in the Stack");
        printf("\n2. POP (Delete) from the Stack");
        printf("\n3. PALINDROME check using Stack");
        printf("\n4. Exit (End the Execution)");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter a element to be pushed: ");
                scanf("%d", &item);
                push(item);
                display();
                break;
            case 2:
                item = pop();
                display();
                break;
            case 3:
                palindrome();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice");
        }
    } while (ch != 4);
    return 0;
}

