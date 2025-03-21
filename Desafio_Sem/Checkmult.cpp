/*Checkmult*/
/*Para detectar errores de transmisión en redes de datos, es habitual calcular
un checksum o "suma de verificación" a partir de los datos transmitidos, y
enviar también el valor obtenido. En el otro extremo, se recalcula el valor
con los datos recibidos y si el resultado no coincide con el esperado se
asume que se ha producido un error de transmisión y se toman las medidas
oportunas.

Hay muchas formas de calcular el checksum, que se conocen de forma conjunta
como funciones de redundancia. La idea es tan útil que se utiliza en muchos
otros lugares, como detección de errores en dispositivos de almacenamiento, o
incluso criptografía y firmas digitales.

Inspirado por el término inglés checksum, Asier Rorde Tecta ha inventado su
propia función de redundancia y la ha llamado checkmult. Para calcular el
valor asociado a un número, toma todos sus dígitos que no sean cero y los
multiplica entre sí, repitiendo el proceso hasta terminar con un solo dígito.
Además, cuenta el número de ceros que se encuentra durante el proceso,
incluidos los del número original. Al final, termina con dos valores: el
dígito resultado de las sucesivas multiplicaciones y el número de ceros
vistos. Pone ambos juntos y ese es el valor del checkmult.
Entrada
El programa deberá procesar múltiples casos de prueba, cada uno un número
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
El último ejemplo, 506, tiene un primer cero. La multiplicación de sus
dígitos que no son cero, 5 y 6, da 30, lo que añade un segundo cero. Al
quitarlo, se queda un único dígito, el 3. El checkmult es la concatenación
de este dígito final y del número total de ceros encontrados, de ahí el 32. */
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
    
    // Leer múltiples casos de prueba
    while (cin >> num && num != 0) {
        int digitos_arr[10];  // Arr(GRUMETE)ay para almacenar los dígitos (máximo 10 dígitos para números <= 10^9)
        int longitud = 0;
        int total_ceros = 0;
        
        // Extraer los dígitos del número
        digitos(num, digitos_arr, longitud);
        
        // Realizar las multiplicaciones de los dígitos no cero
        int multiplicacion = 1;
        for (int i = 0; i < longitud; i++) {
            if (digitos_arr[i] != 0) {
                multiplicacion *= digitos_arr[i];
            } else {
                total_ceros++;
            }
        }
        
        // Repetir el proceso hasta que el número sea un solo dígito
        while (multiplicacion >= 10) {
            int nuevo_multiplicacion = 1;
            int ceros_en_this_pass = 0;
            
            // Extraer los dígitos del nuevo número y multiplicarlos
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
   















   
   










