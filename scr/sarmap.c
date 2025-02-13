/*THIS FILE IS CREATED TO MAKE IT EASY FOR MY SELF IN STRING ARRAY MANIPULATION
CREATOR: JOHN MARK M. CAMOTA
MONTH AND YEAR: FEBUARY 2025 (START)
FINISH??
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputSTR() //for inputting string much more easier using dynamic memory 
{
    int size = 0;
    char *pstr = NULL;
    char *temp = NULL;
    char *final_str = NULL;
    char str;
    
    while(1) //1 is TRUE 
    {
        str = getchar();// getchar use to get input one at a time 
        if(str == '\n')
        {
            break;
        }

        temp = realloc(pstr, size + 1); //resizes the pointer string 
        if(temp == NULL)
        {
            printf("failed");
            free(pstr);
            return NULL;
        }

        pstr = temp;
        pstr[size] = str;
        size++;

    }

    
    final_str = realloc(pstr, size + 1);// final allocation to add one space and add the NULL character
    if (final_str != NULL )
    {
        pstr = final_str;
        pstr[size] = '\0';
    }
    else
    {
        printf("failed");
        free(pstr);
        return NULL;
    }
    return pstr;
}

char **arraySTR(char *string, char **array)//pointer to pointer array that stores the strings
{
    int count = 0;
    if(array != NULL) // checks the array size
    {
        while(array[count] != NULL)
        {
            count++;
        }
    }

    char **newarray = realloc(array, (count + 1 + 1) * sizeof(char *)); //sizes array and adding one for the new string

    if (newarray == NULL) {
        printf("failed to allocate memory for new array\n");
        return array;
    }

    array = newarray;
    array[count] = strdup(string);
    array[count + 1] = NULL;
    return array;
}

void clearBuffer() //used to remove the buffer on getchar(), must be used after calling the function 'inputSTR' on the main 
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
