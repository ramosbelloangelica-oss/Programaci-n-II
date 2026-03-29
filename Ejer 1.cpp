#include <bits/stdc++.h>
using namespace std;

class Rectangulo {
private:
    double base;
    double altura ;

public:

    Rectangulo(double base, double altura ){
        this->altura=altura;
        this->base=base;
    }

    double get_base(){
        return base;
    }
    void set_base(double new_base){
        if(base>0){
            base=new_base;
        }
        else {
            cout << "Error" << endl;
            base = 0;
        }
    }
    double get_altura(){
        return altura;
    }
    void set_altura(double new_altura ){
        if(altura>0){
            altura =new_altura;
        }
        else {
            cout << "Error" << endl;
            altura = 0;
        }
    }

    double Area(){
        return base*altura;
    }
    double Perimetro(){
        return (base + altura) * 2;
    }
};

int main(){
    double b, h;
    cout<<"Introduzca la base y la altura"<< endl;
    cin>> b;
    cin >> h;
    Rectangulo r(b, h);
    cout << r.get_altura() << endl;
    cout << "El area es "<< r.Area()<< endl ;
    // cout<<"El perimetro es"<< r.Perimetro()<< endl ;



}
