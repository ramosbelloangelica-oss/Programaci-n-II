#include<bits/stdc++.h>
using namespace std;

class Reloj{
    private:
int horas , minutos , segundos;
    public:
    Reloj(int h,int m , int s){
        if(h>=o && h<=23){
            horas=h
        }
        if(m>=0 && m<=59){
            minutos =m
        }
        if(s>0 && s<59){
            segundos =s;

        }
    }
    void avanzarsegundo(){
        segundos++;
        if(segundos ==60){
            segundos =0;
            minutos ++
            if (minutos == 60){
                minutos=0;
                horas++;
                if(horas==24){
                    horas=0;
                }
            }
        }
    }
void mostrarHora(){
    cout<<horas<< ":" << minutos<< ":" << segundos<< endl;

}
    

};
int main(){
    int h , m , s ;
    cout<<"Ingrese hora inicial:";
    cin>> h;
    cout<<"Ingrese minutos iniciales:";
    cin>>m;
    cout<< "Ingrese segundos iniciales:";
    cin>>s;

    Reloj reloj(h,m,s);
    cout<<"Hora actual:";
    reloj.mostrarHora();
    reloj.avanzarSegundo();
    cout<<"Hora despues de avanzar un segundo: ";
    reloj.mostrarHora();
    return 0;

}
