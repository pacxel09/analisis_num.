#define MINIMOS_CUADRADOS_h
#define MINIMOS_CUADRADOS_h
#include <iostream>//bibliotecas de entrada/salida
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<clocale>//caracteres especiales
using namespace std;
void portada (void)
{
std::cout<<"\n\n                    INSTITUTO POLITECNICO NACIONAL "<<std::endl;
std::cout<<"\n\n           Escuela Superior de Ingeniería Mecánica y eléctrica"<<std::endl;
std::cout<<"\n\n                            ESIME Zacatenco"<<std::endl;
std::cout<<"\n\n              Ingenieria en control y automatización"<<std::endl;
std::cout<<"\n\n                      Analisis Numerico\n"<<std::endl;
std::cout<<"                            3AM5\n"<<std::endl;
std::cout<<"                Nombre:Tinoco Martinez Axel Javier\n"<<std::endl;


}
void minimos(void)
{
    double *x,*y,a[100][100],sumx[100],sumy[100],vs[100];
    int i,j,n,m,k;
    string nom1;

    cout<<"\nnumero de puntos m= ";cin>>n;
    x=new double [n];
    y=new double [n];
    for (i=0;i<n;i++)
    {
        cout<<"x["<<i<<"]= ";cin>>x[i];
        cout<<"\ty["<<i<<"]= ";cin>>y[i];
    }

    cout<<"grado del polinomio n ";cin>>m;
    //se crea la suma de potencias de x
    for(i=0;i<=2*(m);i++)
    {
        sumx[i]=0;
        for(j=0;j<n;j++)
        {
            sumx[i]+=pow(x[j],i);
        }
    }
    //se crea la suma de potencias de xy
    for (i=0;i<=m;i++)
    {
        sumy[i]=0;
        for (j=0;j<n;j++)
        {
            sumy[i]+=y[j]*pow(x[j],i);
        }
    }
    for (i=0;i<=m;i++)
    {int k=i;
        for (j=0;j<=m;j++,k++)
        {
            a[i][j]=sumx[k];
        }
        a[i][m+1]=sumy[i];
    }

    for (i=0;i<=m;i++)
    {
        printf("\n\t|");
        for (j=0;j<=m+1;j++)
        {
            //cout<<"a["<<i<<"]["<<j<<"]= "<<a[i][j]<<endl;
            printf("%12.4f\t",a[i][j]);
        }
        printf("|");
    }
    //m debe ser el grado del polinomio que va a encontrar y vs[] es un vector solucion
    cout<<endl;


    double aux;
    for(i=0;i<=n;i++)

    {
        aux=a[i][i];
        for(j=0;j<=n+1;j++)
            a[i][j]=a[i][j]/aux;

        for(j=0;j<=n;j++)
        {
            if(i!=j)
            {
                aux=a[j][i];
                for(k=i;k<=n+1;k++)
                {
                    a[j][k]=a[j][k]-a[i][k]*aux;
                }
            }
        }
    }

    for(i=0;i<=n;i++)
    {
        x[i]=a[i][n+1];
    }

    for(i=0;i<=n;i++)
    {
        cout<<nom1<<"["<<i<<"]= "<<x[i]<<endl;
    }
}

int main(){//orden de llamado de las funciones
    setlocale(LC_ALL,"spanish");//carga la biblioteca para los acentos
    system("color F9");//COLOR DEL SISTEMA
    portada();
    minimos();
    return 0;
}



