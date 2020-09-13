#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
    Série 1, Exercice 4
    -------------------
    
    La multifactorielle M(n, k) des deux entiers strictement positifs n et k est définie
    comme le produit M(n, k) = n*(n−k)*(n−2k) ··· de tous les entiers strictement
    positifs m tels que m <= n et n − m est divisible par k. Ecrire un programme 
    capable de calculer la multifactorielle de deux nombres donnés.

    Auteur: Alexandre Rouma
    Date:   12/09/2020
*/

int main() {
    int n, k;

    printf("n: ");
    if (!scanf("%d", &n)) { printf("Valeur invalide!\n"); return 1; }
    printf("k: ");
    if (!scanf("%d", &k)) { printf("Valeur invalide!\n"); return 1; }

    if (n < 0 || k < 0) {
        printf("Erreur: Les valuers doivent être positives\n");
        return 1;
    }

    uint64_t M = n;

    for (int i = 1; n - (i * k) > 0; i++) {
        M *= n - (i * k);
    }

    printf("%" PRId64 "\n", M);

    return 0;
}