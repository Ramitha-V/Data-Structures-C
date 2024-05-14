#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct Node {
    int rno;             // Student roll number
    struct Node* next;   // Pointer to the next node
    struct Node* prev;   // Pointer to the previous node
};

// Function to insert a new node at the beginning of the list
struct Node* Insertion_at_Beginning(struct Node* head) {
    // Allocate memory for a new node
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory Allocation failed");  // Memory allocation error
        exit(1);
    }
    printf("Enter the Roll no:");
    scanf("%d", &newnode->rno);

    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL) {
        head->prev = newnode;
    }
    head = newnode;  // Update the head to the new node

    return head;
}

// Function to insert a new node at the end of the list
struct Node* Insertion_at_End(struct Node* head) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory Allocation failed");
        exit(1);
    }
    printf("Enter the roll no:");
    scanf("%d", &newnode->rno);

    struct Node* temp = head;
    newnode->next = NULL;
    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;  // If the list is empty, the new node becomes the head
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        newnode->prev = temp;
        temp->next = newnode;  // Update the last node's next pointer to the new node
    }

    return head;
}

// Function to insert a new node at a specified position in the list
struct Node* Insertion_at_Position(struct Node* head, int pos) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (pos <= 0 || pos > count + 1) {
        printf("Invalid Position\n");
    } else {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        if (newnode == NULL) {
            printf("Memory Allocation failed\n");
            exit(1);
        }
        printf("Enter the roll no: ");
        scanf("%d", &newnode->rno);

        if (pos == 1) {
            return Insertion_at_Beginning(head);  // Insert at the beginning
        } else if (pos == count + 1) {
            return Insertion_at_End(head);  // Insert at the end
        } else {
            temp = head;
            int i = 1;
            while (i < pos - 1) {
                temp = temp->next;
                i++;
            }
            newnode->prev = temp;
            newnode->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = newnode;
            }
            temp->next = newnode;  // Insert at the specified position
        }
    }
    return head;
}

// Function to delete a node from the beginning of the list
struct Node* Deletion_from_Beginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);  // Free memory for the deleted node
    return head;
}

// Function to delete a node from the end of the list
struct Node* Deletion_from_End(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;  // If list had only one element, set head to NULL
    }

    free(temp);  // Free memory for the deleted node
    return head;
}

// Function to delete a node from a specified position in the list
struct Node* Deletion_from_Position(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    int count = 0;
    struct Node* temp = head;

    // Count the number of nodes in the list
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (pos <= 0 || pos > count) {
        printf("Invalid Position\n");
    } else if (count == 1 || pos == 1) {
        // Special case: Deleting the first element
        head = Deletion_from_Beginning(head);
    } else if (pos == count) {
        // Special case: Deleting the last element
        head = Deletion_from_End(head);
    } else {
        temp = head;
        int i = 1;
        while (i < pos) {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);  // Free memory for the deleted node
    }

    return head;
}

// Function to print the elements of the list
void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->rno);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *head=NULL;
    struct Node *temp=NULL;

    // Create the first node for the initial list
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    if (newnode==NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }
    newnode->next=NULL;
    newnode->prev=NULL;
    printf("Enter the roll no:");
    scanf("%d",&newnode->rno);

    if (head==NULL){
        head=newnode;
        temp=newnode;
    }
    else{
        newnode->next=NULL;
        newnode->prev=temp;
        temp->next=newnode;
    }

    temp=head;
    printf("The entered roll number is:");
    while(temp!=NULL){
        printf("%d",temp->rno);
        temp=temp->next;
    }
    int choice;

    do {
        printf("\n");
        printf("0. Stop Inserting\n");
        printf("1. Insertion at beginning\n");
        printf("2. Insertion at End\n");
        printf("3. Insertion at Position\n");
        printf("4. Deletion from the beginning\n");
        printf("5. Deletion from the end\n");
        printf("6. Deletion from a position\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                break;
            case 1:
                head = Insertion_at_Beginning(head);
                print(head);
                break;
            case 2:
                head = Insertion_at_End(head);
                print(head);
                break;
            case 3:
                int position;
                printf("Enter the position: ");
                scanf("%d", &position);
                head = Insertion_at_Position(head, position);
                print(head);
                break;
            case 4:
                head = Deletion_from_Beginning(head);
                print(head);
                break;
            case 5:
                head = Deletion_from_End(head);
                print(head);
                break;
            case 6:
                int pos;
                printf("Enter the position: ");
                scanf("%d", &pos);
                head = Deletion_from_Position(head, pos);
                print(head);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 0);
    
    printf("The original list is: ");
    print(head);

    // Reverse the list
    temp = NULL;
    struct Node* current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev; // Set the new head
    }

    printf("The Reversed list is: ");
    print(head);

    // Free memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}
