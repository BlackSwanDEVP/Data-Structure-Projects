#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

int prioridad(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}


bool esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


string infijaAPostfija(const string& infija) {
    stack<char> pila;
    string postfija = "";

    for (size_t i = 0; i < infija.length(); i++) {
        char c = infija[i];

        if (isspace(c)) continue;
      
        if (isalnum(c) || c == '.') {
            postfija += c;
            if (i + 1 < infija.length() && !isalnum(infija[i + 1]) && infija[i + 1] != '.') {
                postfija += ' ';
            }
        }
        else if (c == '(') {
            pila.push(c);
        }
        else if (c == ')') {
            while (!pila.empty() && pila.top() != '(') {
                postfija += ' ';
                postfija += pila.top();
                pila.pop();
            }
            if (!pila.empty()) pila.pop();
        }
        else if (esOperador(c)) {
            postfija += ' ';
            while (!pila.empty() && (
                   (prioridad(pila.top()) > prioridad(c)) ||
                   (prioridad(pila.top()) == prioridad(c) && c != '^') 
                  )) {
                postfija += pila.top();
                postfija += ' ';
                pila.pop();
            }
            pila.push(c);
        }
    }

    while (!pila.empty()) {
        postfija += ' ';
        postfija += pila.top();
        pila.pop();
    }

    return postfija;
}

string infijaAPrefija(string infija) {
    reverse(infija.begin(), infija.end());

    for (size_t i = 0; i < infija.length(); i++) {
        if (infija[i] == '(') {
            infija[i] = ')';
        } else if (infija[i] == ')') {
            infija[i] = '(';
        }
    }

    string postfija = infijaAPostfija(infija);
    reverse(postfija.begin(), postfija.end());
    return postfija;
}

int main() {
    string expresion;
    int opcion;

    cout << "=== CONVERTIDOR DE NOTACIÓN INFIJA ===\n";
    cout << "Ingresa la expresion infija (ejemplo: (A+B)*C o (2+3)*4): ";
    getline(cin, expresion);

    cout << "\nSelecciona el tipo de conversion:\n";
    cout << "1. Convertir a Notacion Postfija \n";
    cout << "2. Convertir a Notacion Prefija\n";
    cout << "3. Convertir a Ambas\n";
    cout << "Opcion: ";
    cin >> opcion;

    cout << "\n-----------------------------------\n";
    switch (opcion) {
        case 1:
            cout << "Expresion Postfija: " << infijaAPostfija(expresion) << endl;
            break;
        case 2:
            cout << "Expresion Prefija:  " << infijaAPrefija(expresion) << endl;
            break;
        case 3:
            cout << "Expresion Postfija: " << infijaAPostfija(expresion) << endl;
            cout << "Expresion Prefija:  " << infijaAPrefija(expresion) << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
    }
    cout << "-----------------------------------\n";

    return 0;
}   

