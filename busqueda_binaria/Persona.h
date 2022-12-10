#pragma once

#include <iostream>

class Persona
{
	// atributos --- protegidos (Publicos, privados, protegidos)
private:
	std::string nombre;
	std::string ap_p;
	std::string ap_m;
	int edad;

	// Metodos
public:
	// constructor
	Persona()
	{
		nombre = "sin nombre";
		ap_p = "sin apellido";
		ap_m = "sin apellido";
		edad = 0;
	};
	Persona(std::string nombre, std::string ap_p, std::string ap_m, int edad)
	{
		this->nombre = nombre;
		this->ap_p = ap_p;
		this->ap_m = ap_m;
		this->edad = edad;
	};
	std::string get_nombre()
	{
		return nombre;
	};
	void saludar()
	{
		std::cout << "Hola como estas";
	};
};
