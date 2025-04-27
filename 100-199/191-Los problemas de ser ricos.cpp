#include <iostream>
using namespace std;

int main (){
    int casos;
    cin >> casos;
    for(int i=0; i<casos; i++){
        int numero;
        int inicio;
        int decremento;
        cin >> numero >> inicio >> decremento;
        long long suma=0;
        for(int j=0; j<numero; j++){
            suma+=inicio - decremento*j;
        }
        cout << suma << endl;
        }

    }

