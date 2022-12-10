// Busqueda lineal //en un arreglo.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void mostrarArreglo(const int[], int); // prototipo de funcion que
// recibe un arreglo constante
int busquedaLineal(const int[], int, int); // arreglo, tamano, Value
int main()
{
    // Inicializamos variables:
    int Value = 0;
    const int tamano = 15;
    int arreglo[tamano] = {25, 17, 13, 16, 41, 32, 12, 115, 95, 84, 54, 63, 78, 21, 10};

    // Le mostramos todos los valores del arreglo al usuario:
    cout << "Elementos del arreglo: " << endl;
    mostrarArreglo(arreglo, tamano);
    // Le pedimos el valor que desea buscar para retornarle el indice.
    cout << "Indique un valor a buscar y se le devolvera el indice: " << endl;
    cin >> Value;
    // Buscamos de manera binaria el idice que le corresponde.
    cout << "Su valor se encuentra en el index:" << busquedaLineal(arreglo, tamano, Value) << endl;
    cout << "Fin del programa." << endl;
    return 0;
} // fin de main
void mostrarArreglo(const int arreglo[], int tamano)
{
    // Iteramos sobre todos los valores del arreglo para mostrarlos
    for (int i = 0; i < tamano; i++)
        cout << arreglo[i] << endl;
}
int busquedaLineal(const int arreglo[], int tamano, int Value)
{
    // Iteramos sobre todos los valores de la lista
    for (int i = 0; i < tamano; i++)
        // Si el valor que corresponde en el for es igual al valor que
        // se introdujo retornar el indice de la iteracion
        if (arreglo[i] == Value)
            return i;
    // Si el valor no se encuentra returnar -1
    return -1;
}