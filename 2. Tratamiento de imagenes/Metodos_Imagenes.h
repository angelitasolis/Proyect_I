#include <iostream>
#include"CImg.h" 
using namespace cimg_library;
using namespace cimg;

void Clear();
void CalcularNegativo(CImg<unsigned char>& I, int w, int h);
void EnfriarImagen(CImg<unsigned char>& I, int w, int h);
void EnfatizadoClaros(CImg<unsigned char>& I, int w, int h);
void Oscurecer(CImg<unsigned char>& I, int w, int h);
void Tonosdegrises(CImg<unsigned char>& I, int w, int h);
void CalentarImagen(CImg<unsigned char>& I, int w, int h);
