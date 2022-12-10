#include <iostream>

using namespace std;

class ListaStatica
{
private:
    bool orderedList;
    int tamanio, u;
    char lista[1000];

public:
    ListaStatica(int t)
    {
        orderedList = false;
        tamanio = t;
        u = -1;
    }

    bool isFull()
    {
        return u == tamanio - 1;
    }

    bool isEmpty()
    {
        return u == -1;
    }

    char recupera()
    {
        if (!isEmpty())
        {

            int index;
            cout << "\n\nIngresa la posicion para recuperar su valor\n\n";
            cout << ": ";
            cin >> index;

            if (index < 0 || index > u)
            {
                return '#';
            }
            else
            {
                return lista[index];
            }
        }
        else
        {
            cout << "Lista vacia\n";
            return '#';
        }
    }

    void agregar()
    {
        if (!isFull())
        {

            char car;
            cout << "\n\nIngresa el caracter que desea guardar\n\n";
            cout << ": ";
            cin >> car;

            lista[++u] = car;
            cout << "\nSe guardo correctamente en la posicion: " << u << " Con el valor: " << car << "\n";
        }
        else
        {
            cout << "Lista llena\n";
        }
    }

    void eliminar()
    {
        if (!isEmpty())
        {
            int index;
            cout << "\n\nIngresa la posicion en la que quieres eliminar su valor\n\n";
            cout << ": ";
            cin >> index;
            char tem = lista[index];
            if (index < 0 || index > u)
            {
                cout << "No existe registro en esta posicion: " << index << endl;
            }
            else
            {
                for (int i = index; i < u; i++)
                {
                    lista[i] = lista[i + 1];
                }
                u--;
                cout << "Valor eliminado:  " << tem << "\n";
            }
        }
        else
        {
            cout << "Lista vacia\n";
        }
    }
    /////////// Metodos de ordenamiento ///////////////
    // Metodo de ordenamiento burbuja
    void burbuja()
    {
        if (!isEmpty())
        {
            if (orderedList)
            {
                cout << "Lista ordenada\n";
            }
            else
            {

                int tmp = tamanio;

                cout << "Desordenada: ";
                imprimir();
                cout << endl;
                for (int i = 0; i < tamanio; i++)
                {

                    for (int j = 0; j < tmp - 1; j++)
                        if (lista[j] > lista[j + 1])
                        {
                            intercambiar(lista[j], lista[j + 1]);
                        }
                    tmp--;
                }
                orderedList = true;
                cout << "Ordenada: ";
                imprimir();
                cout << endl;
            }
        }
        else
        {
            cout << "Lista vacia\n";
        }
    }

    void insercionSort()
    {
        if (!isEmpty())
        {
            if (orderedList)
            {
                cout << "Lista ordenada\n";
            }
            else
            {

                cout << "Desordenada: ";
                imprimir();
                cout << endl;

                int i, j;
                char v;

                for (i = 1; i < tamanio; i++)
                {
                    v = lista[i];
                    j = i - 1;
                    while (j >= 0 && lista[j] > v)
                    {
                        lista[j + 1] = lista[j];
                        j--;
                    }

                    lista[j + 1] = v;
                }

                orderedList = true;
                cout << "Ordenada: ";
                imprimir();
                cout << endl;
            }
        }
        else
        {
            cout << "Lista vacia\n";
        }
    }

    int particion(int start, int end)
    {

        int pivot = lista[start];

        int i = start + 1;
        for (int j = i; j <= end; j++)
        {
            if (lista[j] < pivot)
            {
                intercambiar(lista[i], lista[j]);
                i++;
            }
        }

        intercambiar(lista[start], lista[i - 1]);

        return i - 1;
    }

    void quickSort(int start, int end)
    {

        // Dar fin cuando start es mayor o igual a final
        if (start >= end)
            return;

        // partición de lista
        int p = particion(start, end);

        // Ordenando la parte izquierda
        quickSort(start, p - 1);

        // Ordenando la parte derecha
        quickSort(p + 1, end);
    }

    void ordenamientoQuickSort()
    {
        if (!isEmpty())
        {
            if (orderedList)
            {
                cout << "Lista ordenada\n";
            }
            else
            {

                cout << "Desordenada: ";
                imprimir();
                cout << endl;
                quickSort(0, u);
                orderedList = true;
                cout << "Ordenada: ";
                imprimir();
                cout << endl;
            }
        }
        else
        {
            cout << "Lista vacia\n";
        }
    }

    void merge(int start, int mitad, int end)
    {
        int i, j, k;
        int elementosIzq = mitad - start + 1;
        int elementosDer = end - mitad;

        char izquierda[elementosIzq];
        char derecha[elementosDer];

        for (int i = 0; i < elementosIzq; i++)
        {
            izquierda[i] = lista[start + i];
        }

        for (int j = 0; j < elementosDer; j++)
        {
            derecha[j] = lista[mitad + 1 + j];
        }

        i = 0;
        j = 0;
        k = start;

        while (i < elementosIzq && j < elementosDer)
        {
            if (izquierda[i] <= derecha[j])
            {
                lista[k] = izquierda[i];
                i++;
            }
            else
            {
                lista[k] = derecha[j];
                j++;
            }
            k++;
        }

        // Siclos while para vaciar los arreglos en caso de ser necesario
        while (j < elementosDer)
        {
            lista[k] = derecha[j];
            j++;
            k++;
        }

        while (i < elementosIzq)
        {
            lista[k] = izquierda[i];
            i++;
            k++;
        }
    }

    void mergeSort(int start, int end)
    {
        // Dar fin cuando start es mayor o igual a final
        if (start < end)
        {

            int mitad = start + (end - start) / 2;
            mergeSort(start, mitad);
            mergeSort(mitad + 1, end);
            merge(start, mitad, end);
        }
    }

    void ordenamientoMergeSort()
    {
        if (!isEmpty())
        {
            if (orderedList)
            {
                cout << "Lista ordenada\n";
            }
            else
            {

                cout << "Desordenada: ";
                imprimir();
                cout << endl;
                mergeSort(0, u);
                orderedList = true;
                cout << "Ordenada: ";
                imprimir();
                cout << endl;
            }
        }
        else
        {
            cout << "Lista vacia\n";
        }
    }

    void intercambiar(char &a, char &b)
    {
        int tmp = b;
        b = a;
        a = tmp;
    }

    //////////////////////////////////////////////

    /////////// Metodos de busqueda ///////////////

    void busquedaLineal()
    {

        if (!isEmpty())
        {

            char caracter;
            cout << "\n\nIngresa el valor que deseas obtener su indice\n\n";
            cout << ": ";
            cin >> caracter;

            for (int i = 0; i <= u; i++)
            {
                if (lista[i] == caracter)
                {
                    cout << "Se encuantra en la posición: " << i;
                    return;
                }
            }
            cout << "No se encontro el registro: -1\n";
        }
        else
        {
            cout << "Lista vacia\n";
        }
    }

    void busquedaBinaria()
    {

        if (isEmpty())
        {
            cout << "Lista vacia\n";
        }
        else if (!orderedList)
        {
            cout << "Lista desordenada\n";
        }
        else
        {
            char caracter;
            cout << "\n\nIngresa el valor que deseas obtener su indice\n\n";
            cout << ": ";
            cin >> caracter;

            int Iarriba = tamanio - 1;
            int Iabajo = 0;
            int Icentro;
            while (Iabajo <= Iarriba)
            {
                Icentro = (Iarriba + Iabajo) / 2;
                if (lista[Icentro] == caracter)
                {
                    cout << "Se encuantra en la posición: " << Icentro;
                    return;
                }
                else if (caracter < lista[Icentro])
                    Iarriba = Icentro - 1;
                else
                    Iabajo = Icentro + 1;
            }
            cout << "No se encontro el registro: -1";
        }
    }

    ///////////////////////////////

    void imprimir()
    {
        if (!isEmpty())
        {

            for (int i = 0; i <= u; i++)
                cout << lista[i];
        }
        else
        {
            cout << "Lista vacia\n";
        }
    }

    void anular()
    {
        u = -1;
        orderedList = false;
        cout << "Lista anulada\n";
    }
};