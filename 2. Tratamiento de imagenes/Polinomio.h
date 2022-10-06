#pragma once
#include <iostream>
using namespace std;
#include<math.h>

const int n = 5, m = 2 * n;

void Llenar_Matriz(long double M[n][n], long double X[n]);
//Es la matriz de Vandermonde (siempre tiene inversa (si los x's son distintos))

void Multiplicar(long double M[n][n], long double Y[n], long double Z[n]);
//Multiplica la Matriz M por el vector Y produciendo el vector Z

bool Inversa(long double A[n][n], long double Ainv[n][n]);
//Calcula la matriz inversa de A (si existe) y la copia en la matriz Ainv

void Calcular_Polinomio(long double Xs[n], long double Ys[n], long double P[n]);

void Mostrar_Polinomio(long double P[n]);
//Muestra el polinomio de interpolacion
