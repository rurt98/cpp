#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void mostrarArreglo(const int[], int);
int busquedaBinaria(const int[], int, int);

int main()
{
    // Inicializamos variables:
    int value = 0;
    const int tamano = 13;
    int arreglo[tamano] = {10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70};

    // Le mostramos todos los valores del arreglo al usuario:
    cout << "Elementos del arreglo: " << endl;
    mostrarArreglo(arreglo, tamano);
    // Le pedimos el valor que desea buscar para retornarle el indice.
    cout << "Indique un valor a buscar y se le devolvera el indice: " << endl;
    cin >> value;
    // Buscamos de manera binaria el idice que le corresponde.
    cout << "Su valor se encuentra en el index: " << busquedaBinaria(arreglo, tamano, value) << endl;
    cout << "Fin del programa." << endl;
    return 0;
}
void mostrarArreglo(const int arreglo[], int tamano)
{
    // Iteramos sobre todos los valores del arreglo para mostrarlos
    for (int i = 0; i < tamano; i++)
        cout << arreglo[i] << endl;
}
int busquedaBinaria(const int arreglo[], int tamano, int value)
{
    // inicializamos el inice de arriba (Tamño - 1) y abajo (0)
    int Iarriba = tamano - 1;
    int Iabajo = 0;
    int Icentro;

    // Con este while se ejecutara el codigo hasta que el indice de abajo sea menor o igual al indice de arriba:
    // Si se cumple retornaremos un -1
    while (Iabajo <= Iarriba)
    {
        // Calcularos el inidce de a medias:
        Icentro = (Iarriba + Iabajo) / 2;
        // Si se encuenta ese valor con el valor ingresado, retornar el resultado.
        if (arreglo[Icentro] == value)
            return Icentro;
        else if (value < arreglo[Icentro])
            Iarriba = Icentro - 1;
        else
            Iabajo = Icentro + 1;
    }
    return -1;
}
