#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 80

int CalcBlobSize (int array[], int arrayChecked[], int posX, int posY);

int main (void) {
    srand(time(0));
    int *array = malloc(sizeof(int) * WIDTH * HEIGHT);
    int *arrayChecked = malloc(sizeof(int) * WIDTH * HEIGHT);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        array[i] = (rand() % 10) > 0 ? 0: 1;
        arrayChecked[i] = 0;
        if (i % WIDTH == 0) {
            printf("\n");
        }
        if (array[i] == 0) {
            printf("  ", array[i]);
        } else {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
    
    //printf("Neigbors of x= %d, y= %d equals: %d\n", 0, 1, GetUnCountedNeighbors(array, arrayChecked, 0, 1));
    printf("Blob size of x= %d, y= %d equals: %d\n", WIDTH/2, HEIGHT/2, CalcBlobSize(array, arrayChecked, WIDTH/2, HEIGHT/2));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (i % WIDTH == 0) {
            printf("\n");
        }
        if (array[i] == 0) {
            printf("  ", array[i]);
        } else {
            printf("%d ", array[i]);
        }
    }
    printf("\n");

    return EXIT_SUCCESS;
}

int CalcBlobSize (int array[], int arrayChecked[], int posX, int posY) {
    int index = posY * WIDTH + posX;
    int result = 0;
    if (arrayChecked[index] == 1 || array[index] == 0) {
        result = 0;
    }
    else {
        arrayChecked[index] = 1;
        result = 1;
        array[index]++;
        for (int i = -1; i <= 1; i++) {
            int y = posY + i;
            if (y >= 0 && y < HEIGHT) {
                for (int j = -1; j <= 1; j++) {
                    int x = posX + j;
                    if ((i != 0 || j != 0) && (x >= 0 && x < WIDTH)) {
                        int offsetIndex = y * WIDTH + x;
                        if (array[offsetIndex] == 1) {
                            result += CalcBlobSize(array, arrayChecked, x, y);
                        }
                    }
                }
            }
        }
    }
    return result;
}