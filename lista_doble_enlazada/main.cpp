#include <iostream>
#include "lista_doble_ligada.h"
using namespace std;

void menu()
{
    system("clear");
    cout << "\n\t..[ Lista doble enlazada con encabezado ]..\n\n";
    cout << "\t [1] Insertar elemento\n";
    cout << "\t [2] Eliminar elemento\n";
    cout << "\t [3] Imprimir lista\n";
    cout << "\t [4] Localiza elemento\n";
    cout << "\t [5] Recupera elemento\n";
    cout << "\t [6] Anular\n";
    cout << "\t [7] Vacía\n";
    cout << "\t [8] Primero\n";
    cout << "\t [9] Ultimo\n";
    cout << "\t [10] SALIR\n";

    cout << "\n\t Ingrese opcion : ";
}

int main()
{
    Lista_doble_ligada lista;

    int n, pos;
    int op, op2;

    do
    {
        menu();
        cin >> op;
        cout << endl;

        switch (op)
        {
        case 1:
            cout << " Ingrese valor : ";
            cin >> n;
            cout << " Ingrese posicion : ";
            cin >> pos;
            lista.agregar(n, pos);

            cout << "\n\tAgregado..!\n\tValor agregado: " << n;
            break;

        case 2:
            if (lista.vacia())
                cout << "\n\t lista vacia..!";
            else
            {
                cout << "Posicion del valor a eliminar : ";
                cin >> pos;
                lista.eliminar(pos);
            }

            break;

        case 3:
            if (lista.vacia())
                cout << "\n\t Lista vacia..!";
            else
                lista.imprimir();
            break;

        case 4:
            if (lista.vacia())
            {
                cout << "\n\t Lista vacia..!";
            }
            else
            {
                cout << " Ingrese valor a localizar : ";
                cin >> n;
                int index = lista.localiza(n);

                if (index < 0)
                {
                    cout << "No se localizo el Elemento";
                }
                else
                {
                    cout << "El elemento se localizo en el index: " << index;
                }
            }
            break;

        case 5:
            if (lista.vacia())
            {
                cout << "\n\t Lista vacia..!";
            }
            else
            {
                cout << " Ingrese posicion a recuperar su valor : " << endl;
                cin >> pos;
                int valor = lista.recupera(pos);

                if (valor < 0)
                {
                    cout << "No se encontro ningun valor en la posicion " << pos;
                }
                else
                {
                    cout << "El valor es : " << valor;
                }
            }
            break;

        case 6:
            if (lista.vacia())
            {
                cout << "\n\t Lista vacia..!";
            }
            else
            {

                lista.anular();
                cout << "\n\tLista anulada..!" << endl;
            }
            break;
        case 7:
            if (lista.vacia())
                cout << "\n\t TRUE\n";
            else
                cout << "\n\tFALSE\n";
            break;
        case 8:
            if (lista.vacia())
            {
                cout << "\n\t Lista vacia..!";
            }
            else
            {
                cout << "\n\t Primero: ";
                lista.getPrimero();
            }
            break;
        case 9:
            if (lista.vacia())
            {
                cout << "\n\t Lista vacia..!";
            }
            else
            {
                cout << "\n\t Ultimo: ";
                lista.getUltimo();
            }
            break;
        }

        cout << "\n\n\n";
        system("read -p 'Presione enter para continuar...' var"); // hacer pausa y presionar una tecla para continuar
    } while (op != 10);

    return 0;
}