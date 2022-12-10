#include <iostream>
#include "nodo.h"
using namespace std;

class Lista_doble_ligada
{
private:
    Nodo *ptr_lista; // ancla
    Nodo *ultimo;
    int count;

public:
    Lista_doble_ligada()
    {
        ptr_lista = nullptr;
        ultimo = nullptr;
        count = 0;
    };

    bool vacia() { return ptr_lista == nullptr; };

    void agregar(int n, int pos)
    {
        Nodo *nodo = new Nodo;
        nodo->dato = n;

        count++;

        if (vacia()) // Validar lista vacia
        {
            nodo->sig = nullptr;
            nodo->ant = nullptr;
            ptr_lista = nodo;
            return;
        }

        if (pos == 0) // Insertar en la Posicion 0
        {

            ptr_lista->ant = nodo;
            nodo->sig = ptr_lista;
            nodo->ant = nullptr;
            ptr_lista = nodo;
            return;
        }
        else // Si es distinto de 0 avanzar hasta el numero de posicion
        {
            if (pos > count - 1) // Si la posicion es mayor a count
            {
                pos = count - 1;
            }
            Nodo *temp = ptr_lista;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->sig;
                if (temp == nullptr)
                {
                    return;
                }
            }
            if (temp->sig != nullptr) // Insertar nodo en posicion que no sea 0 ni el ultimo
            {
                temp->sig->ant = nodo;
                nodo->sig = temp->sig;
                nodo->ant = temp;
                temp->sig = nodo;
            }
            else // Insertar en la ultima posicion
            {
                temp->sig = nodo;
                nodo->ant = temp;
                ultimo = nodo;
            }
        }
    };

    void imprimir()
    {
        cout << endl;
        for (Nodo *p = ptr_lista; p != nullptr; p = p->sig)
            cout << p->dato << "  ";

        cout << endl
             << endl;
    }

    void getPrimero()
    {
        cout << ptr_lista->dato;
    }

    void getUltimo()
    {
        cout << ultimo->dato;
    }

    void anular()
    {
        Nodo *aux;
        while (ptr_lista != nullptr)
        {
            aux = ptr_lista;
            ptr_lista = ptr_lista->sig;
            delete aux;
        }
    }

    int localiza(int n)
    {
        int pos = 0;
        for (Nodo *p = ptr_lista; p != nullptr; p = p->sig)
        {
            if (p->dato == n)
            {
                cout << pos << "  ";
                return pos;
            }

            pos++;
        }

        return -1;
    }

    int recupera(int pos)
    {
        int countAux = 0;
        for (Nodo *p = ptr_lista; p != nullptr; p = p->sig)
        {
            if (countAux == pos)
                return p->dato;

            countAux++;
        }

        return -1;
    }

    void eliminar(int pos)
    {

        if (pos < 0 || pos > count)
        {
            cout << "No existe la posicion ingresada" << endl;
            return;
        }

        count--;
        if (pos == 0) // eliminar en la posicion 0
        {
            Nodo *temp2 = ptr_lista->sig;
            cout << "Valor eliminado: " << ptr_lista->dato << endl;
            delete ptr_lista;
            ptr_lista = temp2;
            ptr_lista->ant = nullptr;
        }
        else
        {
            Nodo *temp = ptr_lista;
            for (int i = 0; i < pos; i++)
            {
                temp = temp->sig;
                if (temp == NULL)
                {
                    return;
                }
            }
            cout << "Valor eliminado: " << temp->dato << endl;
            if (temp == ultimo) // eliminar en la ultima posicion
            {
                ultimo = temp->ant;
                temp->ant->sig = nullptr;
                temp->ant = nullptr;
                delete temp;
            }
            else // eliminar Enmedio
            {
                temp->sig->ant = temp->ant;
                temp->ant->sig = temp->sig;
                delete temp;
            }
        }
    }
};
