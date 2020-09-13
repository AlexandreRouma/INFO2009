#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>
#include <stdlib.h>

/*
    Série 1, Exercice 6
    -------------------
    
    Écrire un programme capable de calculer la valeur de {log2x} pour un nombre entier 
    strictement positif x donné, où {x} dénote le plus grand entier inférieur ou égal à x.

    Auteur: Alexandre Rouma
    Date:   12/09/2020
*/

int main() {
    double x;
    
    printf("x: ");
    if (!scanf("%lf", &x)) { printf("Valeur invalide!\n"); return 1; }

    printf("%lf\n", floor(log2(x)));

    return 0;
}