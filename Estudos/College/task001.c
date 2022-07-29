#include <stdio.h>

const char *coordPos(double coordX, double coordY)
{
  char *quadrante = "A coordenada se encontra na origem\n";

  if (coordX > 0 && coordY > 0)
  {
    quadrante = "A coordenada eh do primeiro quadrante\n";
  }
  else if (coordX < 0 && coordY > 0)
  {
    quadrante = "A coordenada eh do segundo quadrante\n";
  }
  else if (coordX < 0 && coordY < 0)
  {
    quadrante = "A coordenada eh do terceiro quadrante\n";
  }
  else if (coordX > 0 && coordY < 0)
  {
    quadrante = "A coordenada eh do quarto quadrante\n";
  }
  else if (coordX == 0 && coordY != 0)
  {
    quadrante = "A coordenada esta no eixo Y\n";
  }
  else if (coordX != 0 && coordY == 0)
  {
    quadrante = "A coordenada esta no eixo X\n";
  }

  return quadrante;
}

void main()
{
  double coordX, coordY;

  printf("Digite a coodernada para o eixo X: ");
  scanf("%lf", &coordX);

  printf("Digite a coodernada para o eixo Y: ");
  scanf("%lf", &coordY);

  printf(coordPos(coordX, coordY));
}