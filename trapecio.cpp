#define TRAPECIO_h
#define TRAPECIO_h
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
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
void trapecio(void)
{
    int y,m;
    double xo,xn,fxo,fxn,h,xi,fxi,At,n,f;
    cout<<"Funcion: x^2-x-1\n";
    cout<<"\n\nvalor de Xo\n";
    cin>>xo;
    cout<<"valor de Xn\n";
    cin>>xn;
    cout<<"valor de n\n";
    cin>>n;
    cout<<"numero de X\n";
    cin>>m;
    fxo=pow(xo,2)-xo-1;
    fxn=pow(xn,2)-xn-1;
    h=((xn-xo)/n);

    cout<<"["<<xo<<","<<xn<<"]";
    cout<<setiosflags(ios::fixed)<<setiosflags(ios::showpoint)<<setprecision(2)<<endl;
    cout<<"\nf(Xo)= "<<fxo<<endl<<"f(Xn)= "<<fxn<<endl<<"h= "<<h;
    f=0;
    for(y=1; y<=m; y++)
    {
        xi=xo+(y*h);
        fxi=pow(xi,2)-xi-1;
        cout<<setiosflags(ios::fixed)<<setiosflags(ios::showpoint)<<setprecision(2)<<endl;
        cout<<"\nX("<<y<<")= "<<xi;
        cout<<"\nf(X"<<y<<")= "<<fxi;
        f=f+fxi;
        f=fxi;

    }

    cout<<"\n\nA="<<(h*(((fxo+fxn)/2)+f));
}

int main()
{
    //orden de llamado de las funciones
    setlocale(LC_ALL,"spanish");//carga la biblioteca para los acentos
    system("color F9");//COLOR DEL SISTEMA
    portada();
    trapecio();
    return 0;
}

