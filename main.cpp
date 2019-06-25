#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include "Matriz.h"

int menu();
string nombre1(string, string);
string delimitador(string);
string nombre2(string, string);
bool valNombre(string, vector<Matriz *>);

int main()
{
    int opc = 0;
    int salir = 0;
    int tamanio = 0;
    //int val = 0;
    string nombre;
    double determinante = 0.0;
    double **matrix = NULL;
    Matriz *matriz;
    int pos;
    vector<double **> matrices;
    vector<Matriz *> matrixes;
    string operacion;
    string operador, nombrem1, nombrem2;
    int tam1, tam2;
    int pos1, pos2;
    Matriz* summatriz=NULL;
    do
    {
        switch (opc = menu())
        {

        case 1:
            do
            {
                cout << "Ingrese tamanio: [2 o 3]" << endl;
                cin >> tamanio;
                while (tamanio < 2 || tamanio > 3)
                {
                    cout << "Tamanio debe de ser 2 o 3" << endl;
                    cin >> tamanio;
                }
                cout << "Ingrese el nombre: " << endl;
                cin >> nombre;
                matrix = matriz->provisionarMatriz(tamanio);
                matrix = matriz->readMatriz(matrix, tamanio);
                matrices.push_back(matrix);
                matriz = new Matriz(tamanio, matrix, nombre);
                matrixes.push_back(matriz);
                cout << "Desea ingresar otra matriz?: [1.-Si, 2.-No]" << endl;
                cin >> salir;
            } while (salir != 2);

            break;

        case 2:
            for (int i = 0; i < matrixes.size(); i++)
            {
                cout << matrixes[i]->getNombre() << endl;
                matrixes[i]->printMatrix(matrixes[i]->getMatriz(), matrixes[i]->getTamanio());
                cout << endl;
            }

            break;

        case 3:
            for (int i = 0; i < matrixes.size(); i++)
            {
                cout << "Numero " << i << endl;
                matrixes[i]->printMatrix(matrixes[i]->getMatriz(), matrixes[i]->getTamanio());
                cout << endl;
            }
            cout << "Posicion que desa eliminar? " << endl;
            cin >> pos;
            while (pos < 0 || pos > matrixes.size())
            {
                cout << "Posicion VALIDA que desa eliminar? " << endl;
                cin >> pos;
            }
            matrixes.erase(matrixes.begin() + pos);
            break;

        case 4:
            cout << "Ingrese la Operacion: " << endl;
            cin >> operacion;
            operador = delimitador(operacion);
            nombrem1 = nombre1(operacion, operador);
            nombrem2 = nombre2(operacion, operador);
            /*if (valNombre(nombrem1, matrixes) == false || valNombre(nombrem2, matrixes))
            {
                cout << "Ingrese la Operacion con Matrices Existentes: " << endl;
                cin >> operacion;
                operador = delimitador(operacion);
                nombrem1 = nombre1(operacion, operador);
                nombrem2 = nombre2(operacion, operador);
            }
            */
            if (operador == "|")
            {
                for (int i = 0; i < matrixes.size(); i++)
                {
                    if (matrixes[i]->getNombre() == nombrem1)
                    {
                        tam1 = matrixes[i]->getTamanio();
                        pos1=i;
                    }
                    if (matrixes[i]->getNombre() == nombrem2)
                    {
                        tam2 = matrixes[i]->getTamanio();
                        pos2=i;
                    }
                }
                if (tam1 == tam2)
                {
                    summatriz->suma(matrixes[pos1]->getMatriz(), matrixes[pos2]->getMatriz(), tam1);
                    summatriz->printMatrix(summatriz->matrix, tam1);
                }
            }
            
            if (operador == "|")
            {
                for (int i = 0; i < matrixes.size(); i++)
                {
                    if (matrixes[i]->getNombre() == nombrem1)
                    {
                        tam1 = matrixes[i]->getTamanio();
                        pos1=i;
                    }
                    if (matrixes[i]->getNombre() == nombrem2)
                    {
                        tam2 = matrixes[i]->getTamanio();
                        pos2=i;
                    }
                }
                if (tam1 == tam2)
                {
                    summatriz->producto(matrixes[pos1]->getMatriz(), matrixes[pos2]->getMatriz(), tam1);
                    summatriz->printMatrix(summatriz->matrix, tam1);
                }
            }

            break;

        case 5:
            for (int i = 0; i < matrixes.size(); i++)
            {
                matrixes[i]->liberarMatriz(matrices[i], matrixes[i]->getTamanio());
            }

            for (int i = 0; i < matrices.size(); i++)
            {
                delete matrices[i];
                matrices[i] = NULL;
            }
            matrices.clear();

            for (int i = 0; i < matrixes.size(); i++)
            {
                delete matrixes[i];
                matrixes[i] = NULL;
            }
            matrixes.clear();
            cout << "Saliendo del programa" << endl;
            break;
        }
    } while (opc != 5);

    return 0;
}

int menu()
{
    while (true)
    {
        cout << "MENU" << endl
             << "1.- Crear Matrices" << endl
             << "2.- Listar Matrices" << endl
             << "3.- Eliminar Matrices" << endl
             << "4.- Operar Matrices" << endl
             << "5.- Salir" << endl;
        cout << "Ingrese una opcion: ";
        int opcion = 0;
        cin >> opcion;
        if (opcion >= 1 && opcion <= 5)
        {
            return opcion;
        }
        else
        {

            cout << "La opcion elegida no es valida, ingrese 1 a 5" << endl;
        }
    } //end del while
    return 0;
}

string delimitador(string x)
{
    string del = "n";
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '|')
        {
            del = "|";
        }

        if (x[i] == '+')
        {
            if (x[i + 1] == '+')
            {
                del = "++";
            }
        }

        if (x[i] == '-')
        {
            if (x[i + 1] == '-')
            {
                del = "--";
            }
        }

        if (x[i] == '>')
        {
            del = ">";
        }

        if (x[i] == '&')
        {
            del = "&";
        }

        if (x[i] == '+')
        {
            del = "+";
        }

        if (x[i] == '*')
        {
            del = "*";
        }
    }

    return del;
}

bool valNombre(string x, vector<Matriz *> vec)
{
    bool resp;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i]->getNombre() == x)
        {
            resp = true;
        }
    }
    resp = false;
    return resp;
}

string nombre1(string x, string operador)
{
    string nombre1 = "";
    vector<string> separar;
    int cont = 0;
    int found = x.find(operador);
    nombre1 = x.substr(0, found);
    return nombre1;
}

string nombre2(string x, string operador)
{
    string nombre2 = "";
    vector<string> separar;
    int cont = 0;
    int found = x.find(operador);
    nombre2 = x.substr(found + 1, x.size());
    return nombre2;
}