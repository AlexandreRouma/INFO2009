#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Série 2, Exercice 3
    -------------------

    Écrire un programme C permettant de calculer efficacement la valeur d’un coefficient binomial

    Cmn = n! / (m! * (n - m)!)

    Auteur: Alexandre Rouma
    Date:   12/09/2020
*/

int main() {
    uint64_t m, n, n_minus_m;

    printf("m: ");
    if (!scanf("%" PRId64, &m)) { printf("Valeur invalide!\n"); return 1; }
    printf("n: ");
    if (!scanf("%" PRId64, &n)) { printf("Valeur invalide!\n"); return 1; }

    if (n < m) {
        printf("Erreur: m doit être inférieur à n\n");
        return 1;
    }

    n_minus_m = n - m;

    uint64_t fact_m = 1;
    uint64_t fact_n = 1;
    uint64_t fact_n_minus_m = 1;

    for (int i = 2; i <= n; i++) {
        fact_n *= i;
        if (i <= m) {
            fact_m *= i;
        }
        if (i <= n_minus_m) {
            fact_n_minus_m *= i;
        }
    }

    printf("%" PRId64 "\n", fact_n / (fact_m * fact_n_minus_m));

    return 0;
}