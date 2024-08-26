#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "generator.h"

int is_number(const char *str) {
    // Check if the string represents a valid integer
    if (*str == '-' || *str == '+') str++; // Skip leading sign

    if (*str == '\0') return 0; // Empty string after sign

    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

void generate_random(int min, int max, int count) {
    int range = (max-min)+1;
    int *values = malloc(range * sizeof(int));

    if (min > max) {
        printf("ERROR: Max cannot be less than min!!\n");
        return;
    }
    if (count > range) {
        printf("ERROR: Range cannot be less than number of unique values!!\n");
        return;
    }
    if (count <= 0) {
        printf("ERROR: Values must be positive!!\n");
        return;
    }

    srand(time(NULL));

    for (int i = 0; i<range; i++) {
        values[i] = min + i;
    }

    for (int i=0; i < count; i++) {
        int index = rand() % range;
        printf("Value %d : %d \n", i+1, values[index]);

        values[index] = values[range - 1];
        range--;
    }

    free(values);

}
