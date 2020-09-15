#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <draw.h>

#undef M_PI
#define M_PI            3.14159265358979323846

#define PATH            "output/S5E6.svg"
#define WIDTH           400
#define HEIGHT          400

#define TRI_RAD         150

#define DEGREE          6

/*
    Série 5, Exercice 6
    -------------------

    

    Auteur: Alexandre Rouma
    Date:   12/09/2020
*/

struct vec2 {
    double x;
    double y;
};
typedef struct vec2 vec2_t;

void normalize_vec(vec2_t* vec) {
    double len = sqrt((vec->x*vec->x) + (vec->y*vec->y));
    *vec = (vec2_t){.x = vec->x / len, .y = vec->y / len};
}

/*         
        B o
   CSB   /
S o--o--o B'
CAS o  o C
      o A'
     /
  A o
*/

void coche(vec2_t a, vec2_t b, vec2_t norm, int w, int re, int gr, int bl, int depth, int max_depth) {
    vec2_t _a = (vec2_t){.x = ((2.0 * a.x) + b.x) / 3.0, .y = ((2.0 * a.y) + b.y) / 3.0};
    vec2_t _b = (vec2_t){.x = ((2.0 * b.x) + a.x) / 3.0, .y = ((2.0 * b.y) + a.y) / 3.0};
    vec2_t c = (vec2_t){.x = (a.x + b.x) / 2.0, .y =  (a.y + b.y) / 2.0};
    vec2_t ab = (vec2_t){.x = b.x - a.x, .y = b.y - a.y};

    double len = sqrt((ab.x*ab.x) + (ab.y*ab.y)) / 3.0;
    double h = len * (sqrt(3.0) / 2.0);

    vec2_t s = (vec2_t){.x = (norm.x * h) + c.x, .y = (norm.y * h) + c.y};

    if (depth >= max_depth) {
        draw_line(a.x, a.y, _a.x, _a.y, w, re, gr, bl);
        draw_line(_a.x, _a.y, s.x, s.y, w, re, gr, bl);
        draw_line(s.x, s.y, _b.x, _b.y, w, re, gr, bl);
        draw_line(_b.x, _b.y, b.x, b.y, w, re, gr, bl);
        return;
    }

    vec2_t cas = (vec2_t){.x = (_a.x + s.x) / 2.0, .y = (_a.y + s.y) / 2.0};
    vec2_t csb = (vec2_t){.x = (s.x + _b.x) / 2.0, .y = (s.y + _b.y) / 2.0};

    vec2_t norm_as = (vec2_t){.x = cas.x - _b.x, .y = cas.y - _b.y};
    vec2_t norm_sb = (vec2_t){.x = csb.x - _a.x, .y = csb.y - _a.y};
    normalize_vec(&norm_as);
    normalize_vec(&norm_sb);

    depth++;
    coche(a, _a, norm, w, re, gr, bl, depth, max_depth);
    coche(_a, s, norm_as, w, re, gr, bl, depth, max_depth);
    coche(s, _b, norm_sb, w, re, gr, bl, depth, max_depth);
    coche(_b, b, norm, w, re, gr, bl, depth, max_depth);
}

int main() {
    draw_init(PATH, WIDTH, HEIGHT);

    double cx = (double)WIDTH / 2.0;
    double cy = (double)HEIGHT / 2.0;

    draw_line(0, 0, WIDTH - 1, 0, 2, 0, 0, 0);
    draw_line(0, HEIGHT - 1, WIDTH - 1, HEIGHT - 1, 2, 0, 0, 0);
    draw_line(0, 0, 0, HEIGHT - 1, 2, 0, 0, 0);
    draw_line(WIDTH - 1, 0, WIDTH - 1, HEIGHT - 1, 2, 0, 0, 0);

    vec2_t a, b, c, _a, _b, _c, norm_ab, norm_bc, norm_ca;

    double sin30 = sin(M_PI / 6.0) * TRI_RAD;
    double cos30 = cos(M_PI / 6.0) * TRI_RAD;

    a = (vec2_t){.x = cx - cos30, .y = cy + sin30};
    b = (vec2_t){.x = cx, .y = cy - TRI_RAD};
    c = (vec2_t){.x = cx + cos30, .y = cy + sin30};

    _a = (vec2_t){.x = (a.x + b.x) / 2.0, .y = (a.y + b.y) / 2.0};
    _b = (vec2_t){.x = (b.x + c.x) / 2.0, .y = (b.y + c.y) / 2.0};
    _c = (vec2_t){.x = (c.x + a.x) / 2.0, .y = (c.y + a.y) / 2.0};
    
    norm_ab = (vec2_t){.x = _a.x - c.x, .y = _a.y - c.y};
    norm_bc = (vec2_t){.x = _b.x - a.x, .y = _b.y - a.y};
    norm_ca = (vec2_t){.x = _c.x - b.x, .y = _c.y - b.y};
    normalize_vec(&norm_ab);
    normalize_vec(&norm_bc);
    normalize_vec(&norm_ca);

    if (DEGREE < 2) {
        return 0;
    }
    
    coche(a, b, norm_ab, 1, 0, 0, 0, 0, DEGREE - 2);
    coche(b, c, norm_bc, 1, 0, 0, 0, 0, DEGREE - 2);
    coche(c, a, norm_ca, 1, 0, 0, 0, 0, DEGREE - 2);

    draw_close();

    return 0;
}