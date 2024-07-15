// Autor: Ronald Elian Hurtado Jama
// Fecha: 14 de Julio de 2024
// Tema: Funciones varias en C++

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

// Función que busca el número en el vector
int BuscaNumero(int vector[], int total, int num) {
    int cont = 0;
    for (int i = 0; i < total; i++) {
        if (vector[i] == num)
            cont++;
    }
    return cont;
}

// Función que convierte un entero a binario
vector<int> EnteroABinario(int entero) {
    vector<int> binario;
    while (entero > 0) {
        binario.insert(binario.begin(), entero % 2);
        entero /= 2;
    }
    return binario;
}

// Función para multiplicar todos los elementos del vector por un número
void MultiplicarVector(int vector[], int total, int numero) {
    for (int i = 0; i < total; i++) {
        vector[i] *= numero;
    }
}

// Función que suma las posiciones pares del vector, multiplica por 100 y divide por la suma de las posiciones impares multiplicadas por 2
double ProcesarVector(int vector[], int total) {
    int suma_pares = 0;
    int suma_impares = 0;

    for (int i = 0; i < total; i++) {
        if (i % 2 == 0) {
            suma_pares += vector[i];
        } else {
            suma_impares += vector[i] * 2;
        }
    }

    if (suma_impares == 0) { // Evitar división por cero
        return numeric_limits<double>::infinity();
    }

    return (suma_pares * 100.0) / suma_impares;
}

// Función para determinar si los elementos del vector son primos
bool EsPrimo(int numero) {
    if (numero < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(numero); i++) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}

// Función que devuelve la sumatoria de los números primos en el vector
int SumatoriaPrimos(int vector[], int total) {
    int sumatoria = 0;
    for (int i = 0; i < total; i++) {
        if (EsPrimo(vector[i])) {
            sumatoria += vector[i];
        }
    }
    return sumatoria;
}

int main() {
    int vector[] = {10, 20, 6, 45, 78, 95, 21, 45, 74, 21, 2, 1};
    int total = sizeof(vector) / sizeof(int);
    int num = 21;

    // 1a. Contar ocurrencias
    int cont = BuscaNumero(vector, total, num);
    cout << endl << "El elemento " << num << " existe " << cont << " veces en el vector";

    // 1b. Convertir entero a binario
    int entero = 10;
    vector<int> binario = EnteroABinario(entero);
    cout << endl << "Binario de " << entero << ": ";
    for (int bit : binario) {
        cout << bit;
    }

    // 2. Multiplicar vector
    int numero_multiplicar = 2;
    MultiplicarVector(vector, total, numero_multiplicar);
    cout << endl << "Vector multiplicado por " << numero_multiplicar << ": ";
    for (int i = 0; i < total; i++) {
        cout << vector[i] << " ";
    }

    // 3. Suma y procesar posiciones pares e impares del vector
    cout << endl << "Resultado de procesar vector: " << ProcesarVector(vector, total);

    // 4. Sumatoria de números primos en el vector
    cout << endl << "Sumatoria de primos en el vector: " << SumatoriaPrimos(vector, total);

    return 0;
}