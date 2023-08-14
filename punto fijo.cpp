#include <iostream>//bibliotecas de entrada/salida
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<clocale>//caracteres especiales
#include<iomanip>

using namespace std;

class Puntofijo{
private:
    double xi,err;
    int n;
public:
    Puntofijo();
    void datos();
    double calcularRaiz();
    double f(double x);
    double g(double x);
    void resultado();
    double Error_re(double x1,double x2);
    ~Puntofijo();
};
Puntofijo::Puntofijo(): xi(0.0), err(0.0), n(0) {}
void Puntofijo::datos()
{

    cout<<" "<<endl;
    cout<<"\t\tDame el valor inicial Xi= ";cin>>xi;
    cout<<"\t\tDame el margen de error err= ";cin>>err;
    cout<<"\t\tDame el numero de iteraciones n= ";cin>>n;
}

double Puntofijo::calcularRaiz()
{
    double xr=0.0;
    cout<<setiosflags(ios::fixed)<<setiosflags(ios::showpoint)<<setprecision(4)<<endl;
    cout<<"n\t\txi\t\tf(Xi+1)\t\tError(%)"<<endl<<endl;

    for(int i=1;i<=n;i++)
    {
        xr=g(xi);

        cout<<i<<"\t\t"<<xi<<"\t\t"<<xr<<"\t\t"<<Error_re(xr,xi)*100<<endl;

        if(Error_re(xr,xi)<err)
            return xr;
        else
            xi=xr;
    }
    cout<<endl;
    return xr;

}

double Puntofijo::f(double x){return pow(x,2)-x-2.0;}
double Puntofijo::g(double x){return sqrt(x+2);}
void Puntofijo::resultado(){cout<<"la raiz es Xr= "<<calcularRaiz()<<endl;}
double Puntofijo::Error_re(double x1, double x2)
{return abs(x1-x2)/abs(x1);}
Puntofijo::~Puntofijo(){}
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
int main(void){//definicion de la cabecera
//orden de llamado de las funciones
    setlocale(LC_ALL,"spanish");//carga la biblioteca para los acentos
    system("color F9");//COLOR DEL SISTEMA
    portada();
    Puntofijo obj;
    obj.datos();
    obj.resultado();
}

