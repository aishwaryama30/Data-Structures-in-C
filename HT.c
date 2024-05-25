#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 3

struct employee
{
    int flag;
    int eid;
    char ename[15];
};

struct employee emp[MAX];

int hash(int key)
{
    int index;
    index = key % MAX;
    return index;
}

int linear_prob(int addr)
{
    int i = (addr + 1) % MAX;
    while (i != addr)
    {
        if (emp[i].flag != -1)
            i = (i + 1) % MAX; // Changed from (i++) to (i + 1)
        else
            break;
    }
    if (i != addr)
        return i;
    else
        return -1;
}

void insert()
{
    int id, addr;
    char name[15];
    printf("\nEnter emp id: ");
    scanf("%d", &id);
    printf("\nEnter emp name: ");
    scanf("%s", name);
    addr = hash(id);
    printf("addr=%d", addr);
    if (emp[addr].flag == -1)
    {
        emp[addr].eid = id;
        emp[addr].flag = 1;
        strcpy(emp[addr].ename, name);
    }
    else
    {
        printf("\nCollision detected..");
        addr = linear_prob(addr);
        if (addr != -1)
        {
            emp[addr].eid = id; 
            emp[addr].flag = 1;
            strcpy(emp[addr].ename, name);
        }
        else
        {
            printf("\nHash Table is full.. Cannot insert");
            return;
        }
    }
}

void display()
{
    int i;
    printf("\nThe hash table is:\n");
    printf("\nHTKey\tEmpID\tEmpName");
    for (i = 0; i < MAX; i++)
    {
        if (emp[i].flag != -1)
        {
            printf("\n%d\t%d\t%s", i, emp[i].eid, emp[i].ename);
            continue;
        }
    }
}

int main() // Changed from void to int
{
    int i, ch;
    printf("\nCollision handling by linear probing");
    for (i = 0; i < MAX; i++)
    {
        emp[i].flag = -1;
    }
    printf("\n1.Insert\n2.Display\n");
    for (;;)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(); // Changed from getdata() to insert()
            break;
        case 2:
            display();
            break;
        default:
            exit(0);
        }
    }
    return 0; // Added return 0 to indicate successful execution
}

