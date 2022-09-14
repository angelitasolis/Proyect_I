#include "Proyecto_1progra_1.h"
#include "Cimg.h"
#include "Grafico.h"
#include "Control.h"

void Llenar_Matriz(long double M[r][r], long double X[r])
//Es la matriz de Vandermonde (siempre tiene inversa (si los x's son distintos))
{
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < r; j++)
			M[i][j] = pow(X[i], j);
	return;
}

void Multiplicar(long double M[r][r], long double Y[r], long double Z[r])
//Multiplica la Matriz M por el vector Y produciendo el vector Z
{
	int i, k;
	for (i = 0; i < r; i++)
	{
		Z[i] = 0;
		for (k = 0; k < r; k++)
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

bool Inversa(long double A[r][r], long double Ainv[r][r])
//Calcula la matriz inversa de A (si existe) y la copia en la matriz Ainv
{
	long double AI[r][m];
	int i, j, ii;
	bool resp = true;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < r; j++)
		{
			AI[i][j] = A[i][j];
			AI[i][j + r] = 0;
		}
		AI[i][i + r] = 1;
	}
	for (i = 0; i < r; i++)
	{
		if (AI[i][i] == 0)
		{
			for (ii = i + 1; (AI[i][i] == 0) && (ii < r); ii++)
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
			for (ii = 0; ii < r; ii++)
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
		for (i = 0; i < r; i++)
			for (j = 0; j < r; j++)
				Ainv[i][j] = AI[i][j + r];
	}
	return resp;
}

void Calcular_Polinomio(long double Xs[r], long double Ys[r], long double P[r])
{
	long double M0[r][r], M1[r][r];
	Llenar_Matriz(M0, Xs);
	Inversa(M0, M1);
	Multiplicar(M1, Ys, P);
	return;
}


void Mostrar_Polinomio(long double P[r])
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
	for (i = 2; i < r; i++)
	{
		cout.precision(2);
		cout << fixed << P[i] << "x^" << i;
		if ((i != r - 1) && (P[i + 1] > 0))
			cout << '+';
	}
	cout << '\n';
	return;
}
long double evaluarX(long double P[r], long double x) {
	long double result = P[r - 1];
	for (int i = r - 1; i >= 1; i--) {
		result = result * x + P[i - 1];
	}
	return result;
}

Grafico::Grafico(){

	//ubicación en pixeles para graficar en la ventana:
	ubicX0 = 10;
	ubicY0 = 110;

	//inicializa el vector con ceros:
	for (int i = 0; i < n; i++) {
		valores_Y[i] = 0;
	}
}

void::Grafico::calcularPolinomio(long double P[r]) {
	//auxX se usará para los valores del eje X
	double auxX = -3.0;

	for (int i = 0; i < n; i++) {
		auxX += 0.03; //la x tiene incrementos de 0.03 radianes
		//el rango del seno va de -1 a 1, de modo que para graficar lo aumentamos 100 veces
		//de ese modo el gráfico tendrá valores entre -100 y 100 pixeles en el eje Y
		valores_Y[i] = evaluarX(P, auxX)*33; 
	}
}

void Grafico::pintar(CImg<unsigned char>& imagen) {
	//definición de los colores a usar para graficar con la biblioteca CImg:
	const unsigned char negro[] = { 0, 0, 0 }; //los valores corresponden a {Red, Green, Blue,}
	const unsigned char rojo[] = { 250, 0, 0 };

	for (int i = 0; i < n - 1; i++) {
		//dibujar un punto correspondiente al valor de Y guardado en valores_Y
		imagen.draw_line(ubicX0 + i, ubicY0 - valores_Y[i], ubicX0 + i + 1, ubicY0 - valores_Y[i + 1], negro);
	}

	//Pintar bordes y eje X del gráfico
	imagen.draw_line(ubicX0 - 1, ubicY0 - 101, ubicX0 + n, ubicY0 - 101, rojo); //horiz sup
	imagen.draw_line(ubicX0 - 1, ubicY0 + 101, ubicX0 + n, ubicY0 + 101, rojo); //horiz inf
	imagen.draw_line(ubicX0 - 1, ubicY0, ubicX0 + n, ubicY0, rojo); //horiz eje X
	imagen.draw_line(ubicX0 - 1, ubicY0 - 101, ubicX0 - 1, ubicY0 + 101, rojo); //vert izq
	imagen.draw_line(ubicX0 + n, ubicY0 - 101, ubicX0 + n, ubicY0 + 101, rojo); //vert der
}
Control::Control() {
	w = 220; //ancho de venta
	h = 220; //alto de ventana
	ventana.resize(w, h, true); //cambia el tamaño de la ventana
	ventana.set_title("Gráfico"); //establece el título de la ventana
	imagen.assign(w, h, 1, 3, 255); //cambia el tamaño de la imagen, la profundidad,...
	//los canales (3:RGB) y los establece en 255 (blanco)

}

void Control::correr(long double P[r]) { //método que controla la ejecución del programa

	//llama el método calcularPolinomio() del objeto "grafico_Seno" (objeto de la clase Grafico)
	grafico_Seno.calcularPolinomio(P);

	//mientras la ventana no se cierre, llama el método pintar del objeto "programa" (objeto de la clase Control)
	while (!ventana.is_closed()) {
		pintar();
		//llama el método wait de la instancia ventana de la biblioteca CImg, con parámetro 100 milisegundos
		ventana.wait(100);
	}
}

void Control::pintar() { //método principal de graficado del objeto "programa" (objeto de la clase Control)
	//definición del color gris para usar con la bibloteca CImg:
	const unsigned char gris[] = { 192, 192, 192 };

	imagen.draw_rectangle(0, 0, w, h, gris); //Esto es para realizar un borrado de pantalla

	grafico_Seno.pintar(imagen); //llama el método pintar del objeto "grafico_Seno" (objeto de la clase Grafico)

	ventana.display(imagen); //pinta la ventana, como parámetro se le da el atributo "imagen" de la instancia "programa"
}
