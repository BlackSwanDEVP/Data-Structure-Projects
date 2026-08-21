#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {    
    cout << "======= CALCULO DE ECUACIONES DE SEGUNDO GRADO ITERACIONES =======" << endl;
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

    double contenidoraiz = pow(b,2)-4*a*c;

    if (contenidoraiz < 0) {
        cout << "Error: La operacion no puede completarse en los numeros imaginarios" << endl;
        return 0;
    }

    double tolerancia = 1e-7;
    int maxiteraciones = 100;

    double valorx1 = -10.0;
    
    for (int i = 0; i < maxiteraciones; i++) {
        double fx = a * valorx1 * valorx1 + b * valorx1 + c;
        double dfx = 2 * a * valorx1 + b;
        
        if (abs(dfx) < 1e-12) {
            break;
        }
        
        double x_nuevo = valorx1 - (fx / dfx);
        
        if (abs(x_nuevo - valorx1) < tolerancia) {
            valorx1 = x_nuevo;
            break;
        }
        
        valorx1 = x_nuevo;
    }

    double valorx2 = 10.0;
    
    for (int i = 0; i < maxiteraciones; i++) {
        double fx = a * valorx2 * valorx2 + b * valorx2 + c;
        double dfx = 2 * a * valorx2 + b;
        
        if (abs(dfx) < 1e-12) {
            break;
        }
        
        double x_nuevo = valorx2 - (fx / dfx);

        if (abs(x_nuevo - valorx2) < tolerancia) {
            valorx2 = x_nuevo;
            break;
        }
        
        valorx2 = x_nuevo;
    }

    cout << fixed << setprecision(6);
    cout << "El resultado de x1 es: " << valorx1 << endl;
    cout << "El resultado de X2 es: " << valorx2 << endl;
    return 0;
};