#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};



struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);  // duplicates go right

    return root;
}

void inorderTraversal(struct TreeNode* root) {
    static int depth = 0;

    if (root == NULL) {
        if (depth == 0)
            printf("The tree is empty\n");
        return;
    }

    depth++;

    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);

    depth--;

    if (depth == 0)
        printf("\n");
}

void preorderTraversal(struct TreeNode* root) {
    static int depth = 0;

    if (root == NULL) {
        if (depth == 0)
            printf("The tree is empty\n");
        return;
    }

    depth++;

    printf("%d ", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);

    depth--;

    if (depth == 0)
        printf("\n");
}
void postorderTraversal(struct TreeNode* root) {
    static int depth = 0;

    if (root == NULL) {
        if (depth == 0)
            printf("The tree is empty\n");
        return;
    }

    depth++;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->val);

    depth--;

    if (depth == 0)
        printf("\n");
}

struct TreeNode* findMin(struct TreeNode* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int val, int* found) {
    if (root == NULL)
        return NULL;

    if (val < root->val)
        root->left = deleteNode(root->left, val, found);

    else if (val > root->val)
        root->right = deleteNode(root->right, val, found);

    else {
        *found = 1;

        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val, found);
    }

    return root;
}

void freeTree(struct TreeNode* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}


int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    while (1) {
        printf("1. Insert Node\n");
        printf("2. In-Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Data: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                inorderTraversal(root);
                break;
            case 3:
                preorderTraversal(root);
                break;
            case 4:
                postorderTraversal(root);
                break;
            case 5: {
                printf("Delete: ");
                scanf("%d", &data);
                int found = 0;
                root = deleteNode(root, data, &found);
                if (!found) {
                    printf("Value not found\n");
                }
                break;
            }
            case 6:
                freeTree(root);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
