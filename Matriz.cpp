#include "Matriz.h"
#include <string>
using std::string;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
Matriz::Matriz()
{
}

Matriz::Matriz(int ptamanio, double** pmatriz, string pnombre)
{
    this->tamanio = ptamanio;
    this->matrix = pmatriz;
    this->nombre = pnombre;
}

int Matriz::getTamanio()
{
    return tamanio;
}

void Matriz::setTamanio(int ptamanio)
{
    tamanio = ptamanio;
}

double Matriz::getDeterminante()
{
    return determinante;
}

void Matriz::setDeterminante(double pdeterminante)
{
    determinante = pdeterminante;
}

double** Matriz::getMatriz()
{
    return matrix;
}

void Matriz::setMatriz(double** pmatriz)
{
    matrix = pmatriz;
}

string Matriz::getNombre()
{
    return nombre;
}

void Matriz::setNombre(string pnombre)
{
    nombre = pnombre;
}

double Matriz::Determinante(double** matriz, int x){
    double temp;
    double resut=1;
    for (int i = 0; i < x-1; i++)
    {
        determinante*=matriz[i][i];
        if (matriz[i][i]==0)
        {
            return 0;
        }
        else{
            for (int j = i+1; j < x; j++)
            {
                temp=-matriz[j][i];
                for (int k = i; k < x; k++)
                {
                    matriz[j][k]=matriz[j][k]+temp*matriz[i][k]/matriz[i][i];
                }
                
            }
            
        }
    }
    resut*=matriz[x-1][x-1];
    return resut;
}

double**Matriz::provisionarMatriz(int tamanio)
{
    double**matrix = new double *[tamanio];
    for (int i = 0; i < tamanio; i++)
    {
        matrix[i] = new double[tamanio];
    }
    return matrix;
}

void Matriz::liberarMatriz(double** &matrix, int tamanio)
{
    for (int i = 0; i < tamanio; i++)
    {
        if (matrix[i] != NULL)
        {
            delete[] matrix[i];
            matrix[i] = NULL;
        }
    }

    if (matrix != NULL)
    {
        delete[] matrix;
        matrix = NULL;
    }
}

void Matriz::printMatrix(double**matriz, int tamanio)
{
    for (int i = 0; i < tamanio; i++)
    {
        for (int j = 0; j < tamanio; j++)
            cout << "[ " << matriz[i][j] << " ] ";

        cout << endl;
    }
}

double** Matriz::readMatriz(double** matriz, int tamanio)
{
    for (int i = 0; i < tamanio; i++)
    {
        for (int j = 0; j < tamanio; j++)
        {
                cout << "Ingrese el valor de casilla [" << i << "," << j << "]" << endl;
                cin >> matriz[i][j];
        }
    }
    return matriz;
}

double**Matriz::suma(double**matriz1, double** matriz2, int tamanio){
    double**matrix = new double *[tamanio];
    for (int i = 0; i < tamanio; i++)
    {
        matrix[i] = new double[tamanio];
    }

    for (int i = 0; i < tamanio; i++)
    {
        for (int j = 0; j < tamanio; j++)
        {
            matrix[i][j]=matriz1[i][j]+matriz2[i][j];
        }
        
    }
    return matrix;
}

double**Matriz::producto(double**matriz1, double** matriz2, int tamanio){
    int cont=0;
    double**matrix = new double *[tamanio];
    for (int i = 0; i < tamanio; i++)
    {
        matrix[i] = new double[tamanio];
    }

    for (int i = 0; i < tamanio; i++)
    {
        for (int j = 0; j < tamanio; j++)
        {
            for (int k = 0; k < tamanio; i++)
            {
                matrix[i][j]=matrix[i][j]+matriz1[i][k]*matriz2[k][j];
            }
        }
        
    }
    return matrix;
}