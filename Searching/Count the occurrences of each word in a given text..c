#include <stdio.h>
#include <string.h>
#include <ctype.h>

void wordCount(char text[]) {
    char unique_words[100][100]; // Intialising 2D array for storing the unique words
    int occurrences[100]; // Count of occurences of each word
    int word_count = 0; // Number of unique words found
    int i=0;
    int j=0;
    int found=0;

    // Convert the text to lowercase 
    for (i = 0; text[i] != '\0'; i++) {
        text[i] = tolower(text[i]);
    }

    // Tokenizing the text and count word occurrences
    i = 0;
    while (text[i] != '\0') {
        // Separating the words if a null character or a punctuation mark is encountered
        while (text[i] != '\0' && !isalnum(text[i])) {
            i++;
        }

        // Checking the end of the string 
        if (text[i] == '\0') {
            break;
        }

        // checking the end of the word
        j = 0;
        while (text[i] != '\0' && isalnum(text[i])) {
            unique_words[word_count][j] = text[i];
            i++;
            j++;
        }
        unique_words[word_count][j] = '\0'; // Null-terminate the word

        // Checking for repeating of words
        found = 0;
        for (j = 0; j < word_count; j++) {
            if (strcmp(unique_words[j], unique_words[word_count]) == 0) {
                occurrences[j]++;
                found = 1;
                break;
            }
        }

        // Adding unique words
        if (!found) {
            occurrences[word_count]++;
            word_count++;
        }
    }

    // Printing the results
    printf("Word occurrences:\n");
    for (i = 0; i < word_count; i++) {
        printf("%s: %d\n", unique_words[i], occurrences[i]);
    }
}

int main() {
    char text[100];
    printf("Enter the text:");
    gets(text);
    wordCount(text);

    return 0;
}
