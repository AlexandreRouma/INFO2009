#include <stdio.h>

#include "draw.h"

static FILE *file;

int  draw_init(char *file_name, unsigned width, unsigned height)
{
  file = fopen(file_name, "w");
  if (!file)
    {
      fprintf(stderr, "unable to create file [%s]\n", file_name);
      return -1;
    }

  if (fprintf(file,
              "<svg version=\"1.1\"\n"
              "    baseProfile=\"full\"\n"
              "    width=\"%u\" height=\"%u\"\n"
              "    xmlns=\"http://www.w3.org/2000/svg\">\n\n"
              "  <rect width=\"100%%\" height=\"100%%\" fill=\"white\"/>\n",
              width, height) < 0)
    return -1;

  return 0;
}

int  draw_line(int x1, int y1, int x2, int y2, unsigned stroke_width,
               unsigned r, unsigned g, unsigned b)
{
  if (fprintf(file,
              "  <line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\""
              " stroke=\"rgb(%u, %u, %u)\" stroke-width=\"%u\"/>\n",
              x1, y1, x2, y2, r, g, b, stroke_width) < 0)
    return -1;

  return 0;
}

int  draw_close()
{
  if (fprintf(file, "</svg>\n") < 0)
    return -1;

  fclose(file);
  return 0;
}