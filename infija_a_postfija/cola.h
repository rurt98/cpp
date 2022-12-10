#include <iostream>

class Cola
{
private:
    int tamanio, d, u;
    char cola[1000];

public:
    Cola(int t)
    {
        tamanio = t;
        d = 0;
        u = 0;
    }

    void push(char v)
    {
        if (empty())
        {
            d = 1;
            u = 1;
        }
        else
        {
            u++;
        }

        cola[u] = v;
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
        d++;
        if (d > u)
        {
            d = 0;
            u = 0;
        }
    }

    bool empty()
    {
        return d == 0 && u == 0;
    }
};