#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void mostrarArreglo(const int[], int);
void ordenarArreglo(int[], int);
void intercambiar(int &, int &);
int main()
{
    const int tamano = 15;
    int arreglo[tamano] = {8, 10, 9, 14, 1, 2, 12, 15, 11, 5, 6, 7, 3, 4, 13};
    cout << "Arreglo antes de ordenarse: "
         << endl;
    mostrarArreglo(arreglo, tamano);
    cout << "Arreglo despues de ordenarse: " << endl;
    ordenarArreglo(arreglo, tamano);
    mostrarArreglo(arreglo, tamano);
    return 0;
} // fin de main
void mostrarArreglo(const int arreglo[], int tamano)
{
    for (int i = 0; i < tamano; i++)
        cout << arreglo[i] << endl;
}
void ordenarArreglo(int arreglo[], int tamano)
{

    for (int i = 0; i < tamano; i++)
    {

        for (int j = 0; j < tamano - 1; j++)
            if (arreglo[j] < arreglo[j + 1])
            {
                intercambiar(arreglo[j], arreglo[j + 1]);
            }
    }
}
void intercambiar(int &a, int &b)
{
    int tmp = b;
    b = a;
    a = tmp;
}