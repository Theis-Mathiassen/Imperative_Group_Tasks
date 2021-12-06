#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define FILE_PATH "text.txt"
#define MAX_NAME_LGT 50
#define NUM_PEOPLE 11
struct person{
    char fornavn[MAX_NAME_LGT];
    char efternavn[MAX_NAME_LGT];
    char vejnavn[MAX_NAME_LGT];
    int vejnummer;
    int postnummer;
    char bynavn[MAX_NAME_LGT];
};

int main (void) {

    struct person persons[NUM_PEOPLE];

    FILE *file = fopen(FILE_PATH, "r");
    FILE *writeFile = fopen("out.txt", "w");
    if(file == NULL) {
        perror("Error opening file");
        return(-1);
    }
    char stringInput[MAX_NAME_LGT];
    for (int i = 0; fgets(stringInput, MAX_NAME_LGT, file) != NULL; i++) {
        printf("%s", stringInput);
        sscanf(stringInput, "%s %[^,], %[^0123456789] %i, %i %[^.]", persons[i].fornavn, persons[i].efternavn, persons[i].vejnavn, &(persons[i].vejnummer), &(persons[i].postnummer), persons[i].bynavn);
        fprintf(writeFile,"Fornavn: %s, Efternavn: %s, Vejnavn: %s, Vejnummer: %d, Postnummer: %d, Bynavn: %s.\n", persons[i].fornavn, persons[i].efternavn, persons[i].vejnavn, persons[i].vejnummer, persons[i].postnummer, persons[i].bynavn);
    }

    fclose(file);


    return EXIT_SUCCESS;
}