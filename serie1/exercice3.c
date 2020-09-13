#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

#define N_MAX   1000000

/*
    Série 1, Exercice 3
    -------------------
    
    Un nombre entier positif est premier s’il possède exactement deux diviseurs: 1 et lui-même.
    Ecrire un programme capable de trouver tous les nombres premiers de 6 chiffres ou moins.

    Auteur: Alexandre Rouma
    Date:   12/09/2020
*/

int main() {
    printf("1\n2\n");

    uint64_t maxCheck;
    bool divisble;

    for (uint64_t i = 3; i < N_MAX; i += 2) {
        maxCheck = i / 2;
        divisble = false;

        for (uint64_t j = 3; j <= maxCheck; j += 2) {
            if (!(i % j)) {
                divisble = true;
                break;
            }
        }

        if (!divisble) {
            printf("%" PRId64 "\n", i);
        }
    }

    printf("===== TERMINÉ =====\n");

    return 0;
}