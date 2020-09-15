#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <draw.h>

#define PATH        "output/S5E2.svg"
#define WIDTH       400
#define HEIGHT      400
#define STEPS       21

/*
    Série 5, Exercice 1
    -------------------

    

    Auteur: Alexandre Rouma
    Date:   12/09/2020
*/

int main() {
    draw_init(PATH, WIDTH, HEIGHT);

    double dx = (double)WIDTH / (double)(STEPS - 1) / 2.0;
    double dy = (double)HEIGHT / (double)(STEPS - 1) / 2.0;
    double cx = (double)WIDTH / 2.0;
    double cy = (double)HEIGHT / 2.0;

    draw_line(0, 0, WIDTH - 1, 0, 2, 0, 0, 0);
    draw_line(0, HEIGHT - 1, WIDTH - 1, HEIGHT - 1, 2, 0, 0, 0);
    draw_line(0, 0, 0, HEIGHT - 1, 2, 0, 0, 0);
    draw_line(WIDTH - 1, 0, WIDTH - 1, HEIGHT - 1, 2, 0, 0, 0);

    for (int i = 0; i < STEPS; i++) {
        draw_line(cx + (dx * i), cy, cx, cy + (dy * (STEPS - i - 1)), 2, 255, 0, 0);
        draw_line(cx - (dx * i), cy, cx, cy + (dy * (STEPS - i - 1)), 2, 255, 0, 0);
        draw_line(cx + (dx * i), cy, cx, cy - (dy * (STEPS - i - 1)), 2, 255, 0, 0);
        draw_line(cx - (dx * i), cy, cx, cy - (dy * (STEPS - i - 1)), 2, 255, 0, 0);
    }

    draw_close();

    return 0;
}