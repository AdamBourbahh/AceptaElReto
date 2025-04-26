#include <iostream>
using namespace std;

int main() {
    int num_muestras; 
    cin >> num_muestras;

    while (num_muestras != 0) {
        int contador = 1; 
        int indice_anterior, indice_actual;
        bool hay_crisis = false;

        cin >> indice_anterior;

        while (contador < num_muestras) {
            cin >> indice_actual;

    
            if (indice_anterior >= indice_actual) {
                hay_crisis = true;
            }


            indice_anterior = indice_actual;
            contador++;
        }

        if (hay_crisis) {
            cout << "NO\n";
        } else {
            cout << "SI\n";
        }

   
        cin >> num_muestras;
    }

    return 0;
}

