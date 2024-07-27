#include <iostream>
using namespace std;

double potencia(double a, int b){
    if(b == 0)
        return 1;
    else
        return a * potencia(a, b-1);
}
int main(){
    double n, res;
    int p;
    cin >> n;
    cin >> p;
    res = potencia(n,p);
    cout << res << endl;
}