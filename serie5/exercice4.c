#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <draw.h>

#undef M_PI
#define M_PI    3.14159265358979323846

#define PATH        "output/S5E4.svg"
#define WIDTH       400
#define HEIGHT      400

#define COLUMS      8
#define ROWS        8
#define SIZE_MULT   0.9

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

    double dx = (double)WIDTH / (double)(COLUMS + 1);
    double dy = (double)HEIGHT / (double)(ROWS + 1);

    draw_line(0, 0, WIDTH - 1, 0, 2, 0, 0, 0);
    draw_line(0, HEIGHT - 1, WIDTH - 1, HEIGHT - 1, 2, 0, 0, 0);
    draw_line(0, 0, 0, HEIGHT - 1, 2, 0, 0, 0);
    draw_line(WIDTH - 1, 0, WIDTH - 1, HEIGHT - 1, 2, 0, 0, 0);

    double ratio, re, gr;
    for (int r = 0; r < ROWS; r++) {
        ratio = (double)r / (double)(ROWS - 1);
        re = 255.0 * (1.0 - ratio);
        gr = 255.0 * ratio;
        for (int c = 0; c < COLUMS; c++) {
            draw_poly((dx * c) + dx, (dy * r) + dy, (dx * SIZE_MULT) / 2.0, c + 3, 2, re, gr, 0);
        }
    }

    draw_close();

    return 0;
}