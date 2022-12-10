#include <iostream>

using namespace std;

class Cola
{
private:
    int tamanio, d, u;
    char cola[1000];

public:
    Cola(int t)
    {
        tamanio = t;
        d = -1;
        u = -1;
    }

    int elementos()
    {
        if (empty())
        {
            return -1;
        }
        else
        {
            if (d <= u)
            {
                return u - d + 1;
            }
            else
            {
                return tamanio - d + u + 1;
            }
        }
    }

    void push()
    {
        if (!isFull())
        {

            char car;
            cout << "\n\nIngresa el caracter que desea guardar\n\n";
            cout << ": ";
            cin >> car;

            if (empty())
            {
                d = 0;
            }

            if (u == tamanio - 1)
            {
                u = 0;
            }
            else
            {

                u++;
            }

            cout << "\nSe guardo correctamente en la posicion: " << u << " Con el valor: " << car << "\n";

            cola[u] = car;

            // cout << "Inicio actual:  " << d;
            // cout << "En final:  " << cola[u] << "  " << u;
        }
        else
        {
            cout << "Cola llena\n";
        }
    }

    char front()
    {
        if (empty())
        {
            return '#';
        }
        return cola[d];
    }

    void pop()
    {
        if (!empty())
        {
            char tem = cola[d];
            if (elementos() == 1)
            {
                u = -1;
                d = -1;
            }
            else
            {

                d++;
            }
            cout << "Valor eliminado:  " << tem << "\n";
            // cout << "Del:  " << tem << "\n";
            // cout << "Nuevo inicio:  " << d << "\n"
            //      << "Con valor: " << cola[d] << "\n"
            //      << "y final: " << u;
        }
        else
        {
            cout << "Cola vacia\n";
        }
    }

    void anular()
    {
        u = -1;
        d = -1;
        cout << "Cola anulada\n";
    }

    void imprimir()
    {
        if (empty())
        {
            cout << "Cola vacia\n";
        }
        else
        {
            if (u < d)
            {
                for (size_t i = d; i < tamanio; i++)
                {
                    cout << cola[i];
                }
                for (size_t i = 0; i <= u; i++)
                {
                    cout << cola[i];
                }
            }
            else
            {
                for (size_t i = d; i <= u; i++)
                {
                    cout << cola[i];
                }
            }
        }
    }

    bool isFull()
    {
        return elementos() == tamanio;
    }

    bool empty()
    {
        return u == -1;
    }
};

// void Lista_alumnos::eliminarAlumno(int pos) {
//   system("cls");
//   // Validamos si existe el registro
//   // para eliminar el elemento registrado
//   if (alumnos[pos].existeRegistro) {

//     alumnos[pos].eliminar_registro();
//     ultimo--;
//   }
//   else {
//     // Si no existe el registo
//     // Validamos si la lista es vacia
//     // para cambair el mensaje
//     if (vacia()) {
//       cout << "Lista vacia";
//     }
//     else {
//       cout << "No existe el registro";
//     }

//   }
//   showOpc();
// }
