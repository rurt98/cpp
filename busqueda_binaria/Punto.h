#pragma once
#include <iostream>

class Punto
{
private:
	float x, y;

public:
	Punto(int x = 0, int y = 0) : x(x), y(y){}; // constructor
	void imprimir() { std::cout << "(" << x << "," << y << ")" << std::endl; }
	Punto sum(Punto a, Punto b)
	{
		Punto c;
		c.x = a.x + b.x;
		c.y = a.y + b.y;

		return c;
	};
	Punto operator+(Punto b)
	{
		Punto c;
		c.x = x + b.x;
		c.y = y + b.y;

		return c;
	};
	Punto operator*(Punto b)
	{
		Punto c;
		c.x = x * b.x;
		c.y = y * b.y;

		return c;
	};
};
