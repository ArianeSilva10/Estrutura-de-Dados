#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot){
    if(nrot == 0){
        return;
    }
    vector<int> aux(vet.size());
    for(unsigned int i = 0; i < vet.size(); i++){
        aux[(i + nrot) % vet.size()] = vet[i];
    }
    for(unsigned int i = 0; i < vet.size(); i++){
        vet[i] = aux[i];
    }
}

void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main(){
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);
}

