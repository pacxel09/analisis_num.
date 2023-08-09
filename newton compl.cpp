#include <iostream>
#include <complex>//complejos
#include <cmath>
#include<clocale>//caracteres especiales
using namespace std;

int maxIter = 10;

// Funcion 1: x^2 - 5x + 6
double f1(double x)
{
	return pow(x,2) - 5*x + 6;
}
double f1Prime(double x)
{
	return 2*x - 5;
}

// Funcion 2 (compleja): z^3 - 1
complex<double> f2(complex<double> z)
{
	return pow(z,3) - complex<double>(1,0);
}
complex<double> f2Prime(complex<double> z)
{
	return complex<double>(3,0)*pow(z,2);
}
void newtonRhapson2(complex<double> z0)
{
	complex<double> z = z0;
	cout << "Iteracion | z" << endl;
	cout << "-------------" << endl;
	for(int i=0; i<maxIter; i++)
	{
		z = z - f2(z)/f2Prime(z);
		cout << i << ", " << z.real() << " + i" << z.imag() << endl;
	}
}

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
	double real, imag;
	cout << "Newton-Rhapson complejo.\nIntroduzca la parte real de z0: ";
	cin >> real;
	cout << "Ahora la parte imaginaria: ";
	cin >> imag;
	newtonRhapson2(complex<double>(real, imag));

	return 0;
}

/*esperando que funcione por que no le entendi como hacer este programa profe */
/*cuando se reo este programa solo dios y yo sabiamos como funcionaba, ahora solo dios sabe*/
