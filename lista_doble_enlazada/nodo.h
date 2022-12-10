#include <iostream>

using namespace std;

class Nodo
{
public:
    int dato;
    Nodo *sig, *ant;
    Nodo()
    {
        sig = nullptr;
        ant = nullptr;
    };
};