#ifndef CAIXA_H
#define CAIXA_H


template <typename T>
class Caixa{
    private:
    int coisa;
    public:
    Caixa() = default;

    Caixa(const T& coisa){
        this->coisa=coisa;
    }
    T getCoisa(){
        return coisa
    }
    T setCoisa(int n){
        this->coisa = n;
    }
};

#endif