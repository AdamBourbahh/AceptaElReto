#include <iostream>
#include <string>
using namespace std;

int SepMin(string hora){
    string Min={hora[3],hora[4]};
    return stoi(Min);
}

int SepHoras(string hora){
    string Min={hora[0],hora[1]};
    return stoi(Min);
}

int Calculo(string hora){
    int minutos=SepHoras(hora)*60;
    int total=minutos+SepMin(hora);
    int restante=1440-total;
    return restante;
}

int main (){
    string hora;
    cin >> hora;
    while(hora!="00:00"){
        cout <<Calculo(hora) << endl;
        cin >> hora;
    }
    }
