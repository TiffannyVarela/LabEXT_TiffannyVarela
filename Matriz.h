#pragma once
#include <string>
using std::string;
class Matriz
{
public:
    int tamanio;
    double determinante;
    string nombre;
    double** matrix;
    Matriz** matrixes;
    Matriz(/* args */);
    Matriz(int, double**, string);

    int getTamanio();
    void setTamanio(int);

    double getDeterminante();
    void setDeterminante(double);

    double** getMatriz();
    void setMatriz(double**);

    string getNombre();
    void setNombre(string);

    double Determinante (double**, int);

    double**provisionarMatriz(int);
    void liberarMatriz(double**&, int);
    void printMatrix(double**, int);
    double**readMatriz(double**, int);

    double** suma(double**, double**, int);
    double** producto(double**, double**, int);
};
