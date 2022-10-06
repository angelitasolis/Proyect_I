#include <iostream>
#include "Metodos_Imagenes.h" 
#include "CImg.h" 
using namespace std;

int main()
{
    CImg<unsigned char> img("Killua y Gun.jpeg");
    CImg<unsigned char> img2;
    int w, h, options, porcentaje, total, SINo = 0;
    float enfriar, fc;
    img2 = img;
    w = img.width();
    h = img.height();
    total = w * h;
    char resp = 's';
    while (resp == 's' || resp == 'S')
    {
        cout << endl << "---------------MENU DE IMAGENES--------------" << endl;
        cout << "---------------------------------------------" << endl << endl;
        cout << "....Calcular el negativo de una imagen.....(1)" << endl;
        cout << ".............Enfriar la imagen.............(2)" << endl;
        cout << "............Oscurecer la imagen............(3)" << endl;
        cout << "...Mostrar el histograma Tonos de grises...(4)" << endl;
        cout << "......Enfatizar los colores oscuros........(5)" << endl;
        cout << ".............Calentar la imagen............(6)" << endl;
        cout << endl << "---------------------------------------------" << endl;
        cout << "Para realizar alguno de estos procesos digite el numero que le corresponde: " << endl;
        cin >> options;

        if (options == 1) {
            CalcularNegativo(img2, w, h);
            CImgDisplay disp2(img, "My image", 1, false);
            CImgDisplay disp(img2, "My image 2", 1, false);
            while (!disp.is_closed()) {
                disp.wait();
            }
            cout << "Quiere guardar la imagen editada?" << endl;
            cout << "(1) Si" << endl;
            cout << "(2) No" << endl;
            cin >> SINo;
            if (SINo == 1) {
                img2.save_jpeg("Imagen Negativa.jpg", 100);
                cout << "Imagen guardada, revisa la carpeta del proyecto" << endl;
            }
            img2 = img;
        }
        if (options == 2) {
            EnfriarImagen(img2, w, h);
            CImgDisplay disp2(img, "My image", 0, false);
            CImgDisplay disp(img2, "My image 2", 0, false);
            while (!disp.is_closed()) {
                disp.wait();
            }
            cout << "Quiere guardar la imagen editada?" << endl;
            cout << "(1) Si" << endl;
            cout << "(2) No" << endl;
            cin >> SINo;
            if (SINo == 1) {
                img2.save_jpeg("Imagen Fría.jpg", 100);
                cout << "Imagen guardada, revisa la carpeta del proyecto" << endl;
            }
            img2 = img;
        }
        if (options == 3) {
            Oscurecer(img2, w, h);
            CImgDisplay disp2(img, "My image", 0, false);
            CImgDisplay disp(img2, "My image 2", 0, false);
            while (!disp.is_closed()) {
                disp.wait();
            }
            cout << "Quiere guardar la imagen editada?" << endl;
            cout << "(1) Si" << endl;
            cout << "(2) No" << endl;
            cin >> SINo;
            if (SINo == 1) {
                img2.save_jpeg("Imagen Oscura.jpg", 100);
                cout << "Imagen guardada, revisa la carpeta del proyecto" << endl;
            }
            img2 = img;
        }
        if (options == 4) {
            Tonosdegrises(img2, w, h);

            CImg<float> img3 = CImg<float>(img).histogram(255, 0, 255);
            img3.display_graph(0, 3);

            CImg<float> img4 = CImg<float>(img2).histogram(255, 0, 255);
            img4.display_graph(0, 3);
            img2 = img;
        }
        if (options == 5) {
        }
        if (options == 6) {
        }
        if (options > 6 || options < 0) {
            cout << "Digite un numero correcto" << endl;
        }
        cout << endl << "Desea continuar? Digite (S). Desea cerrar la consola? Digite (N)" << endl << endl;
        cin >> resp;
        Clear();
    }
    return 0;
}