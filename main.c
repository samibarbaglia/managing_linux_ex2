#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "generator.h"

int main(int argc, char *argv[]) {

    if (argc != 4) {
        if (argc < 4) {
            printf("ERROR: Not enough values. Expected 3, got %d\n", argc - 1);
        }
        else {
            printf("ERROR: Too many values. Expected 3, got %d\n", argc - 1);
        }
        return 1;
    }

    if (!is_number(argv[1]) || !is_number(argv[2]) || !is_number(argv[3])) {
        printf("ERROR: All values must be NUMBERS\n");
        return 1;
    }
   
    int min = atoi(argv[1]);
    int max = atoi(argv[2]);
    int count = atoi(argv[3]);

    printf("1: %d, 2: %d, 3: %d\n", min, max, count);

    generate_random(min, max, count);

    return 0;
}