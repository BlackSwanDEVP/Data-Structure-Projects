#include <iostream>
#include <cmath>
using namespace std;

int main () {
    cout << "======= CALCULO DE ECUACIONES DE SEGUNDO GRADO DIRECTO =======" << endl;
    cout << "Una ecuacion de segundo grado es de la forma: ax\u00b2+bx+c=0" << endl;
    cout << "Recuerde ingresar numeros enteros, puedes usar signos (-a o +b)" << endl;
    
    int a = 0, b = 0, c = 0;
    cout << "Ingrese el valor para A: ";
    cin >> a;

    cout << "Ingrese el valor para B: ";
    cin >> b;

    cout << "Ingrese el valor para C: ";
    cin >> c;

    if (a == 0) {
        cout << "Error: No se puede hacer una division por 0" << endl;
        return 0;
    }

    float contenidoraiz = pow(b,2)-4*a*c;

    if (contenidoraiz < 0) {
        cout << "Error: La operacion no puede completarse en los numeros imaginarios" << endl;
    }else {
       float valorx1 = (-b + sqrt(contenidoraiz))/(2*a);
        cout << "El resultado de X1 es: " << valorx1 << endl;

        float valorx2 = (-b - sqrt(contenidoraiz))/(2*a);
        cout << "El resultado de X2 es: " << valorx2 << endl;
    } 
};