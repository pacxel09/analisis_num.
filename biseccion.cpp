#include <iostream>//bibliotecas de entrada/salida
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<clocale>//caracteres especiales
using namespace std;
double f(double);
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
    int imax,iter;
    double xi,xd,ea,em,test,xa,xaold;


    printf("\nMETODO DE BISECCION\n\n");

    printf("Introduce el X0\n");
    scanf("%lf",&xi);
    printf("Introduce el Xf\n");
    scanf("%lf",&xd);
    printf("Introduce el numero de iteraciones maximas\n");
    scanf("%d",&imax);
    printf("Introduce el error minimo\n");
    scanf("%lf",&em);

    iter=0;
    xa=0;

    if(f(xi)*f(xd)>0)
        printf("No hay raiz en ese intervalo\n");

    else{

        printf("\nIteracion    Raiz     Error aprox\n");

        do{

            iter++;

            xaold=xa;

            xa=(xi+xd)/2;

            ea=fabs((xa-xaold)/xa)*100;

            test=f(xi)*f(xa);

            if(test<0)
                xd=xa;

            else if(test >0)
                xi=xa;

            else
                ea=0;

            printf("\t\n%d    %f    %f\n",iter,xa,ea);


        } while(ea>em && iter<imax);

    }



    return 0;
}


double f(double x)
{
    return x*x -2;
}
