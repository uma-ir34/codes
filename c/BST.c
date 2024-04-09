#include<stdio.h>
#include<stdlib.h>

// Define a structure for a node in the binary search tree
typedef struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new node with the given key
TreeNode* createNode(int key) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key into the binary search tree
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to search for a key in the binary search tree
void search(TreeNode* root, int key) {
    if (root == NULL) {
        printf("Key not found. Inserting %d.\n", key);
        insert(root, key);
    } else if (key == root->key) {
        printf("Key found.\n");
    } else if (key < root->key) {
        search(root->left, key);
    } else {
        search(root->right, key);
    }
}

// Function to perform inorder traversal
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal
void preorderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform postorder traversal
void postorderTraversal(TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

int main() {
    TreeNode* root = NULL;
    int choice, key;

    do {
        printf("\n1. Search/Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to search/insert: ");
                scanf("%d", &key);
                search(root, key);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }

    } while (choice != 5);

    return 0;
}
