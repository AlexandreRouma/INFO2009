#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Série 2, Exercice 2
    -------------------

    Unesuite de Collatz s’obtient en calculant, pour un nombre entier z0 > 1 donné, 
    les nombres z1, z2, z3, ... de la façon suivante. Pour tout i >= 0:

        | Si zi est pair: z(i + 1) = zi / 2
        | Si zi est impair: z(i + 1) = 3zi + 1

    Écrire un programme C capable de calculer, pour un nombre z0 entré au clavier,
    le nombre d’étapes nécessaires pour atteindre le nombre 1. (c’est-à-dire la plus 
    petite valeur de i pour laquelle on a zi= 1).

    Auteur: Alexandre Rouma
    Date:   12/09/2020
*/

int main() {
    int z0;

    printf("z0: ");
    if (!scanf("%d", &z0)) { printf("Valeur invalide!\n"); return 1; }
    
    if (z0 <= 2) {
        printf("Valeur invalide car z0 > 1\n");
        return 1;
    }

    bool odd = (z0 % 2);

    for (int i = 1;; i++) {
        if (odd) {
            z0 = (z0 * 3) + 1;
        }
        else {
            z0 /= 2;
        }
        if (z0 == 1) {
            printf("%d\n", i);
            return 0;
        }
        odd = (z0 % 2);
    }

    return 0;
}