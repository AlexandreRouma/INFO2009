#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>
#include <stdlib.h>

/*
    Série 1, Exercice 5
    -------------------
    
    Écrire un programme capable de calculer la somme, le produit,
    la moyenne arithmétique, le plus grand et le plus petit élément d’un
    ensemble (fini) quelconque de nombres réels entrés au clavier.

    Auteur: Alexandre Rouma
    Date:   12/09/2020
*/

int main() {
    int n;
    double* nums;
    double min = INFINITY;
    double max = -INFINITY;
    double val;

    printf("Nombre de réels: ");
    if (!scanf("%d", &n)) { printf("Valeur invalide!\n"); return 1; }
    if (n <= 0) { printf("Valeur invalide!\n"); return 1; }

    nums = (double*)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        printf("Réel n°%d: ", i + 1);
        if (!scanf("%lf", &val)) { printf("Valeur invalide!\n"); return 1; }

        if (val < min) {
            min = val;
        }
        if (val >  max) {
            max = val;
        }

        nums[i] = val;
    }

    double sum;
    double prod = 1;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        prod *= nums[i];
    }

    free(nums);

    printf("Somme: %lf, Produit: %lf, Moyenne: %lf, Min: %lf, Max: %lf\n", sum, prod, sum / (double)n, min, max);

    return 0;
}