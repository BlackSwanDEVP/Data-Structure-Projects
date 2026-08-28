#include <iostream>
#include <stack>
using namespace std;

void MostrarMenu() {
    cout << "\n======= Menu de Operaciones =======\n"; 
    cout << "1. Elemento en la cima\n";
    cout << "2. Agregar un Elemento\n";
    cout << "3. Imprimir la Pila\n"; 
    cout << "4. Salir del Programa\n"; 
    cout << "Ingrese una opcion: ";
}

void ProcesarNuevaEntrada(stack<char>& pila) {
    string nuevaEntrada;
    
    cin.ignore(1000, '\n'); 

    cout << "Ingresa el texto de la nueva entrada: ";
    getline(cin, nuevaEntrada);
    for (char e : nuevaEntrada) {
        pila.push(e);
    }
}

void ImprimirPila (stack<char>pila) {
    cout << "El Texto en la Pila es: ";
    while (!pila.empty()) {
        cout << pila.top();
        pila.pop();
    }  
    cout << endl; 
}

int main () {
    stack<char> pila;
    string entradatexto;

    cout << "Ingresa el texto que estara en la Pila: ";
    getline(cin, entradatexto); /*Obtiene toda linea de texto hasta el salto de linea*/

    for (char e : entradatexto) {
        pila.push(e);
    }

    int opcion;
    
    do {
       MostrarMenu();
       cin >> opcion;

       switch (opcion) {
        case 1:
        if (!pila.empty()) {
            cout << "El elemento en la cima es: " << pila.top() << endl;    
        }
        else {
            cout << "La pila está vacía." << endl;
        }
        break;
        case 2:
            ProcesarNuevaEntrada(pila);
        break; 
        case 3:
            ImprimirPila(pila);
         break;
        case 4: 
            cout << "Saliendo del programa..." << endl;
            return 0;    
        break;
       default:
        cout << "Ingrese una opcion valida" << endl;
        break;
       }
    } while (opcion != 4); 
    return 0;
}