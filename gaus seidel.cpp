#define GAUSS_SEIDEL_h
#define GAUSS_SEIDEL_h
#include<iostream>

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
int main(void)
{
    //definicion de la cabecera
//orden de llamado de las funciones
    setlocale(LC_ALL,"spanish");//carga la biblioteca para los acentos
    system("color F9");//COLOR DEL SISTEMA
    portada();//invocacion o llamado de definicion portada
    float a[10][10], b[10], x[10], y[10];
    int n = 0, m = 0, i = 0, j = 0;
    cout << "numero de Incognitas: ";//Definiendo el tamaño
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "\nIntroduzca los valores de: (" << i << ", " << j << "): ";//Llenado de Matriz
            cin >> a[i][j];
        }
    }
    cout << "\n\nIngrese los valores de los Resultado\n";//Llenado el vetor resultado
    for (i = 0; i < n; i++)
    {
        cout << "Resultado en:(" << i << ", " << i << ") ";
        cin >> b[i];
    }
    cout << "\n valores iniciales:\n";
    for (i = 0; i < n; i++)
    {
        cout << "valores iniciales:(" << i<<"):";
        cin >> x[i];
    }
    cout << "\n numero de iteraciones  : ";
    cin >> m;
    cout << "\n\nResultados:\n";
    while (m > 0)
    {
        for (i = 0; i < n; i++)
        {
            y[i] = (b[i] / a[i][i]);
            for (j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
                x[i] = y[i];
            }
            cout << (i + 1, y[i]) << endl;
        }
        cout << " \n ";
        m--;
    }
    return 0;
}


