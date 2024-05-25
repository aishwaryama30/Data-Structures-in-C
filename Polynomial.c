#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node {
    int co, ex, ey, ez;
    int flag;
    struct node *link;
};

typedef struct node* poly;

poly attach(int c, int x, int y, int z, poly head) {
    poly temp, cur;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->co = c;
    temp->ex = x;
    temp->ey = y;
    temp->ez = z;
    cur = head;
    while (cur->link != head)
        cur = cur->link;
    cur->link = temp;
    temp->link = head;
    return head;
}

poly read(poly head) {
    int cf, x, y, z, n;
    printf("\nEnter the number of terms: ");
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        printf("Enter value for term %d \n Coeff and 3 exponents: ",i);
        scanf("%d%d%d%d", &cf, &x, &y, &z);
        head = attach(cf, x, y, z, head);
    }
    return head;
}

void display(poly head) {
    poly temp;
    if (head->link == head) {
        printf("polynomial does not exist\n");
        return;
    }
    temp = head->link;
    while (temp != head) {
        if (temp->co < 0)
            printf(" %d x^%d y^%d z^%d", temp->co, temp->ex, temp->ey, temp->ez);
        else
            printf(" +%d x^%d y^%d z^%d", temp->co, temp->ex, temp->ey, temp->ez);
        temp = temp->link;
    }
}

poly add(poly first, poly sec, poly res) {
    poly a, b;
    int x1, x2, y1, y2, z1, z2, cf1, cf2, cf;
    a = first->link;
    while (a != first) {
        x1 = a->ex;
        y1 = a->ey;
        z1 = a->ez;
        cf1 = a->co;
        b = sec->link;
        while (b != sec) {
            x2 = b->ex;
            y2 = b->ey;
            z2 = b->ez;
            cf2 = b->co;
            if (x1 == x2 && y1 == y2 && z1 == z2)
                break;
            b = b->link;
        }
        if (b != sec) {
            cf = cf1 + cf2;
            b->flag = 1;
            if (cf != 0)
                res = attach(cf, x1, y1, z1, res);
            a = a->link;
        } else {
            res = attach(cf1, x1, y1, z1, res);
            a = a->link;
        }
    }
    b = sec->link;
    while (b != sec) {
        if (b->flag == 0)
            res = attach(b->co, b->ex, b->ey, b->ez, res);
        b = b->link;
    }
    return res;
}

void evaluate(poly head) {
    poly h1;
    int x, y, z;
    int result = 0;
    h1 = head->link;
    printf("\nEnter values of x, y and z to evaluate:\n");
    scanf("%d%d%d", &x, &y, &z);
    while (h1 != head) {
        result += h1->co * pow(x, h1->ex) * pow(y, h1->ey) * pow(z, h1->ez);
        h1 = h1->link;
    }
    printf("\nPolynomial result is: %d\n", result);
}

int main() {
    int ch;
    poly eval, first, sec, res;
    first = (struct node *)malloc(sizeof(struct node));
    sec = (struct node *)malloc(sizeof(struct node));
    res = (struct node *)malloc(sizeof(struct node));
    first->link = first;
    sec->link = sec;
    res->link = res;
    printf("\n1. Evaluate polynomial\n2. Add 2 polynomials\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
        case 1:
            printf("Enter the polynomial\n");
            eval = read(first);
            display(first);
            evaluate(eval);
            break;
        case 2:
            printf("Enter the first polynomial\n");
            first = read(first);
            printf("Enter the second polynomial\n");
            sec = read(sec);
            res = add(first, sec, res);
            printf("\nFirst Polynomial equation is\n");
            display(first);
            printf("\nSecond Polynomial equation is\n");
            display(sec);
            printf("\nResultant polynomial equation is \n");
            display(res);
            break;
        case 3:
            exit(0);
        default:
            printf("\nInvalid choice!!!\n");
    }
    return 0;
}

