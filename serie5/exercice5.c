#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <draw.h>

#undef M_PI
#define M_PI    3.14159265358979323846

#define PATH        "output/S5E5.svg"
#define WIDTH       400
#define HEIGHT      400

#define TRI_RAD     150

/*
    Série 5, Exercice 5
    -------------------

    

    Auteur: Alexandre Rouma
    Date:   12/09/2020
*/

struct point {
    double x;
    double y;
};
typedef struct point point_t;

/*
       B o
        / \
    A' o   o B'
      /     \
   A o---o---o C
        C'
*/
void tri_recursive(point_t a, point_t b, point_t c, int w, int re, int gr, int bl, int depth, int max_depth) {
    point_t _a, _b, _c;
    _a = (point_t){.x = (a.x + b.x) / 2.0, .y = (a.y + b.y) / 2.0};
    _b = (point_t){.x = (b.x + c.x) / 2.0, .y = (b.y + c.y) / 2.0};
    _c = (point_t){.x = (c.x + a.x) / 2.0, .y = (c.y + a.y) / 2.0};

    draw_line(_a.x, _a.y, _b.x, _b.y, w, re, gr, bl);
    draw_line(_b.x, _b.y, _c.x, _c.y, w, re, gr, bl);
    draw_line(_c.x, _c.y, _a.x, _a.y, w, re, gr, bl);

    depth++;
    if (depth >= max_depth) {
        return;
    }
    
    tri_recursive(a, _a, _c, w, re, gr, bl, depth, max_depth);
    tri_recursive(_a, b, _b, w, re, gr, bl, depth, max_depth);
    tri_recursive(_c, _b, c, w, re, gr, bl, depth, max_depth);
}

int main() {
    draw_init(PATH, WIDTH, HEIGHT);

    double cx = (double)WIDTH / 2.0;
    double cy = (double)HEIGHT / 2.0;

    draw_line(0, 0, WIDTH - 1, 0, 2, 0, 0, 0);
    draw_line(0, HEIGHT - 1, WIDTH - 1, HEIGHT - 1, 2, 0, 0, 0);
    draw_line(0, 0, 0, HEIGHT - 1, 2, 0, 0, 0);
    draw_line(WIDTH - 1, 0, WIDTH - 1, HEIGHT - 1, 2, 0, 0, 0);

    point_t a, b, c;

    double sin30 = sin(M_PI / 6.0) * TRI_RAD;
    double cos30 = cos(M_PI / 6.0) * TRI_RAD;

    a = (point_t){.x = cx - cos30, .y = cy + sin30};
    b = (point_t){.x = cx, .y = cy - TRI_RAD};
    c = (point_t){.x = cx + cos30, .y = cy + sin30};

    draw_line(a.x, a.y, b.x, b.y, 1, 0, 0, 0);
    draw_line(b.x, b.y, c.x, c.y, 1, 0, 0, 0);
    draw_line(c.x, c.y, a.x, a.y, 1, 0, 0, 0);

    tri_recursive(a, b, c, 1, 0, 0, 0, 0, 6);

    draw_close();

    return 0;
}