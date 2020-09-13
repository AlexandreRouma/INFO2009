#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

/*
    Série 2, Exercice 1
    -------------------

    

    Auteur: Alexandre Rouma
    Date:   12/09/2020
*/

uint64_t factorial(int n) {
    uint64_t fact = 1;
    for (int i = 2; i < n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    

    return 0;
}