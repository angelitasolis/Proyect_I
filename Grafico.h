#pragma once
#include"CImg.h"
int const n = 200;
using namespace cimg_library;

class Grafico
{
public:
	Grafico(); //constructor

	//método para pintar usando la biblioteca CImg
	void pintar(CImg<unsigned char>& imagen);
	void calcularPolinomio(long double P[r]);
private:

	//Ubicación en la ventana de la coordenada 0,0 (x,y):
	int ubicX0, ubicY0;

	//valores de Y.
	int valores_Y[n];
};

