#include <stdio.h>
#include <string.h>
#include <ctype.h> // Include the header for the tolower() function

// Function to perform binary search for the target word in the sorted array of words(strings)
int binarySearchWords(char *words[], int size, char *target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int comp = strcasecmp(words[mid], target); // Comparing the target words and the middle word with case-insensitivity

        if (comp == 0) {
            return mid; // Target word found at index mid
        } else if (comp < 0) {
            low = mid + 1; // Target word should be in the right half
        } else {
            high = mid - 1; // Target word should be in the left half
        }
    }

    return -1; // Target word not found in the array
}

int main() {
    int size;
    printf("Enter the number of words: ");
    scanf("%d", &size);

    char *words[size];

    // Input sorted words from the user
    printf("Enter the sorted words (separated by spaces):\n");
    for (int i = 0; i < size; i++) {
        words[i] = (char *)malloc(100 * sizeof(char)); // Allocate memory for each word
        scanf("%s", words[i]);

        // Convert the word to lowercase using a loop
        for (int j = 0; words[i][j]; j++) {
            words[i][j] = tolower(words[i][j]);
        }
    }

    char target[100];
    printf("Enter the target word to search for: ");
    scanf("%s", target);

    // Convert the target word to lowercase using a loop
    for (int i = 0; target[i]; i++) {
        target[i] = tolower(target[i]);
    }

    int index = binarySearchWords(words, size, target);

    if (index != -1) {
        printf("The word '%s' is found at index %d.\n", target, index);
    } else {
        printf("The word '%s' is not present in the array.\n", target);
    }

    // Free allocated memory for each word
    for (int i = 0; i < size; i++) {
        free(words[i]);
    }

    return 0;
}
