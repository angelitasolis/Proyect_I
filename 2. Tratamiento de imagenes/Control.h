#pragma once
#include"CImg.h"
#include <iostream>
#include "Grafico.h"

using namespace cimg_library;
class Control
{
public:
	Control(); //constructor de la clase
	void correr(long double P[r]); //método público que controla la ejecución del programa
private:
	CImgDisplay ventana; //atributo Display de la biblioteca CImg
	CImg<unsigned char> imagen; //atributo imagen de la biblioteca CImg, corresponde al contenido de la ventana
	unsigned int w, h; //atributos de ancho y alto de la ventana e imagen
	Grafico grafico_Seno; //instancia de la clase Grafico

	//métodos privados:
	void pintar(); //método pintar de la clase Control

};