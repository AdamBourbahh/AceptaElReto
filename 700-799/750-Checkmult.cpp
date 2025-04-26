/*Checkmult*/
/*Para detectar errores de transmisi�n en redes de datos, es habitual calcular
un checksum o "suma de verificaci�n" a partir de los datos transmitidos, y
enviar tambi�n el valor obtenido. En el otro extremo, se recalcula el valor
con los datos recibidos y si el resultado no coincide con el esperado se
asume que se ha producido un error de transmisi�n y se toman las medidas
oportunas.

Hay muchas formas de calcular el checksum, que se conocen de forma conjunta
como funciones de redundancia. La idea es tan �til que se utiliza en muchos
otros lugares, como detecci�n de errores en dispositivos de almacenamiento, o
incluso criptograf�a y firmas digitales.

Inspirado por el t�rmino ingl�s checksum, Asier Rorde Tecta ha inventado su
propia funci�n de redundancia y la ha llamado checkmult. Para calcular el
valor asociado a un n�mero, toma todos sus d�gitos que no sean cero y los
multiplica entre s�, repitiendo el proceso hasta terminar con un solo d�gito.
Adem�s, cuenta el n�mero de ceros que se encuentra durante el proceso,
incluidos los del n�mero original. Al final, termina con dos valores: el
d�gito resultado de las sucesivas multiplicaciones y el n�mero de ceros
vistos. Pone ambos juntos y ese es el valor del checkmult.
Entrada
El programa deber� procesar m�ltiples casos de prueba, cada uno un n�mero
1<=N<=10^9.La entrada termina con un 0, que no debe procesarse.
Entrada de ejemplo
1  
20  
506  
0  
Salida de ejemplo
10  
21  
32 
Notas
El �ltimo ejemplo, 506, tiene un primer cero. La multiplicaci�n de sus
d�gitos que no son cero, 5 y 6, da 30, lo que a�ade un segundo cero. Al
quitarlo, se queda un �nico d�gito, el 3. El checkmult es la concatenaci�n
de este d�gito final y del n�mero total de ceros encontrados, de ah� el 32. */
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void digitos(int numero, int digitos[], int &longitud){
   longitud=0;
   while(numero > 0){
      digitos[longitud++]=numero%10;
      numero/=10;
   }
}

int main() {
    int num;
    
    // Leer m�ltiples casos de prueba
    while (cin >> num && num != 0) {
        int digitos_arr[10];  // Arr(GRUMETE)ay para almacenar los d�gitos (m�ximo 10 d�gitos para n�meros <= 10^9)
        int longitud = 0;
        int total_ceros = 0;
        
        // Extraer los d�gitos del n�mero
        digitos(num, digitos_arr, longitud);
        
        // Realizar las multiplicaciones de los d�gitos no cero
        int multiplicacion = 1;
        for (int i = 0; i < longitud; i++) {
            if (digitos_arr[i] != 0) {
                multiplicacion *= digitos_arr[i];
            } else {
                total_ceros++;
            }
        }
        
        // Repetir el proceso hasta que el n�mero sea un solo d�gito
        while (multiplicacion >= 10) {
            int nuevo_multiplicacion = 1;
            int ceros_en_this_pass = 0;
            
            // Extraer los d�gitos del nuevo n�mero y multiplicarlos
            digitos(multiplicacion, digitos_arr, longitud);
            for (int i = 0; i < longitud; i++) {
                if (digitos_arr[i] != 0) {
                    nuevo_multiplicacion *= digitos_arr[i];
                } else {
                    ceros_en_this_pass++;
                }
            }
            
            multiplicacion = nuevo_multiplicacion;
            total_ceros += ceros_en_this_pass;
        }
        
        // Imprimir el resultado final
        cout << multiplicacion*10+total_ceros << endl;
    }
    
    return 0;
}
   















   
   










