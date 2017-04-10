#include <iostream>

class Nodo{
public:
	
	Nodo *padre;
	Nodo *Izq;
	Nodo *Der;
	int Dato;
	Nodo(int Dato);
	Nodo(int Dato,Nodo *padre);
};