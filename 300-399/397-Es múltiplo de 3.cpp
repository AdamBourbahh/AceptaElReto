#include <iostream>
using namespace std;

int main () {
    long long casos;
    cin >> casos;
    for(int i=0; i<casos; i++){
        long long n;
        cin >> n;
        if(n%3==1) cout << "NO" << endl;
        else cout << "SI" << endl;
    }

}
