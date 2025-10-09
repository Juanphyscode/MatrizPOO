#include <iostream>
#include <stdlib.h>

using namespace std;

class Matriz {
private:
    int filas;
    int columnas;
    int **datos; // Mover la declaración de datos al ámbito de la clase

public:
    Matriz(int filas, int columnas) : filas(filas), columnas(columnas) {
        datos = new int*[filas];
        for (int i = 0; i < filas; i++) {
            datos[i] = new int[columnas];
        }
    }

    void ingresarDatos() {
        cout << "Ingrese los elementos de la matriz:" << endl;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << "Digite el número:" << i << "," << j << endl;
                cin >> datos[i][j]; // Utilizar directamente la matriz de datos
            }
        }
    }

    void mostrarMatriz() {
        cout << "La matriz es:" << endl;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << datos[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matriz operator*(const Matriz& otra) {
        if (columnas != otra.filas) {
            cout << "No se pueden multiplicar las matrices. El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz." << endl;
            // Puedes manejar el error de otra manera si es necesario
        }

        Matriz resultado(filas, otra.columnas);

        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < otra.columnas; j++) {
                resultado.datos[i][j] = 0;
                for (int k = 0; k < columnas; k++) {
                    resultado.datos[i][j] += datos[i][k] * otra.datos[k][j];
                }
            }
        }

        return resultado;
    }

 Matriz operator+(const Matriz& otra) {
        if (filas != otra.filas || columnas != otra.columnas) {
            cout << "Las dimensiones de las matrices no son compatibles" << endl;
            // Puedes manejar el error de otra manera si es necesario
        }
            Matriz res(filas, columnas);
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    res.datos[i][j] = datos[i][j] + otra.datos[i][j];
                }
            }
            return res;
        }
   // Destructor
    ~Matriz() {
        for (int i = 0; i < filas; i++) {
            delete[] datos[i];
        }
        delete[] datos;
  }

};

int main() {
  int filas1, columnas1, filas2, columnas2, a;

    cout << "Digite el número de filas la matriz 1: ";
    cin >> filas1;
    cout <<"y sus columas: ";cin >> columnas1;

    Matriz matriz1(filas1, columnas1);

    matriz1.ingresarDatos();
    matriz1.mostrarMatriz();
    cout << "----------------------" << endl;
    cout << "Digite el número de filas para la matriz 2: ";
    cin >> filas2;
    cout<<" y sus columnas "; cin >> columnas2;

    Matriz matriz2(filas2, columnas2);

    matriz2.ingresarDatos();
    matriz2.mostrarMatriz();
    cout << "--------------------------------" << endl;
    cout << "Escoja lo que desea hacer:" << endl;
    cout << " 1 MULIPLICAR, 2 SUMAR: ";
    cin >> a;
    cout << "=============" << endl;
    switch(a){

    case 1:
      {
    Matriz resultado = matriz1 * matriz2;
    resultado.mostrarMatriz();
      }
    break;

    case 2:
      {
      Matriz res = matriz1 + matriz2;
      res.mostrarMatriz();
      break;
      }
    }

    return 0;
}