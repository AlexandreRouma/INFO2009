#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <draw.h>

#undef M_PI
#define M_PI    3.14159265358979323846

#define PATH        "output/S5E3.svg"
#define WIDTH       400
#define HEIGHT      400

/*
    Série 5, Exercice 3
    -------------------

    

    Auteur: Alexandre Rouma
    Date:   12/09/2020
*/

void draw_poly(int x, int y, int r, int n, int w, int re, int gr, int bl) {
    double alpha = (2.0 * M_PI) / (double)n;
    double ax, ay, bx, by;
    n++;
    for (int i = 1; i < n; i++) {
        ax = cos((i - 1) * alpha) * r;
        ay = sin((i - 1) * alpha) * r;
        bx = cos(i * alpha) * r;
        by = sin(i * alpha) * r;
        draw_line(x + ax, y + ay, x + bx, y + by, w, re, gr, bl);
    }
}

int main() {
    draw_init(PATH, WIDTH, HEIGHT);

    double cx = (double)WIDTH / 2.0;
    double cy = (double)HEIGHT / 2.0;

    draw_line(0, 0, WIDTH - 1, 0, 2, 0, 0, 0);
    draw_line(0, HEIGHT - 1, WIDTH - 1, HEIGHT - 1, 2, 0, 0, 0);
    draw_line(0, 0, 0, HEIGHT - 1, 2, 0, 0, 0);
    draw_line(WIDTH - 1, 0, WIDTH - 1, HEIGHT - 1, 2, 0, 0, 0);

    draw_poly(cx, cy, 100, 7, 2, 0, 128, 0);

    draw_close();

    return 0;
}