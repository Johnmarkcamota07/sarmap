#include "include/sarmap.h"

int main() //main function to check if everything is working
{   
    int count = 0;
    char **array = NULL;
    char choice;

    do {
        printf("input string: ");
        char *string = inputSTR();
        array = arraySTR(string, array);
        printf("string: %s\n", string);

        if(array != NULL) {
            count = 0;
            while (array[count] != NULL) {
                printf("string no. %d: %s\n", count, array[count]);
                count++;
            }
        }
        free(string); // Free the string after it has been added to the array
        printf("Do you want to add another string? (y/n): ");
        scanf(" %c", &choice);

        clearBuffer();

    } while(choice == 'y' || choice == 'Y');

    if(array != NULL) {
        count = 0;
        while(array[count] != NULL) {
            free(array[count]);
            count++; // Increment count to avoid infinite loop
        }
    }
    free(array);
    return 0; 
}
