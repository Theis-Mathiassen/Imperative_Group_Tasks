#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main (void) {
    char* stringInputWord;
    char* stringResultWord;
    int length;

    printf("Type your word> ");
    scanf(" %s", stringInputWord);

    

    length = strlen(stringInputWord);
    printf("%d\n", length);

    stringResultWord = malloc(length + 4);
    
    strcpy(stringResultWord, stringInputWord);

    printf("String %s\n", stringResultWord);

    if (stringResultWord[(length-1)] == 'y')
    {
        stringResultWord[length-1] = '\0';
        char temp[] = "ies";
        strcat(stringResultWord, temp);
    } else if (stringResultWord[(length-1)] == 's') {
        char temp[] = "es";
        strcat(stringResultWord, temp);
    } else {
        char temp[] = "s";
        strcat(stringResultWord, temp);
    }
       

    printf("String: %s, with length %d", stringResultWord, length);
    free(stringResultWord);
    return EXIT_SUCCESS;
}