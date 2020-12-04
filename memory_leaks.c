/*
 * This program demonstrates that memory leaks arise when allocating
 * memory on the heap and not freeing it before the program ends.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 100

int main(){
    // create and array of ARR_SIZE ints
    int* intArray = malloc(sizeof(int) * ARR_SIZE);

    // populate them
    for(int i = 0; i < ARR_SIZE; i++){
        intArray[i] = i;
    }

    // print one of them randomly
    // first, seed the random number generator
    srand(time(NULL));
    int randNum = rand() % ARR_SIZE;

    printf("intArray[%d]: %d\n", randNum, intArray[randNum]);

    // end without freeing!
    return 0;
}