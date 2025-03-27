/* Los campesinos han recogido la cosecha en sacos, cuyos pesos no son necesariamente iguales. 
Cada burro lleva un par de alforjas, colgadas una a cada lado del lomo. En cada alforja se lleva
un saco, que puede ser de cualquier peso aunque es importante que las dos alforjas lleven el 
mismo peso para que el burrito vaya equilibrado y no se caiga.
Yafeu tiene mucho trabajo, y le aburre dedicar todo un día a emparejar los sacos.
Este año le han recomendado un estudiante asegurándole que le ahorrará mucho tiempo.
Está dispuesto a darle una buena recompensa si eso es cierto.
- Entrada
La entrada comienza con un entero que indica el número de casos de prueba que vendrán a continuación.
Cada caso consta de dos líneas. La primera contiene el número de burros disponibles y el número de sacos
que hay que cargar (ambos entre 1 y 1.000.000). En la línea siguiente aparecen los pesos en gramos de
cada saco separados por espacios. Cada uno pesa como mucho 20 Kg (valores entre 1 y 20.000).
- Salida
Para cada caso de prueba se indicará el máximo número de burros que se pueden cargar.

- Entrada de ejemplo

3
6 10
1 2 3 1 2 3 1 2 3 1
2 6
3 3 2 2 1 1
3 7
3 14 15 92 65 35 89

- Salida de ejemplo

4
2
0

*/

#include <iostream>
using namespace std;

int maxBurros(int psacos[], int sacos, int burros) {
    int parejas = 0;
    bool usado[sacos] = {false};  // Marcar sacos ya usados
    
    // Buscamos parejas de sacos con el mismo peso
    for(int i = 0; i < sacos && parejas < burros; i++) {
        if (!usado[i]) {
            for(int j = i + 1; j < sacos && parejas < burros; j++) {
                if (psacos[i] == psacos[j] && !usado[j]) {
                    parejas++;
                    usado[i] = usado[j] = true;  // Marcamos ambos sacos como usados
                    
                }
            }
        }
    }
    return parejas;
}

int main() {
    int casos;
    const int MAX_SIZE = 1000000;
    cin >> casos;
    
    for(int i = 0; i < casos; i++) {
        int burros, sacos;
        cin >> burros >> sacos;
        
        int psacos[MAX_SIZE];
        
        // Leemos los pesos de los sacos
        for(int j = 0; j < sacos; j++) {
            cin >> psacos[j];
        }
        
        // Calculamos y mostramos el resultado
        cout << maxBurros(psacos, sacos, burros) << endl;
    }
}