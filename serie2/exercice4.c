#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Série 2, Exercice 3
    -------------------

    Écrire un programme C capable de factoriser un nombre entier entré au clavier. 
    Le résultat doit être affiché sous la forme:
    
        facteur_premier^puissance facteur_premier^puissance ...

    où les facteur premiers apparaissent dans l’ordre croissant.

    Auteur: Alexandre Rouma
    Date:   12/09/2020
*/

int next_prime(int n) {
    if (n == 2) {
        return 3;
    }

    bool divisible;
    for (int i = n + 2;; i += 2) {
        divisible = false;
        for (int j = i / 2; j > 1; j -= 2) {
            if (!(i % j)) {
                divisible = true;
                break;
            }
        }
        if (!divisible) {
            return i;
        }
    }

    return -1; // ???
}

int main() {
    int n = 0;

    printf("n: ");
    if (!scanf("%" PRId64, &n)) { printf("Valeur invalide!\n"); return 1; }

    if (n < 0) {
        printf("Erreur: n doit être positif\n");
        return 1;
    }

    int prime = 2;
    int count = 0;

    while (n > 1) {
        if (!(n % prime)) {
            count++;
            n /= prime;
        }
        else {
            if (count > 1) {
                printf("%d^%d ", prime, count);
            }
            else if (count == 1) {
                printf("%d ", prime);
            }
            count = 0;
            prime = next_prime(prime);
        }
    }

    if (count > 1) {
        printf("%d^%d ", prime, count);
    }
    else if (count == 1) {
        printf("%d ", prime);
    }

    printf("\n");

    return 0;
}