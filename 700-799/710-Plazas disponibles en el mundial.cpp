#include <iostream>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    for(int i=0; i<casos; i++){
        int plazas_totales;
        cin >> plazas_totales;
        int sum=0;
        for(int j=0;j<6;j++){
            int num;
            cin >> num;
            sum+=num;
            }
            cout << plazas_totales-sum << endl;;
        }
    }

