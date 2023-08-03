#define GAUSS_JORDAN_h
#define GAUSS_JORDAN_h
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <iostream>
using namespace std;
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
//Sirve para estructurar la matriz
struct matriz
{
    int n, m; //número de filas y columnas de la matriz
    double** p; //matriz con punteros

    matriz(){}
    //inicia la matriz
    matriz(int ni,int  mi){
        n = ni;
        m = mi;
        p = new double*[ni];
        for (int i = 0; i < ni; i++)
        {
            p[i] = new double[mi];
        }
    }

};


//lee la matriz
void leer_matriz(matriz *entrada){
    double aux;
    for(int i = 0; i < entrada->n; ++i)
    {
        for(int j = 0; j < entrada->m; ++j)
        {
            scanf("%lf", &aux);
            entrada->p[i][j] = aux;
        }
    }
}


//hace la eliminacion gaussiana de una matriz y retorna la matriz
//de multiplicadores
matriz eliminacion_gaussiana(matriz *mext){
    if(mext->n+1 != mext->m){
        printf("error, la matriz no es una matriz extendida\n");
        matriz m;
        return m;
    }else{
        //matriz de multiplicadores
        matriz m(mext->n, mext->m);
        for(int k = 0; k < mext->n-1; ++k){
            for(int i = k+1; i < mext->n; ++i){
                m.p[i][k] = mext->p[i][k]/mext->p[k][k];
                for(int j = k; j < mext->m; ++j){
                    mext->p[i][j] -=(m.p[i][k]*mext->p[k][j]);
                }
            }
        }
        return m;
    }

}

//sustituye de la ultima variable hasta la primera
//retorna una matriz de 1 X n (numero de variables)
matriz sustitucion_regresiva(matriz in){

    matriz r (1, in.n);
    for(int k = in.n-1; k >= 0; --k){
        double acum = 0.0;
        //sumatoria interna de términos
        for(int i = k+1; i < in.n; ++i){
            acum += (in.p[k][i]*r.p[0][i]);
        }
        r.p[0][k] = (in.p[k][in.n] - acum)/in.p[k][k]; //b_i - sumatoria
    }

    return r;

}

//sustituye de la primera variable hasta la ultima
//retorna una matriz de 1 X n (numero de variables)
matriz sustitucion_progresiva(matriz in){
    matriz r (1, in.n);
    for(int k = 0; k<= in.n-1; ++k){
        double acum = 0.0;
        //sumatoria interna de términos
        for(int i = 0; i < k-1; ++i){
            acum += (in.p[k][i]*r.p[0][i]);
        }
        r.p[0][k] = (in.p[k][in.n] - acum)/in.p[k][k]; //b_i - sumatoria
    }
    return r;
}




//imprime la matriz
void imprimir(matriz in){
    printf("impresion de la matriz n con %d filas y %d columnas\n", in.n, in.m);
    for(int i = 0; i < in.n; ++i){
        for(int j = 0; j < in.m; ++j){
            printf("%lf ", in.p[i][j]);
        }
        printf("\n");
    }
}



int main()
{
    //definicion de la cabecera
//orden de llamado de las funciones
    setlocale(LC_ALL,"spanish");//carga la biblioteca para los acentos
    system("color F9");//COLOR DEL SISTEMA
    portada();//invocacion o llamado de definicion portada
    cout<<("\n------===GAUSS JORDAN===------\n\n");
    int filas, columnas;
    cout<<("ingrese el numero de filas y columnas\n");
    scanf("%d %d", &filas, &columnas);
    cout<<("ingrese la matriz por filas separadas por espacio\n");
    matriz entrada(filas, columnas);
    leer_matriz(&entrada);
    matriz m;
    m = eliminacion_gaussiana(&entrada);
    cout<<("\n matriz de multiplicadores\n\n");
    imprimir(m);
    cout<<("\nmatriz luego de la eliminacion gaussiana\n\n");
    imprimir(entrada);
    matriz resultados = sustitucion_regresiva(entrada);
    cout<<("resultados a las ecuaciones: \n");
    imprimir(resultados);
    return 0;
}


