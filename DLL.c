#include <stdio.h>
#include <stdlib.h>

struct emp {
    int ssn, sal;
    char name[20], dept[10], desig[15], phno[10];
    struct emp *left;
    struct emp *right;
};

typedef struct emp NODE;
NODE *first = NULL, *temp = NULL, *newnode = NULL;

NODE* getnode() {
    newnode = (NODE*)malloc(sizeof(NODE)); // Create first NODE
    printf("\nEnter SSN, Name, Dept. , Desig, Ph.No and salary\n");
    scanf("%d", &(newnode->ssn));
    scanf("%s", newnode->name);
    scanf("%s", newnode->dept);
    scanf("%s", newnode->desig);
    scanf("%s", newnode->phno);
    scanf("%d", &(newnode->sal));
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insert_front() {
    NODE *newnode = getnode();
    newnode->right = first;
    if (first != NULL)
        first->left = newnode;
    first = newnode;
}

void delete_front() {
    if (first == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    temp = first;
    if (first != NULL)
        first = first->right;
    free(temp);
    first->left = NULL;
}

void insert_rear() {
    newnode = getnode();
    if (first == NULL)
        first = newnode;
    else {
        temp = first;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        temp->right = newnode;
        newnode->left = temp;
    }
}

void delete_rear() {
    if (first == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    if (first->right == NULL) {
        free(first);
        first = NULL;
        return;
    }
    temp = first;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    temp->left->right = NULL;
    free(temp);
}

void display() {
    int count = 0;
    if (first == NULL) {
        printf("List is empty..! \n");
        return;
    }
    temp = first;
    printf("\n----EMPLOYEE DATA----\n");
    printf("\nSSN\tNAME\tDept\tDesig\tPh.NO.\tSalary\n");
    while (temp != NULL) {
        printf("%d\t%s\t%s\t%s\t%s\t%d\n", temp->ssn, temp->name, temp->dept, temp->desig, temp->phno, temp->sal);
        temp = temp->right;
        count++;
    }
    printf("No of employees = %d\n", count);
}

int main() {
    int ch, n, i;
    while (1) {
        printf("-----------------MENU----------------------\n");
        printf("\n1–Create\n2–Display\n3–Insert at the rear\n4–Delete from rear\n");
        printf("5–Insert at front\n6–Delete from front\n7–Exit\n");
        printf("--------------------------------------------\n");
        printf("\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter no of employees : ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                    insert_rear();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_rear();
                break;
            case 4:
                delete_rear();
                break;
            case 5:
                insert_front();
                break;
            case 6:
                delete_front();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

