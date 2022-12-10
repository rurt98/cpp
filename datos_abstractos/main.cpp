#include <iostream>
#include "cola.h"
#include "lista_estatica.h"

using namespace std;

int menuPrincipal();
int menuCola();
int menuLista();
void continuarOutput();

int main()
{
    int opc, pos;
    do
    {
        system("clear");
        opc = menuPrincipal();

        if (opc == 1)
        {
            opc = menuCola();
        }
        else if (opc == 2)
        {
            opc = menuLista();
        }

    } while (opc != 3);

    return 0;
}

int menuPrincipal()
{

    int opc;

    system("clear");

    cout << "Menu\n";
    cout << "Seleccione una opcion:\n\n";
    cout << "1. Cola estática\n";
    cout << "2. Lista estática\n\n";
    cout << "3. Salir\n\n";
    cout << ":";
    cin >> opc;

    return opc;
}

int menuCola()
{
    system("clear");
    int opc, tamanio;
    cout << "Ingrese el tamaño de la cola:\n";
    cout << ":";
    cin >> tamanio;
    Cola cola(tamanio);

    do
    {

        system("clear");

        cout << "Menu\n";
        cout << "Seleccione una metodo:\n\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Front\n";
        cout << "4. Imprimir\n";
        cout << "5. Anular\n";
        cout << "6. Regresar\n\n";
        cout << ":";
        cin >> opc;

        switch (opc)
        {
        case 1:
            cola.push();
            continuarOutput();
            break;
        case 2:
            cola.pop();
            continuarOutput();
            break;
        case 3:
            cout << "Front: " << cola.front() << endl;
            continuarOutput();
            break;
        case 4:
            cola.imprimir();
            continuarOutput();
            break;
        case 5:
            cola.anular();
            continuarOutput();
            break;

        default:
            break;
        }

    } while (opc != 6);

    return opc;
}

void continuarOutput()
{
    char opc;
    cout << "\n\nContinuar (z + ENTER)\n";
    cout << ":";
    cin >> opc;
}

int menuLista()
{

    system("clear");
    int opc, tamanio;
    cout << "Ingrese el tamaño de la lista:\n";
    cout << ":";
    cin >> tamanio;
    ListaStatica lista(tamanio);

    do
    {

        system("clear");

        cout << "Menu\n";
        cout << "Seleccione un metodo:\n\n";
        cout << "1. Insertar\n";
        cout << "2. Vacia\n";
        cout << "3. Llena\n";
        cout << "4. Eliminar\n";
        cout << "5. Recuperar\n";
        cout << "6. Imprimir\n";
        cout << "7. Anular\n";
        cout << endl;
        cout << "METODOS DE ORDENAMIENTO:\n";
        cout << "8. Burbuja\n";
        cout << "9. Insercion\n";
        cout << "10. Quicksort\n";
        cout << "11. Mergesort\n";
        cout << endl;
        cout << "METODOS DE BUSQUEDA:\n";
        cout << "12. Busqueda lineal\n";
        cout << "13. Busqueda Binaria\n";
        cout << endl;
        cout << "14. Regresar\n\n";
        cout << ":";
        cin >> opc;

        system("clear");

        switch (opc)
        {
        case 1:
            lista.agregar();
            continuarOutput();
            break;
        case 2:
            if (lista.isEmpty())
                cout << "TRUE";
            else
                cout << "False";

            continuarOutput();
            break;
        case 3:
            if (lista.isFull())
                cout << "TRUE";
            else
                cout << "False";
            continuarOutput();
            break;
        case 4:
            lista.eliminar();
            continuarOutput();
            break;
        case 5:
            cout << lista.recupera();
            continuarOutput();
            break;
        case 6:
            lista.imprimir();
            continuarOutput();
            break;
        case 7:
            lista.anular();
            continuarOutput();
            break;
        case 8:
            lista.burbuja();
            continuarOutput();
            break;
        case 9:
            lista.insercionSort();
            continuarOutput();
            break;
        case 10:
            lista.ordenamientoQuickSort();
            continuarOutput();
            break;
        case 11:
            lista.ordenamientoMergeSort();
            continuarOutput();
            break;
        case 12:
            lista.busquedaLineal();
            continuarOutput();
            break;
        case 13:
            lista.busquedaBinaria();
            continuarOutput();
            break;

        default:
            break;
        }

        system("clear");

    } while (opc != 14);

    return opc;
}