#include <stdio.h>

/*
    Série 1, Exercice 1
    -------------------
    
    Écrire un programme permettant de convertir une température tF exprimée
    en degrés Fahrenheit vers une température tC exprimée en degré.
    Si la valeur calculée de tC est inférieure à 2°C, le programme doit également
    afficher qu’un risque de verglas est présent.

    Auteur: Alexandre Rouma
    Date:   12/09/2020
*/

int main() {
    double tF, tC;

    printf("tF: ");
    if (!scanf("%lf", &tF)) { printf("Valeur invalide!\n"); return 1; }

    tC = (tF - 32.0) * (5.0 / 9.0);

    printf("tC: %lf°C%s\n", tC, tC < 2.0 ? "\nATTENTION: Risque de verglas!!!" : "");

    return 0;
}