//------------------------
// Universidade Federal de Sergipe
// Departamento de Matemática
// Prof Evilson Vieira
// Imagem Bicolor
// 1. Compilar: gcc ppmreta.c -o ppmreta -lm
// 2. Executar: ./ppmreta
// 3. Os arquivos reta.ppm
// 4. Para visualizar: eog reta-comp.ppm & eog reta-cos.ppm
// Aluno: Mateus Figueiredo Pereira
// Aracaju-SE
//------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char **argv)
{
  int i, j, l = 100, h = 100;
  unsigned char cmax = 255;
  FILE *fp;

  unsigned char m[h][l][3];
  unsigned char n[h][l][3];

  float a = (float)23 / 42;
  float b = (float)42 - 713 / 42;
  printf("a = %f\n", a);
  printf("b = %f\n", b);
  
  float ux = (float)-23 / 42;
  float uy = (float)1;

  float x0 = (float)31;
  float y0 = (float)42;
  // Logica do produto interno
  for (i = 0; i < h; i++)
    for (j = 0; j < l; j++)
    {
      float vx = (float)j - x0;
      float vy = (float)i - y0;
      int prod = round(ux * vx + uy * vy);
      if (prod == 0)
      {
        n[i][j][0] = 0;
        n[i][j][1] = 0;
        n[i][j][2] = 0;
      }
      if (prod > 0)
      {
        n[i][j][0] = 255;
        n[i][j][1] = 0;
        n[i][j][2] = 0;
      }
      if (prod < 0)
      {
        n[i][j][0] = 0;
        n[i][j][1] = 0;
        n[i][j][2] = 255;
      }
    }

  // Logica de comparação
  for (i = 0; i < h; i++)
    for (j = 0; j < l; j++)
    {
      int fx = round(a * j + b);
      if (fx == i)
      {
        m[i][j][0] = 0;
        m[i][j][1] = 0;
        m[i][j][2] = 0;
      }
      if (fx > i)
      {
        m[i][j][0] = 0;
        m[i][j][1] = 0;
        m[i][j][2] = 255;
      }
      if (fx < i)
      {
        m[i][j][0] = 254;
        m[i][j][1] = 161;
        m[i][j][2] = 25;
      }
    }

  fp = fopen("reta-comp.ppm", "w");
  fprintf(fp, "P6\n");
  fprintf(fp, "%u %u\n%hhu\n", l, h, cmax);

  for (i = 0; i < h; i++)
    for (j = 0; j < l; j++)
    {
      fprintf(fp, "%c%c%c", m[i][j][0], m[i][j][1], m[i][j][2]);
    }

  fclose(fp);

  fp = fopen("reta-cos.ppm", "w");
  fprintf(fp, "P6\n");
  fprintf(fp, "%u %u\n%hhu\n", l, h, cmax);

  for (i = 0; i < h; i++)
    for (j = 0; j < l; j++)
    {
      fprintf(fp, "%c%c%c", n[i][j][0], n[i][j][1], n[i][j][2]);
    }

  fclose(fp);
  return 0;
}