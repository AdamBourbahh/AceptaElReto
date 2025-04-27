#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool EsRepDigit(string num){
    int frec[10]{0};
    bool condicion=false;
            for(int i=0; i<=3&&!condicion; i++){
                    frec[num[i]-'0']++;
        if(frec[num[i]-'0']>3) condicion=true;
        }
    return condicion;
}

int OrdenarDigDesc(string &num){
    vector<int> numer{num[0]-'0', num[1]-'0', num[2]-'0', num[3]-'0'};
    sort(numer.begin(), numer.end(), greater<int>());
    for(int i=0; i<=3; i++){
        num[i] = numer[i] + '0';
    }
    return stoi(num);
}

int OrdenarDigAsc(string &num){
    vector<int> numer{num[0]-'0', num[1]-'0', num[2]-'0', num[3]-'0'};
    sort(numer.begin(), numer.end());
    for(int i=0; i<=3; i++){
        num[i] = numer[i] + '0';
    }
    return stoi(num);
}

int main (){
    string numero_str;
    int numero_int;
    int casos;
    cin >> casos;
    for(int i=0; i<casos; i++){
        cin >> numero_str;
        while (numero_str.size() < 4) numero_str = '0' + numero_str;
        numero_int = stoi(numero_str);
        if(!EsRepDigit(numero_str)){
            int j = 0;
            while(numero_int != 6174){
                numero_int = OrdenarDigDesc(numero_str) - OrdenarDigAsc(numero_str);
                numero_str = to_string(numero_int);
                while (numero_str.size() < 4) numero_str = '0' + numero_str;
                j++;
            }
            cout << j << endl;
        }
        else cout << 8 << endl;
    }
}
