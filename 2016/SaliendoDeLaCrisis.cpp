/*Saliendo de la crisis
La abeja reina dijo hace unos cuantos meses que la colmena estaba por fin saliendo de la crisis. Ahora Maya quiere comprobar cómo de ciertas eran aquellas declaraciones, así que ha recopilado el histórico de distintos indicadores económicos desde el día de la declaración hasta hoy para ver si, efectivamente, todos ellos han ido creciendo día a día desde entonces.

Entrada
La entrada estará compuesta de distintos indicadores económicos, cada uno de ellos en dos líneas distintas. La primera línea indica el número de muestras recogidas del indicador (0 < n = 100). La segunda línea contiene n números positivos con los valores económicos (entre 1 y 10.000.000) medidos desde el día de la declaración de la abeja reina hasta el día de hoy.

La entrada termina con un indicador sin muestras (0) que no debe procesarse.

Salida
Por cada caso de prueba se dirá si según ese indicador la abeja reina tenía razón (SI) o las cosas no están tan bien como ella cree (NO).
Entrada de ejemplo
3
1 3 6
4
1 3 2 5
3
6 6 6
0
Salida de ejemplo
SI
NO
NO
*/
#include <iostream>
using namespace std;

int main() {
    int num_muestras;  // Número de muestras a procesar
    cin >> num_muestras;

    while (num_muestras != 0) {
        int contador = 1;  // Contador para iterar sobre las muestras
        int indice_anterior, indice_actual;
        bool hay_crisis = false;

        // Leer el primer índice económico
        cin >> indice_anterior;

        // Procesar el resto de las muestras
        while (contador < num_muestras) {
            cin >> indice_actual;

            // Si el índice actual es menor o igual al anterior, hay crisis
            if (indice_anterior >= indice_actual) {
                hay_crisis = true;
            }

            // Actualizar el índice anterior para la siguiente comparación
            indice_anterior = indice_actual;
            contador++;
        }

        // Imprimir el resultado según la detección de crisis
        if (hay_crisis) {
            cout << "NO\n";
        } else {
            cout << "SI\n";
        }

        // Leer el próximo número de muestras para continuar o terminar
        cin >> num_muestras;
    }

    return 0;
}

