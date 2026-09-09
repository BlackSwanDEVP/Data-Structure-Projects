#include <iostream>
#include <list>
using namespace std;

void MostrarMenu() {
    cout << "\n======= Menu de Operaciones =======\n"; 
    cout << "1. Imprimir Lista\n";
    cout << "2. Agregar un numero al final\n";
    cout << "3. Agregar un numero al inicio\n";
    cout << "4. Salir del Programa\n";
    cout << "Ingrese una opcion: ";
}

int main () {
    list<int>Lista;
    int tamanoLista = 0;
    
    cout << "=== Lista Enlazada ===\n";
    cout << "Ingresa la cantidad de numeros a ingresar en la lista: ";
    cin >> tamanoLista;

    for (int i = 0; i < tamanoLista; i++) {
        int numero;
        cout << "Ingresa un numero: ";
        cin >> numero;
        Lista.push_back(numero);
    }
    
    int opcion;

    do {
        MostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            for (int e : Lista) {
                cout << e << endl;
            }
            break;
        case 2: 
            int numeroFinal;
            cout << "Ingresa el numero: ";
            cin >> numeroFinal;
            Lista.push_back(numeroFinal);
            break;
        case 3: 
            int numeroInicio;
            cout << "Ingresa el numero: ";
            cin >> numeroInicio;
            Lista.push_front(numeroInicio);
            break;
        case 4:
            cout << "Saliendo del Programa..." << endl;
            return 0;
        default:
            cout << "Ingrese una opcion valida para continuar" << endl;
            break;
        }    
    } while (opcion != 4);
    
    return 0;
}

