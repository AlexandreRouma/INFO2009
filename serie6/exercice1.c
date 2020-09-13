#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

#define ENTRY_COUNT     64

/*
    Série 2, Exercice 1
    -------------------

    

    Auteur: Alexandre Rouma
    Date:   12/09/2020
*/

double moyenne(double* buf, size_t count) {
    double sum;
    for (size_t i = 0; i < count; i++) {
        sum += buf[i];
    }
    return sum / (double)count;
}

int main() {
    double* buf = (double*)malloc(ENTRY_COUNT * sizeof(double));

    for (size_t i = 0; i < ENTRY_COUNT; i++) {
        buf[i] = i;
    }

    printf("Moyenne: %lf\n", moyenne(buf, ENTRY_COUNT));

    free(buf);

    return 0;
}