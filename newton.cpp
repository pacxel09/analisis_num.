#include <iostream>//bibliotecas de entrada/salida
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<clocale>//caracteres especiales

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
    float x0,fx,dfx,nx0,Er,marErr;
    int n,contador;
    float funcionO(float xi);
    float funcionD(float xi);
    float funcionN(float xi, float fx,float dfx);
    float error(float xi, float nxi );
    printf("\t\tMetodo de Newton\n");
    printf("\n Introduzca las iteraciones a realizar=");
    scanf("%d",&n);
    printf("\n Introduzca el margen de Error=");
    scanf("%f",&marErr);
    printf("\n Introduzca el valor de xi:");
    scanf(" %f",&x0);

    printf("Contador\t F(x)\t \tF'(x)\t \tXm\t \t\tErr\t\n");
    for(contador=1 ; contador<=n ; contador++)
    {
        fx= funcionO(x0);
        dfx=funcionD(x0);
        nx0=funcionN(x0,fx,dfx);
        Er= error(x0,nx0);

        printf("\t%d\t  %f\t %f\t %f\t %f\n", contador,fx,dfx, nx0,Er);

        if(marErr>Er)
        {
            printf("\n %.2f es la raiz \n\n",Er);
            return 0;
        }
        if(dfx==0)
        {
            printf("\n SE PRODUCE UNA INDETERMINACION");
            return 0;
        }
        x0=nx0;
    }

}
float funcionO(float x)
{
    float fun;
    fun= pow(x,2)-x-1 ;
    return fun;
}
float funcionD(float x)
{
    float func;
    func=(2*x)-1 ;
    return func;
}
float funcionN(float x,float fdx,float dx)
{
    float xinew;
    xinew= x-(fdx/dx);
    return xinew;
}
float error(float x,float xn)
{
    float E;
    E= ((xn-x)/xn)*100;
    if(E<0)
    {
        E=E*-1;
        return E;
    }
    else
    {
        return E;
    }
}
