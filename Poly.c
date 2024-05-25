#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COMPARE(x, y) ((x == y) ? 0 : (x > y) ? 1 : -1)

struct node {
    int cf;
    int xp, yp, zp;
    struct node* link;
};

typedef struct node* NODE;

NODE getnode() {
    NODE x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Running out of memory \n");
        exit(1); // exit the program if memory allocation fails
    }
    return x;
}

NODE attach(int cf, int xp, int yp, int zp, NODE head) {
    NODE temp = getnode();
    temp->cf = cf;
    temp->xp = xp;
    temp->yp = yp;
    temp->zp = zp;
    NODE cur = head->link;
    while (cur->link != head) {
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = head;
    return head;
}

NODE read(NODE head) {
    int i, cf, xp, yp, zp, n;
    printf("\nEnter the number of terms in the polynomial: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
	printf("\nEnter the term %d : \n\tCoefficient = ", i);
	scanf("%d", &cf);
	printf("\n\tEnter Power(x), Power(y), and Power(z): "); 
	scanf("%d%d%d", &xp, &yp, &zp);
	head = attach(cf, xp, yp, zp, head);
    }
    return head;
}

void display(NODE head) {
    NODE temp;
    if (head->link == head) {
        printf("\nPolynomial does not exist.");
        return;
    }
    temp = head->link;
    while (temp != head) {
        printf("%dx^%dy^%dz^%d", temp->cf, temp->xp, temp->yp, temp->zp);
        temp = temp->link;
        if (temp != head)
            printf(" + ");
    }
}

int eval(NODE head) {
    int x, y, z, sum = 0;
    printf("\nEnter the value of x, y, and z: ");
    scanf("%d %d %d", &x, &y, &z);
    NODE poly = head->link;
    while (poly != head) {
        sum += poly->cf * pow(x, poly->xp) * pow(y, poly->yp) * pow(z, poly->zp);
        poly = poly->link;
    }
    return sum;
}

NODE poly_sum(NODE head1, NODE head2, NODE head3) {
    NODE a, b;
    int cf;
    a = head1->link;
    b = head2->link;
    while (a != head1 && b != head2) {
        while (1) {
            if (a->xp == b->xp && a->yp == b->yp && a->zp == b->zp) {
                cf = a->cf + b->cf;
                head3 = attach(cf, a->xp, a->yp, a->zp, head3);
                a = a->link;
                b = b->link;
                break;
            }
            if (a->xp != 0 || b->xp != 0) {
                switch (COMPARE(a->xp, b->xp)) {
                    case -1:
                        head3 = attach(b->cf, b->xp, b->yp, b->zp, head3);
                        b = b->link;
                        break;
                    case 0:
                        if (a->yp > b->yp) {
                            head3 = attach(a->cf, a->xp, a->yp, a->zp, head3);
                            a = a->link;
                            break;
                        }
                        else if (a->yp < b->yp) {
                            head3 = attach(b->cf, b->xp, b->yp, b->zp, head3);
                            b = b->link;
                            break;
                        }
                        else if (a->zp > b->zp) {
                            head3 = attach(a->cf, a->xp, a->yp, a->zp, head3);
                            a = a->link;
                            break;
                        }
                        else if (a->zp < b->zp) {
                            head3 = attach(b->cf, b->xp, b->yp, b->zp, head3);
                            b = b->link;
                            break;
                        }
                    case 1:
                        head3 = attach(a->cf, a->xp, a->yp, a->zp, head3);
                        a = a->link;
                        break;
                }
                break;
            }
            if (a->yp != 0 || b->yp != 0) {
                switch (COMPARE(a->yp, b->yp)) {
                    case -1:
                        head3 = attach(b->cf, b->xp, b->yp, b->zp, head3);
                        b = b->link;
                        break;
                    case 0:
                        if (a->zp > b->zp) {
                            head3 = attach(a->cf, a->xp, a->yp, a->zp, head3);
                            a = a->link;
                            break;
                        }
                        else if (a->zp < b->zp) {
                            head3 = attach(b->cf, b->xp, b->yp, b->zp, head3);
                            b = b->link;
                            break;
                        }
                    case 1:
                        head3 = attach(a->cf, a->xp, a->yp, a->zp, head3);
                        a = a->link;
                        break;
                }
                break;
            }
            if (a->zp != 0 || b->zp != 0) {
                switch (COMPARE(a->zp, b->zp)) {
                    case -1:
                        head3 = attach(b->cf, b->xp, b->yp, b->zp, head3);
                        b = b->link;
                        break;
                    case 1:
                        head3 = attach(a->cf, a->xp, a->yp, a->zp, head3);
                        a = a->link;
                        break;
                }
                break;
            }
        }
    }
    while (a != head1) {
        head3 = attach(a->cf, a->xp, a->yp, a->zp, head3);
        a = a->link;
    }
    while (b != head2) {
        head3 = attach(b->cf, b->xp, b->yp, b->zp, head3);
        b = b->link;
    }
    return head3;
}

int main() {
    NODE head, head1, head2, head3;
    int res, ch;
    head = getnode(); // For polynomial evaluation
    head1 = getnode(); // To hold POLY1
    head2 = getnode(); // To hold POLY2
    head3 = getnode(); // To hold POLYSUM
    head->link = head;
    head1->link = head1;
    head2->link = head2;
    head3->link = head3;

    printf("\n~~~Menu~~~");
    printf("\n1. Represent and Evaluate a Polynomial P(x, y, z)");
    printf("\n2. Find the sum of two polynomials POLY1(x, y, z)");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\n~~~~ Polynomial Evaluation P(x, y, z) ~~~\n");
                head = read(head);
                printf("\nRepresentation of Polynomial for evaluation: \n");
                display(head);
                res = eval(head);
                printf("\nResult of polynomial evaluation is: %d \n", res);
                break;
            case 2:
                printf("\nEnter the POLY1(x, y, z):\n");
                head1 = read(head1);
                printf("\nPolynomial 1 is:\n");
                display(head1);
                printf("\nEnter the POLY2(x, y, z):\n");
                head2 = read(head2);
                printf("\nPolynomial 2 is:\n");
                display(head2);
                printf("\nPolynomial addition result:\n");
                head3 = poly_sum(head1, head2, head3);
                display(head3);
                break;
            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

