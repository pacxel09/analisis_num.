#define SIMPSON_h
#define SIMPSON_h
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <iostream>//bibliotecas de entrada/salida
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<clocale>//caracteres especiales
using namespace std;
void portada (void)//funcion de retorno nulo,valor de entrada nulo void= nulo
{
std::cout<<"\n\n                    INSTITUTO POLITECNICO NACIONAL "<<std::endl;
std::cout<<"\n\n           Escuela Superior de Ingeniería Mecánica y eléctrica"<<std::endl;
std::cout<<"\n\n                            ESIME Zacatenco"<<std::endl;
std::cout<<"\n\n              Ingenieria en control y automatización"<<std::endl;
std::cout<<"\n\n                      Analisis Numerico\n"<<std::endl;
std::cout<<"                            3AM5\n"<<std::endl;
std::cout<<"                Nombre:Tinoco Martinez Axel Javier\n"<<std::endl;


}
void simpson(void)
{
    int y,m;
    double xo,x2,fxo,fx2,h,x,fx,a,n,p=0,i=0;
    cout<<"\nvalor de Xo\n";
    cin>>xo;
    cout<<"valor de X2n\n";
    cin>>x2;
    cout<<"valor de n\n";
    cin>>n;
    cout<<"numero de X\n";
    cin>>m;
    fxo=pow(xo,2)-xo-1;
    fx2=pow(x2,2)-x2-1;
    h=((x2-xo)/(2*n));
    cout<<"["<<xo<<","<<x2<<"]";
    cout<<setiosflags(ios::fixed)<<setiosflags(ios::showpoint)<<setprecision(2)<<endl;
    cout<<"\nf(Xo)= "<<fxo<<endl<<"f(X2n)= "<<fx2<<endl<<"h= "<<h;
    for(y=1; y<=m; y++)
    {
        x=xo+(y*h);
        fx=pow(x,2)-x-1;
        cout<<setiosflags(ios::fixed)<<setiosflags(ios::showpoint)<<setprecision(2)<<endl;
        cout<<"\nX("<<y<<")= "<<x;
        cout<<"\nf(X"<<y<<")= "<<fx;
        if(y%2==0)
        {p=p+fx;}
        else
        {i=i+fx;}
    }
    cout<<setiosflags(ios::fixed)<<setiosflags(ios::showpoint)<<setprecision(2)<<endl;

    cout<<"\n\nA="<<((h/3)*(fxo+fx2+(4*i)+(2*p)));
}

int main()
{
//orden de llamado de las funciones
    setlocale(LC_ALL,"spanish");//carga la biblioteca para los acentos
    system("color F9");//COLOR DEL SISTEMA
    portada();
    simpson();
    return 0;
}



