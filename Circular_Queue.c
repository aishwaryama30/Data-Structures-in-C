#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int ch, front = 0, rear = -1, count = 0;
char q[MAX], item;

void insert() {
    if (count == MAX)
        printf("\nQueue is Full");
    else {
    	printf("Enter the character/item to be inserted: ");
        scanf(" %c", &item);  // Added space before %c to consume newline
        rear = (rear + 1) % MAX;
        q[rear] = item;
        count++;
    }
}

void del() {
    if (count == 0)
        printf("\nQueue is Empty");
    else {
        item = q[front];
        printf("\nDeleted item is: %c", item);
        if (front == rear) {
            front = 0;
            rear = -1;
            count = 0;
        } else {
            front = (front + 1) % MAX;
            count--;
        }
    }
}

void display() {
    int i, f = front, r = rear;
    if (count == 0)
        printf("\nQueue is Empty");
    else {
        printf("\nContents of Queue\n");
        for (i = 0; i < count; i++) {
            printf("%c\t", q[f]);
            f = (f + 1) % MAX;
        }
    }
}

int main() {
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (ch != 4);

    return 0;
}

