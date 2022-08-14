#include <stdio.h>

struct ponto
{
  int x, y;
};

//Com seta
void funcSeta (struct ponto *p)
{
  p -> x = 10;
  p -> y = 20;
}
//Sem seta
void func (struct ponto *p)
{
  (*p).x = 10;
  (*p).y = 20;
}