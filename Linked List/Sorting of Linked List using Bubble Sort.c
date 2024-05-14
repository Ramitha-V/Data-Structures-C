#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to swap two nodes
void swapped(struct node *a, struct node *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to perform Bubble Sort on the linked list
void bubbleSort(struct node *start) {
    int swap;
    struct node *ptr1;
    struct node *ptr2 = NULL;

    if (start == NULL)
        return;

    do {
        swap=0;
        ptr1=start;

        while (ptr1->next !=ptr2) {
            if (ptr1->data > ptr1->next->data) {
                swapped(ptr1, ptr1->next);
                swap=1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swap);
}

int main() {
    struct node *head = NULL;
    struct node *newnode;
    struct node *temp;

    int choice;

    do {
        newnode = (struct node *)malloc(sizeof(struct node));

        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1; 
        }

        printf("Enter the data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to enter more nodes? (1/0): ");
        scanf("%d", &choice);

    } while (choice == 1);

    printf("The unsorted linked list is: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Sort the linked list using Bubble Sort
    bubbleSort(head);

    printf("\nThe sorted linked list is: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    //Free allocated memory
    temp = head;
    while (temp != NULL) {
        struct node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
