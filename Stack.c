#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stack[MAX], item;
int ch, top = -1, status = 0;

/* PUSH FUNCTION */
void push(int item) {
    if (top == (MAX - 1))
        printf("\n\nStack is Overflow");
    else {
        stack[++top] = item;
        status++;
    }
}

/* POP FUNCTION */
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

/* FUNCTION TO CHECK STACK IS PALINDROME OR NOT */
void palindrome() {
    int i, j;
    j = top; // Start j from the top of the stack
    for(i = 0; i <= top / 2; i++) { // Iterate until the middle of the stack
        if(stack[i] != stack[j]) { // If elements from both ends don't match
            printf("\nStack contents are not palindrome");
            return;
        }
        j--; // Move j towards the bottom of the stack
    }
    printf("\nStack contents are Palindrome");
}

/* FUNCTION TO DISPLAY STACK */
void display() {
    int i;
    if (top == -1)
        printf("\nStack is Empty");
    else {
        printf("\nThe stack contents are:");
        for (i = top; i >= 0; i--)
            printf("\n %d|", stack[i]);
        printf("\n");
    }
}

/* MAIN PROGRAM */
void main() {
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
                printf("\nEND OF EXECUTION");
        }//end switch
    } while (ch != 4);
}

