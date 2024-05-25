#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};

typedef struct BST NODE;
NODE *root = NULL;

NODE *insert(NODE *node, int item) {
    if (node == NULL) {
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        temp->data = item;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (item < node->data)
        node->left = insert(node->left, item);
    else if (item > node->data)
        node->right = insert(node->right, item);

    return node;
}

void inorder(NODE *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d\t", node->data);
        inorder(node->right);
    }
}

void deleteNode(NODE *node, int item) {
    if (node == NULL) {
        printf("Item not found\n");
        return;
    }

    if (item < node->data)
        deleteNode(node->left, item);
    else if (item > node->data)
        deleteNode(node->right, item);
    else {
        if (node->left == NULL) {
            NODE *temp = node->right;
            free(node);
            if (temp) temp->right = NULL;
        } else if (node->right == NULL) {
            NODE *temp = node->left;
            free(node);
            if (temp) temp->left = NULL;
        } else {
            NODE *temp = node->right;
            while (temp->left != NULL)
                temp = temp->left;
            node->data = temp->data;
            deleteNode(node->right, temp->data);
        }
    }
}

int main() {
    int choice, item;

    do {
        printf("\n----- Menu -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter items to create BST like (6,9,5,2,8,15,24,14,7, 8,5,2 )\n");
		for(int i=0;i<12;i++)
		{
			scanf("%d", &item);
			root = insert(root,item);
		}
		break;
            case 2:
                printf("\nEnter element to delete: ");
                scanf("%d", &item);
                deleteNode(root, item);
                break;
            case 3:
                printf("\nInorder Traversal:\n");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

