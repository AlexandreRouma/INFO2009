#include <stdio.h>
#include <math.h>

/*
    Série 1, Exercice 2
    -------------------
    
    Écrire un programme capable de résoudre l’équation ax^2 + bx + c = 0,
    pour des valeurs quelconques de a, b et c.

    Auteur: Alexandre Rouma
    Date:   12/09/2020
*/

int main() {
    double a, b, c;

    printf("a: ");
    if (!scanf("%lf", &a)) { printf("Valeur invalide!\n"); return 1; }
    printf("b: ");
    if (!scanf("%lf", &b)) { printf("Valeur invalide!\n"); return 1; }
    printf("c: ");
    if (!scanf("%lf", &c)) { printf("Valeur invalide!\n"); return 1; }

    if (a == 0) {
        printf("Erreur: A ne peut pas valoir 0\n");
        return 1;
    }

    double delta = (b * b) - (4 * a * c);

    if (delta < 0) {
        printf("Pas de solutions\n");
        return 0;
    }

    double z0 = ((0 - b) - sqrt(delta)) / (2 * a);
    double z1 = ((0 - b) + sqrt(delta)) / (2 * a);

    if (delta == 0) {
        printf("Zero double: %lf\n", z0);
        return 0;
    }
    
    printf("Zeros: %lf et %lf\n", z0, z1);
    
    return 0;
}