#include <iostream>
#include "arbol.h"
#define TIPO_DATO int

using namespace std;

void menu()
{
     system("clear");
     cout << "\n\t\t..[ ARBOL BINARIO ]..\n\n";
     cout << "\t [1] Insertar elemento\n";
     cout << "\t [2] Mostrar arbol\n";
     cout << "\t [3] Recorridos de profundiad\n";
     cout << "\t [4] Buscar elemento\n";
     cout << "\t [5] Eliminar elemento\n";
     cout << "\t [6] Anular\n";
     cout << "\t [7] Vacia\n";
     cout << "\t [8] SALIR\n";

     cout << "\n\t Ingrese opcion : ";
}

void menu2()
{
     system("clear"); // limpiar pantalla
     cout << endl;
     cout << "\t [1] En Orden\n";
     cout << "\t [2] Pre Orden\n";
     cout << "\t [3] Post Orden\n";
     cout << "\n\tOpcion :  ";
}

int main()
{

     // int a, b = 7;
     // int *p1 = &a, *p2 = &a, **p3 = nullptr;

     // *p1 = 12;
     // *p2 = 8;
     // p3 = &p2;
     // *p3 = &a;

     // *p2 = 3;
     // cout << a << " " << b << std::endl;
     Arbol ancla;
     Nodo a;

     int n;
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
               a.insertar(ancla.arbol, n, nullptr);
               cout << "\n\tAgregado..!\n\tValor agregado: " << n << endl;
               break;

          case 2:
               if (a.vacia(ancla.arbol))
                    cout << "\n\t Arbol vacio..!";
               else
                    a.printArbol(ancla.arbol, 0);
               break;

          case 3:

               if (a.vacia(ancla.arbol))
               {
                    cout << "\n\t Arbol vacio..!";
               }
               else
               {
                    menu2();
                    cin >> op2;
                    switch (op2)
                    {
                    case 1:
                         a.inorder(ancla.arbol);
                         break;
                    case 2:
                         a.preorder(ancla.arbol);
                         break;
                    case 3:
                         a.postorder(ancla.arbol);
                         break;
                    }
               }

               break;

          case 4:
               if (a.vacia(ancla.arbol))
               {
                    cout << "\n\t Arbol vacio..!";
               }
               else
               {
                    bool band;

                    cout << " Valor a buscar: ";
                    cin >> n;

                    band = a.busqueda(ancla.arbol, n);

                    if (band)
                         cout << "\n\tEncontrado...";
                    else
                         cout << "\n\tNo encontrado...";
               }
               break;

          case 5:
               if (a.vacia(ancla.arbol))
               {
                    cout << "\n\t Arbol vacio..!";
               }
               else
               {
                    cout << " Valor a eliminar: ";
                    cin >> n;
                    a.elimina(ancla.arbol, n);
                    cout << "\n\tEliminado..!\nValor eliminado:" << n << endl;
               }
               break;

          case 6:
               if (a.vacia(ancla.arbol))
               {
                    cout << "\n\t Arbol vacio..!";
               }
               else
               {

                    a.anular(ancla.arbol);
                    cout << "\n\tArbol anulado..!" << endl;
               }
               break;
          case 7:
               if (a.vacia(ancla.arbol))
                    cout << "\n\tTRUE" << endl;
               else
                    cout << "\n\tFALSE" << endl;
               break;
          }

          cout << "\n\n\n";
          system("read -p 'Presione enter para continuar...' var"); // hacer pausa y presionar una tecla para continuar
     } while (op != 8);

     return 0;
}