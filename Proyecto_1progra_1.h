
#include <iostream>
using namespace std;
#include<math.h>

const int r = 5, m = 2 * r;

void Llenar_Matriz(long double M[r][r], long double X[r]);
//Es la matriz de Vandermonde (siempre tiene inversa (si los x's son distintos))

void Multiplicar(long double M[r][r], long double Y[r], long double Z[r]);
//Multiplica la Matriz M por el vector Y produciendo el vector Z

bool Inversa(long double A[r][r], long double Ainv[r][r]);
//Calcula la matriz inversa de A (si existe) y la copia en la matriz Ainv

void Calcular_Polinomio(long double Xs[r], long double Ys[r], long double P[r]);

void Mostrar_Polinomio(long double P[r]);
//Muestra el polinomio de interpolacion

long double evaluarX(long double P[r], long double x);