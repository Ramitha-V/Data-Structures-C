#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree (BST)
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given value
struct Node* create_node(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory Allocation failed\n");
        exit(1);
    }
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to insert a node with the given value into the BST
struct Node* insert_node(struct Node* root, int value) {
    if (root == NULL) {
        return create_node(value);
    }

    if (value < root->data) {
        root->left = insert_node(root->left, value);
    } else if (value > root->data) {
        root->right = insert_node(root->right, value);
    }
    return root;
}

// Function to perform an inorder traversal of the tree
void inorder_traversal(struct Node* root) {
    if (root == NULL) {
        return; // Base case: empty tree or leaf node
    }
    
    inorder_traversal(root->left);   // Traverse left subtree
    printf("%d ", root->data);       // Print current node
    inorder_traversal(root->right);  // Traverse right subtree
}

// Function to perform a pre-order traversal of the tree
void preorder_traversal(struct Node* root) {
    if (root == NULL) {
        return; // Base case: empty tree or leaf node
    }
    
    printf("%d ", root->data);       // Print current node
    preorder_traversal(root->left);  // Traverse left subtree
    preorder_traversal(root->right); // Traverse right subtree
}

// Function to perform a post-order traversal of the tree
void postorder_traversal(struct Node* root) {
    if (root == NULL) {
        return; // Base case: empty tree or leaf node
    }
    
    postorder_traversal(root->left);  // Traverse left subtree
    postorder_traversal(root->right); // Traverse right subtree
    printf("%d ", root->data);        // Print current node
}

// Function to search for a node with a given value in the BST
struct Node* search_node(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    } else {
        if (value < root->data) {
            return search_node(root->left, value);
        } else {
            return search_node(root->right, value);
        }
    }
}

// Function to find the minimum value node in a BST
struct Node* find_min_node(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node with a given value from the BST
struct Node* delete_node(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = delete_node(root->left, value);
    } else if (value > root->data) {
        root->right = delete_node(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children, get the inorder successor
        struct Node* temp = find_min_node(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice;
    int value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Search for a node\n");
        printf("3. Delete a node\n");
        printf("4. Inorder Traversal\n");
        printf("5. Pre-order Traversal\n");
        printf("6. Post-order Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //Switch case choices
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                root = insert_node(root, value);
                break;

            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                struct Node* search_result = search_node(root, value);
                if (search_result != NULL) {
                    printf("Node with value %d found in the tree.\n", search_result->data);
                } else {
                    printf("Node with value %d not found in the tree.\n", value);
                }
                break;

            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = delete_node(root, value);
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder_traversal(root);
                printf("\n");
                break;

            case 5:
                printf("Pre-order Traversal: ");
                preorder_traversal(root);
                printf("\n");
                break;

            case 6:
                printf("Post-order Traversal: ");
                postorder_traversal(root);
                printf("\n");
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
