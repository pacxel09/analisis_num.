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
class In_New{
	private:
		double Yk,h,K;
		int n;
		double *x,*y,*Dy1,*Dy2,*Dy3,*Dy4,Xk;
	public:
		In_New(){
			Yk=h=K=Xk=0.0;
			n=6;
			x=new double[n];
			*x=0.0;
			y=new double[n];
			*y=0.0;
			Dy1=new double[n-1];
			*Dy1=0.0;
			Dy2=new double[n-2];
			*Dy2=0.0;
			Dy3=new double[n-3];
			*Dy3=0.0;
			Dy4=new double[n-4];
			*Dy4=0.0;
		}
		void LeeDatos(){
			cout<<endl<<"valores de x :"<<endl;
			for(int i=0;i<n;++i){
				cin>>*(x+i);
			}

			cout<<endl<<" valores de y "<<endl;
			for(int i=0;i<n;++i){
				cin>>*(y+i);
			}
			cout<<endl<<"valor del intervalo : ";
			cin>>Xk;
		}
		void Calcula(){
			for(int i=0;i<n-1;++i)
				*(Dy1+i)=*(y+ i+1)-*(y+ i);//Dy1

			for(int i=0;i<n-2;++i)
				*(Dy2+i)=*(Dy1+i+1)-*(Dy1+ i);//Dy2

			for(int i=0;i<n-3;++i)
				*(Dy3+i)=*(Dy2+i+1)-*(Dy2+ i);//Dy3

			for(int i=0;i<n-4;++i)
				*(Dy4+i)=*(Dy3+i+1)-*(Dy3+ i);//Dy4

			h=(5-0)/(6-1);
			K=(Xk-0)/(h);

			Yk= *(y+0)+ (K)*(*(Dy1+0)) + ((((K)*(K-1))/(2))*(*(Dy2+0))) + ((((K)*(K-1)*(K-2))/(3*2))*(*(Dy3+0)))+ ((((K)*(K-1)*(K-2)*(K-3))/(4*3*2))*(*(Dy4+0)));
		}
		void ImprimeDatos(){

			cout<<endl<<" x\t\ty "<<endl;
			for(int i=0;i<n;++i){
				cout<<*(x+i)<<"\t\t"<<*(y+i)<<endl;
			}

			for(int i=0;i<n-1;i++)
				cout<<*(Dy1+i)<<endl;

			for(int i=0;i<n-2;i++)
				cout<<*(Dy2+i)<<endl;

			for(int i=0;i<n-3;i++)
				cout<<*(Dy3+i)<<endl;

			for(int i=0;i<n-4;i++)
				cout<<*(Dy4+i)<<endl;

			cout<<endl<<"Xa = 1.5 "<< "Ya = "<<Yk;

		}
		double Fac(double xn){
			double a=0;
			for(int i=1;i<=xn;++i){
				a*=i;
			}
			return a;
		}
};
int main(){//definicion de la cabecera
//orden de llamado de las funciones
    setlocale(LC_ALL,"spanish");//carga la biblioteca para los acentos
    system("color F9");//COLOR DEL SISTEMA
    portada();
	In_New A;
	A.LeeDatos();
	A.Calcula();
	A.ImprimeDatos();
	return 0;
}
