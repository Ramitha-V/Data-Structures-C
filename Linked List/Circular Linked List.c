#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;  
        *head = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;  // Point to itself to create a circular link
        *head = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
    }
}

// Function to insert a node at a specified position in the circular linked list
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position <= 0) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* temp = *head;
    int count = 1;
    while (temp->next != *head && count < position - 1) {
        temp = temp->next;
        count++;
    }
    if (count < position - 1) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node from the beginning of the circular linked list
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    struct Node* temp = *head;
    if (temp->next == *head) {
        *head = NULL;
    } else {
        *head = temp->next;
        last->next = *head;
    }
    free(temp);
}

// Function to delete a node from the end of the circular linked list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* last = *head;
    struct Node* prev = NULL;
    while (last->next != *head) {
        prev = last;
        last = last->next;
    }
    if (last == *head) {
        *head = NULL;
    } else {
        prev->next = *head;
    }
    free(last);
}

// Function to delete a node from a specified position in the circular linked list
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    int count = 1;
    while (temp->next != *head && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (count < position) {
        printf("Invalid position\n");
        return;
    }
    if (temp == *head) {
        if (temp->next == temp) {
            *head = NULL;
        } else {
            *head = temp->next;
            prev->next = *head;
        }
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Function to search for an element and delete it
void searchAndDelete(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    do {
        if (temp->data == key) {
            if (temp == *head) {
                if (temp->next == temp) {
                    *head = NULL;
                } else {
                    *head = temp->next;
                    prev->next = *head;
                }
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Element %d deleted successfully\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != *head);
    printf("Element %d not found in the list\n", key);
}

// Function to reverse the circular linked list
void reverse(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);
    (*head)->next = prev;
    *head = prev;
}

void display(struct Node* head) {
    struct Node* current = head;
    if (head == NULL) {
        printf("Circular Linked List is empty\n");
        return;
    }
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}


int main() {
    struct Node* head = NULL;
    int choice, data, position, key;

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specified position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from a specified position\n");
        printf("7. Search and delete\n");
        printf("8. Reverse\n");
        printf("9. Display\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                display(head);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                display(head);
                
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                display(head);
                break;
            case 4:
                deleteFromBeginning(&head);
                display(head);
                break;
            case 5:
                deleteFromEnd(&head);
                display(head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                display(head);
                break;
            case 7:
                printf("Enter element to search and delete: ");
                scanf("%d", &key);
                searchAndDelete(&head, key);
                display(head);
                break;
            case 8:
                reverse(&head);
                display(head);
                break;
            case 9:
                display(head);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
