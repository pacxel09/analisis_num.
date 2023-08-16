
#define KUTTA_h
#define KUTTA_h
#include <iostream>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
double FunRK(double,double);
double K1(double,double,double);
double K2(double,double,double);
double K3(double,double,double);
double K4(double,double,double);
double K(double,double,double);
void kutta(double,double,double,int);
void datos(double *,double *,double *,int *);
double xo,yo,xn;
int n;
void portada (void)//funcion de retorno nulo,valor de entrada nulo void= nulo
{
std::cout<<"\n\n                    INSTITUTO POLITECNICO NACIONAL "<<std::endl;
std::cout<<"\n\n           Escuela Superior de Ingeniería Mecánica y eléctrica"<<std::endl;
std::cout<<"\n\n                            ESIME Zacatenco"<<std::endl;
std::cout<<"\n\n              Ingenieria en control y automatización"<<std::endl;
std::cout<<"\n\n                       analisis numerico\n"<<std::endl;
std::cout<<"                            3AM4\n"<<std::endl;
std::cout<<"                Nombre:Tinoco Martinez Axel Javier\n"<<std::endl;


}

int main(void)
{
    //definicion de la cabecera
//orden de llamado de las funciones
    setlocale(LC_ALL,"spanish");//carga la biblioteca para los acentos
    system("color F9");//COLOR DEL SISTEMA
    portada();//invocacion o llamado de definicion portada
    datos (&xo, &yo, &xn,&n);
    kutta(xo, yo, xn,n);
    return 0;
}

void datos(double *xo,double *yo, double *xn, int *n)
{
    double Xo,Yo,Xn; int N;
    cout<<"Inserte el valor de Xo= ";cin>>Xo;
    cout<<"Inserte el valor de Xn= ";cin>>Xn;
    cout<<"Inserte el numero de iteraciones=";cin>>N;
    cout<<"Inserte el valor Yo= "; cin>>Yo;
    *xo=Xo;*yo=Yo;*xn=Xn;*n=N;
}

void kutta(double xo,double yo,double xn,int n)
{
    double xi,yi;
    int i,y,m;
    double h=(xn-xo)/n;
    std::cout << std::fixed;
    std::cout << std::setprecision(4) <<endl;
    cout<<"   n\t\ti\t\tXi\t\t\t\tYi\t\tY(i+1)\n";

    for(i=0,y=17,m=1;i<n;i++,y++,m++)
    {
        yi=yo+K(xo,yo,h);
        cout<<"   "<<m<<"\t\t"<<i<<"\t\t"<<xo<<"\t\t"<<yo<<"\t\t"<<yi<<"\n";
        xo=xo+h;
        yo=yi;
    }

    cout<<"\n\n\t\tLa solucion de la ecuacion diferencial es Xr= "<<setprecision(4)<<yi<<endl;
}

double K1(double x,double y,double h)
{
    return h*FunRK(x,y);
}

double K2(double x,double y,double h)
{
    return h*FunRK((x+(h/2.0)),(y+(K1(x,y,h)/2.0)));
}
double K3(double x,double y,double h)
{
    return h*FunRK((x+(h/2.0)),(y+(K2(x,y,h)/2.0)));
}
double K4(double x,double y,double h)
{
    return h*FunRK((x+h),(y+K3(x,y,h)));
}
double K(double x,double y,double h)
{
    return (1.0/6.0)*(K1(x,y,h)+(2.0*K2(x,y,h))+(2.0*K3(x,y,h))+K4(x,y,h));
}

double FunRK(double x,double y)
{
    return x+y;
}



