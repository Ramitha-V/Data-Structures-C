// Insertion of linked lists
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student node
struct student {
    int Roll_No;
    char Name[30];
    int Age;
    struct student* Next;
};

typedef struct student student;

// Function to insert a new student node at the beginning
student* Insert_at_Beginning(student* head) {
    // Allocate memory for a new student node
    student* new_student = (student*)malloc(sizeof(student));

    // Input details for the student
    printf("Enter details for the student:\n");
    printf("Enter the Roll Number: ");
    scanf("%d", &new_student->Roll_No);

    printf("Enter the Name: ");
    scanf("%s", new_student->Name);

    printf("Enter the Age: ");
    scanf("%d", &new_student->Age);

    // Update the next pointer to point to the previous head
    new_student->Next = head;

    return new_student; // New node becomes the new head
}

// Function to insert a new student node at the end
student* Insert_At_End(student* head) {
    student* new_student = (student*)malloc(sizeof(student));

    printf("Enter details for the student:\n");
    printf("Enter the Roll Number: ");
    scanf("%d", &new_student->Roll_No);

    printf("Enter the Name: ");
    scanf("%s", new_student->Name);

    printf("Enter the Age: ");
    scanf("%d", &new_student->Age);

    new_student->Next = NULL; // New node is the last node

    if (head == NULL) {
        return new_student; // If list is empty, new node becomes head
    }

    student* current = head;
    while (current->Next != NULL) {
        current = current->Next; // Traverse to the last node
    }

    current->Next = new_student; // Link new node to the last node

    return head; // Return the head
}

// Function to insert a new student node at a specified position
student* insert_At_Position(student* head, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return head;
    }

    // Count the number of nodes in the linked list
    int count = 0;
    student* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->Next;
    }

    if (position > count + 1) {
        printf("Position is out of range.\n");
        return head;
    }

    if (position == 1) {
        return Insert_at_Beginning(head); // Call the insertAtBeginning function
    }

    student* new_student = (student*)malloc(sizeof(student));

    printf("Enter details for the student:\n");
    printf("Enter the Roll Number: ");
    scanf("%d", &new_student->Roll_No);

    printf("Enter the Name: ");
    scanf("%s", new_student->Name);

    printf("Enter the Age: ");
    scanf("%d", &new_student->Age);

    student* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->Next; // Traverse to the node before the insertion point
    }

    new_student->Next = current->Next; // Link new node to the next node
    current->Next = new_student; // Link the previous node to the new node

    return head;
}

// Function to print the linked list
void printList(student* head) {
    student* current = head;
    while (current != NULL) {
        printf("\n");
        printf("The Roll Number is: %d\n", current->Roll_No);
        printf("The Name is: %s\n", current->Name);
        printf("The Age is: %d\n\n", current->Age);
        current = current->Next;
    }
}

int main() {
    student* head = NULL; // Initialize an empty linked list

    int choice;
    do {
        printf("Enter 0 to stop, 1 to insert at the beginning, 2 to insert at the end, 3 to insert at a position: ");
        scanf("%d", &choice);

        if (choice == 1) {
            head = Insert_at_Beginning(head); // Call the insertAtBeginning function
        } else if (choice == 2) {
            head = Insert_At_End(head); // Call the insertAtEnd function
        } else if (choice == 3) {
            int position;
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            head = insert_At_Position(head, position); // Call the insertAtPosition function
        }
    } while (choice != 0);

    // Print the linked list
    printList(head);

    // Free the allocated memory for the linked list
    student* current = head;
    while (current != NULL) {
        student* temp = current;
        current = current->Next;
        free(temp);
    }

    return 0;
}
