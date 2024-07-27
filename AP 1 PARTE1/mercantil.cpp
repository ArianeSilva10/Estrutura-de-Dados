#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int p;
    cin >> p;

    float valor[p];
    for(int i = 0; i < p; ++i)
        cin >> valor[i];

    float jog1[p];
    for(int i = 0; i < p; ++i)
        cin >> jog1[i];
    
    char jog2[p];
    for(int i = 0; i < p; ++i)
        cin >> jog2[i];

    int venc1 = 0, venc2 = 0;

    for(int i = 0; i < p; ++i){
        if(jog2[i] == 'm'){
            if(jog1[i] < valor[i])
                venc1++;
            else if(jog1[i] == valor[i])
                venc1++;
            else
                venc2++;
        } 
        else if(jog2[i] == 'M'){
            if(jog1[i] > valor[i])
                venc1++; 
            else if(jog1[i] == valor[i])
                venc1++;
            else
                venc2++;
        }
    }
    if(venc1 > venc2)
        cout << "primeiro" << endl;
    else if(venc1 < venc2)
        cout << "segundo" << endl;
    else
        cout << "empate" << endl;
}