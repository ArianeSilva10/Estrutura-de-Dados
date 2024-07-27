#include <iostream>
#include <iomanip>

double fatorial(int n){
    double fat {1.0};
    for(int i = 1;i<=n;++i){
        fat *= i ;
    }
    return fat;
}
double euler(int n){
    double res{1.0};
   for(int i = 1; i <= n;++i){
    res += 1/fatorial(i);
   }
   return res;
}
int main(){
    using namespace std;
int n;
    cin >> n;
    double e = euler(n);
    cout << std::fixed << std::setprecision(6);
    cout << e << endl;

}