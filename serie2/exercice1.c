#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

/*
    Série 2, Exercice 1
    -------------------

    Les nombres de Fibonacci F1, F2, F3, ... sont définis par les règles suivantes:
        F1 = 1
        F2 = 1
        Fn = F(n - 1) + Fn
    
    Écrire un programme C capable de calculer efficacement la valeur de Fn pour un indice n donné.

    Auteur: Alexandre Rouma
    Date:   12/09/2020
*/

int main() {
    int n;

    printf("n: ");
    if (!scanf("%d", &n)) { printf("Valeur invalide!\n"); return 1; }
    
    if (n <= 2) {
        printf("Valeur invalide car n > 2\n");
        return 1;
    }
    n -= 2;

    int n_minus_1 = 1;
    int n_minus_2 = 1;
    int temp;
    for (int i = 0; i < n; i++) {
        temp = n_minus_1 + n_minus_2;
        n_minus_2 = n_minus_1;
        n_minus_1 = temp;
    }

    printf("%d\n", n_minus_1);

    return 0;
}