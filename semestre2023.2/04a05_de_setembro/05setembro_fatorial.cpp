#include <iostream>
using  namespace std;

long fat(long n){
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return n * fat(n-1);
    }
}
int main(){
    long n,res;
    cin >> n;
    res = fat(n);
    cout << res << endl;
}