#include <iostream>
using namespace std;

int main() {
    int x,y;
    cin >> x >> y;
        while(x>=0&&y>=0 ){
            int perimetro=0;
            perimetro=2*x+2*y;
            cout << perimetro << endl;
            cin >> x >> y;
        }
    }
