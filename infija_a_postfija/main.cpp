#include <iostream>
#include "pila.h"
#include "cola.h"

using namespace std;

Cola cola(100);

int prio(char ca)
{
    switch (ca)
    {
    case '^':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

void itop(string in)
{
    int i = 0;
    Pila pila(100);
    char car;
    while (i < in.size())
    {
        switch (in[i])
        {
        case '(':
            pila.push(in[i]);
            break;
        case ')':
            while (pila.top() != '(')
            {
                car = pila.top();
                pila.pop();
                cola.push(car);
            }
            pila.pop();
            break;
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            while (prio(in[i]) <= prio(pila.top()))
            {
                car = pila.top();
                pila.pop();
                cola.push(car);
            }
            pila.push(in[i]);
            break;
        default:
            // Es un numero
            cola.push(in[i]);
            break;
        }
        i++;
    }
    while (!pila.empty())
    {
        car = pila.top();
        pila.pop();
        cola.push(car);
    }
}

string mostrarPostFija()
{
    Cola cAux = cola;

    string res = "";

    while (!cAux.empty())
    {
        res += cAux.front();
        cAux.pop();
    }

    return res;
}

int main()
{

    string infija;
    cout << "\n\nIngresa la exprsion infija que desea transformar a postFijas:" << endl;
    cin >> infija;

    itop(infija);

    cout << "\nInfija:\n"
         << infija << "\n\n";

    cout << "Postfija:\n"
         << mostrarPostFija() << "\n\n";

    return 0;
}