#include "include/sarmap.h"

int main() {
    printf("Enter a string: ");
    char *userInput = inputSTR();
    clearBuffer();

    if (userInput) {
        printf("You entered: %s\n", userInput);
    }

    char **words = NULL;
    words = arraySTR(userInput, words);

    // Print stored words
    for (int i = 0; words[i] != NULL; i++) {
        printf("Word[%d]: %s\n", i, words[i]);
    }

    free(userInput);

    return 0;
}
