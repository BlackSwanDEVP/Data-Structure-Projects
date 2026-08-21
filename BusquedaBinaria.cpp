#include <iostream>
using namespace std;

int BusquedaBinaria (int arreglo[], int inicio, int final, int objetivo) {

    if (inicio > final) {
        return -1;
    }

    int medio = inicio + (final - inicio) / 2;

    if (arreglo[medio] == objetivo) {
        return medio;
    }

    if (arreglo[medio] < objetivo) {
        return BusquedaBinaria(arreglo, medio + 1, final, objetivo);
    } else {
        return BusquedaBinaria(arreglo, inicio,  medio - 1 , objetivo);
    }
}

int main () {
    int arreglo [10] = {5, 20, 30, 60, 65, 70, 85, 90, 100, 110};
    int objetivo;

    cout << "======= Busqueda Binaria con Recursividad =======" << endl;
    cout << "Puedes buscar los siguientes numeros: ";

    for (int e : arreglo) {
        cout << e << " ";
    }

    cout << "" << endl;
    cout << "Ingresa el numero a buscar: " << endl;
    cin >> objetivo;

    int resultado = BusquedaBinaria(arreglo, 0, 9, objetivo);
    
    if (resultado != -1) {
        std::cout << "Elemento encontrado en el indice: " << resultado << std::endl;
    } else {
        std::cout << "Elemento no encontrado." << std::endl;
    }

    return 0;
}