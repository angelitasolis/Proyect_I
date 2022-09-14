#include <iostream>
#include "Proyecto_1progra_1.h"
#include "Control.h"
using namespace std;

int main()
{//n=5
	long double x;
	long double Xs[r], Ys[r], P[r];
	//Datos de muestra:
	//P(x)=1+2x-3x^2+4x^3+5x^4
	Xs[0] = 0; Xs[1] = 0; Xs[2] = 0; Xs[3] = 0; Xs[4] = 0;
	Ys[0] = 0; Ys[1] = 0; Ys[2] = 0; Ys[3] = 0; Ys[4] = 0;

	for (int i = 0; i < 5; i++) {
		cout << "Digite los valores de X" << i << ":" << endl;
		cin >> Xs[i];
	}

	for (int j = 0; j < 5; j++) {
		cout << "Digite los valores de y" << j << ":" << endl;
		cin >> Ys[j];
	}

	//Calcular los coeficientes del Polinomio
	Calcular_Polinomio(Xs, Ys, P);
	//Ahora los coeficientes del Polinomio de Interpolaci?n est?n en el vector P.
	Mostrar_Polinomio(P);

	cout << "Digite el valor de x: "; cin >> x;

	cout << evaluarX(P, x);

	Control programa; //crea la instancia del Control del programa
	programa.correr(P); //llama el método correr
	return 0;
}

