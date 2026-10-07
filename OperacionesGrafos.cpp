#include <iostream>
#include <string>
#include <queue>
#include <stack> 
using namespace std;

const int Tam = 7;
const int Inicio = 3; 

void Menu(int &opcion) {
    cout << "\n━━━━━━━━━━━━━━  Menu de Opciones  ━━━━━━━━━━━━━━\n";
    cout << "1. Imprimir Grafo\n";
    cout << "2. Recorrer Grafo por Amplitud\n";
    cout << "3. Recorrer Grafo por Profundidad\n";
    cout << "4. Salir del Programa \n"; 
    cout << "Ingrese una opcion: ";
    cin >> opcion;
}

void ImprimirGrafo(const int Matriz[7][7], const char Vertices[7]) {
    cout << "\n━━━━━━━━ GRAFO ━━━━━━━━\n";
    cout << "    "; 
    for (int j = 0; j < Tam; ++j) {
        cout << Vertices[j] << "  ";
    }
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━\n";

    for (int i = 0; i < Tam; ++i) {
        cout << Vertices[i] << " | ";
        for (int j = 0; j < Tam; ++j) {
            cout << Matriz[i][j] << "  ";   
        }
        cout << "\n";
    }
}

void RecorrerAmplitud(const int Matriz[7][7], const char Vertices[7], int inicio) {
    bool visitado[Tam] = {false};
    queue<int> cola;

    visitado[inicio] = true;
    cola.push(inicio);

    cout << "\nRecorrido por Amplitud iniciando fijamente en '" << Vertices[inicio] << "': ";

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();

        cout << Vertices[actual] << " ";

        for (int i = 0; i < Tam; ++i) {
            if (Matriz[actual][i] == 1 && !visitado[i]) {
                visitado[i] = true;
                cola.push(i);
            }
        }
    }
    cout << "\n";
}

void RecorrerProfundidad(const int Matriz[7][7], const char Vertices[7], int inicio) {
    bool visitado[Tam] = {false};
    stack<int> pila;

    pila.push(inicio);

    cout << "\nRecorrido por Profundidad iniciando fijamente en '" << Vertices[inicio] << "': ";

    while (!pila.empty()) {
        int actual = pila.top();
        pila.pop();

        if (!visitado[actual]) {
            visitado[actual] = true;
            cout << Vertices[actual] << " ";
        }

        for (int i = Tam - 1; i >= 0; --i) {
            if (Matriz[actual][i] == 1 && !visitado[i]) {
                pila.push(i);
            }
        }
    }
    cout << "\n";
}

int main() {
    int opcion = 0;
    const int Matriz[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},        
    };

    const char Vertices[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

    do {
        Menu(opcion);

        switch (opcion) {
        case 1: 
            ImprimirGrafo(Matriz, Vertices);
            break;

        case 2: 
            RecorrerAmplitud(Matriz, Vertices, Inicio);
            break;
        case 3:
            RecorrerProfundidad(Matriz, Vertices, Inicio);
            break;
        case 4:
            cout << "Saliendo del Programa...\n";
            break;
        default: 
            cout << "Ingrese una opcion valida (1-4).\n";
            break;
        }

    } while (opcion != 4);

    return 0;
}