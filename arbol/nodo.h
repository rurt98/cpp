#include <iostream>
#define TIPO_DATO int

using namespace std;

class Nodo
{
private:
    TIPO_DATO data;
    Nodo *padre;
    Nodo *hijo_izq;
    Nodo *hijo_der;

public:
    Nodo()
    {
        padre = nullptr;
        hijo_der = nullptr;
        hijo_izq = nullptr;
    };
    bool vacia(Nodo *arbol)
    {
        return arbol == nullptr;
    }
    void insertar(Nodo *&arbol, int x, Nodo *padre)
    {
        if (vacia(arbol))
        {
            Nodo *aux = new Nodo;
            aux->data = x;
            arbol = aux;
            aux->padre = padre;
        }
        else
            (arbol->data > x) ? insertar(arbol->hijo_izq, x, arbol)
                              : insertar(arbol->hijo_der, x, arbol);
    };

    bool busqueda(Nodo *arbol, int n)
    {
        if (vacia(arbol))
            return false;
        else if (arbol->data == n)
            return true;
        else if (n < arbol->data)
            return busqueda(arbol->hijo_izq, n);
        else
            return busqueda(arbol->hijo_der, n);
    }

    void preorder(Nodo *&arbol)
    {
        if (vacia(arbol))
            return;
        cout << arbol->data << "   ";
        preorder(arbol->hijo_izq);
        preorder(arbol->hijo_der);
    };

    void inorder(Nodo *&arbol)
    {
        if (vacia(arbol))
            return;
        inorder(arbol->hijo_izq);
        cout << arbol->data << "  ";
        inorder(arbol->hijo_der);
    };

    void postorder(Nodo *&arbol)
    {
        if (vacia(arbol))
            return;
        postorder(arbol->hijo_izq);
        postorder(arbol->hijo_der);
        cout << arbol->data << "  ";
    };

    void printArbol(Nodo *arbol, int count)
    {
        if (vacia(arbol))
            return;

        printArbol(arbol->hijo_der, count + 1);
        for (int i = 0; i < count; i++)
            cout << "  ";
        cout << arbol->data << endl;
        printArbol(arbol->hijo_izq, count + 1);
    };

    // Funcion para determinar el nodo mas izq posoble
    Nodo *minimo(Nodo *arbol)
    {

        if (arbol->hijo_izq)
            return minimo(arbol->hijo_izq);
        else
            return arbol;
    };

    // Funcion para reemplazar nodo
    void reemplazar(Nodo *arbol, Nodo *nuevoNodo)
    {
        if (arbol->padre)
        {
            if (arbol->padre->hijo_izq)
            {

                if (arbol->data == arbol->padre->hijo_izq->data)
                {
                    arbol->padre->hijo_izq = nuevoNodo;
                }
            }

            if (arbol->data == arbol->padre->hijo_der->data)
            {
                arbol->padre->hijo_der = nuevoNodo;
            }
        }

        if (nuevoNodo)
        {
            nuevoNodo->padre = arbol->padre;
        }
    };

    void destruirNodo(Nodo *nodo)
    {
        nodo->hijo_izq = nullptr;
        nodo->hijo_der = nullptr;

        delete nodo;
    }

    void eliminarNodo(Nodo *nodoEliminar)
    {
        // Si arbol tiene dos hijos
        if (nodoEliminar->hijo_izq && nodoEliminar->hijo_der)
        {
            Nodo *menor = minimo(nodoEliminar->hijo_der);
            nodoEliminar->data = menor->data;
            eliminarNodo(menor);
        }
        // Si arbol solo tiene un hijo
        else if (nodoEliminar->hijo_izq)
        {
            reemplazar(nodoEliminar, nodoEliminar->hijo_izq);
            destruirNodo(nodoEliminar);
        }
        else if (nodoEliminar->hijo_der)
        {
            reemplazar(nodoEliminar, nodoEliminar->hijo_der);
            destruirNodo(nodoEliminar);
        }
        // Si arbol no tiene hijos
        else
        {
            reemplazar(nodoEliminar, nullptr);
            destruirNodo(nodoEliminar);
        }
    };

    void elimina(Nodo *arbol, int x)
    {
        if (vacia(arbol))
            return;

        if (x < arbol->data)
            elimina(arbol->hijo_izq, x);
        else if (x > arbol->data)
            elimina(arbol->hijo_der, x);
        else
            eliminarNodo(arbol);
    };

    void anular(Nodo *&arbol)
    {
        if (vacia(arbol))
            return;

        anular(arbol->hijo_izq);
        anular(arbol->hijo_der);

        if (arbol->padre == nullptr)
        {

            delete arbol;
            arbol = nullptr;
            return;
        }
        elimina(arbol, arbol->data);
    }
};