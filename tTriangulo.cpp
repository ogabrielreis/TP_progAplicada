#include <iostream>
#include <math.h>

using namespace std;

struct Triangulo {
  int lado1;
  int lado2;
  int lado3;
};

int calcPerimetro(int a, int b, int c) {
  int result;
  result = a + b + c;
  return(result);
};

int calcArea(int a, int b) {
  int result;
  result = (a + b)/2;
  return(result);
};

int calcHipotenusa(int a, int b) {
    int result, parcial;
    parcial = pow(a,2) + pow(b,2);
    result = sqrt(parcial);
    return(result);
}