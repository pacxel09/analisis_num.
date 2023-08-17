#include <iostream>//bibliotecas de entrada/salida
#include <iostream>
#include<cmath>
#include<iomanip>
#include<clocale>//caracteres especiales
using namespace std;

class Secante{
private:
    double xi,xii,err;
    int n;
public:
    Secante();
    void datos();
    double calcularRaiz();
    double f(double x);
    void resultado();
    double Error_re(double x1,double x2);
    ~Secante();
};
Secante::Secante(): xi(0.0), xii(0.0), err(0.0), n(0) {}
void Secante::datos()
{

    cout<<"Dame el intervalo izquierdo Xi-1= ";cin>>xii;
    cout<<"Dame el intervalo derecho Xi= ";cin>>xi;
    cout<<"Dame el margen de error err= ";cin>>err;
    cout<<"Dame el maximo numero de iteraciones n= ";cin>>n;
}

double Secante::calcularRaiz()
{
    double xr;
    xr=0.0;
    cout<<setiosflags(ios::fixed)<<setiosflags(ios::showpoint)<<setprecision(7)<<endl;
    cout<<"n\t\txi\t\txi-1\t\tf(xi)\t\tf(Xi-1)\t\tf(Xi+1)\t\tError(%)"<<endl<<endl;

    for(int i=1;i<=n;i++)
    {
        xr=xi-((f(xi)*(xi-xii))/(f(xi)-f(xii)));
        cout<<i<<"\t\t"<<xi<<"\t"<<xii<<"\t" <<f(xi)<<"\t"<<f(xii)<<"\t"<<xr<<"\t"<<Error_re(xr,xi)*100<<endl;

        if(Error_re(xr,xi)<err)
            return xr;
        else
            xi=xii;
        xii=xr;
    }
    cout<<endl;
    return xr;

}

double Secante::f(double x){return pow(x,2)-x-1.0;}
void Secante::resultado(){cout<<"la raiz es Xr= "<<calcularRaiz()<<endl;}
double Secante::Error_re(double x1, double x2)
{return abs(x1-x2)/abs(x1);}
Secante::~Secante(){}
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
    Secante obj;
    obj.datos();
    obj.resultado();
}


