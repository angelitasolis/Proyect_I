#include "metodos.h"
#include "Cimg.h"


void Llenar_Matriz(long double M[n][n], long double X[n])
//Es la matriz de Vandermonde (siempre tiene inversa (si los x's son distintos))
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			M[i][j] = pow(X[i], j);
	return;
}

void Multiplicar(long double M[n][n], long double Y[n], long double Z[n])
//Multiplica la Matriz M por el vector Y produciendo el vector Z
{
	int i, k;
	for (i = 0; i < n; i++)
	{
		Z[i] = 0;
		for (k = 0; k < n; k++)
			Z[i] += M[i][k] * Y[k];
	}
	return;
}

long double x;
void Swap(long double& a, long double& b)
//intercambia 
//notese que los datos a y b se accesan por referencia
{
	x = a; a = b; b = x;
	return;
}

int jj;
void Swap_f(long double A[m], long double B[m])
//intercambia filas
//Note que las matrices se almacenan como una secuencia de filas
{
	for (jj = 0; jj < m; jj++)
		Swap(A[jj], B[jj]);
	return;
}

bool Inversa(long double A[n][n], long double Ainv[n][n])
//Calcula la matriz inversa de A (si existe) y la copia en la matriz Ainv
{
	long double AI[n][m];
	int i, j, ii;
	bool resp = true;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			AI[i][j] = A[i][j];
			AI[i][j + n] = 0;
		}
		AI[i][i + n] = 1;
	}
	for (i = 0; i < n; i++)
	{
		if (AI[i][i] == 0)
		{
			for (ii = i + 1; (AI[i][i] == 0) && (ii < n); ii++)
				if (AI[ii][i] != 0)
					Swap_f(AI[ii], AI[i]);
		}
		if (AI[i][i] != 0)
		{//Forzar 1 en la diagonal
			if (AI[i][i] != 1)
			{
				for (j = 0; j < m; j++)
					if (j != i)
						AI[i][j] /= AI[i][i];
				AI[i][i] = 1;
			}
			//Forzar 0's en la columna
			for (ii = 0; ii < n; ii++)
			{
				if (i != ii)
				{
					if (AI[ii][i] != 0)
					{
						for (j = 0; j < m; j++)
							if (j != i)
								AI[ii][j] -= AI[i][j] * AI[ii][i];
						AI[ii][i] = 0;
					}
				}
			}
		}
		else
		{
			cout << "M no es invertible";
			resp = false;
			break;
		}
	}
	if (resp)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				Ainv[i][j] = AI[i][j + n];
	}
	return resp;
}

void Calcular_Polinomio(long double Xs[n], long double Ys[n], long double P[n])
{
	long double M0[n][n], M1[n][n];
	Llenar_Matriz(M0, Xs);
	Inversa(M0, M1);
	Multiplicar(M1, Ys, P);
	return;
}


void Mostrar_Polinomio(long double P[n])
//Muestra el polinomio de interpolacion
{
	int i;
	cout.precision(2);
	if (P[1] == 0)
		cout << fixed << P[0];
	else
		if (P[1] > 0)
			cout << fixed << P[0] << '+' << P[1] << "x";
		else
			cout << fixed << P[0] << P[1] << "x";
	if (P[2] >= 0)
		cout << '+';
	for (i = 2; i < n; i++)
	{
		cout.precision(2);
		cout << fixed << P[i] << "x^" << i;
		if ((i != n - 1) && (P[i + 1] > 0))
			cout << '+';
	}
	cout << '\n';
	return;
}
long double evaluarX(long double P[n], long double x) {
	int result = P[n-1];
	for (int i = n - 1; i >= 1; i--) {
		result = result * x + P[i-1];
	}
	return result;
}

