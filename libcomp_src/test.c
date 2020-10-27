#include <stdio.h>
#include <stdlib.h>
#include "libcomponent.h"
#define OMEGA "\u03a9"

int main(int argc, char* argv[]) {
    int i = 0;
    float res_array[3];
    float resistance = atof (argv[1]);
    int count = e_resistance(resistance, res_array);

    printf("Antal resistorer som behövs för att ersätta \"orig_resistance\" %.2f%s: %d\n", resistance, OMEGA,  count);

    for(i = 0; i < count; i++) {
        printf("Värde på resistor %d: %.2f%s\n", i+1, res_array[i], OMEGA);
    }
    return 0;
}