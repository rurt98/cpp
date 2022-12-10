#include <iostream>

class Pila
{
private:
    char pila[1000];
    int tope;

    int tamanio;

public:
    Pila(int tam)
    {
        tamanio = tam;
        tope = 0;
    }

    void push(char value)
    {
        if (tamanio > tope)
        {
            tope++;
            pila[tope] = value;
        }
    }

    char top()
    {
        if (tope != 0)
            return pila[tope];
        else
            return -1;
    }

    void pop()
    {
        if (tope > 0)
            tope--;
    }

    bool empty()
    {
        return tope == 0;
    }
};